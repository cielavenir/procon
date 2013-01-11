import java.util.*;
import java.lang.reflect.Array;

class Main{
  public static int totable(int i){return (i-1)/2;}
  public static void main(String []args){
    Scanner cin=new Scanner(System.in);
    int i,j;
    int table[]=new int[3];
    int count[]=new int[3];
    List<Integer> queue[]=new List[3]; //(List<Integer>[])Array.newInstance(new LinkedList<Integer>().getClass(), 3);
    for(i=0;i<3;i++)queue[i]=new LinkedList<Integer>();
    while(true){
      table[0]=cin.nextInt();table[1]=cin.nextInt();table[2]=cin.nextInt();
      if(table[0]==0)break;
      count[0]=count[1]=count[2]=0;
      queue[0].clear();queue[1].clear();queue[2].clear();
      for(i=0;i<3;i++)
        for(j=0;j<table[i];j++)
          queue[i].add(0);
      while(true){
        String stime=cin.next();
        if(stime.equals("#")){
          System.out.println(count[0]+count[1]+count[2]);
          cin.nextLine();break;
        }
        int time=new Integer(stime.substring(0,2))*60+new Integer(stime.substring(3,5));
        int num=cin.nextInt(), t=totable(num);
        while(queue[t].size()>0 && queue[t].get(0)<time){queue[t].remove(0);}
        int seat=queue[t].size()<table[t]?time:queue[t].get(queue[t].size()-table[t]);
        if(seat<=time+30 && seat<=23*60-30){queue[t].add(seat+30);count[t]+=num;}
      }
    }
  }
}