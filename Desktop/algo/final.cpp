#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <sys/time.h>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <climits>

#include "insertionsort.h"
#include "heapsort.h"
#include "countingsort.h"

double rtclock()
{
	struct timezone Tzp;
	struct timeval Tp;
	int stat;
	stat = gettimeofday (&Tp, &Tzp);
	if (stat != 0) printf("Error return from gettimeofday: %d",stat);
	return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

int myrandom (int k) { return std::rand()%k;}

int main(int argc, char **argv) {

	std::srand ( unsigned ( std::time(0) ) );
	std::string file = argv[1];
	std::string line;
	std::unordered_multimap<int, std::string> mymap;
	std::ifstream myfile(file.c_str());
	std::vector<int> vec;
	while(getline(myfile,line)) {
	 	std::stringstream ss(line);
		int val;
		std::string str;
		ss >> val >> str;
		mymap.emplace(val, str);
		vec.push_back(val);
	}
	
	double start, end;
//	std::random_shuffle(vec.begin(), vec.end());
	auto maxIter = std::max_element(vec.begin(), vec.end());

	std::vector<int> res = insertSort(vec);
	for(int i = 0; i < res.size(); i++)
	        std::cout << res[i] << " " << mymap.find(res[i])->second << "\n";
	
	
	std::vector<int> heapres = heapSort(vec);

	std::vector<int> resc = countSort(vec, *maxIter); 


	return 0;

}
