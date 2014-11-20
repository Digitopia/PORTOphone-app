#ifndef BANCO_H
#define BANCO_H

#include "ofMain.h"
#include "Spot.h"

class Banco : public Spot {

public:

    Banco(float xPercentage, float yPercentage, vector<string> paths);

    void draw();
    void mousePressed(ofMouseEventArgs& event);
    
private:

    const static ofColor blue;
    const static ofColor blue_alpha;
    const static float dimPercentage;
    
};

#endif