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
	void initSoundSwitches();
	void checkDimensions(int width);
	void imageStatus(ofMouseEventArgs& event);
	void setupForApp();
	static bool screenRatioIsWeird();
    static bool getIsNight() { return isNight; }
    static bool getIsHelpOn() { return isHelpOn; }
    
	// TODO change this, should be static too, and refactor too
	int novoZeroLargura;
	int novoMaxLargura;
	int novaDifLargura;

private:

	vector<Spot*> spots;

	ofImage imgDay;
	ofImage imgNight;
	ofImage imgHelp;
	ofImage imgBlackBar;
	ofImage imgSplashScreen;

	ofRectangle lightSwitch;
	ofRectangle helpSwitch;

	ofSoundPlayer soundSwitchOn;
	ofSoundPlayer soundSwitchOff;
	ofSoundPlayer soundHelpSwitch;

	static bool isNight;
	static bool isHelpOn;
	static bool inSplashScreen;

	int mouseX;
	int mouseY;
};
