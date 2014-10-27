#include "ofBancos.h"
#include "ofApp.h"

ofBancos::ofBancos(float _x, float _y, float _dim, string _path)
{
    if((ofApp::getWindowHeight()*10/ofApp::getWindowHeight()) > 16) {
    xPos = _x * 0.8 * ofApp::getWindowHeight() + 0.1 * ofApp::getWindowHeight();
    } else {
        xPos = _x * ofApp::getWindowHeight();
    }

    yPos = _y * ofApp::getWindowHeight();
    dim = _dim * ofApp::getWindowHeight();

    ofSetRectMode(OF_RECTMODE_CENTER);
    caixa.set(xPos, yPos, dim, dim);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofAddListener(ofEvents().mousePressed, this, &ofBancos::mousePressed);

    path = _path;

    vol = 0.7f;

    somBanco.loadSound(path);
    somBanco.setLoop(true);

}

void ofBancos::actual() {

    if (bancosOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            if (!on){
                on = true;
            } else if (on){
                on = false;
            }

            bancosOn = false;
        }
    }
}

void ofBancos::mousePressed(ofMouseEventArgs& event) {
    if(caixa.inside(event.x, event.y)) {
        if(!on) {
            vol = 0.7f;
            somBanco.setVolume(vol);
            somBanco.play();
        } else {
            somBanco.stop();
            somBanco.setPosition(0.0f);
        }
        on = !on;
    }
}

void ofBancos::draw() {

	ofRect(xPos+0.03*ofApp::getWindowHeight(), yPos+0.02*ofApp::getWindowHeight(), rad, rad);

/*    if (bancosOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            cout << "chegou ao Banco!!" << endl;
            cout << ofDist(xRato, yRato, xPos, yPos) << endl;
            if (!on){
                on = true;
            } else if (on){
                on = false;
            }

            bancosOn = false;
        }
    }
*/
    if (on) {
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofEnableAlphaBlending();
        ofEnableSmoothing();
        ofFill();
        ofSetColor(10, 20, 160, 100);

        // FOR SOME REASON, RECTANGLES ARE NOT CENTERED!

        ofRect(xPos+0.03*ofApp::getWindowHeight(), yPos+0.02*ofApp::getWindowHeight(), rad, rad);
        ofNoFill();
        ofSetLineWidth(2);
        ofSetColor(10, 20, 160);
      ofRect(xPos+0.03*ofApp::getWindowHeight(), yPos+0.02*ofApp::getWindowHeight(), rad, rad);
        ofDisableAlphaBlending();
        ofDisableSmoothing();
        alive = 1;
        rad  += 0.006 * ofApp::getWindowHeight();
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
        ofRect(xPos+0.03*ofApp::getWindowHeight(), yPos+0.02*ofApp::getWindowHeight(), rad, rad);
        ofNoFill();
        ofSetLineWidth(2);
        ofSetColor(10, 20, 160);
        ofRect(xPos+0.03*ofApp::getWindowHeight(), yPos+0.02*ofApp::getWindowHeight(), rad, rad);
        ofDisableAlphaBlending();
        ofDisableSmoothing();
        alive = 0;
        rad  -= 0.006 * ofApp::getWindowHeight();
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

int ofBancos::active() {
    return alive;
}
