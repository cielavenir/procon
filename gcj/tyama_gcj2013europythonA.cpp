#include <iostream>
#include <string>
#include <vector>
using namespace std;

int insertion_sort(vector<string> &a){
	int r=0;
	int N=a.size();
	int i,j;
	for(i=1;i<N;i++){
		string t = a[i];
		if(a[i-1]>t){
			r++;
			j=i;
			do{
				a[j] = a[j-1];
				j--;
			}while(j>0 && a[j-1]>t);
			a[j] = t;
		}
	}
	return r;
}
int main(){
	int t=1,T,N;
	for(cin>>T;t<=T;t++){
		cin>>N;
		vector<string>a(N);
		getline(cin,a[0]);
		for(int i=0;i<N;i++)getline(cin,a[i]);
		cout<<"Case #"<<t<<": "<<insertion_sort(a)<<endl;
	}
}