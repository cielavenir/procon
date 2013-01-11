//tyama070508poker.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nr   0
#define suit 1
#define getnum(i) '2'<=(i) && (i)<='9' ? (i)-'0' : (i)=='T' ? 10 : (i)=='J' ? 11 : (i)=='Q' ? 12 : (i)=='K' ? 13 : 14 //A

int sort(const void *a, const void *b){return *((int*)a) - *((int*)b);}

int judge(char array[5][3]){
 int i;
 int n[5];
 int rank=0,val1=0,val2=0,val3=0,val4=0,val5=0;
 //val2-5 for high card, val2-4 for pair, val2-3 for twopair.

 for(i=0;i<5;i++)n[i]=array[i][nr];
 qsort(n, 5, sizeof(int), sort);

 //High card
 val1=n[4],val2=n[3],val3=n[2],val4=n[1],val5=n[0];

 //Pair
 if(n[3]==n[4]){
  rank=1;val1=n[4];
  val2=n[2];val3=n[1];val4=n[0];
  if(n[1]==n[2]){
   rank=2;val2=n[2];val3=n[0];
  }
  if(n[0]==n[1]){
   rank=2;val2=n[1];val3=n[2];
  }
  goto end_pair;
 }
 if(n[2]==n[3]){
  rank=1;val1=n[3];
  val2=n[4];val3=n[1];val4=n[0];
  if(n[0]==n[1]){
   rank=2;val2=n[1];val3=n[4];
  }
  goto end_pair;
 }
 if(n[1]==n[2]){
  rank=1;val1=n[2];
  val2=n[4];val3=n[3];val4=n[0];
  goto end_pair;
 }
 if(n[0]==n[1]){
  rank=1;val1=n[1];
  val2=n[4];val3=n[3];val4=n[2];
  //goto end_pair;
 }
 end_pair:

 //Three
 if(n[0]==n[1]&&n[1]==n[2]){
  rank=3;val1=n[2];
  if(n[3]==n[4]){
   rank=6;
   goto end;
  }
 }
 if(n[1]==n[2]&&n[2]==n[3]){
  rank=3;val1=n[3];
 }
 if(n[2]==n[3]&&n[3]==n[4]){
  rank=3;val1=n[4];
  if(n[0]==n[1]){
   rank=6;
   goto end;
  }
 }

 //Straight
 if(n[1]==n[0]+1&&n[2]==n[0]+2&&n[3]==n[0]+3&&n[4]==n[0]+4)rank=4;

 //Flush
 if(array[0][suit]==array[1][suit]&&array[0][suit]==array[2][suit]&&array[0][suit]==array[3][suit]&&array[0][suit]==array[4][suit]){
  if(rank==4)rank<<=1;//(^^;
  else rank=5;
  goto end;
 }

 //Four
 if(n[0]==n[1]&&n[1]==n[2]&&n[2]==n[3]){
  rank=7;val1=n[3];
 }else if(n[1]==n[2]&&n[2]==n[3]&&n[3]==n[4]){
  rank=7;val1=n[4];
 }

 end:
 if(rank!=5){//Be careful... Flush is ranked using "the rules for High Card".
  if(rank)val5=0;
  if(rank>1)val4=0;
  if(rank>2)val2=val3=0;
 }
 return (rank<<20)+(val1<<16)+(val2<<12)+(val3<<8)+(val4<<4)+val5; //really dirty!
}

int main(){
 char black[5][3],white[5][3]; //3 means nr,suit,\0 (^^;
 int rankb,rankw,i;

 begin:
  //input
  black[0][0]=0;
  scanf("%s %s %s %s %s %s %s %s %s %s",
   black[0],black[1],black[2],black[3],black[4],
   white[0],white[1],white[2],white[3],white[4]);
  if(!black[0][0]) return 0;
  for(i=0;i<5;i++){
   black[i][nr]=getnum(black[i][nr]);
   white[i][nr]=getnum(white[i][nr]);
  }
  
  rankb=judge(black);
  rankw=judge(white);
  printf( rankb==rankw ? "Tie.\n" : rankb>rankw ? "Black wins.\n" : "White wins.\n");
 goto begin;
}