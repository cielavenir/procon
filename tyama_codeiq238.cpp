#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct{
	int a,b,c;
}triany;

class TLLI{
	vector<triany>trianies;
	triany zero_triany;
protected:
//public:
	TLLI(){
		zero_triany.a=zero_triany.b=zero_triany.c=0;
		trianies.push_back(zero_triany);
		trianies.push_back(zero_triany);
	}
	int root_triany(){return 1;}
	int allocate_triany(){trianies.push_back(zero_triany);return trianies.size()-1;}
	void set_a(int id,int value){
		if(id<0||trianies.size()<=id)return;
		trianies[id].a=value;
	}
	void set_b(int id,int value){
		if(id<0||trianies.size()<=id)return;
		trianies[id].b=value;
	}
	void set_c(int id,int value){
		if(id<0||trianies.size()<=id)return;
		trianies[id].c=value;
	}
	int get_a(int id){
		if(id<0||trianies.size()<=id)return 0;
		return trianies[id].a;
	}
	int get_b(int id){
		if(id<0||trianies.size()<=id)return 0;
		return trianies[id].b;
	}
	int get_c(int id){
		if(id<0||trianies.size()<=id)return 0;
		return trianies[id].c;
	}
/*
	void setup_list(){
		int x=root_triany();
		int y=allocate_triany();
		int z=allocate_triany();
		set_a(x,31);
		set_b(x,41);
		set_c(x,y);
		set_a(y,59);
		set_b(y,26);
		set_c(y,z);
		set_a(z,53);
		set_b(z,58);
		set_c(z,0);
	}
	void print_list(){
		int t=root_triany();
		for(;t;t=get_c(t)){
			int a=get_a(t);
			int b=get_b(t);
			printf("%d,%d,",a,b);
		}
	}
*/
};

class DICTI: public TLLI{
public:
#if 0
	//version 1 O(N)
	void set_entry(int key,int value){
		int t=root_triany(),succ;
		for(;;t=succ){
			if(key==get_a(t)){
				set_b(t,value);
				return;
			}
			int succ=get_c(t);
			if(succ==0){
				succ=allocate_triany();
				set_a(succ,key);
				set_b(succ,value);
				set_c(t,succ);
				return;
			}
		}
	}
	int find_entry(int key){
		int t=root_triany(),succ;
		for(;;t=succ){
			if(key==get_a(t)){
				return get_b(t);
			}
			succ=get_c(t);
			if(succ==0)return 0;
		}
	}
#else
	//version 2 O(logN)
	int set_entry(int key,int value){
		key^=0x3141516;
		int t=root_triany();
		for(;get_c(t)!=0;){
			if(key<=get_a(t))
				t=get_b(t);
			else
				t=get_c(t);
		}
		if(get_a(t)==key)
			set_b(t,value);
		else{
			int leaf1=allocate_triany();
			int key1=get_a(t);
			int leaf2=allocate_triany();
			int key2=key;
			set_a(leaf1,key1);
			set_b(leaf1,get_b(t));
			set_a(leaf2,key2);
			set_b(leaf2,value);
			if(key1<=key2){ // insert right
				set_b(t,leaf1);
				set_c(t,leaf2);
			}else{ // insert left
				set_a(t,key2); // need to update node key
				set_b(t,leaf2);
				set_c(t,leaf1);
			}
		}
	}
	int find_entry(int key){
		key^=0x3141516;
		int t=root_triany();
		for(;get_c(t)!=0;){
			if(key<=get_a(t))
				t=get_b(t);
			else
				t=get_c(t);
		}
		if(get_a(t)==key)
			return get_b(t);
		else
			return 0;
	}
#endif
/*
	void sample_dicti(){
		int sum=0;
		set_entry(123,1);
		set_entry(456,2);
		set_entry(789,3);
		int n=find_entry(123);
		cout<<n<<endl; // => 1
		sum+=n;
		n=find_entry(999);
		cout<<n<<endl; // => 0
		sum+=n;
		n=find_entry(789);
		cout<<n<<endl; // => 3
		sum+=n;
		set_entry(456,90);
		n=find_entry(456);
		cout<<n<<endl; // => 90
		sum+=n;
		set_entry(456,6);
		n=find_entry(456);
		cout<<n<<endl; // => 6
		sum+=n;
		cout<<sum<<endl; // => 100
	}
*/
};

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}

int main(){
	DICTI dicti;
	string s;
	int sum=0;
	for(;getline(cin,s);){
		if(s[0]=='s'||s[0]=='f'){
			vector<string> a=split(s," ");
			if(a[0]=="s")dicti.set_entry(strtol(a[1].c_str(),NULL,10),strtol(a[2].c_str(),NULL,10));
			else sum+=dicti.find_entry(strtol(a[1].c_str(),NULL,10));
		}
	}
	cout<<sum<<endl; // 141421356 // 0.085s
}