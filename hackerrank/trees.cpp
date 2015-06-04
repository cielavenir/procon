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

int main(){}