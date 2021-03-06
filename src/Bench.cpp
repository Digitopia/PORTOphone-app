#include "Bench.h"
#include "ofApp.h"

const ofColor Bench::blue_light(10, 20, 160, 100);
const ofColor Bench::blue(10, 20, 160);
const float Bench::dimPercentage = 0.08;

Bench::Bench(float xPercentage, float yPercentage, vector<string> paths) : MapSound(xPercentage, yPercentage, paths) {
	this->dim = dimPercentage * ofGetWidth();
	this->rect.set(x-dim/2, y-dim/2, dim, dim);
	this->rad = 0;
}

void Bench::draw() {

	MapSound::draw();

	// rectangles are not centered by default
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofEnableAlphaBlending();

	// fill
	ofFill();
	ofSetColor(blue_light);
	ofDrawRectangle(x, y, rad, rad);

	// outline
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(blue);
	ofDrawRectangle(x, y, rad, rad);

	// go back to normal definitions
	ofDisableAlphaBlending();
	ofSetRectMode(OF_RECTMODE_CORNER);

	// fading in or playing
	if (playing) {
		rad += 0.006 * ofGetWidth();
		if (rad > dim) rad = dim;
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
