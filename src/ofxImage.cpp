#include "ofxImage.h"

bool ofxImage::loadImage(string fileName) {

	string baseFolder = "images/";

	// TODO: need a better check here
	string imageFolder;
    #ifdef TARGET_OF_IOS
	if (ofGetWidth() < 568) {
    #else
    if (ofGetWidth() < 700) {
    #endif
		imageFolder = baseFolder + "low-res/";
	}
	else {
		imageFolder = baseFolder + "high-res/";
	}

	string fullPath = imageFolder + fileName;

	ofLog() << "loading " << fullPath;

	return ofImage::load(fullPath);
}
