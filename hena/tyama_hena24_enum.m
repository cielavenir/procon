//usr/bin/true; tmpfile=$(mktemp); gcc -O2 -o $tmpfile -framework Foundation "$0" && $tmpfile; rm -f $tmpfile; exit

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

#import <stdio.h>
#import <Foundation/Foundation.h>

int isqrt(int n){
	if(n<=0)return 0;
	if(n<4)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
	return x;
}
int icbrt(int n){
	if(n<0)return -icbrt(-n);
	if(n==0)return 0;
	if(n<8)return 1;
	int x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y/y+y*2)/3;
	return x;
}

typedef bool(*tbl)(long long);
typedef bool(*tbll)(long long,long long);

@interface generate_impl:NSEnumerator
-init;
-(NSNumber*)nextObject;
@end
@interface drop_prev_impl:NSEnumerator
-init:(tbl)check _:(id)prev;
-(NSNumber*)nextObject;
@end
@interface drop_next_impl:NSEnumerator
-init:(tbl)check _:(id)prev;
-(NSNumber*)nextObject;
@end
@interface drop_n_impl:NSEnumerator
-init:(tbll)check _:(long long)n _:(id)prev;
-(NSNumber*)nextObject;
@end

@implementation generate_impl
{
	long long i;
}
-init
{
	i=0;
	[super init];
	return self;
}
-(NSNumber*)nextObject;
{
	i+=1;
	return [NSNumber numberWithLongLong:i];
}
@end
id generate(){return [[[generate_impl alloc] init] autorelease];}

@implementation drop_prev_impl
{
	id prev;
	tbl check;
	long long a;
	long long b;
}
-init:(tbl)check_ _:(id)prev_
{
	prev=prev_;
	check=check_;
	a=0;
	b=[[prev nextObject] longLongValue];
	[super init];
	return self;
}
-(NSNumber*)nextObject;
{
	for(;;){
		a=b;
		b=[[prev nextObject] longLongValue];
		if(!check(b)){
			return [NSNumber numberWithLongLong:a];
		}
	}
}
@end
id drop_prev(tbl check,id prev){return [[[drop_prev_impl alloc] init:check _:prev] autorelease];}

@implementation drop_next_impl
{
	id prev;
	tbl check;
	bool first;
	long long a;
	long long b;
}
-init:(tbl)check_ _:(id)prev_
{
	prev=prev_;
	check=check_;
	first=true;
	a=0;
	b=0;
	[super init];
	return self;
}
-(NSNumber*)nextObject;
{
	for(;;){
		a=b;
		b=[[prev nextObject] longLongValue];
		if(first||!check(a)){
			first=false;
			return [NSNumber numberWithLongLong:b];
		}
	}
}
@end
id drop_next(tbl check,id prev){return [[[drop_next_impl alloc] init:check _:prev] autorelease];}

@implementation drop_n_impl
{
	id prev;
	tbll check;
	long long n;
	long long i;
}
-init:(tbll)check_ _:(long long)n_ _:(id)prev_
{
	prev=prev_;
	check=check_;
	n=n_;
	i=0;
	[super init];
	return self;
}
-(NSNumber*)nextObject;
{
	for(;;){
		i+=1;
		long long a=[[prev nextObject] longLongValue];
		if(!check(i,n)){
			return [NSNumber numberWithLongLong:a];
		}
	}
}
@end
id drop_n(tbll check,long long n,id prev){return [[[drop_n_impl alloc] init:check _:n _:prev] autorelease];}

bool is_sq(long long n){
	long long x=isqrt(n);
	return x*x==n;
}
bool is_cb(long long n){
	long long x=icbrt(n);
	return x*x*x==n;
}
bool is_multiple(long long i,long long n){return i%n==0;}
bool is_le(long long i,long long n){return i<=n;}

int main(){
	for(;;){
		id stream=generate();
		for(;;){
			char c=fgetc(stdin);
			if(c=='\n')break;
			else if(c=='S')stream=drop_next(is_sq,stream);
			else if(c=='s')stream=drop_prev(is_sq,stream);
			else if(c=='C')stream=drop_next(is_cb,stream);
			else if(c=='c')stream=drop_prev(is_cb,stream);
			else if(c=='h')stream=drop_n(is_le,100,stream);
			else if(c=='2')stream=drop_n(is_multiple,2,stream);
			else if(c=='3')stream=drop_n(is_multiple,3,stream);
			else if(c=='4')stream=drop_n(is_multiple,4,stream);
			else if(c=='5')stream=drop_n(is_multiple,5,stream);
			else if(c=='6')stream=drop_n(is_multiple,6,stream);
			else if(c=='7')stream=drop_n(is_multiple,7,stream);
			else if(c=='8')stream=drop_n(is_multiple,8,stream);
			else if(c=='9')stream=drop_n(is_multiple,9,stream);
			else return 0;
		}
		int ctr=0;
		for(NSNumber *num in stream){
			if(ctr>0)putchar(',');
			printf("%lld",[num longLongValue]);
			if(++ctr==10)break;
		}
		puts("");
		fflush(stdout);
	}
}
