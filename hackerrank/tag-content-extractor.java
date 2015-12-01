import java.io.*;
import java.util.*;

class Solution{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		while(testCases>0){
			String line=in.nextLine();
			int cur=0;
			boolean none=true;
			for(;;){
				int start=line.indexOf("<",cur);
				if(start<0)break;
	         	int end=line.indexOf(">",start);
				if(end<0)break;
				String tag=line.substring(start+1,end);
				if(tag.length()==0 || tag.charAt(0)=='/'){
					cur=end+1;
					continue;
				}
				int bk=line.indexOf("</"+tag+">");
				if(bk>=0){
					String candidate=line.substring(end+1,bk);
					if(candidate.length()>0 && candidate.indexOf("<")<0){
						none=false;
						System.out.println(candidate);
					}
				}
				cur=end+1;
			}
			if(none)System.out.println("None");
			testCases--;
		}
	}
}