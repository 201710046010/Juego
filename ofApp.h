#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofPoint p1 = ofPoint(980, 500);
		ofPoint p2 = ofPoint(960, 530);
		ofPoint p3 = ofPoint(1000, 530);
		//ofPoint p1, p2, p3;
		int x;
		int y;
		float dx;
		float dy;
		ofPoint translation( float dx, float dy, ofPoint p);
		ofPoint rotation(double theta, ofPoint p);
		ofPoint scaling(float sx, float sy, ofPoint p);
		void warmachine();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
