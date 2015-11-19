#include "ofxImage.h"

bool ofxImage::loadImage(string fileName) {

	string baseFolder = "images/";

	// TODO: need a better check here
	string imageFolder;
	if (ofGetWidth() < 700) {
		imageFolder = baseFolder + "low-res/";
	}
	else {
		imageFolder = baseFolder + "high-res/";
	}

	string fullPath = imageFolder + fileName;

	ofLog() << "loading " << fullPath;

	return ofImage::load(fullPath);
}
