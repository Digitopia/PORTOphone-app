#include "ofApp.h"

Spot::Spot(float xPercentage, float yPercentage, vector<string> paths) {
    
    this->paths = paths;
	this->clickable = false;
	this->playing = false;
    this->sound.setLoop(true);
    this->ipath = -1;
    this->rad = 0.;
    this->y = yPercentage * ofGetHeight();
    this->vol = 0.7;
    
    if (ofApp::screenRatioIsWeird())
        this->x = xPercentage * 0.8 * ofGetWidth() + 0.1 * ofGetWidth();
    else
        this->x = xPercentage * ofGetWidth();
    
    ofAddListener(ofEvents().mousePressed, this, &Spot::mousePressed);

}

void Spot::mousePressed(ofMouseEventArgs& event) {
    
    if (!ofApp::getIsNight() && !ofApp::getIsHelpOn() && boundingBox.inside(event.x, event.y)) {

		ofLog() << "click on spot " << paths[ipath];

		if (!playing) {
            playSound();
        }
		playing = !playing;
	}
    
}

void Spot::playSound() {
    sound.setVolume(0.7);
    sound.play();
    ofLog() << "playing " << paths[ipath];
}

void Spot::reset() {
	this->playing = false;
	this->clickable = false;
	this->sound.stop();
    this->rad = 0;
	this->sound.unloadSound();
}

void Spot::resetDrawing() {
	this->playing = false;
	this->rad = 0;
}

void Spot::draw() {
    
    // bounding box
//    ofNoFill();
//    ofSetLineWidth(1);
//    ofSetColor(100, 100, 100);
//    ofRect(boundingBox);

    // center point
//    ofFill();
//    ofSetColor(100, 0, 0);
//    ofCircle(x, y, 4);
    
}


// whenever this is called, loads the next sound in the paths vector
void Spot::loadSound() {
    
    // first time
    if (ipath == -1) {
        ipath = 0;
    }
    // other times
    else {
        ipath++;
        ipath = ipath % paths.size();
    }
    
    sound.loadSound(paths[ipath]);
    
    ofLog() << "loaded sound " << paths[ipath];
    
}
