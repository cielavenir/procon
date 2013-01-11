//2005 Domestic A
import java.io.*;
import java.util.*;
class Main{
  public static Scanner cin;
  public static int parse(int m, int y){
    int t,c,dm=0;
    double r;
    t=cin.nextInt();r=cin.nextDouble();c=cin.nextInt();
    if(t!=0){
      for(;y!=0;y--){
        dm=(int)(r*m);
        m+=dm-c;
      }
    }else{
       for(;y!=0;y--){
         dm=dm+(int)(r*m);
         m-=c;
       }
       m+=dm;
    }
    return m;
}

  public static void data(){
    int m,y,n,r,x;
    r=m=cin.nextInt();y=cin.nextInt();n=cin.nextInt();
    for(;n!=0;n--){
      x=parse(m,y);
      if(x>r)r=x;
    }
    System.out.println(r);
  }

  public static void main(String args[]){
    cin=new Scanner(System.in);
    int n=cin.nextInt();
    for(;n!=0;n--)data();
  }
}