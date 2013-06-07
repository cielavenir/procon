import java.util.*;
import java.util.regex.*;
class Main{
	final Map<String,String> t0=new HashMap<String,String>(){{
		put("alfa","A");
		put("sierra","S");
		put("bravo","B");
		put("tango","T");
		put("charlie","C");
		put("uniform","U");
		put("delta","D");
		put("victor","V");
		put("echo","E");
		put("whiskey","W");
		put("foxtrot","F");
		put("xray","X");
		put("golf","G");
		put("yankee","Y");
		put("hotel","H");
		put("zulu","Z");
		put("india","I");
		put("zero","0");
		put("juliett","J");
		put("one","1");
		put("kilo","K");
		put("two","2");
		put("lima","L");
		put("three","3");
		put("mike","M");
		put("four","4");
		put("november","N");
		put("five","5");
		put("oscar","O");
		put("six","6");
		put("papa","P");
		put("seven","7");
		put("quebec","Q");
		put("eight","8");
		put("romeo","R");
		put("nine","9");
	}};
	final Set<Map.Entry<String,String>> t=t0.entrySet();
	final int n=6;
	public void run(){
		Scanner cin=new Scanner(System.in);
		int i=0,j,N=cin.nextInt();
		for(;i<N;i++){
			for(j=0;j<n;j++){
				Pattern p=Pattern.compile("^"+cin.next().replace("*",".*")+"$");
				String r=".";
				for(Map.Entry<String,String> e : t){
					if(p.matcher(e.getKey()).matches()){
						if(r.equals(".")){
							r=e.getValue();
						}else{
							r=".";break;
						}
					}
				}
				System.out.print(r);
			}
			System.out.println();
		}
	}
	public static void main(String[]z){new Main().run();}
}