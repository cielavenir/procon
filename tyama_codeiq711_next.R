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
assign("e0",e0,env)
assign("f0",f0,env)
repeat{
	e0=get("e0",env)
	repeat{
		f0=get("f0",env)
		flg<-0
		zero1<-0
		zero2<-N
		one1<-0
		one2<-N
		for(i in 1:(N*2)){
			if(e0[i]==0)zero1=zero1+1
			if(e0[i]==1)one1=one1+1
			if(f0[N*2+1-i]==0)zero2=zero2-1
			if(f0[N*2+1-i]==1)one2=one2-1
			if(zero1==zero2)flg=flg+1
			if(one1==one2)flg=flg+1
		}
		if(flg>=2)r=r+1
		if(!next_permutation(env,"f0"))break
	}
	if(!next_permutation(env,"e0"))break
}
cat(r)
cat("\n")