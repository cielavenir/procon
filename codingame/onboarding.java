import java.util.*;
class Player{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		for(;;){
			String enemy1 = cin.next(); // name of enemy 1
			int dist1 = cin.nextInt(); // distance to enemy 1
			String enemy2 = cin.next(); // name of enemy 2
			int dist2 = cin.nextInt(); // distance to enemy 2

			System.out.println(dist1<dist2 ? enemy1 : enemy2);
		}
	}
}