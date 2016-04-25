#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
	private:
	vector<int> elements;
  	public:
	int maximumDifference;

	Difference(const vector<int> &a):elements(a){}
	void computeDifference(){maximumDifference=*max_element(elements.begin(),elements.end())-*min_element(elements.begin(),elements.end());}
	
}; // End of Difference class

int main() {
	int N;
	cin >> N;
	vector<int> a;
	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;
		a.push_back(e);
	}
	Difference d(a);
	d.computeDifference();
	cout << d.maximumDifference;
	return 0;
}