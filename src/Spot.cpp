#include "ofApp.h"

Spot::Spot(float xPercentage, float yPercentage, vector<string> paths) {

	this->paths = paths;
	this->clickable = false;
	this->playing = false;
	this->isound = -1;
	this->rad = 0.;
    this->vol = 0;
	this->y = yPercentage * ofGetHeight();

	if (ofApp::screenRatioIsWeird())
		this->x = xPercentage * 0.8 * ofGetWidth() + 0.1 * ofGetWidth();
	else
		this->x = xPercentage * ofGetWidth();

	ofAddListener(ofEvents().mousePressed, this, &Spot::mousePressed);

}

void Spot::mousePressed(ofMouseEventArgs& event) {

	if (!ofApp::getIsNight() && !ofApp::getIsHelpOn() && boundingBox.inside(event.x, event.y)) {
//    if (!ofApp::getIsNight() && boundingBox.inside(event.x, event.y)) {

		ofLog() << "click on spot " << paths[isound];

		if (!playing) {
			playSound();
		}
		playing = !playing;
	}

}

void Spot::playSound() {
	ofLog() << isound;
    sound.loadSound(paths[isound], true);
    sound.setLoop(true);
	sound.setVolume(0.7);
	sound.play();
	ofLog() << "playing " << paths[isound];
}

// this is called when switching off the lights
void Spot::reset() {
	this->playing = false;
	this->clickable = false;
	this->rad = 0;
//	this->sounds[isound].setPaused(true);
//    this->sounds[isound].stop();
    sound.unloadSound();
}

// this is called when reentering the application
void Spot::resetDrawing() {
	this->playing = false;
	this->rad = 0;
}

void Spot::draw() {

	// bounding box
    ofNoFill();
	ofSetLineWidth(5);
	ofSetColor(100, 100, 100);
	ofRect(boundingBox);

	// center point
	ofFill();
	ofSetColor(100, 0, 0);
	ofCircle(x, y, 4);

}

ofSoundPlayer Spot::loadSound(string path) {
    ofLog() << "loading a sound ";
    ofSoundPlayer s;
	s.loadSound(path);
	return s;
}

void Spot::loadSounds() {
	for (unsigned int i = 0; i < paths.size(); i++) {
		sounds.push_back(loadSound(paths[i]));
		isound = (isound + 1) % paths.size();
	}
	// the active sound is the first path
	isound = 0;
}

void Spot::activateNextSound() {
	isound = (isound + 1) % paths.size();
    ofLog() << "isound is now " << isound;
}
