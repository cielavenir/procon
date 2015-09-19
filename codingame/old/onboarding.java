import java.util.*;
class Player{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		for(;;){
			String name="";
			int n=cin.nextInt();
			double mi=9999999;
			for(;n>0;n--){
				String enemy=cin.next();
				double dist=cin.nextDouble();
				if(mi>dist){
					mi=dist;
					name=enemy;
				}
			}
			System.out.println(name);
		}
	}
}