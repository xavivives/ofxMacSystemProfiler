#pragma once

#include "ofMain.h"

class ofxMacSystemProfiler: public ofBaseApp{
    
public:
    static void init();
    static string get(string property);
    static map<string, string> systemInfo;
};
