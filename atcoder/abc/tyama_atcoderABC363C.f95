implicit none
interface
subroutine reverse(a_,start_,size_)
	integer a_(*)
	integer start_,size_
end
logical function next_permutation(a_,n_)
	integer a_(:)
	integer n_
end
end interface
integer n,k,r,i,j,x,y
character(:), allocatable :: s
integer, allocatable :: a(:)
read(*,*) n,k
allocate(character(n+1) :: s)
allocate(a(n))
read(*,*) s
do i=1,n
	a(i)=ichar(s(i:i))
enddo
do i=1,n-1
	do j=i+1,n
		if(a(i).gt.a(j)) then
			r=a(i)
			a(i)=a(j)
			a(j)=r
		endif
	enddo
enddo

r=0
do while(.true.)
	i=n-k+1
	do while(i.gt.0)
	 	x=i
		y=i+k-1
		do while(x.lt.y)
			if(a(x).ne.a(y)) exit
			x=x+1
			y=y-1
		enddo
		if(x.ge.y) exit
		i=i-1
	enddo
	if(i.le.0) r=r+1
	if(.not.next_permutation(a,size(a))) exit
enddo
write(*,"(i0)") r
end

subroutine reverse(a_,start_,size_)
	integer a_(*)
	integer start_,size_
	integer end_,i_
	integer z_
	end_=start_+size_-1
	do i_=0,size_/2-1
		z_=a_(start_+i_)
		a_(start_+i_)=a_(end_-i_)
		a_(end_-i_)=z_
	end do
end

logical function next_permutation(a_,n_)
	integer a_(:)
	integer n_
	integer i_,k_,l_
	integer z_
	next_permutation=.false.
	if((0.le.n_).and.(n_.le.size(a_))) then
		call reverse(a_,n_,size(a_)+1-n_)
		i_=size(a_)-1
		do while(i_.ge.1)
			if(a_(i_).lt.a_(i_+1)) then
				exit
			endif
			i_=i_-1
		enddo
		if(i_.lt.1) then
			call reverse(a_,1,size(a_))
		else
			k_=i_
			i_=size(a_)
			do while(i_.ge.k_+1)
				if(a_(k_).lt.a_(i_)) then
					exit
				endif
				i_=i_-1
			enddo
			l_=i_;
			z_=a_(k_)
			a_(k_)=a_(l_)
			a_(l_)=z_
			call reverse(a_,k_+1,size(a_)+1-(k_+1))
			next_permutation=.true.
		endif
	endif
end
