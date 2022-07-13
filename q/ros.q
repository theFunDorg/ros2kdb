// Init functions
.ros.pubInit:{[]
  .ros.pubHndl:neg .z.w;
  show `$"ROS2 Publisher is initialised";
  };

.ros.subInit:{[]
  .ros.subHndl:neg .z.w;
  show `$"ROS2 Subscriber is initialised";
  };

.ros.servInit:{[]
  .ros.servHndl:neg .z.w;
  show `$"ROS2 Service is initialised";
  };

.ros.clientInit:{[]
  .ros.clntHndl:neg .z.w;
  show `$"ROS2 Client is initialised";
  };

// ROS2 Pub/Sub message functions
.ros.send:{[topic;data]
  .ros.pubHndl(topic;(),data);
  };

.ros.receive:{[topic;data]
  (`$topic) upsert .z.P,data
  };

// Dummy function for client/server check
.ros.Serve:{[x;y]
  show x;
  show y;
  :x%y
  };

// ROS2 Client/Server functions
.ros.clientRequest:{[service;request]
  .ros.clntHndl(service;request);
  .ros.makeReq[service] upsert .z.P,request;
  .ros.clntHndl[];
  };

.ros.clientResponse:{[service;response]
  .ros.makeRes[service] upsert .z.P,response;
  show service;
  show response
  };

// Change symbol name to req/resp
.ros.makeReq:{`$string[x],"_request"};
.ros.makeRes:{`$string[x],"_response"};

// Schema parser to parse Topic messages into tables
.ros.parseTopicSchema:{[msgFile]
  rawData:system "cat ../racer_interfaces/msg/",(string msgFile),".msg";
  .ros.createSchema[msgFile;rawData];
  };

// Schema parser to parse Service messages into tables
.ros.parseServiceSchema:{[msgFile]
  rawData:system "cat ../racer_interfaces/srv/",(string msgFile),".srv";
  splitRow:first where trim[rawData]~\:"---";
  request:rawData til splitRow;
  response:rawData (til count rawData) except 0,1+til splitRow;
  .ros.createSchema[.ros.makeReq[msgFile];request];
  .ros.createSchema[.ros.makeRes[msgFile];response];
  };

.ros.createSchema:{[schemaName;schemaFields]
  choppedData:`$" " vs/: ssr[;"\t";" "] each schemaFields;
  tblCols:last each choppedData;
  colTypes:{.ros.config.accessors[x][`dataTypeKDB]$()} each first each choppedData;
  .ros.schemas[schemaName]:`timestamp xcols update timestamp:`timestamp$() from flip (tblCols)!(colTypes);
  };

// Parse and set node's schemas
.ros.setTables:{[nodeType]
    $[nodeType~`server;
      [
        .ros.config.servers:("SSSS";enlist csv) 0: `:config/Servers.csv;
        .ros.parseServiceSchema each distinct .ros.config.servers[`svcNameToSRV];
        {.ros.makeReq[x[`ServerName]] set .ros.schemas[.ros.makeReq[x`svcNameToSRV]]}each .ros.config.servers;
        {.ros.makeRes[x[`ServerName]] set .ros.schemas[.ros.makeRes[x`svcNameToSRV]]}each .ros.config.servers
      ];
    nodeType~`client;
      [
        .ros.config.clients:("SSSS";enlist csv) 0: `:config/Clients.csv;
        .ros.parseServiceSchema each distinct .ros.config.clients[`clntNameToSRV];
        {x[`ClientName] set .ros.schemas[x`clntNameToSRV]}each .ros.config.clients;
        {.ros.makeReq[x[`ClientName]] set .ros.schemas[.ros.makeReq[x`clntNameToSRV]]}each .ros.config.clients;
        {.ros.makeRes[x[`ClientName]] set .ros.schemas[.ros.makeRes[x`clntNameToSRV]]}each .ros.config.clients
      ];
    nodeType~`publisher;
      [
        .ros.config.publishers:("SSS";enlist csv) 0: `:config/Publishers.csv;
        .ros.parseTopicSchema each distinct .ros.config.publishers[`subNameToMsg];
        {x[`PublisherName] set .ros.schemas[x`subNameToMsg]}each .ros.config.publishers;

      ];
    nodeType~`subscriber;
      [
        .ros.config.subscribers:("SSS";enlist csv) 0: `:config/Subscribers.csv;
        .ros.parseTopicSchema each distinct .ros.config.subscribers[`subNameToMsg];
        {x[`SubscriberName] set .ros.schemas[x`subNameToMsg]}each .ros.config.subscribers;
      ]
    ];
  };

// Initialise schema dictionary
.ros.schemas:()!();

// Load in CSV configs for ROS2 Package
.ros.config.accessors:1!("SSSSS";enlist csv) 0: `:config/cKDBAccessors.csv;

// Reading node type
.ros.nodeType:first `$.Q.opt[.z.X][`ROSnode];

// Initialising node
.ros.setTables[.ros.nodeType];

//table Counter
tbls:{([tbl:tables[]]cnt:count each get each tables[])};