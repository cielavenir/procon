#include <stdio.h>
#include <string.h>

// http://www.prefield.com/algorithm/misc/dice.html
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };
class dice {
public:
	void assign(int top,int front,int right,int left,int back,int bottom){
		id[TOP] = top; id[FRONT] = front; id[RIGHT] = right;
		id[LEFT] = left; id[BACK] = back; id[BOTTOM] = bottom;
	}
	dice(int top,int front,int right,int left,int back,int bottom){
		assign(top,front,right,left,back,bottom);
	}
	dice(int top,int front,int right){
		assign(top,front,right,7-right,7-front,7-top);
	}
	dice(int top,int front,bool righthand){
		int right=0;
		if(top==1){
			if(front==2)right=3;
			if(front==3)right=5;
			if(front==5)right=4;
			if(front==4)right=2;
		}else if(top==2){
			if(front==1)right=4;
			if(front==4)right=6;
			if(front==6)right=3;
			if(front==3)right=1;
		}else if(top==3){
			if(front==1)right=2;
			if(front==2)right=6;
			if(front==6)right=5;
			if(front==5)right=1;
		}else if(top==4){
			if(front==1)right=5;
			if(front==5)right=6;
			if(front==6)right=2;
			if(front==2)right=1;
		}else if(top==5){
			if(front==1)right=3;
			if(front==3)right=6;
			if(front==6)right=4;
			if(front==4)right=1;
		}else if(top==6){
			if(front==2)right=4;
			if(front==4)right=5;
			if(front==5)right=3;
			if(front==3)right=2;
		}

		if(!righthand)right=7-right;
		assign(top,front,right,7-right,7-front,7-top);
	}

	const int& operator[](FACE f) const{return id[f];}
	bool operator==(const dice &b) const{
		const dice &a = *this;
		return a[TOP] == b[TOP] && a[BOTTOM] == b[BOTTOM] &&
			a[FRONT] == b[FRONT] && a[BACK] == b[BACK] &&
			 a[LEFT] == b[LEFT] && a[RIGHT] == b[RIGHT];
	}
	void roll_north() {roll(TOP, FRONT, BOTTOM, BACK);}
	void roll_south() {roll(TOP, BACK, BOTTOM, FRONT);}
	void roll_east()  {roll(TOP, LEFT, BOTTOM, RIGHT);}
	void roll_west()  {roll(TOP, RIGHT, BOTTOM, LEFT);}
	void roll_right() {roll(FRONT, LEFT, BACK, RIGHT);}
	void roll_left()  {roll(FRONT, RIGHT, BACK, LEFT);}
private:
	void roll(FACE a, FACE b, FACE c, FACE d){
		int tmp = id[a];
		id[a] = id[b]; id[b] = id[c];
		id[c] = id[d]; id[d] = tmp;
	}
	int id[6];
};

int M[200][200];
int P[200][200];
int R[7];
int main(){
	int N;
	for(;scanf("%d",&N),N;){
		memset(M,0,sizeof(M));
		memset(P,0,sizeof(P));
		memset(R,0,sizeof(R));
		for(;N--;){
			int top,front;
			scanf("%d%d",&top,&front);
			dice di(top,front,true);
			int x=100,y=100;
			for(;;){
				int ma=3,idx;
				if(di[FRONT]>ma && P[y+1][x]<P[y][x])ma=di[FRONT],idx=0;
				if(di[BACK]>ma && P[y-1][x]<P[y][x])ma=di[BACK],idx=1;
				if(di[LEFT]>ma && P[y][x-1]<P[y][x])ma=di[LEFT],idx=2;
				if(di[RIGHT]>ma && P[y][x+1]<P[y][x])ma=di[RIGHT],idx=3;
				if(ma==3)break;
				if(idx==0)y++,di.roll_south();
				if(idx==1)y--,di.roll_north();
				if(idx==2)x--,di.roll_west();
				if(idx==3)x++,di.roll_east();
			}
			P[y][x]++;
			R[M[y][x]]--,M[y][x]=di[TOP],R[M[y][x]]++;
		}
		for(int i=1;i<=6;i++)printf(i<6?"%d ":"%d\n",R[i]);
	}
}