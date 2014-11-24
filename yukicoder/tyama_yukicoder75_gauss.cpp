#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

//derived from checkio expected-dice
//unfortunately TLE using Python, rewriting in C++11.

bool gauss(vector<vector<double> > &a){
	if(a.empty())return false;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(!a[i][i]){
			int j=i+1;
			for(;j<n;j++){
				if(a[j][i]){
					for(int k=i;k<=n;k++)a[i][k]+=a[j][k];
					break;
				}
			}
			if(j<n)return false;
		}
		for(int j=0;j<n;j++)if(i!=j){
			double r=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++)a[j][k]=a[j][k]-a[i][k]*r;
		}
	}
	for(int i=0;i<n;i++){
		double x=a[i][i];
		for(int j=0;j<a[i].size();j++)a[i][j]/=x;
	}
	return true;
}

double expected(int n, int s, int t){//vector<int> b){
	//perform checkio probably-dice
	vector<double> a(s*(n+1)+1);
	for(int i=1;i<=s;i++)a[i+s]=pow(1.0/s,n);
	for(int e=0;e<n-1;e++)for(int i=s*n;i>=0;i--){
		double sum=0;
		for(int j=i;j<i+s;j++)sum+=a[j];
		a[i+s]=sum;
	}
	int l=t+1; //b.size();
	vector<vector<double> > A(l);
	for(int i=0;i<l;i++){
		A[i].resize(l+1);
		A[i][i]=1;
		if(i!=t)A[i][l]=1;
	}
	for(int start=0;start<l;start++)if(start!=t){
		for(int roll=n;roll<=s*n;roll++){
			int end=roll+start;
			//end = (end + b[end%l])%l;
			if(end>=l)end=0;
			A[start][end]-=a[roll+s];
		}
	}
	gauss(A);
	return A[0][A[0].size()-1];
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%f\n",expected(1,6,N));
}