#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node* SortedInsert(Node *head,int data){
	Node *add=new Node();
	add->data=data;
	add->prev=NULL;
	add->next=NULL;
	if(!head)return add;
	if(data<head->data){
		add->next=head;
		head->prev=add;
		return add;
	}
	Node *ret=head;
	for(;head&&head->data<data;)add->prev=head,head=head->next;
	if(head)head->prev=add;
	add->prev->next=add;
	add->next=head;
	return ret;
}

Node* Reverse(Node* head){
	if(!head)return head;
	Node *next,*prev;
	for(;head;){
		next=head->next;
		prev=head->prev;
		head->next=prev;
		head->prev=next;
		head=next;
	}
	return prev->prev;
}

int main(){}