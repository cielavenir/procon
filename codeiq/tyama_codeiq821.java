import java.util.*;
import java.util.regex.*;

class Main{
	private final static boolean FLAG=true;
	private final static Pattern addsub = Pattern.compile("^(.*?)(-?\\d+)([+Z])(-?\\d+)(.*)$");
	private final static Pattern muldiv = Pattern.compile("^(.*?)(-?\\d+)([*/])(-?\\d+)(.*)$");

	private static String process(String s){
/*
		//analyze parens
		int bidx=s.indexOf("(");
		while(bidx!=-1){
			int count=1,eidx=bidx+1;
			for(;count!=0;eidx++){
				if(s.charAt(eidx)=='(')count++;
				if(s.charAt(eidx)==')')count--;
			}
			s=s.substring(0,bidx)+process(s.substring(bidx+1,eidx-1))+s.substring(eidx);
			bidx=s.indexOf("(");
		}
*/
		//calc without parens
		Matcher m=muldiv.matcher(s);
		while(m.find()){
			if(m.group(3).equals("*"))
				s=m.group(1)+(Long.parseLong(m.group(2))*Long.parseLong(m.group(4)))+m.group(5);
			else
				s=m.group(1)+(Long.parseLong(m.group(2))/Long.parseLong(m.group(4)))+m.group(5);
			m=muldiv.matcher(s);
		}

		m=addsub.matcher(s);
		while(m.find()){
			if(m.group(3).equals("+"))
				s=m.group(1)+(Long.parseLong(m.group(2))+Long.parseLong(m.group(4)))+m.group(5);
			else
				s=m.group(1)+(Long.parseLong(m.group(2))-Long.parseLong(m.group(4)))+m.group(5);
			m=addsub.matcher(s);
		}
		return s;
	}

	public static boolean dfs(String s,int d,int l,String goal){
		if(d==l){
			//全体的に除算の扱いが怪しい.
			//今回は0除算は発生し得ないから大丈夫.
			String t=s.replaceAll(" ","");
			//System.out.println(t);
			//if(t.indexOf("/0")>=0)return false;
			if(process(t).equals(goal)){
				System.out.println(t);
				return true;
			}
			return false;
		}else{
			for(int i=0;i<5;i++){
				boolean f=dfs(s.substring(0,d*2+1)+"+Z*/ ".charAt(i)+s.substring(d*2+2),d+1,l,goal);
				if(!FLAG&&f)return true;
			}
			return false;
		}
	}
	public static void main(String[]z){
		String goal="1234";
		int i=9,j,k=7;
		String t="";
		if(!FLAG){
			for(i=1;i<10;i++){
				for(k=1;k<10;k++){ //この10は適当な上限。何も出力されなければ増やす必要がある。
					t="";
					for(j=0;j<k-1;j++){
						t+=(char)('0'+i);
						t+=" ";
					}
					t+=(char)('0'+i);
					if(dfs(t,0,k-1,goal)){
						System.out.println(k);
						break;
					}
				}
			}
		}else{
			t="";
			for(j=0;j<k-1;j++){
				t+=(char)('0'+i);
				t+=" ";
			}
			t+=(char)('0'+i);
			dfs(t,0,k-1,goal);
		}
	}
}