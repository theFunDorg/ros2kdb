// Init functions
.ros.subInit:{[]
  .ros.subHndl:neg .z.w;
  if[not .ros.schemasSet;.ros.setSubSchemas[]];
  .lg.info "ROS2 Subscriber is initialised";
  };

// ROS2 Sub message functions
.ros.receive:{[topic;data]
  (`$topic) upsert .z.P,data
  };

// Parse and set node's schemas
.ros.setSubSchemas:{[]
  .ros.config.subscribers:("SSS";enlist csv) 0: hsym `$.ros.configDir,"Subscribers.csv";
  .ros.parseTopicSchema each distinct .ros.config.subscribers[`subNameToMsg];
  {x[`SubscriberName] set .ros.schemas[x`subNameToMsg]}each .ros.config.subscribers;
  .ros.schemasSet:1b;
  };

//================================================= RUN =================================================//

// Get ROS2KDB package directory
.ros.qRDir:getenv `QROS_DIR;

system "l ",.ros.qRDir,"/ros.q";