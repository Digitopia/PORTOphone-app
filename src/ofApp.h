#pragma once

#include "ofMain.h"

#include "Place.h"
#include "Bench.h"
#include "ofxImage.h"

#ifdef TARGET_ANDROID
	#include "ofxAndroid.h"
#endif

#ifdef TARGET_OF_IOS
	#include "ofxiOS.h"
	#include "ofxiOSExtras.h"
#endif

#ifdef TARGET_ANDROID
class ofApp : public ofxAndroidApp {

#elif defined TARGET_OF_IOS
class ofApp : public ofxiOSApp {

#else
class ofApp : public ofBaseApp {
#endif

public:

	// OF stuff
	void setup();
	void update();
	void draw();

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

	#if defined(TARGET_ANDROID) || defined(TARGET_OSX)
	void keyPressed(int key);
	void keyReleased(int key);
	void windowResized(int w, int h);
	#endif

	#ifdef TARGET_ANDROID
	void pause();
	void stop();
	void resume();
	void reloadTextures();

	bool backPressed();
	void okPressed();
	void cancelPressed();

	void touchDown(int x, int y, int id);
	void touchMoved(int x, int y, int id);
	void touchUp(int x, int y, int id);
	void touchDoubleTap(int x, int y, int id);
	void touchCancelled(int x, int y, int id);
	void swipe(ofxAndroidSwipeDir swipeDir, int id);
	#endif

	#ifdef TARGET_OF_IOS
	void touchDown(ofTouchEventArgs& touch);
	void touchMoved(ofTouchEventArgs& touch);
	void touchUp(ofTouchEventArgs& touch);
	void touchDoubleTap(ofTouchEventArgs& touch);
	void touchCancelled(ofTouchEventArgs& touch);

	void exit();
	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	#endif

	#ifdef TARGET_OSX
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	#endif

private:

	vector<MapSound*> mapsounds;

	ofxImage imgDay;
	ofxImage imgNight;
	ofxImage imgHelp;
	ofxImage imgBlackBar;
	ofxImage imgSplashScreen;

	ofRectangle lightSwitch;
	ofRectangle helpSwitch;

	ofSoundPlayer soundSwitchOn;
	ofSoundPlayer soundSwitchOff;
	ofSoundPlayer soundHelpSwitch;

	static bool isNight;
	static bool isHelpOn;
	static bool inSplashScreen;
	static bool setupForAppFinished;

	int minWidthBound;
	int maxWidthBound;
	int diffWidthBound;

};
