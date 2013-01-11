//PKU1119
//どうしても正規表現を使いたくて苦手なJavaで^^;
import java.io.*;
import java.util.*;
import java.util.regex.*;

class Main{
  public static Scanner cin;
  public static Pattern pattern;
  public static Matcher matcher;

  public static String g(String s, String s1, String s2){
    pattern = Pattern.compile(s1);
    matcher = pattern.matcher(s);
    return matcher.replaceAll(s2);
  }

  public static String[] parse(String s){ //Java is ByRef, so this func is destructive... But it is OK.
    //文字種修正
    s=g(s,"[^0-9a-zA-Z ]","");

    //先頭空白削除
    s=g(s,"^\\s*","");

    if(s.equals(""))return null;

    pattern = Pattern.compile(" +");
    return pattern.split(s.toLowerCase()); //case-insensitiveですかい。
  }

  public static void main(String[] args){
    int i,j;

    cin=new Scanner(System.in);
    cin.useDelimiter("----------"); //複数行もOKとは。。。ま、この辺はPerlの\/みたいな技法でw
    String[] ss=parse(cin.next());
    int[] ii=new int[ss.length];

    for(;;){
      try{
        Arrays.fill(ii,0);
        String s=cin.next();

        String[] terms=parse(s);
        if(terms==null)continue;

        //集計
        for(i=0;i<ss.length;i++)
          for(j=0;j<terms.length;j++)
            if(ss[i].equals(terms[j]))ii[i]++;

        //重複単語の点をまとめる
        for(i=0;i<ss.length;i++)
          for(j=i+1;j<ss.length;j++)
            if(ss[i].equals(ss[j])){
              ii[i]+=ii[j];
              ii[j]=0;
            }

        float f=0;
        for(i=0;i<ss.length;i++)f+=Math.sqrt(ii[i]);
        System.out.printf("%.2f\n",f);
      }catch(NoSuchElementException e){
        return; //EOF^^;
      }
    }
  }
}