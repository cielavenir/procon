integer i,t,n,f,g,x,a(1000)
read(*,*)t
do i=1,t
read(*,*)n,(a(x),x=1,n)
do f=1,n
do g=f,n
if(a(f)<a(g))then
x=a(f);a(f)=a(g);a(g)=x
endif
enddo
enddo
x=0
do f=1,n
g=a(f)*f
if(x<g)then
x=g
endif
enddo
print "(i0)",x
enddo
end