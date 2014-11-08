#ifndef OFLOCAL_H
#define OFLOCAL_H

#include "ofMain.h"

class ofLocal {

	public:

		ofLocal(float x, float y, float dim, string path);

		void draw();
		void actual();
		void mousePressed(ofMouseEventArgs& event);

		float xPos, yPos;
		float xRato, yRato;
		float dim, rad, vol;
		bool on, localOn;
		string path;
		ofRectangle bola;
		ofSoundPlayer somLocal;
};

#endif

