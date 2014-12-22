#include <stdio.h>
int *sp = NULL;
int func1() {
	sp = realloc(sp, sizeof(int)*2);
	return 1;
}
int main(void) {
	sp = malloc(sizeof(int)*1);
	*sp = 0;
	//*sp = func1();
	int ret=func1();*sp=ret;
	printf("*ret=%d\n", *sp);
	return 0;
}
/*
*sp = func1();において、実装によってはspがfunc1()実行前に評価されることがある。
よって、int ret=func1();*sp=ret;とすればよい。
また、後ろのspまで一気に評価する処理系もある(問題のコードはllvm-gcc-4.2ではsegmentation faultになる)ので、ある関数内でグローバル変数のポインタを変更する関数を呼ぶべきではない。
*/