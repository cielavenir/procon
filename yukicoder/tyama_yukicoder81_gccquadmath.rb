#!/usr/bin/ruby
IO.popen('gcc -xc -ozzz - -lquadmath','w'){|io|
	io.puts DATA.read
}
IO.popen('./zzz','r+'){|io|
	io.write $<.read
	io.close_write
	puts io.read
}
File.unlink('zzz')

__END__
#include <stdio.h>
#include <quadmath.h>
char buf[99];
int main(){
	int N,i=0;
	scanf("%d",&N);
	__float128 s=0;
	for(;i<N;i++){
		scanf("%s",buf);
		s+=strtoflt128(buf,NULL);
	}
	quadmath_snprintf(buf,sizeof(buf),"%.10Qf",s);
	puts(buf);
	return 0;
}