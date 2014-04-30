import java.util.*;
import java.util.regex.*;

class Main{
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
				s=m.group(1)+(Integer.parseInt(m.group(2))*Integer.parseInt(m.group(4)))+m.group(5);
			else
				s=m.group(1)+(Integer.parseInt(m.group(2))/Integer.parseInt(m.group(4)))+m.group(5);
			m=muldiv.matcher(s);
		}

		m=addsub.matcher(s);
		while(m.find()){
			if(m.group(3).equals("+"))
				s=m.group(1)+(Integer.parseInt(m.group(2))+Integer.parseInt(m.group(4)))+m.group(5);
			else
				s=m.group(1)+(Integer.parseInt(m.group(2))-Integer.parseInt(m.group(4)))+m.group(5);
			m=addsub.matcher(s);
		}
		return s;
	}

	public static boolean dfs(String s,int d,int l,String goal){
		if(d==l){
			//全体的に除算の扱いが怪しい.
			String t=s.replaceAll(" ","");
			if(t.length()==l+1)return false;
			if(t.indexOf("/0")>=0)return false;
			if(process(t).equals(goal)){
				System.err.println(t);
				return true;
			}
			return false;
		}else{
			for(int i=0;i<5;i++){
				if(dfs(s.substring(0,d*2+1)+"+Z*/ ".charAt(i)+s.substring(d*2+2),d+1,l,goal))return true;
			}
			return false;
		}
	}
	public static void main(String[]z){
		int i=1000,j;
		for(;i<10000;i++){
			if(i%10==0)continue;
			String s=String.valueOf(i),t="";
			String goal=new StringBuilder(s).reverse().toString();
			for(j=0;j<s.length()-1;j++){
				t+=s.charAt(j);
				t+=" ";
			}
			t+=s.charAt(j);
			if(dfs(t,0,s.length()-1,goal))System.out.println(i); //5931
		}
	}
}