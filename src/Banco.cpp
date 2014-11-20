#include "Banco.h"
#include "ofApp.h"

const ofColor Banco::blue(10, 20, 160, 100);
const ofColor Banco::blue_alpha(10, 20, 160);
const float Banco::dimPercentage = 0.07;

Banco::Banco(float xPercentage, float yPercentage, vector<string> paths) : Spot(xPercentage, yPercentage, paths) {
    this->dim = dimPercentage * ofGetWidth();
    this->boundingBox.set(x-dim/2, y-dim/2, dim, dim);
    this->rad = 0;
}

void Banco::draw() {
    
//    Spot::draw();

	// rectangles are not centered by default
	ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
	// fill
	ofFill();
	ofSetColor(blue);
	ofRect(x, y, rad, rad);

	// outline
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(blue_alpha);
	ofRect(x, y, rad, rad);

	// go back to normal definitions
	ofDisableAlphaBlending();
	ofDisableSmoothing();
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
            sound.stop();
            sound.setPosition(0.0f);
        }
	}
}
