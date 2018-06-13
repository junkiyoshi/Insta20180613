#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofDrawCircle(ofPoint(), 51);

	int radius_span = 20;
	int deg_span = 5;
	for (int radius = 50; radius < 500; radius += radius_span) {

		for (int deg = 0; deg < 360; deg += deg_span) {

			float noise_value = ofNoise(radius * 0.0005 - ofGetFrameNum() * 0.005, deg * 0.05);
			if (noise_value > 0.6) {

				ofBeginShape();
				for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg += 1) {

					ofVertex(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD));
				}

				for (int tmp_deg = deg + deg_span; tmp_deg >= deg; tmp_deg -= 1) {

					ofVertex((radius + radius_span) * cos(tmp_deg * DEG_TO_RAD), (radius + radius_span) * sin(tmp_deg * DEG_TO_RAD));
				}
				ofEndShape(true);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}