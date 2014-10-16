implicit none
integer::n,k,m,r,i
do while(.true.)
	read(*,*),n,k,m
	if(n.eq.0)exit
	r=0
	do i=1,n-1
		r=mod(r+k,i)
	end do
	write(*,"(i0)"),mod(r+m,n)+1
end do
end