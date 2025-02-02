#pragma once

#include "ofMain.h"
#include <vector>
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 1, 03-02-2025
*/
class ofApp : public ofBaseApp{

	public:
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
		int generateRandNum(int min, int max);
		void generateRadii();
		void bubbleSort(vector<int>& nums);
		void insertionSort(vector<int>& nums);
		//Used for Merge Sorting algorithm
		void merge(vector<int>& nums, int left, int mid, int right);
		void mergeSort(vector<int>& nums, int left, int right);
		//Used for Quick Sorting algorithm
		int partition(vector<int>& nums, int low, int high);
		void quickSort(vector<int>& nums, int low, int high);

		std::vector<int> radii;
		std::vector<float> circlePositions;
		int minRadius = 10;
		int maxRadius = 100;
		
};
