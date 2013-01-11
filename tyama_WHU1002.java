import java.util.*;
import java.util.regex.*;

class Main{
  public static Pattern pattern;
  public static Matcher matcher;

  public static Matcher m(String s, String p){
    pattern = Pattern.compile(p);
    matcher = pattern.matcher(s);
    if(!matcher.matches())return null;
    return matcher;
  }

  public static void main(String[]a){
    Scanner cin=new Scanner(System.in);
    String ch=cin.next(),s;
    int i=0;
    while(cin.hasNext()){
      s=cin.next();
      if(s.equals(".")||s.equals(",")||s.equals(":")||s.equals(";"))continue;
      if(m(s,"[0-9]+:[0-9]+")!=null){
        System.out.println(ch+" "+i);
        ch=s;
        i=0;continue;
      }
      i++;
    }
    System.out.println(ch+" "+i);
  }
}