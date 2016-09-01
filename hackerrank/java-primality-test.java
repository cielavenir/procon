import java.util.*;
import java.math.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		BigInteger n=cin.nextBigInteger();
		System.out.println(n.isProbablePrime(100) ? "prime" : "not prime");
	}
}