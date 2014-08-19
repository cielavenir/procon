import java.util.*;
import java.util.regex.*;

// (5-(6/2/2+50*3/2/3*6/4)/9*2-(6/2/2+50*3/2/3*6)-36)*2-1=

class Main{
	private final static Pattern addsub = Pattern.compile("^(.*?)(-?\\d+)([+Z])(-?\\d+)(.*)$");
	private final static Pattern muldiv = Pattern.compile("^(.*?)(-?\\d+)([*/])(-?\\d+)(.*)$");

	private static String process(String s){
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

	public static void main(String[]z){
		Scanner x=new Scanner(System.in);
		int n=x.nextInt();for(;n>0;n--){
			String s=x.next().replaceAll("-","Z");
			System.out.println(process(s.substring(0,s.length()-1)));
		}
	}
}