import java.util.*;
class Main{
  public static void main(String[]z){
    int t=0,u=0,i=0,j=0;
    Scanner x=new Scanner(System.in);
    for(;x.hasNext();t=u=i=j=0){
      String s=x.nextLine();
      for(;(t=s.indexOf("IOI",t))!=-1;t+=2)i++;
      for(;(u=s.indexOf("JOI",u))!=-1;u+=3)j++;
      System.out.println(j+"\n"+i);
    }
  }
}