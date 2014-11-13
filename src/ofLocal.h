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

		// on = true makes sound play
		bool on;

		// se está clicavel
		bool localOn;

		// parar de diminuir vol e rad
		bool stop;

		string path;
		ofRectangle bola;
		ofSoundPlayer somLocal;
};

#endif

