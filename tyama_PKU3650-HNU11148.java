import java.util.*;
import java.util.regex.*;

class Main{
  public static Pattern pattern;
  public static Matcher matcher;

  public static String g(String s, String str1, String str2){
    pattern = Pattern.compile(str1);
    matcher = pattern.matcher(s);
    return matcher.replaceAll(str2);
  }

  public static void out(String s){
    s=g(s,"%","%25");
    s=g(s," ","%20");
    s=g(s,"!","%21");
    s=g(s,"\\$","%24");
    s=g(s,"\\(","%28");
    s=g(s,"\\)","%29");
    s=g(s,"\\*","%2a");
    System.out.println(s);
  }

  public static void main(String[] args){
    Scanner cin=new Scanner(System.in);
    String s;
    while(!(s=cin.nextLine()).equals("#"))out(s);
  }
}