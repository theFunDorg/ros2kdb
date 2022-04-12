system "p 1234";

// make below keyed table with additional msg file name column
.ros.topicTbl:([topic:`$()]tblName:`$();msgFile:`$());
.ros.topicTbl[`$"/r_pod/actuate/exhaust"]:(`rightExhaustIn;`ExhaustInput);
.ros.topicTbl[`$"/l_pod/actuate/exhaust"]:(`leftExhaustIn;`ExhaustInput);
.ros.topicTbl[`$"/r_pod/actuate/edf"]:(`rightFanIn;`EdfInput);
.ros.topicTbl[`$"/l_pod/actuate/edf"]:(`leftFanIn;`EdfInput);
.ros.topicTbl[`$"/r_pod/actuate/elevon"]:(`rightElevonIn;`ElevonInput);
.ros.topicTbl[`$"/l_pod/actuate/elevon"]:(`leftElevonIn;`ElevonInput);
.ros.topicTbl[`$"/c_pod/actuate/elevon"]:(`computeElevonIn;`ElevonInput);

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
  .ros.pubHndl:neg .z.w;
  show `$"ROS2 Service is initialised";
  };

.ros.send:{[topic;data]
  .ros.pubHndl(topic;(),data);
  };

.ros.receive:{[topic;data]
  .ros.topicTbl[`$topic][`tblName] upsert .z.P,data;
  };
.ros.funcOne:{[x;y]
  :x%y
  }
//.ros.receive:{show sc-.z.P;show x;show y};

.ros.parseSchema:{[msgFile]
  dat:"\t" vs/: system "cat ../podracer_interfaces/msg/",(string msgFile),".msg";
  .ros.msgSchemas[msgFile]:flip (`time,`$dat[;1])!(`timestamp,(`$dat[;0] except\: "64"))$\:();
  };

/ Parse msg file schemas into KDB tables
.ros.parseSchema each distinct exec msgFile from .ros.topicTbl;

/ Assign table schemas to topic tablenames
{x[`tblName] set .ros.msgSchemas[x`msgFile]}each .ros.topicTbl;
/
get msg filenames

parse into table schema, store in dictionary
create conversion dictionary thugh, way easier, cleaner


flip (`time,`$dat[;1])!(`timestamp,(`$dat[;0] except\: "64"))$\:()
assign tableSchema to tableName

"Locate";
"Antenna";
"EdfOutput";
"ElevonOutput";
"ExhaustOutput";