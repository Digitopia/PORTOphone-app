#include "ofApp.h"

// initialize static member variables (has to be here)
bool ofApp::isNight = true;
bool ofApp::isHelpOn = false;

void ofApp::setup() {

	ofLog(OF_LOG_NOTICE);

    ofBackground(127, 127, 127); // grey

	ofSetFrameRate(60);

	checkDimensions();

    initSpots();
    initImages();

    soundSwitchOn.loadSound("sounds/switch_on.wav");
    soundSwitchOn.setVolume(0.7);
    soundSwitchOn.setPosition(0.0);

    soundSwitchOff.loadSound("sounds/switch_off.wav");
    soundSwitchOff.setVolume(0.7);
    soundSwitchOff.setPosition(0.0);

	ofAddListener(ofEvents().mousePressed, this, &ofApp::imageStatus);
}

void ofApp::initImages() {

	imgDay.loadImage("images/day.jpg");
	imgHelp.loadImage("images/help.jpg");
	imgNight.loadImage("images/night.jpg");
	imgBlack.loadImage("images/black.jpg");

	imgDay.resize(novaDifLargura, ofGetHeight());
	imgHelp.resize(novaDifLargura, ofGetHeight());
	imgNight.resize(novaDifLargura, ofGetHeight());

	ofSetRectMode(OF_RECTMODE_CENTER);
	lightSwitch.set((0.88*novaDifLargura+novoZeroLargura), 0.8275*ofGetHeight(), (0.08*novaDifLargura+novoZeroLargura), 0.2*ofGetHeight());
	helpSwitch.set((0.92*novaDifLargura+novoZeroLargura), (0.41*ofGetHeight()), (0.06*novaDifLargura+novoZeroLargura), (0.15*ofGetHeight()));
    ofSetRectMode(OF_RECTMODE_CORNER);

}

void ofApp::initSpots() {

    vector<string> metros;
    metros.push_back("sounds/metro_1.mp3");
    metros.push_back("sounds/metro_2.mp3");
    metros.push_back("sounds/metro_3.mp3");
    
    vector<string> parque_cidades;
    parque_cidades.push_back("sounds/parque_cidade_1.mp3");
    parque_cidades.push_back("sounds/parque_cidade_2.mp3");
    parque_cidades.push_back("sounds/parque_cidade_3.mp3");

    vector<string> serralves;
    serralves.push_back("sounds/serralves_1.mp3");
    serralves.push_back("sounds/serralves_2.mp3");

    vector<string> batalhas;
    batalhas.push_back("sounds/batalha_1.mp3");
    batalhas.push_back("sounds/batalha_2.mp3");
    batalhas.push_back("sounds/batalha_3.mp3");

    vector<string> santa_catarinas;
    santa_catarinas.push_back("sounds/santa_catarina_1.mp3");
    santa_catarinas.push_back("sounds/santa_catarina_2.mp3");
    santa_catarinas.push_back("sounds/santa_catarina_3.mp3");

    vector<string> casa_musicas;
    casa_musicas.push_back("sounds/casa_musica_1.mp3");
    casa_musicas.push_back("sounds/casa_musica_2.mp3");

    vector<string> bolhaos;
    bolhaos.push_back("sounds/bolhao_1.mp3");
    bolhaos.push_back("sounds/bolhao_2.mp3");
    bolhaos.push_back("sounds/bolhao_3.mp3");

    vector<string> ribeiras;
    ribeiras.push_back("sounds/ribeira_1.mp3");
    ribeiras.push_back("sounds/ribeira_2.mp3");
    ribeiras.push_back("sounds/ribeira_3.mp3");

    spots.push_back(new Local(0.14, 0.19, metros));
    spots.push_back(new Local(0.27, 0.57, parque_cidades));
    spots.push_back(new Local(0.43, 0.78, serralves));
    spots.push_back(new Local(0.80, 0.71, batalhas));
    spots.push_back(new Local(0.71, 0.33, santa_catarinas));
    spots.push_back(new Local(0.83, 0.12, casa_musicas));
    spots.push_back(new Local(0.45, 0.15, bolhaos));
    spots.push_back(new Local(0.05, 0.86, ribeiras));

    vector<string> bancos_1;
    bancos_1.push_back("sounds/banco_1.mp3");
    bancos_1.push_back("sounds/banco_2.mp3");
    bancos_1.push_back("sounds/banco_3.mp3");

    vector<string> bancos_2;
    bancos_2.push_back("sounds/banco_4.mp3");
    bancos_2.push_back("sounds/banco_5.mp3");

    vector<string> bancos_3;
    bancos_3.push_back("sounds/banco_6.mp3");
    bancos_3.push_back("sounds/banco_7.mp3");

    vector<string> bancos_4;
    bancos_4.push_back("sounds/banco_8.mp3");
    bancos_4.push_back("sounds/banco_9.mp3");

    vector<string> bancos_5;
	bancos_5.push_back("sounds/banco_10.mp3");
	bancos_5.push_back("sounds/banco_11.mp3");

	vector<string> bancos_6;
	bancos_6.push_back("sounds/banco_12.mp3");
	bancos_6.push_back("sounds/banco_13.mp3");

	spots.push_back(new Banco(0.45, 0.31, bancos_1)); // por baixo bolhao
    spots.push_back(new Banco(0.64, 0.07, bancos_2)); // casa da musica esquerda
    spots.push_back(new Banco(0.06, 0.07, bancos_3)); // metro
    spots.push_back(new Banco(0.22, 0.83, bancos_4)); // parque da cidade
    spots.push_back(new Banco(0.61, 0.86, bancos_5)); // aliados
    spots.push_back(new Banco(0.89, 0.30, bancos_6)); // casa da musica baixo

}

void ofApp::checkDimensions() {
	if (screenRatioIsWeird()) {
		novoZeroLargura = 0.1 * ofGetWidth();
		novoMaxLargura = 0.9 * ofGetWidth();
	}
	else {
		novoZeroLargura = 0;
		novoMaxLargura = ofGetWidth();
	}
	novaDifLargura = novoMaxLargura - novoZeroLargura;
}

void ofApp::update() {

}

bool ofApp::screenRatioIsWeird() {
	return (ofGetWidth() * 10 / ofGetHeight()) > 16;
}

void ofApp::draw() {
    
    ofSetHexColor(0xFFFFFF);

	if (screenRatioIsWeird()) {
		imgBlack.draw(0, 0, novoZeroLargura, ofGetHeight());
		imgBlack.draw(novoMaxLargura, 0, novoZeroLargura, ofGetHeight());
	}

	if (isNight)
		 imgNight.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());
	else if (isHelpOn)
		imgHelp.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());
	else
		imgDay.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());
    
	if (!isNight && !isHelpOn) {
        for (unsigned int i = 0; i < spots.size(); i++)
			spots[i]->draw();
	}
}

void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}

void ofApp::imageStatus(ofMouseEventArgs& event) {

	ofLog() << "touch";

    if (helpSwitch.inside(event.x, event.y))
        isHelpOn = !isHelpOn;

    if (lightSwitch.inside(event.x, event.y)) {

        isNight = !isNight;

        // night -> day
		if (!isNight) {

			soundSwitchOn.play();

            for (unsigned int i = 0; i < spots.size(); i++)
                spots[i]->loadSound();
        }

        // day -> night
        else {

        	soundSwitchOff.play();

            for (unsigned int i = 0; i < spots.size(); i++)
                spots[i]->reset();

        }
        
	}

}

