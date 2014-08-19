//Based on CodeIQ 343.

import java.io.*;
import java.awt.image.BufferedImage;
import javax.imageio.*;

class Main{
	//garbage :p
	final static String table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	private static String base64_encode(byte[] in){
		String ret="";
		int i=0,b=0,I=0;
		int x=0;
		for(;I<in.length;I++){
			x=((x<<8)+(in[I]&0xff))&0xffff; //I really want to use unsigned here...
			i++;
			b+=8;
			while(b>=6){b-=6;ret+=table.charAt((x>>b)&0x3f);}
		}
		if(b>0)ret+=table.charAt((x<<(6-b))&0x3f);
		i%=3;
		if(i==2)ret+="=";
		if(i==1)ret+="==";
		return ret;
	}

	public static void main(String[]z){
		try{
			BufferedImage big;
			FileInputStream in = new FileInputStream(z[0]); //take29_wh.png
			big=ImageIO.read(in);
			in.close();
			//int []rgb=big.getRGB(0,0,23,1,null,0,1); //somehow not working.
			for(int i=0;i<23;i++)System.out.print(String.valueOf((char)(big.getRGB(i,0)>>24)));
			System.out.println();
		}catch(IOException e){e.printStackTrace();}
	}
}