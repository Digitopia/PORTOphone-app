#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"

#include "ofLocais.h"
#include "ofBancos.h"

class ofApp : public ofxAndroidApp {
	
	public:

		static int getWindowWidth() {
			return ofGetWindowHeight();
		}

		static int getWindowHeight() {
			return ofGetWindowWidth();
		}
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);

		void touchDown(int x, int y, int id);
		void touchMoved(int x, int y, int id);
		void touchUp(int x, int y, int id);
		void touchDoubleTap(int x, int y, int id);
		void touchCancelled(int x, int y, int id);
		void swipe(ofxAndroidSwipeDir swipeDir, int id);

		void pause();
		void stop();
		void resume();
		void reloadTextures();

		bool backPressed();
		void okPressed();
		void cancelPressed();

		ofLocais** locais;   // an array of pointers of type ofLocais
		int nLocais;         // variable for the number of Locais

		vector<int> allLocais;

		ofBancos** bancos;
		int nBancos;

		vector<int> allBancos;

		int novoZeroLargura;
		int novoMaxLargura;
		int novaDifLargura;

		int counter; // para renovar os sons

	private:

	    ofImage dia;
	    ofImage noite;
	    ofImage ajuda;
	    ofImage preto;

	    ofRectangle ligaDesliga, ajudaDesajuda;

	    bool night;
	    bool help;
	    int ratoX, ratoY;

};
