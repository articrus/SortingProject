#include "ofApp.h"
#include <random>
/*
 * Written by: Gianni Coladonato 
 * ID: 2414537
 * Assignment 1, 03-02-2025
*/

//--------------------------------------------------------------
void ofApp::setup(){
	generateRadii(); //Generates the first set of random radii
}

//--------------------------------------------------------------
void ofApp::update(){

}

//-Draws the circles, their raduis determened by the radii vector, and draw their numbers/size on top of them
void ofApp::draw(){
	for (int i = 0; i < radii.size(); i++) {
		ofSetColor(0,255,0);
		ofDrawCircle(ofGetWidth() * (i+1)/6, ofGetHeight()/2, radii[i]);
		ofSetColor(255, 255, 255);
		ofDrawBitmapString(radii[i], ofGetWidth() * (i + 1) / 6, ofGetHeight() / 2);
	}
}

//-Handle user input
void ofApp::keyPressed(int key){
	key = std::tolower(key); //R and r are viewed as different keys
	switch (key) {
	case 'r': generateRadii(); break;
	case 'b': bubbleSort(radii); break;
	case 'i': insertionSort(radii); break;
	case 'm': mergeSort(radii, 0, radii.size() - 1); break;
	case 'q': quickSort(radii, 0, radii.size() - 1); break;
	//optional FISHER-YATES case 's': break;
	}
}

//-Generates a random number between the min and maximum and returns it
int ofApp::generateRandNum(int min, int max) {
	std::random_device rd; //The random object
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> range(min, max); //Setting the bounds
	return range(gen);
}

//-Empties the vector and generates 5 numbers between 10-100 to fill the list
void ofApp::generateRadii() {
	radii.clear();
	for (int i = 0; i < 5; i++) { radii.push_back(generateRandNum(minRadius, maxRadius)); } //Generate new numbers in bounds
}

//-Sorts the vector using the bubble sort alhorithm
void ofApp::bubbleSort(vector<int>& nums) 
{
	int n = nums.size() - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++)
		{
			if (nums[j] > nums[j + 1]) { swap(nums[j], nums[j + 1]); }
		}
	}
}

//-Sorts the vector using the insertion sort algorithm
void ofApp::insertionSort(vector<int>& nums) 
{
	int n = nums.size();
	for (int i = 1; i < n; ++i) {
		int current = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > current)
		{
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = current;
	}
}

//-The merge aspect of the merge algorithm
void ofApp::merge(vector<int>& nums, int left, int mid, int right) 
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	//To hold the values we sort
	vector<int> Left(n1), Right(n2);
	for (int i = 0; i < n1; i++) {
		Left[i] = nums[left + i];
	}
	for (int j = 0; j < n2; j++) {
		Right[j] = nums[mid + 1 + j];
	}
	int i = 0, j = 0;
	int k = left;
	//Merge values from vectors back into main vector
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) {
			nums[k] = Left[i];
			i++;
		}
		else {
			nums[k] = Right[j];
			j++;
		}
		k++;
	}
	//Add elements if there are any extra
	while (i < n1) {
		nums[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		nums[k] = Right[j];
		j++;
		k++;
	}
}

//-The main function of the merge algorithm (divide and conquer)
void ofApp::mergeSort(vector<int>& nums, int left, int right) 
{
	if (left >= right) { return; } //If
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid); //Left side
	mergeSort(nums, mid + 1, right); //Right side
	merge(nums, left, mid, right);
}

//-The partition made when using the quicksort algorithm
int ofApp::partition(vector<int>& nums, int left, int right) {
	int middle = nums[right];
	int i = left - 1;
	
	for (int j = left; j <= right - 1; j++) {
		if (nums[j] <= middle) {
			i++;
			swap(nums[i], nums[j]);
		}
	}

	swap(nums[i + 1], nums[right]);
	return (i + 1);
}

//-The main quicksort algorithm
void ofApp::quickSort(vector<int>& nums, int left, int right)
{
	if (left < right) {
		int partIndex = partition(nums, left, right);
		quickSort(nums, left, partIndex - 1); //Left
		quickSort(nums, partIndex + 1, right); //Right
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