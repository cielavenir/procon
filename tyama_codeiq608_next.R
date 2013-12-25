#!/usr/bin/Rscript
next_permutation<-function(env,name,n=NA){
	a=get(name,env)
	if(is.na(n))n<-length(a)
	if(n<0||length(a)<n)return(FALSE)
	i<-0
	a<-c(a[1:n],rev(a[-n:0]))
	for(i in rev(1:(length(a)-1)))if(a[i]<a[i+1])break # r doesn't go beyond the range
	if(a[i]>=a[i+1]){
		assign(name,rev(a),env)
		return(FALSE)
	}
	k<-i
	for(i in rev((k+1):length(a)))if(a[k]<a[i])break
	l<-i
	z<-a[k];a[k]<-a[l];a[l]<-z
	assign(name,a<-c(a[1:k],rev(a[-k:0])),env)
	return(TRUE)
}

env<-new.env()
N<-6
e0<-1:(N*2)
f0<-1:(N*2)
i<-0
r<-0
for(i in 1:N){
	e0[i]=f0[i]=0
	e0[N+i]=f0[N+i]=1
}
e=0:(N*2)
f=0:(N*2)
assign("e0",e0,env)
assign("f0",f0,env)
repeat{
	e0=get("e0",env)
	for(i in 1:(N*2))e[i+1]<-e[i]+e0[i]
	repeat{
		f0=get("f0",env)
		x<-1
		for(i in 1:(N*2)){
			f[i+1]<-f[i]+f0[i]
			if(e[i]==f[i]&&e[i+1]==f[i+1]){x<-0;break}
		}
		r<-r+x
		if(!next_permutation(env,"f0"))break
	}
	if(!next_permutation(env,"e0"))break
}
cat(r)
cat("\n")