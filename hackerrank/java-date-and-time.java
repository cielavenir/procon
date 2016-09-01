import java.util.*;
class Solution{
	static int zeller(int _y,int m,int d){
		m+=1;
		if(m<4){_y-=1;m+=12;}
		int y=_y/100,z=_y%100;
		return (5*y+z+y/4+z/4+13*m/5+d-1)%7;
	}
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int m=Integer.parseInt(cin.next());
		int d=Integer.parseInt(cin.next());
		int y=Integer.parseInt(cin.next());
		System.out.println(new String[]{"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"}[zeller(y,m,d)]);
	}
}