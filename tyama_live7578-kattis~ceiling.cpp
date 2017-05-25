#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

string shape(node *root){
	string s;
	if(root->left)s+='L',s+=shape(root->left);
	s+='N';
	if(root->right)s+='R',s+=shape(root->right);
	free(root);
	return s;
}

void insert(node *root,int n){
	if(!root->data){
		root->data=n;
	}else{
		if(n<root->data){
			if(!root->left)root->left=(node*)calloc(1,sizeof(node));
			insert(root->left,n);
		}else{
			if(!root->right)root->right=(node*)calloc(1,sizeof(node));
			insert(root->right,n);
		}
	}
}

int main(){
	int N,K,x;
	for(;~scanf("%d%d",&N,&K);){
		set<string>se;
		for(int i=0;i<N;i++){
			node *root=(node*)calloc(1,sizeof(node));
			scanf("%d",&root->data);
			for(int j=1;j<K;j++){
				scanf("%d",&x);
				insert(root,x);
			}
			se.insert(shape(root));
		}
		printf("%d\n",se.size());
	}
}