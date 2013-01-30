#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <libnsbmp.h>

typedef unsigned char u8;
typedef unsigned int u32;
u8 buf[256];

#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#include <fcntl.h>
	#define initstdio() setmode(fileno(stdin),O_BINARY),setmode(fileno(stdout),O_BINARY),setmode(fileno(stderr),O_BINARY);
#else
	#include <unistd.h>
	#define initstdio()
#endif

static unsigned int read32(const void *p){
	const unsigned char *x=(const unsigned char*)p;
	return x[0]|(x[1]<<8)|(x[2]<<16)|(x[3]<<24);
}

static void write32(void *p, const unsigned int n){
        unsigned char *x=(unsigned char*)p;
        x[0]=n&0xff,x[1]=(n>>8)&0xff,x[2]=(n>>16)&0xff,x[3]=(n>>24)&0xff;
}

static unsigned short read16(const void *p){
	const unsigned char *x=(const unsigned char*)p;
	return x[0]|(x[1]<<8);
}

static void write16(void *p, const unsigned short n){
        unsigned char *x=(unsigned char*)p;
        x[0]=n&0xff,x[1]=(n>>8)&0xff;
}

static void *bitmap_create(int width, int height, unsigned int state){return malloc(width*height*4);}

static void bitmap_set_suspendable(void *bitmap, void *private_word,
			     void (*invalidate)(void *bitmap, void *private_word)){}

//static void invalidate(void *bitmap, void *private_word){}

static unsigned char *bitmap_get_buffer(void *bitmap){return bitmap;}

static size_t bitmap_get_bpp(void *bitmap){return 4;}

static void bitmap_destroy(void *bitmap){free(bitmap);}

int main(const int argc, const char **argv){
	initstdio();
	if(argc<2){
		fprintf(stderr,
			"codeiq124 in.bmp >out.txt\n"
			"codeiq124 io.bmp <in.txt\n"
		);
		return -1;
	}

	int pixels=0,count=0,color,last;
	if(isatty(fileno(stdin))){ //decode
		struct stat st;
		int x,y;
		FILE *in=fopen(argv[1],"rb");
		if(!in){
			fprintf(stderr,"cannot open %s\n",argv[2]);
			return 1;
		}
		fstat(fileno(in),&st);
		void *imgbuf=malloc(st.st_size);
		fread(imgbuf,1,st.st_size,in);
		fclose(in);

		bmp_image gif;
		bmp_bitmap_callback_vt vt={
			bitmap_create,
			bitmap_destroy,
			bitmap_set_suspendable,
			bitmap_get_buffer,
			bitmap_get_bpp
		};

		bmp_create(&gif,&vt);
		if(bmp_analyse(&gif, st.st_size, imgbuf)||bmp_decode(&gif)){fprintf(stderr,"decode error\n");bmp_finalise(&gif);free(imgbuf);return 1;}
		free(imgbuf);

		for(y=0;y<gif.height;y++){
			for(x=0;x<gif.width;x++){
				u32 coor=y*gif.width+x;
				u8 b=((((u32*)gif.bitmap)[coor]&0xff0000)>>16)&0xff;
				u8 g=((((u32*)gif.bitmap)[coor]&0x00ff00)>>8)&0xff;
				u8 r=((((u32*)gif.bitmap)[coor]&0x0000ff)>>0)&0xff;
				u8 mes=((r&7)<<5)|((g&3)<<3)|((b&7)<<0);
				if(!mes)break;
				putchar(mes);
			}
		}
		bmp_finalise(&gif);
	}else{ //encode
		struct stat st;
		int x,y;
		FILE *f=fopen(argv[1],"rb");
		if(!f){
			fprintf(stderr,"cannot open %s\n",argv[2]);
			return 1;
		}
		fstat(fileno(f),&st);
		void *imgbuf=malloc(st.st_size);
		fread(imgbuf,1,st.st_size,f);
		fclose(f);

		bmp_image gif;
		bmp_bitmap_callback_vt vt={
			bitmap_create,
			bitmap_destroy,
			bitmap_set_suspendable,
			bitmap_get_buffer,
			bitmap_get_bpp
		};

		bmp_create(&gif,&vt);
		if(bmp_analyse(&gif, st.st_size, imgbuf)||bmp_decode(&gif)||!(f=fopen(argv[1],"wb"))){fprintf(stderr,"decode error\n");bmp_finalise(&gif);free(imgbuf);return 1;}
		free(imgbuf);

		int wbytes=3*gif.width;
		int padding=wbytes-((wbytes+3)&~3);
		if(padding)padding=4-padding;
		buf[0]='B',buf[1]='M';
		write32(buf+2,54+gif.width*gif.height*3+padding);
		write32(buf+10,54);
		write32(buf+14,40);
		write32(buf+18,gif.width);
		write32(buf+22,gif.height);
		write16(buf+26,1);
		write16(buf+28,3*8);
		write32(buf+34,gif.width*gif.height*3+padding);
		fwrite(buf,1,54,f);

		for(y=0;y<gif.height;y++){
			for(x=0;x<gif.width;x++){
				u32 coor=y*gif.width+x;
				u8 b=((((u32*)gif.bitmap)[coor]&0xff0000)>>16)&0xff;
				u8 g=((((u32*)gif.bitmap)[coor]&0x00ff00)>>8)&0xff;
				u8 r=((((u32*)gif.bitmap)[coor]&0x0000ff)>>0)&0xff;
				int mes=getchar();
				if(mes==EOF)mes=0;
				b=(b&248)|((mes>>0)&7);
				g=(g&252)|((mes>>3)&3);
				r=(r&248)|((mes>>5)&7);
				((u32*)gif.bitmap)[coor]=(b<<16)|(g<<8)|(r<<0);
				if(!mes)break;
			}
			if(x<gif.width)break;
		}
		for(y=gif.height-1;y>=0;y--){
			for(x=0;x<gif.width;x++){
				u32 coor=y*gif.width+x;
				u8 b=((((u32*)gif.bitmap)[coor]&0xff0000)>>16)&0xff;
				u8 g=((((u32*)gif.bitmap)[coor]&0x00ff00)>>8)&0xff;
				u8 r=((((u32*)gif.bitmap)[coor]&0x0000ff)>>0)&0xff;
				fputc(b,f);
				fputc(g,f);
				fputc(r,f);
			}
			int i=0;
			for(;i<padding;i++)fputc(0,f);
		}
		fclose(f);
		bmp_finalise(&gif);
	}
	return 0;
}
