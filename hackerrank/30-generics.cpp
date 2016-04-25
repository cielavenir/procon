#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(const vector<T>& v){for(auto &e:v)cout<<e<<endl;}

int main() {
	vector<int> vInt{1, 2, 3};
	vector<string> vString{"Hello", "World"};

	printArray<int>(vInt);
	printArray<string>(vString);

	return 0;
}