import java.io.*;
import java.util.*;

class Main{
  public static String output;

  public static boolean match(String s1, String s2){
    return s1.length() < s2.length() ? s1.equals(s2.substring(0,s1.length())) : s2.equals(s1.substring(0,s2.length()));
  }

  public static boolean matchall(Map m,String s){
    Iterator iterator = m.entrySet().iterator();
    while(iterator.hasNext()){
      Map.Entry entry=(Map.Entry)iterator.next();
      if(match((String)entry.getValue(), s))return true;
    }
    return false;
  }

  public static boolean dehuff(Map m,String s,String b,int cs,int cb){
    if(cs>=s.length() || cb>=b.length()) return false;
    char c=s.charAt(cs);
    if(m.containsKey(c)){
      String b0=(String)m.get(c);
      int i0=b0.length();
      if(cb+i0>b.length())return false;
      if(b.substring(cb,cb+i0).equals(b0)){
        if(cs==s.length()-1&&cb+i0==b.length()){
          //set up output
          Iterator iterator = (new TreeMap(m)).entrySet().iterator();
          while(iterator.hasNext()){
            Map.Entry entry=(Map.Entry)(iterator.next());
            output+=String.format("%c = %s\n",entry.getKey(),entry.getValue());
          }
          return true;
        }
        return dehuff(m,s,b,cs+1,cb+i0);
      }
      return false;
    }

    int k=0;
    for(int i=cb+1;i<=b.length();i++){
      String x=b.substring(cb,i);
      if(!matchall(m,x)){
        m.put(c,x);
        //System.out.println(c+" "+x);
        if(cs==s.length()-1&&i==b.length()){
          //set up output
          Iterator iterator = (new TreeMap(m)).entrySet().iterator();
          while(iterator.hasNext()){
            Map.Entry entry=(Map.Entry)(iterator.next());
            output+=String.format("%c = %s\n",entry.getKey(),entry.getValue());
          }
          return true;
        }
        if(dehuff(m,s,b,cs+1,i)){
          //return true;
          if(k==1)return false;k++;//計算量を急上昇させている元凶。
          //PCは、S=s.length()-1、B=b.length()とすると、最悪(S+B)!/S!B!回計算しなければならない^^;
        } 
        m.remove(c);
      }
    }
    return k==1;
  }

  public static void main(String[] args){
    Scanner cin=new Scanner(System.in);
    int n=cin.nextInt();cin.nextLine();
    for(int i=1;i<=n;i++){
      output="";
      System.out.println("DATASET #"+i);

      String s=cin.nextLine(),b=cin.nextLine();
      Map m=new HashMap();
      if(!dehuff(m,s,b,0,0)){
        System.out.println("MULTIPLE TABLES");
        continue;
      }
      System.out.print(output);
    }
  }
}