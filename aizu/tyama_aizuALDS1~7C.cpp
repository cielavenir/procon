#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
map<int,vector<int>>H;
void preorder(int node){
	printf(" %d",node);
	for(auto &e:H[node])if(e!=-1)preorder(e);
}
void inorder(int node){
	auto &children=H[node];
	if(children.size()>=1&&children[0]!=-1)inorder(children[0]);
	printf(" %d",node);
	if(children.size()>=2&&children[1]!=-1)inorder(children[1]);
}
void postorder(int node){
	for(auto &e:H[node])if(e!=-1)postorder(e);
	printf(" %d",node);
}
int main(){
	int N,a,b,c;
	scanf("%d",&N);
	set<int>roots;
	for(int i=0;i<N;i++)roots.insert(i);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&a,&b,&c);
		H[a].push_back(b),roots.erase(b);
		H[a].push_back(c),roots.erase(c);
	}
	int root=*roots.begin();
	puts("Preorder");
	preorder(root);puts("");
	puts("Inorder");
	inorder(root);puts("");
	puts("Postorder");
	postorder(root);puts("");
}
