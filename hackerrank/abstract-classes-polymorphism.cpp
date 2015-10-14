#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

/*
struct Node{
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
	Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
protected: 
	map<int,Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function
};
*/

#include <deque>
class LRUCache{
public:
	deque<pair<int,int> >v;
	int cp;
	LRUCache(const int &x){cp=x;}
	int get(int x){
		for(int i=0;i<v.size();i++)if(v[i].first==x)return v[i].second;
		return -1;
	}
	void set(int x,int y){
		int i=0;
		for(;i<v.size();i++)if(v[i].first==x){v.erase(v.begin()+i);break;}
		if(i==cp)v.pop_back();
		v.push_front(make_pair(x,y));
	}
};

int main() {
	int n, capacity,i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for(i=0;i<n;i++) {
		string command;
		cin >> command;
		if(command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if(command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key,value);
		}
	}
	return 0;
}
