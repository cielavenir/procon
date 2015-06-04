import java.util.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		for(;T>0;T--){
			int a=cin.nextInt(),b=cin.nextInt(),n=cin.nextInt();
			for(int i=0;i<n;i++){
				System.out.print(a+b*((2<<i)-1));
				System.out.print(i<n-1?" ":"\n");
			}
		}
	}
}