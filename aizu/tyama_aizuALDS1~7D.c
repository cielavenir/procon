int preorder[40],inorder[40];
void recover(int fp,int lp,int fi,int li){
	int root=fi;
	for(;root<li;root++)if(preorder[fp]==inorder[root])break;
	if(fi<root)recover(fp+1,fp+(root-fi)+1,fi,root);
	if(root<li-1)recover(fp+(root-fi)+1,lp,root+1,li);
	printf(inorder[root]==preorder[0]?"%d\n":"%d ",inorder[root]);
}
main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",preorder+i);
	for(i=0;i<n;i++)scanf("%d",inorder+i);
	recover(0,n,0,n);
	return 0;
}