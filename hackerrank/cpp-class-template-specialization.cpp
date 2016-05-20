#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<typename T>
struct Traits{
	static string name(int n){return "unknown";};
};
template<>
struct Traits<Color>{
	static string name(int n){return n==0?"red":n==1?"green":n==2?"orange":"unknown";};
};
template<>
struct Traits<Fruit>{
	static string name(int n){return n==0?"apple":n==1?"orange":n==2?"pear":"unknown";};
};

int main()
{
	int t = 0; std::cin >> t;

	for (int i=0; i!=t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}
