// Init functions
.ros.servInit:{[]
  .ros.servHndl:neg .z.w;
  if[not .ros.schemasSet;.ros.setServerSchemas[]];
  .lg.info "ROS2 Service is initialised";
  };

// Dummy function for client/server check
.ros.Serve:{[x;y]
  show x;
  show y;
  :x%y
  };

// Parse and set node's schemas
.ros.setServerSchemas:{[]
  .ros.config.servers:("SSSS";enlist csv) 0: hsym `$.ros.configDir,"Servers.csv";
  .ros.parseServiceSchema each distinct .ros.config.servers[`svcNameToSRV];
  {.ros.makeReq[x[`ServerName]] set .ros.schemas[.ros.makeReq[x`svcNameToSRV]]}each .ros.config.servers;
  {.ros.makeRes[x[`ServerName]] set .ros.schemas[.ros.makeRes[x`svcNameToSRV]]}each .ros.config.servers;
  .ros.schemasSet:1b;
  };

//================================================= RUN =================================================//

// Get ROS2KDB package directory
.ros.qRDir:getenv `QROS_DIR;

system "l ",.ros.qRDir,"/ros.q";