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
	case 'i': insertionSort(radii); break;
	case 'm': mergeSort(radii, 0, radii.size() - 1); break;
	case 'q': quickSort(radii, 0, radii.size() - 1); break;
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

//-Sorts the vector using the insertion sort alhorithm
void ofApp::insertionSort(vector<int>& nums) 
{
	int n = nums.size();
	for (int i = 1; i < n; ++i) {
		int cur = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > cur) 
		{
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = cur;
	}
}

void ofApp::merge(vector<int>& nums, int left, int mid, int right) 
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> Left(n1), Right(n2);
	for (int i = 0; i < n1; i++) {
		Left[i] = nums[left + i];
	}
	for (int j = 0; j < n2; j++) {
		Right[j] = nums[mid + 1 + j];
	}
	int i = 0, j = 0;
	int k = left;

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

void ofApp::mergeSort(vector<int>& nums, int left, int right) 
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

int ofApp::partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];
	int i = low - 1;
	
	for (int j = low; j <= high - 1; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}

	swap(nums[i + 1], nums[high]);
	return (i + 1);
}

void ofApp::quickSort(vector<int>& nums, int low, int high)
{
	if (low < high) {
		int partIndex = partition(nums, low, high);
		quickSort(nums, low, partIndex - 1);
		quickSort(nums, partIndex + 1, high);
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
