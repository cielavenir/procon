using System;
using System.Text.RegularExpressions;

// (5-(6/2/2+50*3/2/3*6/4)/9*2-(6/2/2+50*3/2/3*6)-36)*2-1=

class AOJ0109{
	static Regex addsub = new Regex("^(.*?)(-?\\d+)([+Z])(-?\\d+)(.*)$",RegexOptions.Compiled);
	static Regex muldiv = new Regex("^(.*?)(-?\\d+)([*/])(-?\\d+)(.*)$",RegexOptions.Compiled);

	static String process(String s){
		//analyze parens
		int bidx=s.IndexOf("(");
		while(bidx!=-1){
			int count=1,eidx=bidx+1;
			for(;count!=0;eidx++){
				if(s[eidx]=='(')count++;
				if(s[eidx]==')')count--;
			}
			s=s.Substring(0,bidx)+process(s.Substring(bidx+1,eidx-1-(bidx+1)))+s.Substring(eidx);
			bidx=s.IndexOf("(");
		}

		//calc without parens
		MatchCollection m=muldiv.Matches(s);
		while(m.Count>0){
			if(m[0].Groups[3].Value=="*")
				s=m[0].Groups[1].Value+(int.Parse(m[0].Groups[2].Value)*int.Parse(m[0].Groups[4].Value))+m[0].Groups[5].Value;
			else
				s=m[0].Groups[1].Value+(int.Parse(m[0].Groups[2].Value)/int.Parse(m[0].Groups[4].Value))+m[0].Groups[5].Value;
			m=muldiv.Matches(s);
		}

		m=addsub.Matches(s);
		while(m.Count>0){
			if(m[0].Groups[3].Value=="+")
				s=m[0].Groups[1].Value+(int.Parse(m[0].Groups[2].Value)+int.Parse(m[0].Groups[4].Value))+m[0].Groups[5].Value;
			else
				s=m[0].Groups[1].Value+(int.Parse(m[0].Groups[2].Value)-int.Parse(m[0].Groups[4].Value))+m[0].Groups[5].Value;
			m=addsub.Matches(s);
		}
		return s;
	}

	public static void Main(string[]z){
		int n=int.Parse(Console.ReadLine());
		for(;n>0;n--){
			string s=Console.ReadLine().Replace("-","Z");
			Console.WriteLine(process(s.Substring(0,s.Length-1)));
		}
	}
}