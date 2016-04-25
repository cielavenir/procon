#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

void Preorder(node *root) {
	printf("%d ",root->data);
	if(root->left)Preorder(root->left);
	if(root->right)Preorder(root->right);
}

void Postorder(node *root) {
	if(root->left)Postorder(root->left);
	if(root->right)Postorder(root->right);
	printf("%d ",root->data);
}

void Inorder(node *root) {
	if(root->left)Inorder(root->left);
	printf("%d ",root->data);
	if(root->right)Inorder(root->right);
}

#include <queue>
void LevelOrder(node *root){
	queue<node*> q;
	if(root){
		q.push(root);
		while(!q.empty()){
			node *t = q.front();q.pop();
			printf("%d ",t->data);
			if(t->left){
				q.push(t->left);
			}
			if(t->right){
				q.push(t->right);
			}
		}
	}
}

int getHeight(node *root){
	if(!root)return -1;
	return 1+max(getHeight(root->left),getHeight(root->right));
}

void top_view_left(node *root){
	if(root){
		top_view_left(root->left);
		printf("%d ",root->data);
	}
}
void top_view_right(node *root){
	if(root){
		printf("%d ",root->data);
		top_view_right(root->right);
	}
}
void top_view(node *root){
	if(root){
		top_view_left(root->left);
		printf("%d ",root->data);
		top_view_right(root->right);
	}
}

int main(){}