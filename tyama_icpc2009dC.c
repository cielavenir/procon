/*
http://chaste.web.fc2.com/Reference.files/Algo.html
fukumen.c -- 覆面算 (slightly modified)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
enum {FALSE, TRUE};

#define N 15  /* 最大の行数 */

int imax, jmax, solution, digit[128], low[128], ok[N];
char word[N][16];
void found(void)  /* 解の表示 */
{
	int i, j, c;
	for (i = 0; i <= imax; i++){
		if(strlen(word[i])>1&&digit[word[i][strlen(word[i])-1]]==0)return;
	}
	++solution;
/*
	printf("\n解 %d\n", solution);
	for (i = 0; i <= imax; i++) {
		for (j = jmax; j >= 0; j--) {
			c = word[i][j];
			if (c != '\0') printf("%d", digit[c]);
			else           printf(" ");
		}
		printf("\n");
	}
*/
}

void try(int sum)  /* 再帰的に試みる */
{
	static int i = 0, j = 0, carry;
	int c, d;

	c = word[i][j];
	if (i < imax) {
		i++;
		if ((d = digit[c]) < 0) {  /* 定まっていないなら */
			for (d = low[c]; d <= 9; d++)
				if (ok[d]) {
					digit[c] = d;  ok[d] = FALSE;
					try(sum + d);  ok[d] = TRUE;
				}
			digit[c] = -1;
		} else try(sum + d);
		i--;
	} else {
		j++;  i = 0;  d = sum % 10;  carry = sum / 10;
		if (digit[c] == d) {
			if (j <= jmax) try(carry);
			else if (carry == 0) found();
		} else if (digit[c] < 0 && ok[d] && d >= low[c]) {
			digit[c] = d;  ok[d] = FALSE;
			if (j <= jmax) try(carry);
			else if (carry == 0) found();
			digit[c] = -1;  ok[d] = TRUE;
		}
		j--;  i = imax;
	}
}

int main()
{
	int i, j, k, c;
	char buffer[128];

	jmax = 0;
loop:
	//printf("行数? ");
	scanf("%d", &imax);
	if(!imax)return 0;
	imax--;
	memset(word,0,sizeof(word));
	memset(digit,0,sizeof(digit));
	//memset(low,0,sizeof(low));
	memset(ok,0,sizeof(ok));
	for (i = 0; i < N && i <= imax; i++) {
		//printf("%2d: ", i + 1);
		scanf("%s", buffer);
		//low[buffer[0]] = strlen(buffer)>1;
		k = strlen((char *)buffer) - 1;
		if (k > jmax) jmax = k;
		for (j = 0; j <= k; j++) {
			word[i][j] = c = buffer[k - j];
			if (isalpha(c)) digit[c] = -1;
			else if (isdigit(c)) digit[c] = c - '0';
		}
	}
	for (i = 0; i <= 9; i++) ok[i] = TRUE;
	solution = 0;  try(0);
	//if (solution == 0) printf("解はありません.\n");
	printf("%d\n",solution);
	goto loop;
}