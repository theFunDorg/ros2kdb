.ros.msgSchemas:()!();

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

.ros.send:{[topic;data]
  .ros.pubHndl(topic;(),data);
  };

.ros.receive:{[topic;data]
  .ros.topicTbl[`$topic][`tblName] upsert .z.P,data
  };

.ros.funcOne:{[x;y]
  show x;
  show y;
  :x%y
  };

.ros.clientRequest:{[service;request]
  .ros.clntHndl(service;request)
  };

.ros.clientResponse:{[service;response]
  show service;
  show response
  };

.ros.parseSchema:{[msgFile]
  rawData:system "cat ../racer_interfaces/msg/",(string msgFile),".msg";
  choppedData:`$" " vs/: ssr[;"\t";" "] each rawData;
  tblCols:last each choppedData;
  colTypes:{.ros.config.accessors[x][`dataTypeKDB]$()} each first each choppedData;
  .ros.msgSchemas[msgFile]:`timestamp xcols update timestamp:`timestamp$() from flip (tblCols)!(colTypes);

  };
// Load in CSV configs for ROS2 Package
.ros.config.publishers:("SSS";enlist csv) 0: `:config/Publishers.csv;
.ros.config.subscribers:("SSS";enlist csv) 0: `:config/Subscribers.csv;
.ros.config.servers:("SSSS";enlist csv) 0: `:config/Servers.csv;
.ros.config.clients:("SSSS";enlist csv) 0: `:config/Clients.csv;
.ros.config.accessors:1!("SSSSS";enlist csv) 0: `:config/cKDBAccessors.csv;

/ Parse msg file schemas into KDB tables
.ros.parseSchema each distinct .ros.config.publishers[`subNameToMsg];

/ Assign table schemas to topic tablenames
{x[`PublisherName] set .ros.msgSchemas[x`subNameToMsg]}each .ros.config.publishers;