#include "ofApp.h"
#include <math.h>  
using namespace std;

ofPoint ofApp::translation(float dx, float dy, ofPoint p) {
	float MatrA[3] = {p.x , p.y, 1};
	float Matr[3][3];
	float Res[3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; j++) {
			if (j == i) {
				Matr[i][j] = 1;
			}
			else if (j == 2 && i == 0) {
				Matr[i][j] = dx;
			}
			else if (j == 2 && i == 1) {
				Matr[i][j] = dy;
			}
			else {
				Matr[i][j] = 0;
			}
		}
	}

	int j = 0;

	for (short i = 0; i < 3; ++i) {
		for (short k = 0; k < 3; k++) {
			Res[j] += Matr[i][k] * MatrA[k];
		}
		j += 1;
	}
	ofPoint newPoint= ofPoint(Res[0], Res[1]);
	return newPoint;
}

ofPoint ofApp::rotation(double theta, ofPoint p) {
	float MatrA[3] = {p.x, p.y, 1 };
	float Matr[3][3];
	float Res[3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; j++) {
			if ((i == 0 && j == 0) || (i == 1 && j == 1)) {
				Matr[i][j] = cos(theta* PI/180.0);
			}
			else if (i == 1 && j == 0) {
				Matr[i][j] = sin(theta* PI / 180.0);
			}
			else if (i == 0 && j == 1) {
				Matr[i][j] = sin(theta* PI / 180.0)*-1;
			}
			else if (i == j) {
				Matr[i][j] = 1;
			}
			else {
				Matr[i][j] = 0;
			}
		}
	}
	int j = 0;

	for (short i = 0; i < 3; ++i) {
		for (short k = 0; k < 3; k++) {
			Res[j] += Matr[i][k] * MatrA[k];
		}
		j += 1;
	}
	ofPoint newPoint = ofPoint(Res[0], Res[1]);
	return newPoint;
}

ofPoint ofApp::scaling(float sx, float sy, ofPoint p) {
	float MatrA[3] = { p.x, p.y, 1 };
	float Matr[3][3];
	float Res[3] = {};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; j++) {
			if (j == i) {
				if (j == 0) {
					Matr[i][j] = sx;
				}
				else if (j == 1) {
					Matr[i][j] = sy;
				}
				else {
					Matr[i][j] = 1;
				}
			}
			else {
				Matr[i][j] = 0;
			}
		}
	}
	int j = 0;

	for (short i = 0; i < 3; ++i) {
		for (short k = 0; k < 3; k++) {
			Res[j] += Matr[i][k] * MatrA[k];
		}
		j += 1;
	}
	ofPoint newPoint = ofPoint(Res[0], Res[1]);
	return newPoint;
}

void ofApp::warmachine() {
	ofBackground(0, 0, 0); //Set white background
	ofSetColor(255, 255, 255); //Set black color
	ofTriangle(p1, p2, p3);

}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
}


//--------------------------------------------------------------
void ofApp::update(){
	 
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	warmachine();
	
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
		switch (key)
		{
			case ofKey::OF_KEY_LEFT:
			{
				p1 = translation(-10, 0, p1);
				p2 = translation(-10, 0, p2);
				p3 = translation(-10, 0, p3);
				draw();
				break;
			}
			case ofKey::OF_KEY_RIGHT:
			{
				p1 = translation(10, 0, p1);
				p2 = translation(10, 0, p2);
				p3 = translation(10, 0, p3);
				draw();
				break;
			}
			case ofKey::OF_KEY_UP:
			{
				p1 = translation(0, -10, p1);
				p2 = translation(0, -10, p2);
				p3 = translation(0, -10, p3);
				draw();
				break;
			}
			case ofKey::OF_KEY_DOWN:
			{
				p1 = translation(0, 10, p1);
				p2 = translation(0, 10, p2);
				p3 = translation(0, 10, p3);
				draw();
				break;
			}
			case ofKey::OF_KEY_BACKSPACE:
			{
				p1 = rotation(10, p1);
				p2 = rotation(10, p2);
				p3 = rotation(10, p3);
				draw();
				break;
			}
			case ofKey::OF_KEY_F1:
			{
				p1 = scaling(1.01, 1.01, p1);
				p2 = scaling(1.01, 1.01, p2);
				p3 = scaling(1.01, 1.01, p3);

				draw();
				break;
			}
			case ofKey::OF_KEY_F2:
			{
				p1 = scaling(0.99, 0.99, p1);
				p2 = scaling(0.99, 0.99, p2);
				p3 = scaling(0.99, 0.99, p3);

				draw();
				break;
			}
			case ofKey::OF_KEY_F3:
			{
				p1 = scaling(1.01, 1, p1);
				p2 = scaling(1.01, 1, p2);
				p3 = scaling(1.01, 1, p3);

				draw();
				break;
			}
			default:
				break;
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
