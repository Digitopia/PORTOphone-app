#include "ofLocais.h"
#include "ofApp.h"

ofLocais::ofLocais(float _x, float _y, float _dim, string _path)
{

    if((ofGetWindowHeight()*10/ofApp::getWindowWidth()) > 16) {
        xPos = _x * 0.8 * ofGetWindowHeight() + 0.1 * ofGetWindowHeight();
    } else {
        xPos = _x * ofGetWindowHeight();
    }

    yPos = _y * ofApp::getWindowWidth();
    dim = _dim * ofApp::getWindowWidth();

    ofSetRectMode(OF_RECTMODE_CENTER);
    bola.set(xPos-0.6*dim, yPos-0.6*dim, 1.4*dim, 1.4*dim);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofAddListener(ofEvents().mousePressed, this, &ofLocais::mousePressed);

    path = _path;

    vol = 0.7f;

    somLocal.loadSound(path);
    somLocal.setLoop(true);

}

void ofLocais::actual() {

    if (localOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            if (!on){
                on = true;
            } else if (on){
                on = false;
            }

            localOn = false;
        }
    }
}

void ofLocais::mousePressed(ofMouseEventArgs& event) {
    if(bola.inside(event.x, event.y)) {
        if(!on) {
            vol = 0.7f;
            somLocal.setVolume(vol);
            somLocal.setPosition(0.0f);
            somLocal.play();
        }
        on = !on;
    }
}

void ofLocais::draw() {

    if (localOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            cout << "chegou aqui!!" << endl;
            cout << ofDist(xRato, yRato, xPos, yPos) << endl;
            if (!on){
                on = true;
            } else if (on){
                on = false;
            }

            localOn = false;
        }
    }

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
        alive = 1;
        rad += 0.006 * ofGetWindowHeight();
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
        alive = 0;
        rad -= 0.006 * ofGetWindowHeight();
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

int ofLocais::active() {
    return alive;
}
