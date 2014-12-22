#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 6
template<typename T>
bool my_next_permutation(vector<T> &a,int n){
	if(n<0||a.size()<n)return false;
	int i;
	reverse(a.begin()+n,a.begin()+a.size());
	for(i=a.size()-2;i>=0;i--)if(a[i]<a[i+1])break;
	if(i<0){
		reverse(a.begin(),a.begin()+a.size());
		return false;
	}
	int k=i;
	for(i=a.size()-1;i>=k+1;i--)if(a[k]<a[i])break;
	int l=i;
	T z=a[k];a[k]=a[l];a[l]=z;
	reverse(a.begin()+k+1,a.begin()+a.size());
	return true;
}
template<typename T>
bool my_next_permutation(vector<T> &a){return my_next_permutation(a,a.size());}
int main(){
	int r=0,i;
	vector<int>e0(N*2),f0(N*2);
	for(i=0;i<N;i++)e0[N+i]=f0[N+i]=1;
	do{
		do{
			int flg=0;
			int zero1=0;
			int zero2=N;
			int one1=0;
			int one2=N;
			for(i=0;i<N*2;i++){
				if(e0[i]==0)zero1++;
				if(e0[i]==1)one1++;
				if(f0[N*2-1-i]==0)zero2--;
				if(f0[N*2-1-i]==1)one2--;
				if(zero1==zero2)flg++;
				if(one1==one2)flg++;
			}
			if(flg>=2)r++;
		//}while(my_next_permutation(f0));
		}while(next_permutation(f0.begin(),f0.end()));
	//}while(my_next_permutation(e0));
	}while(next_permutation(e0.begin(),e0.end()));
	printf("%d\n",r);
}