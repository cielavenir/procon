import java.io.*;
import java.util.*;

class Player{
	String name;
	int score;
}

class Checker{
	Comparator<Player> desc;
	Checker(){desc=new Inner();}

	class Inner implements Comparator<Player>{
		@Override
		public int compare(Player arg0,Player arg1){
				int c=Integer.valueOf(arg0.score).compareTo(arg1.score);
				if(c!=0)return -c;
				return -arg0.name.compareTo(arg1.name);
		}
	}
}

class Solution{
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		int N=Integer.parseInt(br.readLine().trim());
		String s;
		StringTokenizer st;
		Player Player[]=new Player[N];
		Checker check=new Checker();
		for(int i=0;i<N;i++){
			s=br.readLine().trim();
			st=new StringTokenizer(s);
			Player[i]=new Player();
			Player[i].name=st.nextToken();
			Player[i].score=Integer.parseInt(st.nextToken());
		}

		Arrays.sort(Player,check.desc);
		for(int i=0;i<Player.length;i++){
			System.out.printf("%s %s\n",Player[i].name,Player[i].score);
		}
	}
}