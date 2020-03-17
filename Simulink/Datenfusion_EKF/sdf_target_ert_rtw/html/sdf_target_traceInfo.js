function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "sdf_target"};
	this.sidHashMap["sdf_target"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "sdf_target:15"};
	this.sidHashMap["sdf_target:15"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "sdf_target:38"};
	this.sidHashMap["sdf_target:38"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/Demux"] = {sid: "sdf_target:40"};
	this.sidHashMap["sdf_target:40"] = {rtwname: "<Root>/Demux"};
	this.rtwnameHashMap["<Root>/EKF"] = {sid: "sdf_target:15"};
	this.sidHashMap["sdf_target:15"] = {rtwname: "<Root>/EKF"};
	this.rtwnameHashMap["<Root>/Gain3"] = {sid: "sdf_target:31"};
	this.sidHashMap["sdf_target:31"] = {rtwname: "<Root>/Gain3"};
	this.rtwnameHashMap["<Root>/Gain5"] = {sid: "sdf_target:32"};
	this.sidHashMap["sdf_target:32"] = {rtwname: "<Root>/Gain5"};
	this.rtwnameHashMap["<Root>/Gain6"] = {sid: "sdf_target:43"};
	this.sidHashMap["sdf_target:43"] = {rtwname: "<Root>/Gain6"};
	this.rtwnameHashMap["<Root>/Integrator"] = {sid: "sdf_target:39"};
	this.sidHashMap["sdf_target:39"] = {rtwname: "<Root>/Integrator"};
	this.rtwnameHashMap["<Root>/KF_target"] = {sid: "sdf_target:38"};
	this.sidHashMap["sdf_target:38"] = {rtwname: "<Root>/KF_target"};
	this.rtwnameHashMap["<Root>/LSM9DS1 IMU Sensor"] = {sid: "sdf_target:14"};
	this.sidHashMap["sdf_target:14"] = {rtwname: "<Root>/LSM9DS1 IMU Sensor"};
	this.rtwnameHashMap["<Root>/Samplezeit"] = {sid: "sdf_target:1"};
	this.sidHashMap["sdf_target:1"] = {rtwname: "<Root>/Samplezeit"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "sdf_target:30"};
	this.sidHashMap["sdf_target:30"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "sdf_target:41"};
	this.sidHashMap["sdf_target:41"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "sdf_target:42"};
	this.sidHashMap["sdf_target:42"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "sdf_target:44"};
	this.sidHashMap["sdf_target:44"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "sdf_target:45"};
	this.sidHashMap["sdf_target:45"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "sdf_target:20"};
	this.sidHashMap["sdf_target:20"] = {rtwname: "<Root>/To Workspace"};
	this.rtwnameHashMap["<Root>/To Workspace1"] = {sid: "sdf_target:21"};
	this.sidHashMap["sdf_target:21"] = {rtwname: "<Root>/To Workspace1"};
	this.rtwnameHashMap["<Root>/To Workspace2"] = {sid: "sdf_target:22"};
	this.sidHashMap["sdf_target:22"] = {rtwname: "<Root>/To Workspace2"};
	this.rtwnameHashMap["<Root>/ToAccel"] = {sid: "sdf_target:12"};
	this.sidHashMap["sdf_target:12"] = {rtwname: "<Root>/ToAccel"};
	this.rtwnameHashMap["<Root>/degToRad"] = {sid: "sdf_target:13"};
	this.sidHashMap["sdf_target:13"] = {rtwname: "<Root>/degToRad"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "sdf_target:15:1"};
	this.sidHashMap["sdf_target:15:1"] = {rtwname: "<S1>:1"};
	this.rtwnameHashMap["<S2>:1"] = {sid: "sdf_target:38:1"};
	this.sidHashMap["sdf_target:38:1"] = {rtwname: "<S2>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();