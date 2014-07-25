#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0,0,0);
	ofEnableAntiAliasing();
	ofSetWindowTitle("Lucky Stars");

	ofSetFrameRate(60);

	starID = 0;

	switch (starID){
    case 0:
        star = new SoundStar("stems/synth.wav", 2048);
        star->x = ofGetWidth() * 0.5;
        star->y = ofGetHeight() * 0.5;
        break;
	}

}

//--------------------------------------------------------------
void ofApp::update(){
    star->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    star->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'q'){
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
void ofApp::exit(ofEventArgs &args){
    ofSoundShutdown();
}
