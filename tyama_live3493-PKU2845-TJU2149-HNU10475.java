import java.io.*;
import java.util.*;
import java.math.*;
class Main{
public static void main(String[] args){
Scanner cin = new Scanner(System.in);
for(int c=cin.nextInt(),i=1;i<=c;i++)
System.out.println(i+" "+new BigInteger(cin.next(),2).add(new BigInteger(cin.next(),2)).toString(2));
}
}