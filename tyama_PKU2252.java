import java.util.*;
import java.util.regex.*;

class Main{
	private final static Pattern addsub = Pattern.compile("^(.*?)([0-9,-]+)([+Z])([0-9,-]+)(.*)$");
	private final static Pattern muldiv = Pattern.compile("^(.*?)([0-9,-]+)([*])([0-9,-]+)(.*)$");

	//多項式加減乗
	private static int[] add(int[] a,int[] b){
		int m=Math.max(a.length,b.length);
		int[] ret=new int[m];
		for(int i=0;i<m;i++){
			ret[i]=(i<a.length?a[i]:0)+(i<b.length?b[i]:0);
		}
		return ret;
	}
	private static int[] sub(int[] a,int[] _b){
		int[] b=new int[_b.length];
		for(int i=0;i<_b.length;i++)b[i]=-_b[i];
		return add(a,b);
	}
	private static int[] mul(int[] a,int[] _b){
		int[] r=new int[0];
		for(int i=0;i<_b.length;i++){
			int[] b=new int[i+a.length];
			for(int j=0;j<a.length;j++)b[i+j]=_b[i]*a[j];
			r=add(r,b);
		}
		return r;
	}
	private static int[] toInt(String s){
		String[] a=s.split(",");
		int[] r=new int[a.length];
		for(int i=0;i<a.length;i++)r[i]=Integer.parseInt(a[i]);
		return r;
	}
	private static String toStr(int[] a){
		String r="";
		for(int i=0;i<a.length;i++){
			r+=String.valueOf(a[i]);
			if(i<a.length-1)r+=",";
		}
		return r;
	}

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
				s=m.group(1)+toStr(mul(toInt(m.group(2)),toInt(m.group(4))))+m.group(5);
			//else
			//	s=m.group(1)+(Integer.parseInt(m.group(2))/Integer.parseInt(m.group(4)))+m.group(5);
			m=muldiv.matcher(s);
		}

		m=addsub.matcher(s);
		while(m.find()){
			if(m.group(3).equals("+"))
				s=m.group(1)+toStr(add(toInt(m.group(2)),toInt(m.group(4))))+m.group(5);
			else
				s=m.group(1)+toStr(sub(toInt(m.group(2)),toInt(m.group(4))))+m.group(5);
			m=addsub.matcher(s);
		}
		return s;
	}

	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int T=1;
		for(;cin.hasNext();T++){
			System.out.printf("Equation #%d\n",T);
			String line=cin.nextLine().replaceAll("-","Z").replaceAll("x","0,1");
			String[] a=line.split("=");
			int[] r=toInt(process(process(a[0])+'Z'+process(a[1])));
			if(r[1]!=0){
				System.out.printf("x = %.6f\n",-r[0]*1.0/r[1]);
			}else{
				if(r[0]==0)System.out.println("Infinitely many solutions.");
				else System.out.println("No solution.");
			}
			System.out.println();
		}
	}
}