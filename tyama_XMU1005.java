import java.util.*;

class Main{
  public static ArrayList<Integer> l;
  public static int n;
  public static void p(){
    int i=0;

    IN: while(true){
      OUT:{
        if(l.size()==n){
          for(int x=0;x<n;x++){
            if(x>0)System.out.print(" ");
            System.out.print(l.get(x)+1);
          }
          System.out.println("");
          break OUT;
        }
        for(;i<n;i++){
          if(l.indexOf(i)==-1){
            l.add(i);
            i=0;
            continue IN;
          }
        }
        if(l.size()==0)return;
      }
      i=l.remove(l.size()-1)+1;
    }
  }

  public static void main(String []args){
    n=new Scanner(System.in).nextInt();
    l=new ArrayList<Integer>();
    p();
  }
}