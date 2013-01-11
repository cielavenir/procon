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

  public static void main(String[] args){
    cin=new Scanner(System.in);
    while(true){
      String s=cin.nextLine();
      if(s.equals("THE END."))return;
      s=g(s,"[^a-zA-Z]","").toLowerCase();
      System.out.println(s.equals(new StringBuffer(s).reverse().toString())?"Yes":"No");
    }
  }
}