#include <cstdio>
#include <vector>
std::vector<std::vector<int> >v(3);
void output(){
	for(int i=0;i<3;i++){
		printf("%c",i+65);
		for(int j=0;j<v[i].size();j++)printf(" %d",v[i][j]);
		puts("");
	}
	puts("");
}
void hanoi(int n,int a,int b,int c){
	if(!n)return;
	hanoi(n-1,a,c,b);
	v[b].push_back(*v[a].rbegin());
	v[a].pop_back();
	output();
	hanoi(n-1,c,b,a);
}
int main(){
	int n,i;scanf("%d",&n);
	for(i=n;i;i--)v[0].push_back(i);
	output();
	hanoi(n,0,2,1);
}