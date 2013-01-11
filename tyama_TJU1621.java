import java.util.*;

class Main{
  public static int mday(int i,int y){
    int []md={31,28,31,30,31,30,31,31,30,31,30,32};
    return i==1&&new GregorianCalendar().isLeapYear(y) ? 29 : md[i];
  }
    
  public static void main(String[]a){
    String []month={"January","February","March","April","May","June","July","August","September","October","November","December"};
    String []day  ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int m,d,y;
    Scanner cin=new Scanner(System.in);
    while(true){
      m=cin.nextInt();d=cin.nextInt();y=cin.nextInt();
      if(m==0)break;m--;
      if(!(-1<m&&m<12 && 0<d&&d<=mday(m,y)) || (y==1752&&m==8&&2<d&&d<14)){
        System.out.println((m+1)+"/"+d+"/"+y+" is an invalid date.");
        continue;
      }
      GregorianCalendar c=new GregorianCalendar(y,m,d);
      int i=c.get(Calendar.DAY_OF_WEEK)-1;
      if((y<1752)||(y==1752&&m<8)||(y==1752&&m==8&&d<3))i-=3;
      //if((y<1700)||(y==1700&&m<1)||(y==1700&&m==1&&d<29))i-=1;
      if((y<1600)||(y==1600&&m<1)||(y==1600&&m==1&&d<29))i-=1;
      if(i<0)i+=7;
      System.out.println(month[m]+" "+d+", "+y+" is a "+day[i]);
    }
  }
}