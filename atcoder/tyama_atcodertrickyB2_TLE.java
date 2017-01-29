import java.util.*;
class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		int T=Integer.parseInt(cin.next());
		for(int i=0;i<T;i++){
			long a=Long.parseLong(cin.next());
			long b=Long.parseLong(cin.next());
			long c=Long.parseLong(cin.next());
			if(a==0){
				if(b==0)System.out.println(c!=0?"0":"3");
				else System.out.printf("1 %.12f\n",-c*1.0/b);
			}else{
				if(a<0){a=-a;b=-b;c=-c;}
				double d=b*b-4.0*a*c;
				if(Math.abs(d)<1e-9)System.out.printf("1 %.12f\n",-b/2.0/a);
				else if(d<0)System.out.println("0");
				else{
					// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
					double x,y;
					if(b>0){
						x = (-b-Math.sqrt(d))/2/a;
						y = c*1.0/a/x;
					}else{
						y = (-b+Math.sqrt(d))/2/a;
						x = c*1.0/a/y;
					}
					System.out.printf("2 %.12f %.12f\n",x,y);
				}
			}
		}
	}
}
