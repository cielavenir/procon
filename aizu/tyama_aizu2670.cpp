#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int> section;
section read(){
	int x,y,z,w;
	scanf("%02d:%02d-%02d:%02d",&x,&y,&z,&w);
	return make_pair(x*60+y,z*60+w);
}
void read_merge(vector<section>&s){
	int N;
	for(scanf("%d",&N);N--;)s.push_back(read());
}
int main(){
	int r=0,i;
	vector<section> ti,teacher,student;
	read_merge(ti);
	for(scanf("%d",&r);r--;)read_merge(teacher);
	for(scanf("%d",&r);r;--r)read_merge(student);
	for(int i=0;i<ti.size();i++){
		int a=0,b=0;
		for(int j=0;j<teacher.size();j++)a+=teacher[j].first<=ti[i].first&&ti[i].second<=teacher[j].second;
		for(int j=0;j<student.size();j++)b+=student[j].first<=ti[i].first&&ti[i].second<=student[j].second;
		r+=min(a,b);
	}
	printf("%d\n",r);
}