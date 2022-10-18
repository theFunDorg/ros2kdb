// Init functions
.ros.pubInit:{[]
  .ros.pubHndl:neg .z.w;
  if[not .ros.schemasSet;.ros.setPubSchemas[]];
  .lg.info "ROS2 Publisher is initialised";
  };

// ROS2 Pub/Sub message functions
.ros.send:{[topic;data]
  .ros.pubHndl(topic;(),data);
  };

// Parse and set node's schemas
.ros.setPubSchemas:{[]
  .ros.config.publishers:("SSS";enlist csv) 0: hsym `$.ros.configDir,"Publishers.csv";
  .ros.parseTopicSchema each distinct .ros.config.publishers[`subNameToMsg];
  {x[`PublisherName] set .ros.schemas[x`subNameToMsg]}each .ros.config.publishers;
  .ros.schemasSet:1b;
  }

//================================================= RUN =================================================//

// Get ROS2KDB package directory
.ros.qRDir:getenv `QROS_DIR;

system "l ",.ros.qRDir,"/ros.q";