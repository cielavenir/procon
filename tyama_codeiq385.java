//Based on CodeIQ 343, 8946 Take29.
//Modified on Aug 22. Score=89.25

import java.io.*;
import java.util.*;
import java.awt.image.BufferedImage;
import javax.imageio.*;

class Main{
	private final static int scaleXmin=90,scaleXmax=585,scaleYmin=380,scaleYmax=82;
	private final static int Xsize=scaleXmax-scaleXmin+1;
	private final static int[] month={0,31,28,31,30,31,30,31,31,30,31,30,31};
	public static double scaleY(double y){
		return 10*(scaleYmin-y)/(scaleYmin-scaleYmax);
	}
	public static void main(String[]args){
		try{
			String dirPath=args.length>0?args[0]:".";
			File dir=new File(dirPath);
			String[] lst=dir.list();
			Arrays.sort(lst);
			int pictnum=1;
			for(String fname : lst){
				if(!fname.endsWith(".png"))continue;
				int dh,dw;
				BufferedImage big;
				FileInputStream in = new FileInputStream(dirPath+File.separator+fname);
				big=ImageIO.read(in);
				in.close();

				//must be tuned below.
				double[] graphToVal=new double[Xsize];
				for(int i=0;i<Xsize;i++){
					double maxwhite=999999;
					double maxY1=0,maxY2=0;
					for(int j=scaleYmax;j<=scaleYmin;j++){
						int rgb=big.getRGB(i+scaleXmin,j);
						int r=(rgb>>24)&0xff;
						int g=(rgb>>16)&0xff;
						int b=(rgb>>8)&0xff;
						double white=r+g+b;
						if(white==maxwhite)maxY2=j;
						if(maxwhite>white){maxwhite=white;maxY1=maxY2=j;}
					}
					graphToVal[i]=(maxY1+maxY2)/2;
				}
				int m=1,d=1;
				for(int i=0;i<365;i++){
					double val=scaleY(graphToVal[i*Xsize/365]);
					System.out.printf("%03d\t%02d-%02d\t%f\n",pictnum,m,d,val);
					if(++d>month[m]){m++;d=1;}
				}
				pictnum++;
			}
		}catch(Exception e){e.printStackTrace();}
	}
}