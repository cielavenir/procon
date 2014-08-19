#include <libstree.h>
#include <stdio.h>
#define lst_string_fromstr(s) lst_string_new(s,1,strlen(s))
char k[99999];
long long N;
int z(LST_Node *node, void *data){
	if(lst_node_is_root(node))return 1;
	int x=lst_edge_get_length(node->up_edge);
	N+=x-lst_node_is_leaf(node); //what is this "1"? maybe terminal mark of leaf?
	return 1;
}
main(i,mul){
	long long n,d,p,j,x;
	scanf("%s",k);
	n=strlen(k);
	d=0;p=1;
	for(i=1;i<=n;i++){
		j=n+1-i;
		p*=4;
		if(p<j){
			d+=p;
		}else{
			d+=j*(j+1)/2;
			break;
		}
	}
	//printf("%lld\n",d);
	LST_STree tree;
	lst_stree_init(&tree);
	lst_stree_add_string(&tree,lst_string_fromstr(k));
	lst_alg_dfs(&tree,z,NULL);
	//printf("%lld\n",N);
	printf("%f\n",N*1.0/d); //N == sum of the length of all edges
}