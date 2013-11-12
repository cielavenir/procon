import java.io.*;
import java.util.*;

class Main{
  public static Scanner cin;
  public static int Rails(int n){
    ArrayList<Integer> l=new ArrayList<Integer>();
    int i=1,x=cin.nextInt(),c=0;
    if(x==0)return -1;
    for(;i<=n;i++){
      l.add(i);
      while(l.size()>0&&l.get(l.size()-1)==x){l.remove(l.size()-1);c++;if(c==n)return 0;x=cin.nextInt();}
    }
    //for(c++;c<n;c++)cin.nextInt();
    cin.nextLine();
    return 1;
  }
  public static void main(String []args){
    cin=new Scanner(System.in);
    int n=cin.nextInt();
    while(n!=0){
      while(true){
        int r=Rails(n);
        if(r==-1)break;
        if(r==0)System.out.println("Yes");
        if(r==1)System.out.println("No");
      }
      System.out.println("");
      n=cin.nextInt();
    }
  }
}