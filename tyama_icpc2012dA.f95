implicit none
integer::i,n,y,m,d,r
read(*,*) n
i=0
do while(i.lt.n)
	read(*,*),y,m,d
	y=y-1;m=m-1
	r=0
	if(mod(y,3).ne.2) then
		r=m/2
	endif
	write(*,"(i0)") 196471-y*195-y/3*5-m*20+r-d
	i=i+1
enddo
end