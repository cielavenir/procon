//tyama_maja.c 070702

#include <stdio.h>

void solve(int i){
	int s=0, state=0, a=0, b=0, move;
	for(;s<i;a++)s+=a*6; //一辺の長さは6
	a--;move=s-i;

	//a: min(a) s.t. i<=(a, 0)
	//move: (a, 0)-i
	for(;move;move--){
		switch(state){
			case 0:
				b--;
				if(a==-1*b)state=1;
				break;
			case 1:
				a--;
				if(!a)state=2;
				break;
			case 2:
				a--;b++;
				if(!b)state=3;
				break;
			case 3:
				b++;
				if(a==-1*b)state=4;
				break;
			case 4:
				a++;
				if(!a)state=5;
				break;
			case 5:
				a++;b--;
				//if(!b)... 分岐が必要になる前にmoveが尽きると仮定する。
				break;
		}
	}
	printf("%d %d\n",a,b);
}

int main(){
	int i;
	begin:
		i=0;
		scanf("%d",&i);
		if(!i)return 0;
		if(i==1){ //solveを0開始にする
			printf("0 0\n");
			goto begin;
		}
		solve(i-1);
	goto begin;
}