import java.util.*;
class Main{
  public static void main(String[]z){
    char []p;
    String t;
    Scanner x=new Scanner(System.in);
    int i,m=0,n=x.nextInt();x.nextLine();
    for(;m<n;){
      p=x.nextLine().toCharArray();t=x.nextLine();
      for(i=0;i<p.length;i++)
        if(p[i]!=32)p[i]=t.charAt(p[i]-65);
      System.out.println(++m+" "+new String(p));
    }   
  }
}