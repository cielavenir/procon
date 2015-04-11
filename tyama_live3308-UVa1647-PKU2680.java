import java.util.*;
import java.math.*;
class Main{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		BigInteger two=BigInteger.ONE.add(BigInteger.ONE),three=two.add(BigInteger.ONE);
		for(;cin.hasNext();){
			int p=cin.nextInt();
			System.out.println(two.pow(p-1).add(BigInteger.ONE).divide(three));
		}
	}
}