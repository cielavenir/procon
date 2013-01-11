//PKU1917
import java.util.*;
import java.util.regex.*;

class Main{
  public static Scanner cin;
  public static Pattern pattern;
  public static Matcher matcher;

  public static Matcher m(String s, String p){
    pattern = Pattern.compile(p);
    matcher = pattern.matcher(s);
    if(!matcher.matches())return null;
    return matcher;
  }

  public static void main(String[] args){
    cin=new Scanner(System.in);
    int n=cin.nextInt();
    cin.nextLine();
    for(;n!=0;n--){
      String s1=cin.nextLine(), s2=cin.nextLine();
      Matcher m1=m(s1,"(.*)\\<(.*)\\>(.*)\\<(.*)\\>(.*)"), m2=m(s2,"(.*)\\s?\\.\\.\\.");
      System.out.print(
        m1.group(1)+m1.group(2)+m1.group(3)+m1.group(4)+m1.group(5)+"\n"+
        m2.group(1)+m1.group(4)+m1.group(3)+m1.group(2)+m1.group(5)+"\n");
    }
  }
}