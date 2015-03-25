#ifndef BENCH_H
#define BENCH_H

#include "ofMain.h"
#include "MapSound.h"

class Bench : public MapSound {

public:

	Bench(float xPercentage, float yPercentage, vector<string> paths);

	void draw();
	void mousePressed(ofMouseEventArgs& event);

	const static float dimPercentage;
	ofRectangle rect;

private:

	const static ofColor blue_light;
	const static ofColor blue;

};

#endif
