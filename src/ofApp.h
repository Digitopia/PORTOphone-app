#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"

#include "Local.h"
#include "Banco.h"

class ofApp : public ofxAndroidApp {

public:

	// OF stuff
	void setup();
	void update();
	void draw();
    
	// android stuff
	void keyPressed(int key);
	void keyReleased(int key);
	void windowResized(int w, int h);
	void touchDown(int x, int y, int id);
	void touchMoved(int x, int y, int id);
	void touchUp(int x, int y, int id);
	void touchDoubleTap(int x, int y, int id);
	void touchCancelled(int x, int y, int id);
	void pause();
	void stop();
	void resume();
	void reloadTextures();
	bool backPressed();
	void okPressed();
	void cancelPressed();

	// our stuff
	void initSpots();
	void initImages();
	void checkDimensions();
	void imageStatus(ofMouseEventArgs& event);
	static bool screenRatioIsWeird();
    static bool getIsNight() { return isNight; }
    static bool getIsHelpOn() { return isHelpOn; }
    
	// TODO change this, should be static too, and refactor too
	int novoZeroLargura;
	int novoMaxLargura;
	int novaDifLargura;

private:

    // TODO why doens't this work with plain objects and only works with references?
	// TODO change to single array of spots, makes more sense!
	vector<Local*> locais;
	vector<Banco*> bancos;

	ofImage imgDay;
	ofImage imgNight;
	ofImage imgHelp;
	ofImage imgBlack;

	ofRectangle lightSwitch;
	ofRectangle helpSwitch;

	static bool isNight;
	static bool isHelpOn;

	int mouseX;
	int mouseY;
};
