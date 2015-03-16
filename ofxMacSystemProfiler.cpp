
#include "ofxMacSystemProfiler.h"

//The setup() function must be run before anything. It make take over a second to complete the call.
//run: "system_profiler SPHardwareDataType SPSoftwareDataType" on the terminal to get all the properties you can use
//Then just call them by using get("machine_model");

map <string, string> ofxMacSystemProfiler::systemInfo;

void ofxMacSystemProfiler::setup()
{
    //run "system_profiler -listDataTypes" for possilbe data types
    string xmlString =ofSystem("system_profiler SPHardwareDataType SPSoftwareDataType SPDisplaysDataType -xml");
   // xmlString = xmlString.erase(xmlString.find("\377")); //there is a line break at the end  //there is no line break anymore in 0.9.0?
    
    ofXml xml;
    bool succes = false;
    succes = xml.loadFromBuffer(xmlString);
    
    if(!succes)
        ofLogError("ofxMacSystemProfiler: Was not possible to parse the XML");
    
    
    //TODO: make it recursive so we can get values even if the returned xml changed the format
    
    succes = xml.setTo("array/dict[0]/array[1]/dict");
    if(!succes)
        ofLogError("ofxMacSystemProfiler: Was not find SPHardwareDataType properties");
    
    
    
    int num = xml.getNumChildren()/2;
    
    for(int i = 0; i<num ;i++)
    {
        xml.setTo("key["+ofToString(i)+"]");
        string key = xml.getValue("");
        xml.setToSibling();
        string value = xml.getValue("");
        xml.setToParent();
        systemInfo[key] = value;
        //cout << "\n "<< key << ": "<< value;
    }
    
    xml.reset();
    succes = xml.setTo("array/dict[1]/array[1]/dict");
    
    if(!succes)
        ofLogError("ofxMacSystemProfiler: Was not find SPSoftwareDataType properties");
    
    num = xml.getNumChildren()/2;
    
    for(int i = 0; i<num ;i++)
    {
        xml.setTo("key["+ofToString(i)+"]");
        string key = xml.getValue("");
        xml.setToSibling();
        string value = xml.getValue("");
        xml.setToParent();
        systemInfo[key] = value;
        //cout << "\n "<< key << ": "<< value;
    }

    xml.reset();
    succes = xml.setTo("array/dict[2]/array[1]/dict");
    
    if(!succes)
        ofLogError("ofxMacSystemProfiler: Was not find SPDisplaysDataType properties");
    
    num = xml.getNumChildren()/2;
    
    for(int i = 0; i<num ;i++)
    {
        xml.setTo("key["+ofToString(i)+"]");
        string key = xml.getValue("");
        xml.setToSibling();
        string value = xml.getValue("");
        xml.setToParent();
        systemInfo[key] = value;
        //cout << "\n "<< key << ": "<< value;
    }

}

string ofxMacSystemProfiler::get(string property)
{
    if ( systemInfo.find(property) == systemInfo.end() )
    {
        ofLogWarning("ofxMacProfiler: Property '"+ property+ "' does not exist. Make sure you called setup() previously");
        return "";
    } else {
        return systemInfo.find(property)->second;
    }
    
}
