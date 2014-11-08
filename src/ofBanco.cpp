#include "ofBanco.h"
#include "ofApp.h"

ofBanco::ofBanco(float _x, float _y, float _dim, string _path) {

    if((ofGetHeight()*10/ofGetWidth()) > 16) {
    xPos = _x * 0.8 * ofGetHeight() + 0.1 * ofGetHeight();
    } else {
        xPos = _x * ofGetHeight();
    }

    yPos = _y * ofGetWidth();
    dim = _dim * ofGetWidth();

    ofSetRectMode(OF_RECTMODE_CENTER);
    caixa.set(xPos, yPos, dim, dim);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofAddListener(ofEvents().mousePressed, this, &ofBanco::mousePressed);

    path = _path;

    vol = 0.7f;
// TODO: check if reading from disk is workable
    somBanco.loadSound(path, true);
    somBanco.setLoop(true);

}

void ofBanco::actual() {
}

void ofBanco::mousePressed(ofMouseEventArgs& event) {

	if(bancoOn) {

		if (caixa.inside(event.x, event.y)) {

			if (!on) {
				vol = 0.7f;
				somBanco.setVolume(vol);
				somBanco.play();
			}

			else {
				somBanco.stop();
				somBanco.setPosition(0.0f);
			}

			on = !on;
		}
	}

}

void ofBanco::draw() {
	if (on) {
	        ofSetRectMode(OF_RECTMODE_CENTER);
	        ofEnableAlphaBlending();
	        ofEnableSmoothing();
	        ofFill();
	        ofSetColor(10, 20, 160, 100);

	        // FOR SOME REASON, RECTANGLES ARE NOT CENTERED!

	        ofRect(xPos+0.03*ofGetHeight(), yPos+0.02*ofGetWidth(), rad, rad);
	        ofNoFill();
	        ofSetLineWidth(2);
	        ofSetColor(10, 20, 160);
	      ofRect(xPos+0.03*ofGetHeight(), yPos+0.02*ofGetWidth(), rad, rad);
	        ofDisableAlphaBlending();
	        ofDisableSmoothing();
	        rad  += 0.006 * ofGetHeight();
	        ofSetRectMode(OF_RECTMODE_CORNER);
	        if (rad > dim) {
	            rad = dim;
	        }
	    } else if (!on) {
	        ofSetRectMode(OF_RECTMODE_CENTER);
	        ofEnableAlphaBlending();
	        ofEnableSmoothing();
	        ofFill();
	        ofSetColor(10, 20, 160, 100);
	        ofRect(xPos+0.03*ofGetHeight(), yPos+0.02*ofGetWidth(), rad, rad);
	        ofNoFill();
	        ofSetLineWidth(2);
	        ofSetColor(10, 20, 160);
	        ofRect(xPos+0.03*ofGetHeight(), yPos+0.02*ofGetWidth(), rad, rad);
	        ofDisableAlphaBlending();
	        ofDisableSmoothing();
	        rad  -= 0.006 * ofGetHeight();
	        ofSetRectMode(OF_RECTMODE_CORNER);
	        vol -= 0.05f;
	        somBanco.setVolume(vol);
	        if (rad < 0.) {
	            rad = 0.;
	        }
	        if( vol <0.) {
	            vol = 0.0f;
	            somBanco.stop();
	        }
	    }
}
