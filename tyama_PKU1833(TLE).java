//based on progcons/report1/permutation_o.java

import java.util.*;
class Main{
  public static ArrayList<Integer> l;
  public static int n,k;
  public static void p(){
    int i=1;

    IN: while(true){
      OUT:{
        if(l.size()==n){
          k--;
          if(k<0){
            for(int x=0;x<n;x++){
              if(x>0)System.out.print(" ");
              System.out.print(l.get(x));
            }
            System.out.println("");
            return;
          }
          break OUT;
        }
        for(;i<=n;i++){
          if(l.indexOf(i)==-1){
            l.add(i);
            i=1;
            continue IN;
          }
        }
        if(l.size()==0)return;
      }
      i=l.remove(l.size()-1)+1;
    }
  }

  public static void main(String[]z){
    Scanner cin=new Scanner(System.in);
    int x=cin.nextInt(),i;
    for(;x>0;x--){
      n=cin.nextInt();k=cin.nextInt();
      l=new ArrayList<Integer>();
      for(i=1;i<=n;i++)l.add(cin.nextInt());
      p();
      if(k>=0){
        for(i=1;i<=n;i++)l.add(i);
        p();
      }
    }
  }
}