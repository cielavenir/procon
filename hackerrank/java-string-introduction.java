import java.util.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int N=cin.nextInt();
		int[] a=new int[N+1];
		for(int i=1;i<=N;i++)a[i]=cin.nextInt()+a[i-1];
		int r=0;
		for(int i=0;i<N;i++)for(int j=i+1;j<=N;j++)if(a[j]-a[i]<0)r++;
		System.out.println(r);
	}
}