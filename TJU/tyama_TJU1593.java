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
    int i=1,n=cin.nextInt();
    cin.nextLine();
    for(;i<=n;i++){
      String s=cin.nextLine();
      Matcher m1=m(s,"(.*?)://([^:/]*?)(:[0-9]+?)?(/.+)?");
      String p=m1.group(1),h=m1.group(2),o=m1.group(3)!=null?m1.group(3).substring(1):"<default>",a=m1.group(4)!=null?m1.group(4).substring(1):"<default>";
      System.out.println(
        "URL #"+i+"\n"+
        "Protocol = "+p+"\n"+
        "Host     = "+h+"\n"+
        "Port     = "+o+"\n"+
        "Path     = "+a+"\n");
    }
  }
}