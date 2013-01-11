integer i,n,c,j,p
character*1001 s
character t,x
read(*,*)n
do i=1,n
read(*,*)s
c=1
p=1
t=s(1:1)
do j=2,1001
x=s(j:j)
if(t.ne.x)then
print "(i0,a,$)",j-p,t
if(x.eq." ")then
exit
endif
p=j
t=x
endif
enddo
print "(a)",""
enddo
end