#include <libstree.h>
#include <stdio.h>
#define lst_string_fromstr(s) lst_string_new(s,1,strlen(s))
char k[999];
int z(LST_Node *node, void *data){
	if(lst_node_is_root(node))return 1;
	LST_String *s1=lst_node_get_string(node,0);
	const char *p1=lst_string_print(s1);
	if(!strcmp(p1,"<eos>"))return 1;
	strcpy(k,p1);
	puts(p1+lst_node_get_string_length(lst_node_get_parent(node)));
	return 1;
}
main(){
	scanf("%s",k);
	LST_STree tree;
	lst_stree_init(&tree);
	lst_stree_add_string(&tree,lst_string_fromstr(k));
	lst_alg_dfs(&tree,z,NULL);
}