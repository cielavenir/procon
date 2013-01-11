//yama070423lcd.c 070423
//CÇæÇ∆if(a)bÇ!a||bÇÃÇÊÇ§Ç…ÇÕèëÇØÇ»Ç¢ÇÒÇ≈Ç∑ÇÀ...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void print_top(char c, char bar){
 for(; bar; bar--){
  switch(c){
   case '0':
   case '2':
   case '3':
   case '5':
   case '6':
   case '7':
   case '8':
   case '9':
    printf("-");continue;
   case '1':
   case '4':
    printf(" ");continue;
  }
 }
}

inline void print_center(char c, int bar){
 for(; bar; bar--){
  switch(c){
   case '2':
   case '3':
   case '4':
   case '5':
   case '6':
   case '8':
   case '9':
    printf("-");continue;
   case '0':
   case '1':
   case '7':
    printf(" ");continue;
  }
 }
}

inline void print_bottom(char c, int bar){
 for(; bar; bar--){
  switch(c){
   case '0':
   case '2':
   case '3':
   case '5':
   case '6':
   case '8':
   case '9':
    printf("-");continue;
   case '1':
   case '4':
   case '7':
    printf(" ");continue;
  }
 }
}

inline void print_tleft(char c){
 switch(c){
  case '0':
  case '4':
  case '5':
  case '6':
  case '8':
  case '9':
   printf("|");return;
  case '1':
  case '2':
  case '3':
  case '7':
   printf(" ");return;
 }
}

inline void print_bleft(char c){
 switch(c){
  case '0':
  case '2':
  case '6':
  case '8':
   printf("|");return;
  case '1':
  case '3':
  case '4':
  case '5':
  case '7':
  case '9':
   printf(" ");return;
 }
}

inline void print_tright(char c){
 switch(c){
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '7':
  case '8':
  case '9':
   printf("|");return;
  case '5':
  case '6':
   printf(" ");return;
 }
}

inline void print_bright(char c){
 switch(c){
  case '0':
  case '1':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
   printf("|");return;
  case '2':
   printf(" ");return;
 }
}

int main(){
 char i,j,k,len,bar,nums[9]; //max 99999999
 int _bar;
 
 while(1){
  //input
  scanf("%d %s", &_bar, nums);
  bar=(char)_bar;
  if(!bar) return 0; //end, because nums is valid only when bar!=0.
  len=strlen(nums);
  
  for(i=0; i<len; i++){
   printf(" ");
   print_top(*(nums+i),bar);
   printf(" ");
   if(i!=len-1)printf(" ");
  }
  printf("\n");
  for(j=0; j<bar; j++){
   for(i=0; i<len; i++){
    print_tleft(*(nums+i));
	for(k=0; k<bar; k++)
	 printf(" ");
	print_tright(*(nums+i));
	if(i!=len-1)printf(" ");
   }
   printf("\n");
  }
  for(i=0; i<len; i++){
   printf(" ");
   print_center(*(nums+i),bar);
   printf(" ");
   if(i!=len-1)printf(" ");
  }
  printf("\n");
  for(j=0; j<bar; j++){
   for(i=0; i<len; i++){
    print_bleft(*(nums+i));
	for(k=0; k<bar; k++)
	 printf(" ");
	print_bright(*(nums+i));
    if(i!=len-1)printf(" ");
   }
   printf("\n");
  }
  for(i=0; i<len; i++){
   printf(" ");
   print_bottom(*(nums+i),bar);
   printf(" ");
   if(i!=len-1)printf(" ");
  }
  printf("\n\n"); //with blank
 }
}