#ofxMacSystemProfiler
An Openframeworks addon to get information of your system.
Its a wrapper around `system_profiler` command

##Usage
    ofxMacSystemProfiler::init();
    
    ofLogNotice(ofxMacSystemProfiler::get("machine_name"));
    ofLogNotice(ofxMacSystemProfiler::get("machine_model"));
    ofLogNotice(ofxMacSystemProfiler::get("cpu_type"));
    ofLogNotice(ofxMacSystemProfiler::get("current_processor_speed"));
    ofLogNotice(ofxMacSystemProfiler::get("packages"));
    ofLogNotice(ofxMacSystemProfiler::get("number_processors"));
    ofLogNotice(ofxMacSystemProfiler::get("physical_memory"));
    ofLogNotice(ofxMacSystemProfiler::get("boot_rom_version"));
    ofLogNotice(ofxMacSystemProfiler::get("SMC_version_system"));
    ofLogNotice(ofxMacSystemProfiler::get("serial_number"));
    ofLogNotice(ofxMacSystemProfiler::get("platform_UUID"));
    ofLogNotice(ofxMacSystemProfiler::get("os_version"));
    ofLogNotice(ofxMacSystemProfiler::get("local_host_name"));
    ofLogNotice(ofxMacSystemProfiler::get("user_name"));
    ofLogNotice(ofxMacSystemProfiler::get("secure_vm"));
    ofLogNotice(ofxMacSystemProfiler::get("uptime"));

    
##Tip
Run  this on your command line to see a readable version of the type of information you can get:
`system_profiler SPHardwareDataType SPSoftwareDataType SPHardwareDataType`

Add the -xml flag to get the name of the property you are looking for:
`system_profiler SPHardwareDataType SPSoftwareDataType SPHardwareDataType -xml`