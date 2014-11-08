#include "ofLocal.h"
#include "ofApp.h"

ofLocal::ofLocal(float _x, float _y, float _dim, string _path) {

    if((ofGetHeight()*10/ofGetWidth()) > 16) {
        xPos = _x * 0.8 * ofGetHeight() + 0.1 * ofGetHeight();
    } else {
        xPos = _x * ofGetHeight();
    }

    yPos = _y * ofGetWidth();
    dim = _dim * ofGetWidth();

    ofSetRectMode(OF_RECTMODE_CENTER);
    bola.set(xPos-0.6*dim, yPos-0.6*dim, 1.4*dim, 1.4*dim);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofAddListener(ofEvents().mousePressed, this, &ofLocal::mousePressed);

    path = _path;

    vol = 0.7f;
    // TODO: check if reading from disk is workable
    somLocal.loadSound(path, true);
    somLocal.setLoop(true);
}

void ofLocal::actual() {
}

void ofLocal::mousePressed(ofMouseEventArgs& event) {
	if(localOn) {
		if(bola.inside(event.x, event.y)) {
			if(!on) {
				vol = 0.7f;
				somLocal.setVolume(vol);
				somLocal.setPosition(0.0f);
				somLocal.play();
			}
			else {
				somLocal.stop();
				somLocal.setPosition(0.0f);
			}
			on = !on;
		}
	}
}

void ofLocal::draw() {


  /*  if (localOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            if (!on){
                on = true;
            } else if (on){
                on = false;
            }

            localOn = false;
        }
    }*/

    if (on) {
        ofEnableAlphaBlending();
        ofEnableSmoothing();
        ofFill();
        ofSetColor(100, 20, 60, 100);
        ofCircle(xPos, yPos, rad);
        ofNoFill();
        ofSetLineWidth(2);
        ofSetColor(100, 20, 60);
        ofCircle(xPos, yPos, rad);
        ofDisableAlphaBlending();
        ofDisableSmoothing();
        rad += 0.006 * ofGetHeight();
        if (rad > dim) {
            rad = dim;
        }
    } else if (!on) {
        ofEnableAlphaBlending();
        ofEnableSmoothing();
        ofFill();
        ofSetColor(100, 20, 60, 100);
        ofCircle(xPos, yPos, rad);
        ofNoFill();
        ofSetLineWidth(2);
        ofSetColor(100, 20, 60);
        ofCircle(xPos, yPos, rad);
        ofDisableAlphaBlending();
        ofDisableSmoothing();
        rad -= 0.006 * ofGetHeight();
        vol -= 0.05f;
        somLocal.setVolume(vol);
        if (rad < 0.) {
            rad = 0.;
        }
        if( vol <0.) {
            vol = 0.0f;
            somLocal.stop();
        }
    }
}
