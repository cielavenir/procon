#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

short h(vector<int> &id){
	short r=0,i=0;
	for(;i<6;i++)r=r*6+id[i];
	return r;
}

// http://www.prefield.com/algorithm/misc/dice.html
enum FACE { TOP, LEFT, FRONT, BACK, RIGHT, BOTTOM }; ///
class dice {
public:
  dice(vector<int>&v):id(v) {}
  void roll_x() { roll(TOP, BACK, BOTTOM, FRONT); }
  void roll_x2() { roll(TOP, FRONT, BOTTOM, BACK); }
  void roll_y() { roll(TOP, LEFT, BOTTOM, RIGHT); }
  void roll_y2() { roll(TOP, RIGHT, BOTTOM, LEFT); }
  void roll_z() { roll(FRONT, RIGHT, BACK, LEFT); }
  void roll_z2() { roll(FRONT, LEFT, BACK, RIGHT); }
  void all_rolls(set<short>&s){
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        s.insert(h(id));
  }
  vector<int> id;
private:
  void roll(FACE a, FACE b, FACE c, FACE d) {
    int tmp = id[a];
    id[a] = id[b]; id[b] = id[c];
    id[c] = id[d]; id[d] = tmp;
  }
};

int main(){
	map<char,int>m;
	m['R']=0,m['Y']=1,m['B']=2,m['M']=3,m['G']=4,m['C']=5;
	string str;
	vector<int>v(6);
	int n,i,j,r;
	for(;cin>>n,n;){
		set<short>s;
		for(r=i=0;i<n;i++){
			for(j=0;j<6;j++)cin>>str,v[j]=m[str[0]];
			if(s.find(h(v))!=s.end())r++;
			else{
				dice d(v);
				d.all_rolls(s);
			}
		}
		cout<<r<<endl;
	}
}