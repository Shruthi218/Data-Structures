#include<vector>
#include<cmath>
#include "heapsort.h"

int getLeft(int i) {
	return (2*i+1);
}

int getRight(int i) {
	return (2 * i + 2);
}


void maxHeapify(std::vector<int> &vec, int i, int n) {
	int left = getLeft(i);
	int right = getRight(i);
	int largest;
	if ( left <= n && vec[left] > vec[i] )
		largest = left;
	else {
		largest = i;
	}
	if( right <= n && vec[right] > vec[largest] ) largest = right;
	if(largest != i) {
		std::swap(vec[i], vec[largest]);
		maxHeapify(vec, largest, vec.size());
	}
}

void buildHeap(std::vector<int> &vec, int n) {
	for(int i = floor(n/2); i >= 1; i--)
		maxHeapify(vec, i, n);
}

std::vector<int> heapSort(std::vector<int> &A) {
	int n = A.size() - 1;
	std::vector<int> vec(A);
	buildHeap(vec, n);
	for(int i = n; i >= 2; i--) {
		std::swap(vec[1], vec[i]);
		maxHeapify(vec, 1, i -1);
	}

	return vec;
}	
