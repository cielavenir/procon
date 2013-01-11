import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner cin=new Scanner(System.in);
    String enc="abcdefghijklmnopqrstuvwxyz";enc+=enc.toUpperCase();
    String dec=cin.nextLine();dec+=dec.toUpperCase();
    char []s=cin.nextLine().toCharArray();
    int i=0,j;
    for(;i<s.length;i++)
      if((j=enc.indexOf(s[i]))!=-1)
        s[i]=dec.charAt(j);
    System.out.print(s);
  }
}