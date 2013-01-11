//tyama070515flapjacks.cpp
//某Yz1ドゥル(死語)もSTL使ってますがUI部分はこの程度ですおw
//やっぱり携帯で書いたソースは汚いw

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define digit(n) ('0'<=(n)&&(n)<='9')
using namespace std;

void flip(char **array,char **sort,int siz,int n){
int i(0);char *p;
for(;i<n;i++)  (*sort)[i]=(*array)[i];
for(;i<siz;i++)(*sort)[i]=(*array)[(siz-1)-(i-n)];
p=*array;*array=*sort;*sort=p; //this is faster than free+malloc (^^;;;
}

int main(){
char str[902];
int len,i,j,k,n;
char *cakes=(char*)malloc(30);
char *sort=(char*)malloc(30);
vector<int> vec;

begin:
//初期化
i=j=k=0;
memset(cakes,0,30);
memset(sort,0,30);
//入力
if(!fgets(str,902,stdin)){
free(cakes);
free(sort);
return 0;
}
printf("%s",str); //str contains "\n".
do{
if(digit(str[j]))
 cakes[i]=cakes[i]*10+(str[j]-'0');
else if(cakes[i])
 i++;
j++;
}while(str[j]&&str[j]!='\r'&&str[j]!='\n');
i++; //i==ケーキの数
//逆転
flip(&cakes,&sort,i,0);
//降順ソート
for(n=100;n;n--){
 for(j=k;j<i;j++){
  if(cakes[j]==n){
   if(j>k){ //if j==k, no sort is needed.
    if(j<i-1){
     flip(&cakes,&sort,i,j);
     vec.push_back(j+1);
    }
    flip(&cakes,&sort,i,k);
    vec.push_back(k+1);
   }
   k++;break;
  }
 }
}
//出力
while(vec.size()){
printf("%d ",vec.front());
vec.erase(vec.begin());
}
printf("0\n");
goto begin;
}