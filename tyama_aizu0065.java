import java.util.*;
import java.io.*;
class Main{
  public static void main(String[]z){
    try{
      String s;
      Map<Integer,Integer> map=new TreeMap<Integer,Integer>();
      int id,mul=1;
      InputStreamReader y=new InputStreamReader(System.in);
      BufferedReader x=new BufferedReader(y);
      while((s=x.readLine())!=null){
        if(s.length()==0){mul=100;continue;}
        id=Integer.parseInt(new StringTokenizer(s,",").nextToken());
        map.put(id,mul+(map.containsKey(id)?map.get(id):0));
      }
      Iterator<Map.Entry<Integer,Integer>> it=map.entrySet().iterator();
      while(it.hasNext()){
        Map.Entry<Integer,Integer>m=it.next();
        int a=m.getValue()/100,b=m.getValue()%100;
        if(a>0&&b>0)System.out.println(m.getKey()+" "+(a+b));
      }
    }catch(Exception e){}
  }
}