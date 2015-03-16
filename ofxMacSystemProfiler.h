#pragma once

#include "ofMain.h"

class ofxMacSystemProfiler: public ofBaseApp{
    
public:
    void setup();
    static string get(string property);
    static map<string, string> systemInfo;
};
