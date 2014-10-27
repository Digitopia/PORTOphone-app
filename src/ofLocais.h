#ifndef __Digi_Porto__ofLocais__
#define __Digi_Porto__ofLocais__

#include "ofMain.h"

// #include "AppCore.h"

class ofLocais {
    public:

    void actual();
    void draw();
    int active();
    void mousePressed(ofMouseEventArgs& event);

    float xPos, yPos;
    float dim;
    float xRato, yRato;
    ofLocais(float x, float y, float dim, string path);
    string path;
    bool localOn;

    float rad;

    bool on;

    int alive;

    ofRectangle bola;
    ofSoundPlayer somLocal;

    float vol;

private:

};
#endif /* defined(__Digi_Porto__ofLocais__) */

