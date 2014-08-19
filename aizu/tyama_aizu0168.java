import java.util.*;
class Main{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int i,n;
		int[] a=new int[31];
		a[0]=a[1]=1;a[2]=2;
		for(i=3;i<31;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
		for(;(n=cin.nextInt())>0;System.out.println((a[n]+3649)/3650));
	}
}