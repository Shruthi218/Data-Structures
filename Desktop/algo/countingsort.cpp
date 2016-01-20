#include <vector>
#include "countingsort.h"

std::vector<int> countSort(std::vector<int> &A, int k) {

	int n = A.size();
	std::vector<int> C(k, 0);
	std::vector<int> B(n);
	for (int i = 0; i < n; i++)
		C[A[i]]++;
	for (int i = 1; i < k; i++)
		C[i] += C[i-1];
	for (int i = n-1; i >= 0; i--)
		B[--C[A[i]]] = A[i];

	return B;
}

