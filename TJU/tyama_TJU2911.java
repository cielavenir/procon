import java.util.*;
import java.util.regex.*;
class Main{
  public static Pattern pattern;
  public static Matcher matcher;
  public static String g(String s, String s1, String s2){
    pattern = Pattern.compile(s1);
    matcher = pattern.matcher(s);
    return matcher.replaceAll(s2);
  }

  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    HashMap m=new HashMap(20);
    int l=x.nextInt(),n=x.nextInt();
    for(;l>0;l--)m.put(x.next(),x.next());
    for(;n>0;n--){
      String s=x.next(),t;
      if(m.containsKey(s))System.out.println(m.get(s));
      else if(!(t=g(s,"([bcdfghklmnpqrstvwxz])y$","$1ies")).equals(s))System.out.println(t);
      else if(!(t=g(s,"(o|s|ch|sh|x)$","$1es")).equals(s))System.out.println(t);
      else System.out.println(s+"s");
    }
  }
}