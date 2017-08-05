//usr/bin/env picoc -s $0 $@;exit
//usage: hena_dumper.c testdata.txt 1>input.txt 2>output.txt
void test(char *in,char *out){
	fprintf(stdout,"%s\n",in);
	fprintf(stderr,"%s\n",out);
	//static int i=0;fprintf(stdout,"test(%d,\"%s\",\"%s\")\n",i++,in,out);
}
