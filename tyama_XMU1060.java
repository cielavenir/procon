import java.util.*;
import java.util.regex.*;
class Main{
  public static Pattern pattern;
  public static Matcher matcher;

  public static Matcher a(String s, String p){
    pattern = Pattern.compile(p);
    matcher = pattern.matcher(s);
    if(!matcher.matches())return null;
    return matcher;
  }

  public static void main(String []args){
    int n,y,o,d,h,m,s;
    Scanner cin=new Scanner(System.in);
    n=cin.nextInt();
    Matcher x=a(cin.next(),"([0-9]+)-([0-9]+)-([0-9]+)");
    y=Integer.parseInt(x.group(1));
    o=Integer.parseInt(x.group(2));
    d=Integer.parseInt(x.group(3));
    x=a(cin.next(),"([0-9]+):([0-9]+):([0-9]+)");
    h=Integer.parseInt(x.group(1));
    m=Integer.parseInt(x.group(2));
    s=Integer.parseInt(x.group(3));
    GregorianCalendar c=new GregorianCalendar(y,o-1,d,h,m,s);c.add(Calendar.SECOND,n);
    System.out.printf("%d-%02d-%02d %02d:%02d:%02d\n",
      c.get(Calendar.YEAR),c.get(Calendar.MONTH)+1,c.get(Calendar.DAY_OF_MONTH),
      c.get(Calendar.HOUR_OF_DAY),c.get(Calendar.MINUTE),c.get(Calendar.SECOND));
  }
}