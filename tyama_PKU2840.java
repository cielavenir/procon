import java.io.*;
import java.util.*;
class Main{
  public static void main(String[]a){
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int n,x,y;
    try{
      n=Integer.parseInt(br.readLine());
      for(;n>0;n--){
        StringTokenizer st=new StringTokenizer(br.readLine(),":");
        x=Integer.parseInt(st.nextToken());
        y=Integer.parseInt(st.nextToken());
        if(y!=0){System.out.println("0");continue;}
        System.out.println((x+11)%24+1);
      }
    }catch(Exception e){}
  }
}