import java.math.*;
import java.util.*;
class Main{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		for(int n=cin.nextInt();n-->0;){
			BigInteger a=new BigInteger(new StringBuilder(cin.next()).reverse().toString());
			BigInteger b=new BigInteger(new StringBuilder(cin.next()).reverse().toString());
			System.out.println(new BigInteger(new StringBuilder(a.add(b).toString()).reverse().toString()));
		}
	}
}