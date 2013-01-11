import java.util.*;
class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		int y,m,d;
		for(y=cin.nextInt();cin.hasNext();System.out.println(196471-(--y)*195-y/3*5-(--m)*20+(y%3!=2?m/2:0)-d)){y=cin.nextInt();m=cin.nextInt();d=cin.nextInt();}
	}
}