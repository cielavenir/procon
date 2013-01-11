//‘S•”‚ ‚Á‚Ä‚é‚Ì‚ÉTLE‚Á‚Ä‚¢‚¤‚Ì‚Íˆê”Ô‚Â‚ç‚¢‚Å‚·B
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

  public static String parse(){
    String s=cin.next();

    s=g(s,"-","");
    s=g(s,"[ABC]","2");
    s=g(s,"[DEF]","3");
    s=g(s,"[GHI]","4");
    s=g(s,"[JKL]","5");
    s=g(s,"[MNO]","6");
    s=g(s,"[PRS]","7");
    s=g(s,"[TUV]","8");
    s=g(s,"[WXY]","9");
    return s.substring(0,3)+"-"+s.substring(3);
  }

  public static void main(String[] args){
    int n,i;
    Integer c;
    String s;
    Iterator iterator;
    Map map;
    Map.Entry entry;

    cin=new Scanner(System.in);
    n=cin.nextInt();

    map = new TreeMap();
    for(;n!=0;n--){
      s=parse();
      if( (c=(Integer)map.get(s))==null )c=0;
      map.put(s,c+1);
    }

    c=0;
    iterator = map.entrySet().iterator();
    while(iterator.hasNext()){
      entry=(Map.Entry)(iterator.next());
      if( (i=(Integer)(entry.getValue()))>1 ){
        System.out.printf(entry.getKey()+" "+i);
        c++;
      }
    }
    if(c==0)System.out.printf("No duplicates.\n");
  }
}