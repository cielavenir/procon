//-ldl -Wl,--export-dynamic
#include <dlfcn.h>
#include <stdio.h> //NULL
typedef void (*Tvoid)();
Tvoid pcatch;
int main(){
	void *h=dlopen(NULL,RTLD_NOW);
	pcatch=(Tvoid)dlsym(h,"catch");
	pcatch();
}