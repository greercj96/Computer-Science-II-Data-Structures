#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	int i = 0;                  //Initialize counter 
	
	cin >> n;                       //Read number of elements from user 
	int userArray[n];

	while (i < n) {
		std::cin >> userArray[i];     //Read user input 'n' number of times 
		i++;
	}

	int r = n - 1;                   //Initialize reverse counter 
	while (r >= 0){
		std::cout << userArray[r] << " ";    //Print array elements in reverse 
		r--;								
	}
	return 0;
}
