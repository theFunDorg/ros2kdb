// Init function
.ros.clientInit:{[]
  .ros.clntHndl:neg .z.w;
  .ros.setClientSchemas[];
  show `$"ROS2 Client is initialised";
  };

// ROS2 Client Request/Response handlers
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

// Parse and set node's schemas
.ros.setClientSchemas:{[]
  .ros.config.clients:("SSSS";enlist csv) 0: hsym `$.ros.configDir,"Clients.csv";
  .ros.parseServiceSchema each distinct .ros.config.clients[`clntNameToSRV];
  {x[`ClientName] set .ros.schemas[x`clntNameToSRV]}each .ros.config.clients;
  {.ros.makeReq[x[`ClientName]] set .ros.schemas[.ros.makeReq[x`clntNameToSRV]]}each .ros.config.clients;
  {.ros.makeRes[x[`ClientName]] set .ros.schemas[.ros.makeRes[x`clntNameToSRV]]}each .ros.config.clients;
  };

//================================================= RUN =================================================//

// Get ROS2KDB package directory
.ros.qRDir:getenv `QROS_DIR;

system "l ",.ros.qRDir,"/ros.q";