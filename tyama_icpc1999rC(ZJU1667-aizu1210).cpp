#include <iostream>
#include <string>
#include <vector>
using namespace std;

// http://www.prefield.com/algorithm/misc/dice.html
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };
class dice {
public:
  dice() {
    id[TOP] = 1; id[FRONT] = 2; id[LEFT] = 3;
    id[RIGHT] = 4; id[BACK] = 5; id[BOTTOM] = 6;
  }
  int& operator[] (FACE f) { return id[f]; }
  const int& operator[] (FACE f) const { return id[f]; }
  bool operator==(const dice &b) const {
    const dice &a = *this;
    return a[TOP] == b[TOP] && a[BOTTOM] == b[BOTTOM] &&
           a[FRONT] == b[FRONT] && a[BACK] == b[BACK] &&
           a[LEFT] == b[LEFT] && a[RIGHT] == b[RIGHT];
  }
  void roll_x() { roll(TOP, BACK, BOTTOM, FRONT); }
  void roll_x2() { roll(TOP, FRONT, BOTTOM, BACK); }
  void roll_y() { roll(TOP, LEFT, BOTTOM, RIGHT); }
  void roll_y2() { roll(TOP, RIGHT, BOTTOM, LEFT); }
  void roll_z() { roll(FRONT, RIGHT, BACK, LEFT); }
  void roll_z2() { roll(FRONT, LEFT, BACK, RIGHT); }
  vector<dice> all_rolls() {
    vector<dice> ret;
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        ret.push_back(*this);
    return ret;
  }
  bool equivalent_to(const dice& di) {
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        if (*this == di) return true;
    return false;
  }
private:
  void roll(FACE a, FACE b, FACE c, FACE d) {
    int tmp = id[a];
    id[a] = id[b]; id[b] = id[c];
    id[c] = id[d]; id[d] = tmp;
  }
  int id[6];
};

int main(){
	int n;
	string s;
	for(;cin>>n,n;){
		dice di;
		for(;n--;){
			cin>>s;
			if(s[0]=='n')di.roll_x();
			if(s[0]=='e')di.roll_y();
			if(s[0]=='w')di.roll_y2();
			if(s[0]=='s')di.roll_x2();
		}
		cout<<di[TOP]<<endl;
	}
}