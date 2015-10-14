#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student{
	vector<int>a;
public:
	void Input(){
		for(int i=0;i<5;i++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
	}
	int CalculateTotalScore(){
		int r=0;
		for(int i=0;i<a.size();i++)r+=a[i];
		return r;
	}
};

int main() {
	int n;
	cin>>n;
	Student s[n];
	for(int i=0;i<n;i++)
		s[i].Input();
	int count=0;
	int krish_score=s[0].CalculateTotalScore();
	for(int i=1;i<n;i++){
		int total=s[i].CalculateTotalScore();
		if(total>krish_score)
			count++;
	}
	cout<<count;
	return 0;
}