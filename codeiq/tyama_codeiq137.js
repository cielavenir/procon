for(Z=[a=0];a<4;Z[a++]=e.join("\n")){for(e=[j=i=y=-1];++y<40;)for(e[y]=[x=-1];++x<80;e[y][x]=Math.abs(x-40)<(y-z*4)%(z*8+8)?"%":"_")z=y/8|0
for(;++i<160;e[y=1+r%38][x=1+r%78]="*",e[y][x-1]=e[y][x+1]="-",e[y-1][x]=e[y+1][x]="|")r=(a+i)*i*49999+59999&65535
for(;++j<40;)e[j]=e[j].join("")}return Z