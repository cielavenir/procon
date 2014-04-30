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
integer,parameter::N=6
integer r,i,flg,zero1,zero2,one1,one2
integer e0(N*2)
integer f0(N*2)
do i=1,N
	e0(i)=0
	f0(i)=0
	e0(N+i)=1
	f0(N+i)=1
enddo
r=0
do while(.true.)
	do while(.true.)
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		do i=1,N*2
			if(e0(i).eq.0) zero1=zero1+1
			if(e0(i).eq.1) one1=one1+1
			if(f0(N*2-i).eq.0) zero2=zero2-1
			if(f0(N*2-i).eq.1) one2=one2-1
			if(zero1.eq.zero2) flg=flg+1
			if(one1.eq.one2) flg=flg+1
		enddo
		if(flg.ge.2) r=r+1
		if(.not.next_permutation(f0,size(f0))) exit
	enddo
	if(.not.next_permutation(e0,size(e0))) exit
enddo
write(*,"(i0)"),r
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