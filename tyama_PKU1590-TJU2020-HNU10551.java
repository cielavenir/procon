import java.io.*;
import java.util.*;
import java.util.regex.*;

class Main{
  public static Scanner cin;
  public static Pattern pattern;
  public static Matcher matcher;

  public static String g(String s, String s1, String s2){
    pattern = Pattern.compile(s1);
    matcher = pattern.matcher(s);
    return matcher.replaceAll(s2);
  }

  public static String r(int i){
    switch(i){
      case 0: return "not a palindrome";
      case 1: return "a regular palindrome";
      case 2: return "a mirrored string";
      default: return "a mirrored palindrome";
    }
  }

  public static String mirror(String _s){
    String s=_s;
    s=g(s,"[BCDFGKNPQR4679]","/");
    if(-1!=s.indexOf('/'))return "";

    s=g(s,"E","/E");
    s=g(s,"J","/J");
    s=g(s,"L","/L");
    s=g(s,"S","/S");
    s=g(s,"Z","/Z");
    s=g(s,"2","/2");
    s=g(s,"3","/3");
    s=g(s,"5","/5");
    s=g(s,"/E","3");
    s=g(s,"/J","L");
    s=g(s,"/L","J");
    s=g(s,"/S","2");
    s=g(s,"/Z","5");
    s=g(s,"/2","S");
    s=g(s,"/3","E");
    s=g(s,"/5","Z");
    return s;
  }

  public static void parse(){
    int i=0;
    String s=cin.next(),t=new StringBuffer(s).reverse().toString();
    if(s.equals(t))i+=1;
    if(s.equals(mirror(t)))i+=2;
    System.out.print(s+" -- is "+r(i)+".\n\n");
  }

  public static void main(String[] args){
    cin=new Scanner(System.in);
    while(cin.hasNext())parse();
  }
}