import java.util.*;
import java.util.regex.*;

class Main{
	private final static Pattern addsubmuldiv = Pattern.compile("^(.*?)(-?\\d+)([+Z*/])(-?\\d+)(.*)$");
	private final static Pattern addsub = Pattern.compile("^(.*?)(-?\\d+)([+Z])(-?\\d+)(.*)$");
	private final static Pattern muldiv = Pattern.compile("^(.*?)(-?\\d+)([*/])(-?\\d+)(.*)$");

	private static String process(String s){
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

	private static String process2(String s){
		Matcher m=addsubmuldiv.matcher(s);
		while(m.find()){
			if(m.group(3).equals("*"))
				s=m.group(1)+(Integer.parseInt(m.group(2))*Integer.parseInt(m.group(4)))+m.group(5);
			else if(m.group(3).equals("/"))
				s=m.group(1)+(Integer.parseInt(m.group(2))/Integer.parseInt(m.group(4)))+m.group(5);
			else if(m.group(3).equals("+"))
				s=m.group(1)+(Integer.parseInt(m.group(2))+Integer.parseInt(m.group(4)))+m.group(5);
			else
				s=m.group(1)+(Integer.parseInt(m.group(2))-Integer.parseInt(m.group(4)))+m.group(5);
			m=addsubmuldiv.matcher(s);
		}
		return s;
	}

	public static void main(String[]z){
		Scanner x=new Scanner(System.in);
		for(;x.hasNext();){
			String s=x.next().replaceAll("-","Z");
			String ans=x.next();
			boolean a=process(s).equals(ans);
			boolean b=process2(s).equals(ans);
			if(a&&b)System.out.println("U");
			if(a&&!b)System.out.println("M");
			if(!a&&b)System.out.println("L");
			if(!a&&!b)System.out.println("I");
		}
	}
}