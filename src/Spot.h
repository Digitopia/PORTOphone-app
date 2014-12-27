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
    ofSoundPlayer* loadSound(string path);
    void playSound();
    virtual void draw();
    void loadSounds();
    void activateNextSound();
    
protected:

    float x;
    float y;

    float rad;
    float vol;
    float dim;

    bool clickable;
    bool playing;

    ofRectangle boundingBox;

    vector<ofSoundPlayer*> sounds;
    ofSoundPlayer* sound;

    vector<string> paths;

    unsigned int isound;
    
};

#endif
