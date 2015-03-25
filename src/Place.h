#ifndef PLACE_H
#define PLACE_H

#include "ofMain.h"
#include "MapSound.h"

class Place : public MapSound {

public:

	Place(float xPercentage, float yPercentage, vector<string> paths);

	void draw();
	void mousePressed(ofMouseEventArgs& event);
	float getRadius() { return dim/2; }

	const static float dimPercentage;

private:

	float dim;

	const static ofColor red_light;
	const static ofColor red;

};

#endif

