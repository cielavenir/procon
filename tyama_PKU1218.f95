implicit none
integer::i,n
real::x
read(*,*)n
do i=1,n
read(*,*)x
print "(i0)",int(sqrt(x))
enddo
end