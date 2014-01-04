import java.util.*;
class Solution{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt(),i=0;
		int[] a=new int[10];
		for(;n>0;n--){
			int x=cin.nextInt(),y=cin.nextInt();
			for(i=0;i<10;i++)a[i]=cin.nextInt();
			for(;x<=y;x++){
				Random rnd=new Random(x);
				for(i=0;i<10;i++)if(a[i]!=rnd.nextInt(1000))break;
				if(i==10){
					System.out.print(x);
					for(i=0;i<10;i++)System.out.print(" "+String.valueOf(rnd.nextInt(1000)));
					System.out.println();
					break;
				}
			}
		}
	}
}