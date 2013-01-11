import java.io.*;
import java.util.*;
import java.util.regex.*;

class Main{
  public static Scanner cin;
  public static Pattern pattern;
  public static Matcher matcher;

  public static String g(String s, String str1, String str2){
    pattern = Pattern.compile(str1);
    matcher = pattern.matcher(s);
    return matcher.replaceAll(str2);
  }

  public static void parse(){
    int i=1,n;
    String s=cin.next();

    s=g(s,"[BFPV]","1");
    s=g(s,"[CGJKQSXZ]","2");
    s=g(s,"[DT]","3");
    s=g(s,"L","4");
    s=g(s,"[MN]","5");
    s=g(s,"R","6");
    s=g(s,"1+","1");
    s=g(s,"2+","2");
    s=g(s,"3+","3");
    s=g(s,"4+","4");
    s=g(s,"5+","5");
    s=g(s,"6+","6");
    s=g(s,"[AEIOUHWY]","");

    System.out.println(s);
  }

  public static void main(String[] args){
    cin=new Scanner(System.in);
    while(cin.hasNext())parse();
  }
}