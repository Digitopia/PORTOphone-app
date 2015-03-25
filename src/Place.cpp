#include "Place.h"
#include "ofApp.h"

const ofColor Place::red_light(100, 20, 60, 100);
const ofColor Place::red(100, 20, 60);
const float Place::dimPercentage = 0.17;

Place::Place(float xPercentage, float yPercentage, vector<string> paths) : MapSound(xPercentage, yPercentage, paths) {
	this->dim = dimPercentage * ofGetWidth();
	this->rad = 0;
}

void Place::draw() {

	// MapSound::draw();

	// for debug purposes
	// ofCircle(x, y, dim/2);

	ofEnableAlphaBlending();

	// inside of circle
	ofFill();
	ofSetColor(red_light);
	ofCircle(x, y, rad);

	// circunference of circle
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(red);
	ofSetCircleResolution(50);
	ofCircle(x, y, rad);

	// go back to normal definitions
	ofDisableAlphaBlending();

	// fading in or playing
	if (playing) {
		rad += 0.006 * ofGetWidth();
		if (rad > dim/2) rad = dim/2;
	}

	// fading out or not playing
	else {

		rad -= 0.006 * ofGetWidth();

		if (vol > 0.0f) vol -= 0.05f;
		if (rad < 0.0f) rad = 0.0f;
		if (vol < 0.0f) vol = 0.0f;

		sound.setVolume(vol);

		if (rad <= 0.0f && vol <= 0.0) {
			// sound.setPaused(true);
			// sound.setPosition(0.0);
			sound.stop();
		}
	}

}
