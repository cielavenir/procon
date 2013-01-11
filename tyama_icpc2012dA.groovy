#!/usr/bin/groovy
Scanner cin=new Scanner(System.in);
int y,m,d;
for(y=cin.nextInt();cin.hasNext();println(196471-(--y)*195-y.intdiv(3)*5-(--m)*20+(y%3!=2?m.intdiv(2):0)-d)){y=cin.nextInt();m=cin.nextInt();d=cin.nextInt();}