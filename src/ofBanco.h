#ifndef OFBANCO_H
#define OFBANCO_H

#include "ofMain.h"

class ofBanco {

	public:

		ofBanco(float x, float y, float dim, string path);

		void actual();
		void draw();
		void mousePressed(ofMouseEventArgs& event);

		float xPos, yPos;
		float xRato, yRato;
		float rad, vol, dim;
		bool bancoOn;
		bool on;
		string path;
		ofRectangle caixa;
		ofSoundPlayer somBanco;

};

#endif
