#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
	vector<pair<double,double> > course;
	{
		string line;
		getline(cin,line);
		istringstream ss(line);
		for(double dist,angle;ss>>dist>>angle;)course.push_back(make_pair(dist,angle));
	}

	vector<pair<double,int> >cars;
	{
		int number;
		double mph,start,end,prevangle=180;
		for(;cin>>number>>mph>>start>>end;){
			double mps=mph/3600,T=0;
			for(int i=0;i<course.size();i++){
				double start2=start*sqrt((prevangle)/180);
				double end2=end*sqrt((course[i].second)/180);
				double t=course[i].first/mps-start2/2.9-end2/2.9;
				T+=t+start2+end2;
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