//usr/bin/env scala $0 $@;exit

object icpc2012dA{
	def main(args: Array[String]){
		val cin=new java.util.Scanner(System.in)
		var y=cin.nextInt();var m=0;var d=0;
		while(cin.hasNext()){
			y=cin.nextInt()-1;m=cin.nextInt()-1;d=cin.nextInt();
			var r=0;
			if(y%3!=2)r=m/2;
			printf("%d\n",196471-y*195-y/3*5-m*20+r-d);
		}
	}
}