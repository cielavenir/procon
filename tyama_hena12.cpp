//http://qiita.com/Nabetani/items/f3cca410428f90333e28
//http://nabetani.sakura.ne.jp/hena/ord12rotdice/
#include <iostream>
#include <string>
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
private:
	void roll(FACE a, FACE b, FACE c, FACE d){
		int tmp = id[a];
		id[a] = id[b]; id[b] = id[c];
		id[c] = id[d]; id[d] = tmp;
	}
	int id[6];
};

int main(){
	string line;
	for(;getline(cin,line);){
		dice di(1,5,4,3,2,6);
		cout<<1;
		for(int i=0;i<line.size();cout<<di[TOP],i++){
			if(line[i]=='N')di.roll_north();
			if(line[i]=='E')di.roll_east();
			if(line[i]=='W')di.roll_west();
			if(line[i]=='S')di.roll_south();
		}
		cout<<endl<<flush;
	}
}