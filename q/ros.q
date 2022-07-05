// system "p 1234";

// make below keyed table with additional msg file name column
.ros.topicTbl:([topic:`$()]tblName:`$();msgFile:`$());
.ros.topicTbl[`$"/r_engine/sensor"]:(`rightEngineSensor;`EngineSensor);
.ros.topicTbl[`$"/l_engine/actuator"]:(`leftEngineActuate;`EngineActuate);

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
  dat:"\t" vs/: system "cat ../racer_interfaces/msg/",(string msgFile),".msg";
  .ros.msgSchemas[msgFile]:flip (`time,`$dat[;1])!(`timestamp,(`$dat[;0] except\: "64"))$\:();
  };

.ros.config.publishers:("SSS";enlist csv) 0: `:config/Publishers.csv;
.ros.config.subscribers:("SSS";enlist csv) 0: `:config/Subscribers.csv;
.ros.config.servers:("SSSS";enlist csv) 0: `:config/Servers.csv;
.ros.config.clients:("SSSS";enlist csv) 0: `:config/Clients.csv;
.ros.config.accessors:("SSSSS";enlist csv) 0: `:config/cKDBAccessors.csv;

/ Parse msg file schemas into KDB tables
//.ros.parseSchema each distinct exec msgFile from .ros.topicTbl;

/ Assign table schemas to topic tablenames
{x[`tblName] set .ros.msgSchemas[x`msgFile]}each .ros.topicTbl;

/
For the publisher/subscribers, make tables with the correct columns and datatypes

For the clients...

Fuck this is the next tricky task