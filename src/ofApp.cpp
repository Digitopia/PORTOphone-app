#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofLog(OF_LOG_NOTICE);

	ofBackground(127, 127, 127);

	ofSetFrameRate(60);

//	ofSetOrientation(OF_ORIENTATION_90_RIGHT);

	// poe barras de lado em funcao do tamanho do display
	if (screenRatioIsWeird()) {
		novoZeroLargura = 0.1 * ofGetWidth();
		novoMaxLargura = 0.9 * ofGetWidth();
	}
	else {
		novoZeroLargura = 0;
		novoMaxLargura = ofGetWidth();
	}

	novaDifLargura = novoMaxLargura - novoZeroLargura;

	//	ofLog() << "novoZeroLargura: " << novoZeroLargura;
	//	ofLog() << "novoMaxLargura: " << novoMaxLargura;
	//	ofLog() << "novaDifLargura: " << novaDifLargura;

	nLocais = 8;
	locais = new ofLocal*[nLocais];
	allLocais.reserve(nLocais);

	locais[0] = new ofLocal(0.14,    0.19,  0.14, "metro1.mp3"); // metro
	locais[1] = new ofLocal(0.26625, 0.565, 0.14, "p1.mp3"); 	 // parque da cidade
	locais[2] = new ofLocal(0.4325,  0.797, 0.14, "ser1.mp3");   // serralves
	locais[3] = new ofLocal(0.79875, 0.713, 0.14, "bat1.mp3");   // batalha
	locais[4] = new ofLocal(0.71375, 0.33,  0.14, "s1.mp3"); 	 // santa catarina
	locais[5] = new ofLocal(0.8325,  0.118, 0.14, "cdm1.mp3");   // casa da musica
	locais[6] = new ofLocal(0.44885, 0.15,  0.14, "bol1.mp3");	 // bolhao
	locais[7] = new ofLocal(0.04875, 0.855, 0.14, "r1.mp3"); 	 // ribeira

	nBancos = 6;
	bancos = new ofBanco*[nBancos];
	allBancos.reserve(nBancos);

	bancos[0] = new ofBanco(0.4215,  0.2983, 0.12, "b1.mp3");
	bancos[1] = new ofBanco(0.6055,  0.0583, 0.12, "b2.mp3"); // bolhao-cdm
	bancos[2] = new ofBanco(0.0220,  0.0517, 0.12, "b3.mp3"); // canto superior esquerdo
	bancos[3] = new ofBanco(0.18875, 0.8067, 0.12, "b4.mp3");
	bancos[4] = new ofBanco(0.5825,  0.8617, 0.12, "b5.mp3");
	bancos[5] = new ofBanco(0.85875, 0.2750, 0.12, "b6.mp3");

	ofLog() << "bancos e locais criados";

	dia.loadImage("images/sonodia.jpg");
	ajuda.loadImage("images/sonodiaajuda.jpg");
	noite.loadImage("images/sononoite.jpg");
	preto.loadImage("images/preto.jpg");

	dia.resize(novaDifLargura, ofGetHeight());
	ajuda.resize(novaDifLargura, ofGetHeight());
	noite.resize(novaDifLargura, ofGetHeight());

	ofLog() << "imagens carregadas e redimensionadas";

	night = true;
	help = false;

	counter = 0;

	for (int i = 0; i < nLocais; i++) {
		locais[i]->on = false;
		locais[i]->rad = 0;
		locais[i]->xRato = 0;
		locais[i]->localOn = false;
		locais[i]->yRato = 0;
	}

	for (int i = 0; i < nBancos; i++) {
		bancos[i]->on = false;
		bancos[i]->rad = 0;
		bancos[i]->xRato = 0;
		bancos[i]->bancoOn = false;
		bancos[i]->yRato = 0;
	}

	ofAddListener(ofEvents().mousePressed, this, &ofApp::imageStatus);

	ofSetRectMode(OF_RECTMODE_CENTER);

	ligaDesliga.set((0.88*novaDifLargura+novoZeroLargura), 0.8275*ofGetHeight(), (0.08*novaDifLargura+novoZeroLargura), 0.2*ofGetHeight());
	ajudaDesajuda.set((0.92*novaDifLargura+novoZeroLargura), (0.41*ofGetHeight()), (0.06*novaDifLargura+novoZeroLargura), (0.15*ofGetHeight()));

    ofSetRectMode(OF_RECTMODE_CORNER);

    ofLog() << "setup terminou";
}

// TODO: better name
bool ofApp::screenRatioIsWeird() {
	return (ofGetWidth() * 10 / ofGetHeight()) > 16;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetHexColor(0xFFFFFF);

	if (screenRatioIsWeird()) {
		preto.draw(0, 0, novoZeroLargura, ofGetHeight());
		preto.draw(novoMaxLargura, 0, novoZeroLargura, ofGetHeight());
	}

	if (night)
		 noite.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());
	else if (!help)
		dia.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());
	else
		ajuda.draw(novoZeroLargura, 0, novaDifLargura, ofGetHeight());

	if (!night && !help) {

		for (int i = 0; i < nLocais; i++) {
			locais[i]->draw();
			locais[i]->localOn = true; // TODO é estranho estar a fazer isto no draw
		}


		for (int i = 0; i < nBancos; i++) {
			bancos[i]->draw();
			bancos[i]->bancoOn = true; //TODO é estranho estar a fazer isto no draw
		}
	}
}

//--------------------------------------------------------------
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
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

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

	if (ligaDesliga.inside(event.x, event.y)) {

		night = !night;

		if (night) {

			counter++;

			for (int i = 0; i < nLocais; i++) {
                locais[i]->on = false;
                locais[i]->localOn = false;
                locais[i]->somLocal.stop();
                locais[i]->somLocal.unloadSound();
                locais[i]->rad = 0.;
            }

            for (int i = 0; i < nBancos; i++) {
                bancos[i]->on = false;
                bancos[i]->bancoOn = false;
                bancos[i]->somBanco.stop();
                bancos[i]->somBanco.unloadSound();
                bancos[i]->rad = 0.;
            }

            if (counter != 0) {

            	if ((counter % 3) == 1) {

                    locais[0]->somLocal.loadSound("metro2.mp3"); // metro
                    locais[1]->somLocal.loadSound("p2.mp3");     // parque da cidade
                    locais[2]->somLocal.loadSound("ser2.mp3");   // serralves
                    locais[3]->somLocal.loadSound("bat2.mp3");   // batalha
                    locais[4]->somLocal.loadSound("s2.mp3");     // santa catarina
                    locais[5]->somLocal.loadSound("cdm2.mp3");   // casa da musica
                    locais[6]->somLocal.loadSound("bol2.mp3");   // bolhão
                    locais[7]->somLocal.loadSound("r2.mp3");     // ribeira

                    bancos[0]->somBanco.loadSound("b7.mp3");
                    bancos[1]->somBanco.loadSound("b8.mp3");
                    bancos[2]->somBanco.loadSound("b9.mp3");
                    bancos[3]->somBanco.loadSound("b10.mp3");
                    bancos[4]->somBanco.loadSound("b11.mp3");
                    bancos[5]->somBanco.loadSound("b12.mp3");

                }

                else if ((counter % 3) == 2) {

                    locais[0]->somLocal.loadSound("metro3.mp3"); // metro
                    locais[1]->somLocal.loadSound("p3.mp3");     // parque da cidade
                    locais[2]->somLocal.loadSound("ser1.mp3");   // serralves
                    locais[3]->somLocal.loadSound("bat3.mp3");   // batalha
                    locais[4]->somLocal.loadSound("s3.mp3");     // santa catarina
                    locais[5]->somLocal.loadSound("cdm2.mp3");   // casa da musica
                    locais[6]->somLocal.loadSound("bol3.mp3");   // bolhão
                    locais[7]->somLocal.loadSound("r3.mp3");     // ribeira

                    bancos[0]->somBanco.loadSound("b13.mp3");
                    bancos[1]->somBanco.loadSound("b2.mp3");
                    bancos[2]->somBanco.loadSound("b5.mp3");
                    bancos[3]->somBanco.loadSound("b7.mp3");
                    bancos[4]->somBanco.loadSound("b1.mp3");
                    bancos[5]->somBanco.loadSound("b10.mp3");

                }

                else if ((counter % 3) == 0) {

                    locais[0]->somLocal.loadSound("metro1.mp3"); // metro
                    locais[1]->somLocal.loadSound("p1.mp3");     // parque da cidade
                    locais[2]->somLocal.loadSound("ser1.mp3");   // serralves
                    locais[3]->somLocal.loadSound("bat1.mp3");   // batalha
                    locais[4]->somLocal.loadSound("s1.mp3");     // santa catarina
                    locais[5]->somLocal.loadSound("cdm1.mp3");   // casa da musica
                    locais[6]->somLocal.loadSound("bol1.mp3");   // bolhão
                    locais[7]->somLocal.loadSound("r1.mp3");     // ribeira

                    bancos[0]->somBanco.loadSound("b1.mp3");
                    bancos[1]->somBanco.loadSound("b2.mp3");
                    bancos[2]->somBanco.loadSound("b3.mp3");
                    bancos[3]->somBanco.loadSound("b4.mp3");
                    bancos[4]->somBanco.loadSound("b5.mp3");
                    bancos[5]->somBanco.loadSound("b6.mp3");
                }

            }
        }

//TODO: verificar se o snippet a seguir é redundante

		/*else {

			for (int i = 0; i < nLocais; i++) {
                locais[i]->on = false;
                locais[i]->localOn = false;
                locais[i]->draw();
            }

			for (int i = 0; i < nBancos; i++) {
                bancos[i]->on = false;
                bancos[i]->bancoOn = false;
                bancos[i]->draw();
            }
        }*/
    }

    if (ajudaDesajuda.inside(event.x, event.y)) {
        help = !help;
    }
}

