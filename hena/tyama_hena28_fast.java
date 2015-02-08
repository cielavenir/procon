// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

import java.util.Scanner;
import java.util.regex.*;

class Main{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		String dir="ESWN";
		for(;cin.hasNext();){
			cin.findInLine("(\\d+),(\\d+),(\\d+),(\\d+):(\\d+)");
			MatchResult match=cin.match();
			cin.nextLine();
			int[] l=new int[]{Integer.parseInt(match.group(2)),Integer.parseInt(match.group(3)),Integer.parseInt(match.group(4)),Integer.parseInt(match.group(1))};
			long days=Long.parseLong(match.group(5))+1;
			int i=0,j,f=1;
			for(;f!=0;i++){
				int[] x=new int[]{l[i%4]+(i%4==0 ? 1 : 0),(i/4+1)*2,l[i%4]-(i%4==3 ? 1 : 0)};
				for(j=0;j<3;j++){
					if(days-x[j]<0){
						System.out.println(dir.charAt((i+j)%4));
						f=0;
						break;
					}
					days-=x[j];
				}
			}
			System.out.flush();
		}
	}
}