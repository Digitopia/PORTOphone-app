#include "Local.h"
#include "ofApp.h"

const ofColor Local::red_light(100, 20, 60, 100);
const ofColor Local::red(100, 20, 60);
const float Local::dimPercentage = 0.15;

Local::Local(float xPercentage, float yPercentage, vector<string> paths) : Spot(xPercentage, yPercentage, paths) {
    this->dim = dimPercentage * ofGetWidth();
    this->boundingBox.set(x - dim/2, y - dim/2, dim, dim);
    this->rad = 0;
}

void Local::draw() {
    
//    Spot::draw();

    ofEnableAlphaBlending();
    ofEnableSmoothing();

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
    ofDisableSmoothing();

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
			sound.stop();
			sound.setPosition(0.0f);
		}
    }

}
