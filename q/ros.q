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
  (`$string[service],"_request") upsert .z.P,request;
  .ros.clntHndl[];
  };

.ros.clientResponse:{[service;response]
  (`$string[service],"_response") upsert .z.P,response;
  show service;
  show response
  };

// Schema parser to parse Topic messages into tables
.ros.parseTopicSchema:{[msgFile]
  rawData:system "cat ../racer_interfaces/msg/",(string msgFile),".msg";
  choppedData:`$" " vs/: ssr[;"\t";" "] each rawData;
  tblCols:last each choppedData;
  colTypes:{.ros.config.accessors[x][`dataTypeKDB]$()} each first each choppedData;
  .ros.schemas[msgFile]:`timestamp xcols update timestamp:`timestamp$() from flip (tblCols)!(colTypes);
  };

// Schema parser to parse Service messages into tables
.ros.parseServiceSchema:{[msgFile]
  rawData:system "cat ../racer_interfaces/srv/",(string msgFile),".srv";
  rawData:rawData where not rawData~\:"---";
  choppedData:`$" " vs/: ssr[;"\t";" "] each rawData;
  tblCols:last each choppedData;
  colTypes:{.ros.config.accessors[x][`dataTypeKDB]$()} each first each choppedData;
  .ros.schemas[msgFile]:`timestamp xcols update timestamp:`timestamp$() from flip (tblCols)!(colTypes);
  };
  // ltrim,rtrim each rawData
  //splitRow:first where rawData~\:"---"
  //request:rawData til splitRow
  //response:rawData (til count rawData) except 0,1+til splitRow

// Parse and set node's schemas
.ros.setTables:{[nodeType]
    $[nodeType~`server;
      [
        .ros.config.servers:("SSSS";enlist csv) 0: `:config/Servers.csv;
        .ros.parseServiceSchema each distinct .ros.config.servers[`svcNameToSRV];
        {x[`ServerName] set .ros.schemas[x`svcNameToSRV]}each .ros.config.servers;
      ];
    nodeType~`client;
      [
        .ros.config.clients:("SSSS";enlist csv) 0: `:config/Clients.csv;
        .ros.parseServiceSchema each distinct .ros.config.clients[`clntNameToSRV];
        {x[`ClientName] set .ros.schemas[x`clntNameToSRV]}each .ros.config.clients;

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