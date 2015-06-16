#include "ofApp.h"
#include "ofxImage.h"

bool ofApp::isNight = true;
bool ofApp::isHelpOn = false;
bool ofApp::inSplashScreen = false;
bool ofApp::setupForAppFinished = false;

// TODO: Fix "Couldn't set thread priority" error on osx
// TODO: travis build
// TODO: make the animation equal speed no matter the FPS
// TODO: should clear objects and memory when leaving application, right?
// TODO: hide status bar in iOS

void ofApp::setup() {

	#ifdef TARGET_OF_IOS
	ofSetOrientation(OF_ORIENTATION_90_LEFT);
	#endif

	clock_t timer_begin = clock() / (CLOCKS_PER_SEC / 1000);

	ofLog(OF_LOG_NOTICE);
	//    ofSetLogLevel(OF_LOG_SILENT);

	ofSetFrameRate(60);

	checkDimensions(ofGetWidth());
	ofAddListener(ofEvents().mousePressed, this, &ofApp::imageStatus);
	imgSplashScreen.loadImage("logo_landscape.png");

	clock_t timer_end = clock() / (CLOCKS_PER_SEC / 1000);
	ofLog() << "setup took " << (timer_end - timer_begin) / 1000.0;

	ofLog() << "width is " << ofGetWidth();
	ofLog() << "height is " << ofGetHeight();

}

void ofApp::setupForApp() {

	clock_t timer_begin = clock() / (CLOCKS_PER_SEC / 1000);

	checkDimensions(ofGetWidth());

	initSpots();
	initImages();
	initSoundSwitches();

	// load all sounds for each spot
	//	for (unsigned int i = 0; i < spots.size(); i++) {
	//		ofLog() << "loading spot " << i;
	//		spots[i]->loadSounds();
	//	}

	clock_t timer_end = clock() / (CLOCKS_PER_SEC / 1000);
	ofLog() << "setup for app took " << (timer_end - timer_begin) / 1000.0;

	setupForAppFinished = true;

}

void ofApp::initSoundSwitches() {

	soundSwitchOn.loadSound("sounds/switch_on.wav");
	soundSwitchOn.setVolume(0.5);

	soundSwitchOff.loadSound("sounds/switch_off.wav");
	soundSwitchOff.setVolume(0.5);

	soundHelpSwitch.loadSound("sounds/help.wav");
	soundHelpSwitch.setVolume(0.5);

}

void ofApp::initImages() {

	imgDay.loadImage("day.jpg");
	imgHelp.loadImage("help.jpg");
	imgNight.loadImage("night.jpg");

	helpSwitch.set((0.895*diffWidthBound+minWidthBound), (0.41*ofGetHeight()), (0.055*diffWidthBound), (0.13*ofGetHeight()));
	lightSwitch.set((0.90*diffWidthBound+minWidthBound), 0.81*ofGetHeight(), (0.07*diffWidthBound), 0.14*ofGetHeight());

}

void ofApp::initSpots() {

	vector<string> metros;
	metros.push_back("sounds/metro_1.mp3");
	metros.push_back("sounds/metro_2.mp3");
	metros.push_back("sounds/metro_3.mp3");

	vector<string> parque_cidades;
	parque_cidades.push_back("sounds/parque_cidade_1.mp3");
	parque_cidades.push_back("sounds/parque_cidade_2.mp3");
	parque_cidades.push_back("sounds/parque_cidade_3.mp3");

	vector<string> serralves;
	serralves.push_back("sounds/serralves_1.mp3");
	serralves.push_back("sounds/serralves_2.mp3");

	vector<string> batalhas;
	batalhas.push_back("sounds/batalha_1.mp3");
	batalhas.push_back("sounds/batalha_2.mp3");
	batalhas.push_back("sounds/batalha_3.mp3");

	vector<string> santa_catarinas;
	santa_catarinas.push_back("sounds/santa_catarina_1.mp3");
	santa_catarinas.push_back("sounds/santa_catarina_2.mp3");
	santa_catarinas.push_back("sounds/santa_catarina_3.mp3");

	vector<string> casa_musicas;
	casa_musicas.push_back("sounds/casa_musica_1.mp3");
	casa_musicas.push_back("sounds/casa_musica_2.mp3");

	vector<string> bolhaos;
	bolhaos.push_back("sounds/bolhao_1.mp3");
	bolhaos.push_back("sounds/bolhao_2.mp3");
	bolhaos.push_back("sounds/bolhao_3.mp3");

	vector<string> ribeiras;
	ribeiras.push_back("sounds/ribeira_1.mp3");
	ribeiras.push_back("sounds/ribeira_2.mp3");
	ribeiras.push_back("sounds/ribeira_3.mp3");

	mapsounds.push_back(new Place(0.16, 0.19, metros));
	mapsounds.push_back(new Place(0.27, 0.57, parque_cidades));
	mapsounds.push_back(new Place(0.43, 0.82, serralves));
	mapsounds.push_back(new Place(0.80, 0.73, batalhas));
	mapsounds.push_back(new Place(0.71, 0.33, santa_catarinas));
	mapsounds.push_back(new Place(0.83, 0.12, casa_musicas));
	mapsounds.push_back(new Place(0.45, 0.15, bolhaos));
	mapsounds.push_back(new Place(0.05, 0.86, ribeiras));

	vector<string> bancos_1;
	bancos_1.push_back("sounds/banco_1.mp3");
	bancos_1.push_back("sounds/banco_2.mp3");
	bancos_1.push_back("sounds/banco_3.mp3");

	vector<string> bancos_2;
	bancos_2.push_back("sounds/banco_4.mp3");
	bancos_2.push_back("sounds/banco_5.mp3");

	vector<string> bancos_3;
	bancos_3.push_back("sounds/banco_6.mp3");
	bancos_3.push_back("sounds/banco_7.mp3");

	vector<string> bancos_4;
	bancos_4.push_back("sounds/banco_8.mp3");
	bancos_4.push_back("sounds/banco_9.mp3");

	vector<string> bancos_5;
	bancos_5.push_back("sounds/banco_10.mp3");
	bancos_5.push_back("sounds/banco_11.mp3");

	vector<string> bancos_6;
	bancos_6.push_back("sounds/banco_12.mp3");
	bancos_6.push_back("sounds/banco_13.mp3");

	mapsounds.push_back(new Bench(0.453, 0.315, bancos_1)); // por baixo bolhao
	mapsounds.push_back(new Bench(0.637, 0.075, bancos_2)); // casa da musica esquerda
	mapsounds.push_back(new Bench(0.060, 0.070, bancos_3)); // metro
	mapsounds.push_back(new Bench(0.223, 0.831, bancos_4)); // parque da cidade
	mapsounds.push_back(new Bench(0.610, 0.873, bancos_5)); // aliados
	mapsounds.push_back(new Bench(0.890, 0.305, bancos_6)); // casa da musica baixo

}

void ofApp::checkDimensions(int width) {
	if (screenRatioIsWeird()) {
		minWidthBound = 0.1 * width;
		maxWidthBound = 0.9 * width;
	}
	else {
		minWidthBound = 0;
		maxWidthBound = width;
	}
	diffWidthBound = maxWidthBound - minWidthBound;
}

void ofApp::update() {

	// TODO: this should be better
	// this fixes the rotation problems of iOS 8, though it's a workaround
	#ifdef TARGET_OF_IOS
	if ( [[[UIDevice currentDevice] systemVersion] compare:@"8.0" options:NSNumericSearch] == NSOrderedDescending ) {
		if (ofxiOSGetGLView().frame.origin.x != 0
		        || ofxiOSGetGLView().frame.size.width != [[UIScreen mainScreen] bounds].size.width) {
			ofxiOSGetGLView().frame = CGRectMake(0,0,[[UIScreen mainScreen] bounds].size.width,[[UIScreen mainScreen] bounds].size.height);
		}
	}
	#endif

	//	 version with timeout
	//	  if (inSplashScreen && ofGetElapsedTimeMillis() > 5.0 * 1000) {
	//	      inSplashScreen = false;
	////	      setupForApp();
	//	      return;
	//	  }

	if (inSplashScreen && !setupForAppFinished) {
		setupForApp();
	}

}

bool ofApp::screenRatioIsWeird() {
	//  return (ofGetWidth() * 10 / ofGetHeight()) > 16;
	//  TODO
	return false;
}

void ofApp::draw() {

	ofSetHexColor(0xFFFFFF);

	if (screenRatioIsWeird()) {
		if (!imgBlackBar.isAllocated()) imgBlackBar.loadImage("black_bar.jpg");
		imgBlackBar.draw(0, 0, minWidthBound, ofGetHeight());
		imgBlackBar.draw(maxWidthBound, 0, minWidthBound, ofGetHeight());
	}

	// this will only run once
	if (!setupForAppFinished) {
		imgSplashScreen.draw(minWidthBound, 0, diffWidthBound, ofGetHeight());
		inSplashScreen = true;
		return;
	}

	if (isNight) {
		if (!imgNight.isAllocated()) imgNight.loadImage("night.jpg");
		imgNight.draw(minWidthBound, 0, diffWidthBound, ofGetHeight());
	}

	else if (isHelpOn) {
		if (!imgHelp.isAllocated()) imgHelp.loadImage("help.jpg");
		imgHelp.draw(minWidthBound, 0, diffWidthBound, ofGetHeight());
	}

	else {
		if (!imgDay.isAllocated()) imgDay.loadImage("day.jpg");
		imgDay.draw(minWidthBound, 0, diffWidthBound, ofGetHeight());
		//        imgHelp.draw(minWidthBound, 0, diffWidthBound, ofGetHeight());
	}

	if (!isNight && !isHelpOn) {
		for (unsigned int i = 0; i < mapsounds.size(); i++)
			mapsounds[i]->draw();
	}

	// ofLog() << ofGetFrameRate() << endl;
}


void ofApp::imageStatus(ofMouseEventArgs& event) {

	ofLog() << "touch";

	// while app is not ready, ignore all touches
	if (!setupForAppFinished) {
		return;
	}

	if (helpSwitch.inside(event.x, event.y) && !isNight) {
		isHelpOn = !isHelpOn;
		soundHelpSwitch.play();
	}

	if (lightSwitch.inside(event.x, event.y)) {

		isNight = !isNight;

		// night -> day
		if (!isNight) {

			// make sure the help doesn't come up again when going to day if it was on before
			isHelpOn = false;

			soundSwitchOn.play();

			for (unsigned int i = 0; i < mapsounds.size(); i++)
				mapsounds[i]->activateNextSound();
		}

		// day -> night
		else {

			soundSwitchOff.play();

			for (unsigned int i = 0; i < mapsounds.size(); i++)
				mapsounds[i]->reset();

		}

	}

}

/*===========================================
=               Android & OSX               =
===========================================*/

#if defined(TARGET_ANDROID) || defined(TARGET_OSX)

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::windowResized(int w, int h) {
	checkDimensions(w);
}

#endif

/*=========================================
=                 Android                 =
=========================================*/

#ifdef TARGET_ANDROID

void ofApp::pause() {
	// so that previous active drawings won't appear
	for (unsigned int i = 0; i < mapsounds.size(); i++) {
		mapsounds[i]->resetDrawing();
	}
}

void ofApp::stop() {

}

void ofApp::resume() {

}

void ofApp::reloadTextures() {

}

bool ofApp::backPressed() {
	return false;
}

void ofApp::okPressed() {

}

void ofApp::cancelPressed() {

}

void ofApp::touchDown(int x, int y, int id) {

}

void ofApp::touchMoved(int x, int y, int id) {

}

void ofApp::touchUp(int x, int y, int id) {

}

void ofApp::touchDoubleTap(int x, int y, int id) {

}

void ofApp::touchCancelled(int x, int y, int id) {

}

void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id) {

}

#endif

/*===============================================
=                      iOS                      =
===============================================*/

#ifdef TARGET_OF_IOS

void ofApp::touchDown(ofTouchEventArgs& touch) {

}

void ofApp::touchMoved(ofTouchEventArgs& touch) {

}

void ofApp::touchUp(ofTouchEventArgs& touch) {

}

void ofApp::touchDoubleTap(ofTouchEventArgs& touch) {

}

void ofApp::touchCancelled(ofTouchEventArgs& touch) {

}

void ofApp::exit() {

}

void ofApp::lostFocus() {

}

void ofApp::gotFocus() {

}

void ofApp::gotMemoryWarning() {

}

void ofApp::deviceOrientationChanged(int newOrientation) {
	if (newOrientation == 3)
		ofSetOrientation(OF_ORIENTATION_90_LEFT);
	else if (newOrientation == 4)
		ofSetOrientation(OF_ORIENTATION_90_RIGHT);
	//		ofLog() << "new orientation " << newOrientation;
	//        OF_ORIENTATION_DEFAULT = 1,
	//        OF_ORIENTATION_180 = 2,
	//        OF_ORIENTATION_90_LEFT = 3,
	//        OF_ORIENTATION_90_RIGHT = 4,
	//        OF_ORIENTATION_UNKNOWN = 5
	//        ofSetOrientation(OF_ORIENTATION_90_LEFT);
}

#endif

/*===============================================
=                      OSX                      =
===============================================*/

#ifdef TARGET_OSX

void ofApp::mouseMoved(int x, int y) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::gotMessage(ofMessage msg) {

}

#endif
