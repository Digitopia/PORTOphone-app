#include "ofxImage.h"

bool ofxImage::loadImage(string fileName) {
    
    string baseFolder = "images/";
    
    // TODO: need a better check here
    string imageFolder;
    if (ofGetWidth() < 700) {
        imageFolder = baseFolder + "low-res/";
    }
    else {
    	// TODO: changed to high-res later
        imageFolder = baseFolder + "low-res/";
    }
        
    
    string fullPath = imageFolder + fileName;
    
    std::cout << "loading " << fullPath << endl;
    
    return ofImage::loadImage(fullPath);
}
