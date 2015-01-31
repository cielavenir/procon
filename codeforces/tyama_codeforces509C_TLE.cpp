#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int compare(vector<int>&a,vector<int>&b){
	if(a.size()>b.size())return -1;
	if(a.size()<b.size())return 1;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i])return -1;
		if(a[i]<b[i])return 1;
	}
	return 0;
}

int main(){
	vector<int> cur;
	int prevn=0;
	int T;scanf("%d",&T);
	for(int t=0;t<T;t++){
		int n;scanf("%d",&n);
		int _digits=cur.size();
		int d=n/9,r=n%9;
		vector<int>a;
		int digits=max(_digits,(r==0?0:1)+d);
		//if(n<prevn)digits++;
		int z=digits-((r==0?0:1)+d);
		for(int i=0;i<z;i++)a.push_back(0);
		if(r!=0)a.push_back(r);
		for(int i=0;i<d;i++)a.push_back(9);
		int idx;
		for(idx=0;idx<digits&&a[idx]==0;idx++);
		a[0]++;
		a[idx]--;
		for(;;){
			if(compare(cur,a)==1){
				for(int i=0;i<a.size();i++)putchar(a[i]+'0');
				puts("");
				cur=a;
				prevn=n;
				break;
			}
			int idx_down,idx_up=-1;
			for(idx_down=digits-1;idx_down>=0&&a[idx_down]==0;idx_down--);
			if(idx_down!=0){
				for(idx_up=idx_down-1;idx_up>=0&&a[idx_up]==9;idx_up--);
			}
			if(idx_up>=0){
				a[idx_down]--;
				a[idx_up]++;
				reverse(a.begin()+idx_up+1,a.end());
			}else{
				digits++;
				d=(n-1)/9;r=(n-1)%9;
				z=digits-(1+(r==0?0:1)+d);
				a.clear();
				a.push_back(1);
				for(int i=0;i<z;i++)a.push_back(0);
				if(r!=0)a.push_back(r);
				for(int i=0;i<d;i++)a.push_back(9);
			}
		}
	}
}