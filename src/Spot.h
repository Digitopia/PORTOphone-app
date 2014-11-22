#ifndef SPOT_H
#define SPOT_H

#include "ofMain.h"

class Spot {

public:

    Spot(float xPercentage, float yPercentage, vector<string> paths);

    void mousePressed(ofMouseEventArgs& event);
    void reset();
    void resetDrawing();
    void setPath(string path);
    void loadSound();
    void playSound();
    virtual void draw();
    
protected:

    float x;
    float y;

    float rad;
    float vol;
    float dim;

    bool clickable;
    bool playing;

    ofRectangle boundingBox;

    ofSoundPlayer sound;
    
    vector<string> paths;
    unsigned int ipath; // index of the current position in paths vector
    
};

#endif
