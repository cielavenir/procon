import java.util.*;
import java.math.*;
class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		int x,y;
		String s;
		for(;cin.hasNext();){
			try{
				s=cin.next();
				x=cin.nextInt();
				y=cin.nextInt();
				s=new BigInteger(s,x).toString(y).toUpperCase();
				System.out.println(s.length()<=7 ? String.format("%7s",s) : "  ERROR");
			}catch(Exception e){System.out.println("  ERROR");}
		}
	}
}