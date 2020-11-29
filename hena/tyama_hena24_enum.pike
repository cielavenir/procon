#!/usr/bin/env pike

typedef function(mixed|void, function(mixed|void...:void)|void:int) F;

int isqrt(int n){
  if(n<=0)return 0;
  if(n<4)return 1;
  int x=0;
  int y=n;
  for(;x!=y&&x+1!=y;){
    x=y;
    y=(n/y+y)/2;
  }
  return x;
}

int icbrt(int n){
  if(n<0)return -icbrt(-n);
  if(n==0)return 0;
  if(n<8)return 1;
  int x=0;
  int y=n;
  for(;x!=y&&x+1!=y;){
    x=y;
    y=(n/y/y+y*2)/3;
  }
  return x;
}

continue int generate(){
  int i=0;
  i++;
  for(;;){
    auto _=yield(i);
    i++;
  }
}

continue int drop_prev(function(int:bool) check, function(mixed|void, function(mixed|void...:void)|void:int) prev){
  int a=prev();
  int b=prev();
  for(;;){
    if(!check(b))auto _2=yield(a);
    a=b;
    b=prev();
  }
}

continue int drop_next(function(int:bool) check, F|void prev){
  int a=prev();
  int b=prev();
  auto _1=yield(a);
  for(;;){
    if(!check(a))auto _2=yield(b);
    a=b;
    b=prev();
  }
}

continue int drop_n(function(int,int:bool) check, int n, function(mixed|void, function(mixed|void...:void)|void:int) prev){
  int i=0;
  for(;;){
    i++;
    int a=prev();
    if(!check(i,n))auto _2=yield(a);
  }
}

bool is_sq(int n){return isqrt(n)**2==n;}
bool is_cb(int n){return icbrt(n)**3==n;}
bool is_multiple(int i, int n){return i%n==0;}
bool is_le(int i, int n){return i<=n;}

F f_S(F prev){return drop_next(is_sq,prev);}
F f_s(F prev){return drop_prev(is_sq,prev);}
F f_C(F prev){return drop_next(is_cb,prev);}
F f_c(F prev){return drop_prev(is_cb,prev);}
F f_h(F prev){return drop_n(is_le,100,prev);}
F f_2(F prev){return drop_n(is_multiple,2,prev);}
F f_3(F prev){return drop_n(is_multiple,3,prev);}
F f_4(F prev){return drop_n(is_multiple,4,prev);}
F f_5(F prev){return drop_n(is_multiple,5,prev);}
F f_6(F prev){return drop_n(is_multiple,6,prev);}
F f_7(F prev){return drop_n(is_multiple,7,prev);}
F f_8(F prev){return drop_n(is_multiple,8,prev);}
F f_9(F prev){return drop_n(is_multiple,9,prev);}

int main(int argc, array(string) argv){
  mapping(int:function(F:F)) m=([
    'S':f_S,
    's':f_s,
    'C':f_C,
    'c':f_c,
    'h':f_h,
    '2':f_2,
    '3':f_3,
    '4':f_4,
    '5':f_5,
    '6':f_6,
    '7':f_7,
    '8':f_8,
    '9':f_9,
  ]);
  for(;string s=Stdio.stdin.gets();){
    F z=generate();
    foreach(s; int i; int c){
      z=m[c](z);
    }
    for(int i=0;i<10;i++){
      if(i)Stdio.stdout.write(",");
      int k=z();
      Stdio.stdout.write(sprintf("%d",k));
    }
    Stdio.stdout.write("\n");
    //Stdio.stdout.flush(); // not buffered
  }
}
