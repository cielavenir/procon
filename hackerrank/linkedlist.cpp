#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void Print(Node *head){if(head)cout<<head->data<<endl,Print(head->next);}

Node* Insert(Node *head,int data){
	Node *add=new Node();
	add->data=data;
	add->next=NULL;
	if(!head)return add;
	Node *ret=head;
	for(;head->next;)head=head->next;
	head->next=add;
	return ret;
}

Node* InsertHead(Node *head,int data){
	Node *add=new Node();
	add->data=data;
	add->next=head;
	return add;
}

Node* InsertNth(Node *head, int data, int position){
	Node *add=new Node();
	add->data=data;
	if(!position){
		add->next=head;
		return add;
	}
	Node *ret=head;
	for(int i=0;i<position-1;i++)head=head->next;
	add->next=head->next;
	head->next=add;
	return ret;
}

Node* Delete(Node *head, int position){
	if(!position)return head->next;
	Node *ret=head;
	for(int i=0;i<position-1;i++)head=head->next;
	head->next=head->next->next;
	return ret;
}

void ReversePrint(Node *head){if(head)ReversePrint(head->next),cout<<head->data<<endl;}

Node* Reverse(Node *head){
	if(head->next){
		Node *ret=Reverse(head->next);
		Node *next=head->next;
		next->next=head;
		head->next=NULL;
		return ret;
	}else{
		return head;
	}
}

int CompareLists(Node *headA, Node* headB){
	if(!headA&&!headB)return 1;
	if(!headA||!headB||headA->data!=headB->data)return 0;
	return CompareLists(headA->next,headB->next);
}

Node* MergeLists(Node *headA, Node* headB){
	if(!headA)return headB;
	if(!headB)return headA;
	Node *ret=headA->data<headB->data ? headA : headB;
	Node *next;
	for(;headA&&headB;){
		if(headA->data<headB->data){
			for(;headA->next&&headA->next->data<headB->data;)headA=headA->next;
			next=headA->next;
			headA->next=headB;
			headA=next;
		}else{
			for(;headB->next&&headB->next->data<headA->data;)headB=headB->next;
			next=headB->next;
			headB->next=headA;
			headB=next;
		}
	}
	return ret;
}

int GetNode(Node *head,int positionFromTail){
	Node *_head=head;
	int i=-1;
	for(head=_head;head;i++)head=head->next;
	i-=positionFromTail;
	for(head=_head;i--;)head=head->next;
	return head->data;
}

Node* RemoveDuplicates(Node *head){
	if(!head)return head;
	Node *ret=head;
	for(;head->next;)if(head->data==head->next->data)head->next=head->next->next;else head=head->next;
	return ret;
}

int HasCycle(Node* head){
	const int N=9999;
	for(int i=0;head&&i<N;i++)head=head->next;
	return !!head;
}

int FindMergeNode(Node *headA, Node *headB){
	int a=0,b=0;
	for(Node *z=headA;z;a++)z=z->next;
	for(Node *z=headB;z;b++)z=z->next;
	for(;a>b;a--)headA=headA->next;
	for(;a<b;b--)headB=headB->next;
	for(;headA->data!=headB->data;)headA=headA->next,headB=headB->next;
	return headA->data;
}

int main(){}