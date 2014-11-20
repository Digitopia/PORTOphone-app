#ifndef LOCAL_H
#define LOCAL_H

#include "ofMain.h"
#include "Spot.h"

class Local : public Spot {

public:

    Local(float xPercentage, float yPercentage, vector<string> paths);

    void draw();
    void mousePressed(ofMouseEventArgs& event);
    
private:
    
    float dim;
    
//    ofCircle circleBox;

    const static ofColor red;
    const static ofColor red_alpha;
    const static float dimPercentage;

};

#endif

