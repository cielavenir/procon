#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<pair<double,double> > course;
	{
		string line;
		getline(cin,line);
		istringstream ss(line);
		for(double dist,angle;ss>>dist>>angle;)course.push_back(make_pair(dist,angle));
	}

	vector<pair<double,int> >cars;
	//加速度 = (加速後速度-加速前速度)/時間
	//距離 = 加速前速度*時間 + 加速度*時間*時間/2
	{
		int number;
		double mph,timeaccel,timebreak;
		for(;cin>>number>>mph>>timeaccel>>timebreak;){
			double mps=mph/3600,T=0,prevangle=180;
			for(int i=0;i<course.size();i++){
				double timeaccel1=timeaccel*(prevangle)/180;
				double timebreak1=timebreak*(course[i].second)/180;
				double accel1=timeaccel1 ? (mps-mps*(180-prevangle)/180)/timeaccel1 : 0;
				double break1=timebreak1 ? (mps*(180-course[i].second)/180-mps)/timebreak1 : 0;
				double distaccel1=mps*(180-prevangle)/180*timeaccel1 + accel1*timeaccel1*timeaccel1/2;
				double distbreak1=mps*timebreak1 + break1*timebreak1*timebreak1/2;
				double t=(course[i].first-distaccel1-distbreak1)/mps;
				T+=t+timeaccel1+timebreak1;
				prevangle=course[i].second;
			}
			cars.push_back(make_pair(T,number));
		}
	}
	sort(cars.begin(),cars.end());
	for(int i=0;i<cars.size();i++){
		printf("%d %.2f\n",cars[i].second,cars[i].first);
	}
}