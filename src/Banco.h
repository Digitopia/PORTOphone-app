#ifndef BANCO_H
#define BANCO_H

#include "ofMain.h"
#include "Spot.h"

class Banco : public Spot {

public:

	Banco(float xPercentage, float yPercentage, vector<string> paths);

	void draw();
	void mousePressed(ofMouseEventArgs& event);

	const static float dimPercentage;
	ofRectangle rect;

private:

	const static ofColor blue_light;
	const static ofColor blue;

};

#endif
