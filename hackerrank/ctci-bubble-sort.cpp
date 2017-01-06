#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,r=0;
	cin >> n;
	vector<int> a(n);
	for(int a_i = 0;a_i < n;a_i++){
	   cin >> a[a_i];
	}

	for (int i = 0; i < n; i++) {
		// Track number of elements swapped during a single array traversal
		int numberOfSwaps = 0;
	
		for (int j = 0; j < n - 1; j++) {
			// Swap adjacent elements if they are in decreasing order
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				numberOfSwaps++;
				r++;
			}
		}
	
		// If no elements were swapped during a traversal, array is sorted
		if (numberOfSwaps == 0) {
			break;
		}
	}
	printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n",r,a[0],a[n-1]);
	return 0;
}
