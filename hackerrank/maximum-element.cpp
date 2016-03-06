#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main(){
	vector<int>st;
	multiset<int>se;
	int N,C;
	scanf("%d",&N);
	for(;N--;){
		scanf("%d",&C);
		if(C==1){
			scanf("%d\n",&C);
			se.insert(C);
			st.push_back(C);
		}else if(C==2){
			C=*st.rbegin();
			se.erase(se.find(C));
			st.pop_back();
		}else{
			printf("%d\n",*se.rbegin());
		}
	}
}