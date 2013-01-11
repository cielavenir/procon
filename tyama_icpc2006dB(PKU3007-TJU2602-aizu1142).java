//090710: Replaced HashMap with HashSet.
import java.io.*;
import java.util.*;
class Main{
  public static void main(String []args){
    Scanner cin=new Scanner(System.in);
    int j=0,n=cin.nextInt();
    cin.nextLine();
    for(;j<n;j++){
    String s=cin.nextLine();
    Set<String> m=new HashSet<String>();
    int i=1;
    for(;i<s.length();i++){
      String s1=s.substring(0,i),s2=s.substring(i),r1=new StringBuilder(s1).reverse().toString(),r2=new StringBuilder(s2).reverse().toString();
      m.add(s1+s2);
      m.add(r1+s2);
      m.add(s1+r2);
      m.add(r1+r2);
      m.add(s2+s1);
      m.add(r2+s1);
      m.add(s2+r1);
      m.add(r2+r1);
    }
    System.out.println(m.size());
    }
  }
}