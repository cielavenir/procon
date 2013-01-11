import java.math.*;
class Main{
	public static void main(String[]z){
		BigInteger b=BigInteger.ONE;
		int i=2,n=new java.util.Scanner(System.in).nextInt();
		for(;i<1501;i++)b=b.multiply(new BigInteger(String.valueOf(i)));System.out.println(b.add(new BigInteger("2")));
		for(i=0;i<n;i++)System.out.println(i+2);
	}
}