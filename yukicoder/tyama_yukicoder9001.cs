using System;
class Test{
	const int SIZE=9999999;
	static byte[] z=new byte[SIZE];
	static int input_count=0;

	static int get(){
		int r=0;
		for(;'0'<=z[input_count]&&z[input_count]<='9';)r=r*10+z[input_count++]-'0';
		input_count++;
		return r;
	}
	static int getC(){
		return z[input_count++];
	}
	static void Main(){
		Console.OpenStandardInput().Read(z,0,SIZE);
		Console.Write(get()+get());
		Console.Write((char)32);
		for(int c;(c=getC())>0;)Console.Write((char)c);
	}
}