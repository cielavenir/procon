import java.util.*;
import java.math.BigInteger;
class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		BigInteger a=cin.nextBigInteger();
		BigInteger b=cin.nextBigInteger();
		System.out.println(a.add(b));
		System.out.println(a.subtract(b));
	}
}