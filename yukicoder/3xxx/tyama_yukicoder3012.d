import core.sys.posix.dlfcn;

void main(){
	void *h=dlopen(null,RTLD_NOW);
	void function() pcatch=cast(void function())dlsym(h,"catch");
	pcatch();
}