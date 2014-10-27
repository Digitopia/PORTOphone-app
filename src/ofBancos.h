#ifndef __PORTOphone2__ofBanco__
#define __PORTOphone2__ofBanco__

#include "ofMain.h"

class ofBancos {
public:

    void actual();
    void draw();
    int active();
    void mousePressed(ofMouseEventArgs& event);

    float xPos, yPos;
    float dim;
    float xRato, yRato;
    string path;
    ofBancos(float x, float y, float dim, string path);
    bool bancosOn;

    float rad;

    bool on;

    int alive;

    ofRectangle caixa;
    ofSoundPlayer somBanco;

    float vol;

private:

};


#endif
