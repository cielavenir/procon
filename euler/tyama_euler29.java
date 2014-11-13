import java.util.*;
import java.math.BigInteger;
class Solution{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		Set<BigInteger> se=new HashSet<BigInteger>();
		BigInteger a1=BigInteger.ONE;
		for(long a0=2;a0<=n;a0++){
			a1=a1.add(BigInteger.ONE);
			BigInteger a=a1.multiply(a1);
			se.add(a);
			for(int b=3;b<=n;b++){
				a=a.multiply(a1);
				se.add(a);
			}
		}
		System.out.println(se.size());
	}
}