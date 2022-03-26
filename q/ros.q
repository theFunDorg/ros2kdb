system "p 1234";

.ros.pubInit:{[]
  .ros.pubHndl:neg .z.w
  };

.ros.subInit:{[]
  .ros.subHndl:neg .z.w
  };

.ros.send:{[]
  .ros.subHndl:neg .z.w
  };

.ros.topicDict:()!();
.ros.topicDict[]:;

.ros.topicDict[`$"r_pod/actuate/exhaust"]:`rightExhaustIn;
.ros.topicDict[`$"l_pod/actuate/exhaust"]:`leftExhaustIn;
.ros.topicDict[`$"r_pod/actuate/edf"]:`rightFanIn;
.ros.topicDict[`$"r_pod/actuate/elevon"]:`rightElevonIn;
.ros.topicDict[`$"l_pod/actuate/edf"]:`leftFanIn;
.ros.topicDict[`$"c_pod/actuate/elevon"]:`computeElevonIn;
.ros.topicDict[`$"l_pod/actuate/elevon"]:`leftElevonIn;



.ros.receive:{[topic;data]
  .ros.topicDict[`$topic] upsert data;
  };

.ros.receive:{show sc-.z.P;show x;show y};

a:0;
