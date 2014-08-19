#include <iostream>
#include <vector>
#include <set>
using namespace std;

// http://www.prefield.com/algorithm/misc/dice.html
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };
class dice {
public:
	dice(int top,int front,int right,int left,int back,int bottom) {
		id[TOP] = top; id[FRONT] = front; id[RIGHT] = right;
		id[LEFT] = left; id[BACK] = back; id[BOTTOM] = bottom;
	}
	int& operator[] (FACE f) { return id[f]; }
	const int& operator[] (FACE f) const { return id[f]; }
	bool operator==(const dice &b) const {
		const dice &a = *this;
		return a[TOP] == b[TOP] && a[BOTTOM] == b[BOTTOM] &&
			a[FRONT] == b[FRONT] && a[BACK] == b[BACK] &&
			 a[LEFT] == b[LEFT] && a[RIGHT] == b[RIGHT];
	}
	void roll_north() { roll(TOP, FRONT, BOTTOM, BACK); }
	void roll_south() { roll(TOP, BACK, BOTTOM, FRONT); }
	void roll_east() { roll(TOP, LEFT, BOTTOM, RIGHT); }
	void roll_west() { roll(TOP, RIGHT, BOTTOM, LEFT); }
	void roll_right() { roll(FRONT, LEFT, BACK, RIGHT); }
	void roll_left() { roll(FRONT, RIGHT, BACK, LEFT); }
	void all_rolls(set<long long> &s){
		for (int k = 0; k < 6; (k&1?roll_east():roll_north()),++k)
			for (int i = 0; i < 4; roll_right(), ++i)
				s.insert(((long long)id[TOP]<<40) | ((long long)id[FRONT]<<32) | (id[RIGHT]<<24) | (id[LEFT]<<16) | (id[BACK]<<8) | (id[BOTTOM]<<0));
	}
private:
	void roll(FACE a, FACE b, FACE c, FACE d){
		int tmp = id[a];
		id[a] = id[b]; id[b] = id[c];
		id[c] = id[d]; id[d] = tmp;
	}
	int id[6];
};

int main(){
	int n,d[6];
	cin>>n;
	int i,j;
	set<long long>s;
	for(i=0;i<n;i++){
		for(j=0;j<6;j++)cin>>d[j];
		long long x=((long long)d[0]<<40) | ((long long)d[1]<<32) | (d[2]<<24) | (d[3]<<16) | (d[4]<<8) | (d[5]<<0);
		if(s.find(x)!=s.end()){
			cout<<"No"<<endl;
			return 0;
		}else{
			dice di(d[0],d[1],d[2],d[3],d[4],d[5]);
			di.all_rolls(s);
		}
	}
	cout<<"Yes"<<endl;
}