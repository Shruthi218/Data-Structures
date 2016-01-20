#include <vector>
#include "insertionsort.h"

std::vector<int> insertSort(std::vector<int> &A) {
	int i, key;
	std::vector<int> vec(A);
	for(int j = 2; j<vec.size(); j++) {
		key = vec[j];
		i = j - 1;
		while ( i > 0 && vec[i] > key ) {
			vec[i+1] = vec[i];
			i = i - 1;
		}
		vec[i+1] = key;
	}
	return vec;

}
