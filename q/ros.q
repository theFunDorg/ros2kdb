//table Counter
tbls:{([tbl:tables[]]cnt:count each get each tables[])};

// Change symbol name to req/resp
.ros.makeReq:{`$string[x],"_request"};
.ros.makeRes:{`$string[x],"_response"};

// Schema parser to parse Topic messages into tables
.ros.parseTopicSchema:{[msgFile]
  rawData:system "cat ",.ros.interfaceDir,"/msg/",(string msgFile),".msg";
  .ros.createSchema[msgFile;rawData];
  };

// Schema parser to parse Service messages into tables
.ros.parseServiceSchema:{[msgFile]
  rawData:system "cat ",.ros.interfaceDir,"/srv/",(string msgFile),".srv";
  splitRow:first where trim[rawData]~\:"---";
  request:rawData til splitRow;
  response:rawData (til count rawData) except 0,1+til splitRow;
  .ros.createSchema[.ros.makeReq[msgFile];request];
  .ros.createSchema[.ros.makeRes[msgFile];response];
  };

// Creating schema from rows of ingested msg/srv/action files
.ros.createSchema:{[schemaName;schemaFields]
  choppedData:`$" " vs/: ssr[;"\t";" "] each schemaFields;
  tblCols:last each choppedData;
  colTypes:{.ros.config.accessors[x][`dataTypeKDB]$()} each first each choppedData;
  .ros.schemas[schemaName]:`timestamp xcols update timestamp:`timestamp$() from flip (tblCols)!(colTypes);
  };

//================================================= RUN =================================================//

// Get ROS2 Interface package directory
.ros.interfaceDir:getenv `INTERFACES_DIR;

// Get ROS2 Interface package directory
.ros.configDir:getenv `CONFIG_DIR;

// Initialise schema dictionary
.ros.schemas:()!();

// Load in CSV configs for ROS2 Package
.ros.config.accessors:1!("SSSSS";enlist csv) 0: hsym `$.ros.configDir,"cKDBAccessors.csv";