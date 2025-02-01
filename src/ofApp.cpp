#include "ofApp.h"
#include <random>
//--------------------------------------------------------------
void ofApp::setup(){
	generateRadii();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < radii.size(); i++) {
		ofDrawBitmapString(radii[i], 30 * i, 20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	key = std::tolower(key);
	switch (key) {
	case 'r': generateRadii(); break;
	case 'b': bubbleSort(radii); break;
	//INSERTION case 'i': generateRadii(); break;
	//MERGE case 'm': generateRadii(); break;
	//QUICK case 'q': generateRadii(); break;
	//optional FISHER-YATES case 's': generateRadii(); break;
	}
}

//-Generates a random number between the min and maximum and returns it
int ofApp::generateRandNum(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

//-Empties the vector and generates 5 numbers between 10-100 to fill the list
void ofApp::generateRadii() {
	radii.clear();
	for (int i = 0; i < 5; i++)
	{
		radii.push_back(generateRandNum(minRadius, maxRadius));
	}
}

//-Sorts the vector using the bubble sort alhorithm
void ofApp::bubbleSort(vector<int>& nums) {
	int n = nums.size() - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++)
		{
			if (nums[j] > nums[j + 1]) { swap(nums[j], nums[j + 1]); }
		}
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
