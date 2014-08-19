#include <libstree.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define lst_string_fromstr(s) lst_string_new(s,1,strlen(s))
set<string>s1,s2,r;
int z(LST_Node *node, void *data){
	if(lst_node_is_leaf(node))return 1;
	if(!node->up_edge)return 1;
	LST_String *s_=lst_node_get_string(node,0);
	const char *p1=lst_string_print(s_);
	if(!strcmp(p1,"<eos>"))return 1;
	string s=p1;
	if(s.length()>=20){
		if(data){
			reverse(s.begin(),s.end());
			s2.insert(s);
		}else s1.insert(s);
	}
	return 1;
}
int main(){
	string s;
	cin>>s;
	{
		LST_STree tree;
		lst_stree_init(&tree);
		lst_stree_add_string(&tree,lst_string_fromstr(s.c_str()));
		lst_alg_dfs(&tree,z,(void*)0);
	}
	reverse(s.begin(),s.end());
	{
		LST_STree tree;
		lst_stree_init(&tree);
		lst_stree_add_string(&tree,lst_string_fromstr(s.c_str()));
		lst_alg_dfs(&tree,z,(void*)1);
	}
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(r,r.end()));
	set<string>::iterator it=r.begin();
	for(;it!=r.end();it++)cout<<*it<<endl;
}