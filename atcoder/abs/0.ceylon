Integer parseInt(String? s,Integer default=-1){
	value result=Integer.parse(s else "");
	if(is Integer result){return result;}
	return default;
}
String readLine(){
	return process.readLine() else "";
}

shared void main(){
	value a=parseInt(readLine());
	value arr=readLine().split().sequence();
	value b=parseInt(arr[0]);
	value c=parseInt(arr[1]);

	print((a+b+c).string+" "+readLine());
	process.exit(0);
}
