import java.util.*;
import java.math.*;
class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		int base;
		BigInteger a,b;
		for(;(base=cin.nextInt())!=0;){
			a=cin.nextBigInteger(base);
			b=cin.nextBigInteger(base);
			System.out.println(a.remainder(b).toString(base));
		}
	}
}