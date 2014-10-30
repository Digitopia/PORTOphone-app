#include "ofBanco.h"
#include "ofApp.h"

ofBanco::ofBanco(float _x, float _y, float _dim, string _path) {

	// TODO: este código está bem? de certeza que não será getWindowWidth na segunda variavél?
	if ((ofApp::getWindowHeight()*10/ofApp::getWindowHeight()) > 16)
		xPos = _x * 0.8 * ofApp::getWindowHeight() + 0.1 * ofApp::getWindowHeight();
	else
        xPos = _x * ofApp::getWindowHeight();

    yPos = _y * ofApp::getWindowHeight();
    dim = _dim * ofApp::getWindowHeight();

    ofSetRectMode(OF_RECTMODE_CENTER);
    caixa.set(xPos, yPos, dim, dim);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofAddListener(ofEvents().mousePressed, this, &ofBanco::mousePressed);

    path = _path;

    vol = 0.7f;

    somBanco.loadSound(path);
    somBanco.setLoop(true);

}

// TODO: isto não está a ser usado. Pode-se apagar ou que?
void ofBanco::actual() {

    if (bancoOn) {
        if (ofDist(xRato, yRato, xPos, yPos) < dim){
            if (!on) {
                on = true;
            }
            else if (on) {
                on = false;
            }
            bancoOn = false;
        }
    }
}

void ofBanco::mousePressed(ofMouseEventArgs& event) {

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

void ofBanco::draw() {

	// this function's rectangles work on center mode
	ofSetRectMode(OF_RECTMODE_CENTER);

	int xRect = xPos + 0.03 * ofApp::getWindowHeight();
	int yRect = yPos + 0.02 * ofApp::getWindowHeight();

	ofRect(xRect, yRect, rad, rad);

	//if (bancosOn) {
	//	if (ofDist(xRato, yRato, xPos, yPos) < dim){
	//		cout << "chegou ao Banco!!" << endl;
	//		cout << ofDist(xRato, yRato, xPos, yPos) << endl;
	//		if (!on){
	//			on = true;
	//		} else if (on){
	//			on = false;
	//		}
	//
	//		bancosOn = false;
	//	}
	//}

	ofEnableAlphaBlending();
	ofEnableSmoothing();

	// fill
	ofFill();
	ofSetColor(10, 20, 160, 100);
	ofRect(xRect, yRect, rad, rad);

	// border
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(10, 20, 160);
	ofRect(xRect, yRect, rad, rad);

	ofDisableAlphaBlending();
	ofDisableSmoothing();

	if (on) {

		alive = 1;
		rad += 0.006 * ofApp::getWindowHeight();

		if (rad > dim) {
			rad = dim;
		}

	}

	else if (!on) {

		alive = 0;
		rad -= 0.006 * ofApp::getWindowHeight();

		vol -= 0.05f;
		somBanco.setVolume(vol);

		if (rad < 0.) {
			rad = 0.;
		}

		if (vol < 0.) {
			vol = 0.0f;
			somBanco.stop();
		}
	}

	// and back to corner mode because of the rest of the app
	ofSetRectMode(OF_RECTMODE_CORNER);

}

int ofBanco::getAlive() {
    return alive;
}
