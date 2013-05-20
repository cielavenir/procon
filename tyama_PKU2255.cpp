#include <iostream>
#include <string>
using namespace std;
string preorder,inorder;
void recover(int fp,int lp,int fi,int li){
	int root=fi;
	for(;root<li;root++)if(preorder[fp]==inorder[root])break;
	if(fi<root)recover(fp+1,fp+(root-fi)+1,fi,root);
	if(root<li-1)recover(fp+(root-fi)+1,lp,root+1,li);
	cout<<inorder[root];
}
int main(){
	for(;cin>>preorder>>inorder;cout<<endl)recover(0,preorder.size(),0,inorder.size());
}