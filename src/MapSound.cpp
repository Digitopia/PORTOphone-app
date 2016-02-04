#include "ofApp.h"

MapSound::MapSound(float xPercentage, float yPercentage, vector<string> paths) {

	this->paths = paths;
	this->clickable = false;
	this->playing = false;
	this->isound = -1;
	this->rad = 0.;
	this->vol = 0;
	this->y = yPercentage * ofGetHeight();

	if (ofApp::screenRatioIsWeird() == 2)
		this->x = xPercentage * 0.75 * ofGetWidth() + 0.125 * ofGetWidth();
	else if ((ofApp::screenRatioIsWeird() == 1))
		this->x = xPercentage * 0.89 * ofGetWidth() + 0.055 * ofGetWidth();
    else this->x = xPercentage * ofGetWidth();

	ofAddListener(ofEvents().mousePressed, this, &MapSound::mousePressed);

}

void MapSound::mousePressed(ofMouseEventArgs& event) {

	bool inside = false;

	if (dynamic_cast<Place*>(this)) {
		Place* place = dynamic_cast<Place*>(this);
		if (ofDist(event.x, event.y, x, y) <= place->getRadius()) {
			inside = true;
			ofLog() << "inside place";
		}
	}

	if (dynamic_cast<Bench*>(this)) {
		Bench* banco = dynamic_cast<Bench*>(this);
		if (banco->rect.inside(event.x, event.y)) {
			inside = true;
			ofLog() << "inside banco";
		}
	}

	if (!ofApp::getIsNight() && !ofApp::getIsHelpOn() && inside) {
		if (!playing)
			playSound();
		playing = !playing;
	}
}

void MapSound::playSound() {
	ofLog() << isound;
	sound.load(paths[isound], true);
	sound.setLoop(true);
	sound.setVolume(0.7);
	sound.play();
	ofLog() << "playing " << paths[isound];
}

// this is called when switching off the lights
void MapSound::reset() {
	this->playing = false;
	this->clickable = false;
	this->rad = 0;
	// this->sounds[isound].setPaused(true);
	// this->sounds[isound].stop();
	sound.unload();
}

// this is called when reentering the application
void MapSound::resetDrawing() {
	this->playing = false;
	this->rad = 0;
}

void MapSound::draw() {

	// bounding box
	// ofNoFill();
	// ofSetLineWidth(5);
	// ofSetColor(100, 100, 100);
	// ofRect(boundingBox);

	// center point
	ofFill();
	ofSetColor(100, 0, 0);
	ofDrawCircle(x, y, 4);

}

ofSoundPlayer MapSound::loadSound(string path) {
	ofLog() << "loading a sound ";
	ofSoundPlayer s;
	s.load(path);
	return s;
}

void MapSound::loadSounds() {
	for (unsigned int i = 0; i < paths.size(); i++) {
		sounds.push_back(loadSound(paths[i]));
		isound = (isound + 1) % paths.size();
	}
	// the active sound is the first path
	isound = 0;
}

void MapSound::activateNextSound() {
	isound = (isound + 1) % paths.size();
	// ofLog() << "isound is now " << isound;
}
