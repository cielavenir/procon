//You should use ArrayList<String> for a in HNU.
import java.io.*;
import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner(System.in);
    int c=0,i,j;
    for(;cin.hasNext();){
      c++;
      List a=new ArrayList();
      for(;;){
        String s=cin.next();
        if(s.equals("9"))break;
        a.add(s);
      }

      fail:{

        for(i=0;i<a.size()-1;i++){
          for(j=i+1;j<a.size();j++){
            String s1=(String)a.get(i),s2=(String)a.get(j);
            if(s1.length()<s2.length()){
              if(s1.equals(s2.substring(0,s1.length()))){break fail;}
            }else{
              if(s2.equals(s1.substring(0,s2.length()))){break fail;}
            }
          }
        }

        System.out.println("Set "+c+" is immediately decodable");
        continue;

      }//fail
      System.out.println("Set "+c+" is not immediately decodable");
    }
  }
}