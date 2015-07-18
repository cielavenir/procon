!pku 2535
!Fortran is good at creating 2D array...
!Row is jury(n) and column is problem(p).
!EOFabort... Why?

!I tried using iostat, only to WA...

implicit none
integer::work(100,100)
integer, dimension(100)::simplest
integer::n,p,tmp,x

integer::i,j,ma,mi,c

read (*,*),n,p
do x=1,n
read (*,*),(work(tmp,x),tmp=1,p)
enddo

  c=0
  do i=1,p
    simplest(i)=0
  enddo

  do i=1,n
    mi=1000
    ma=0
    do j=1,p
      if(work(j,i).lt.mi) then
        mi=work(j,i)
      endif
      if(work(j,i).gt.ma) then
        ma=work(j,i)
      endif
    enddo

    do j=1,p
      if(work(j,i).eq.mi .and. simplest(j).ge.0) then
        if(work(j,i).eq.ma) then
          simplest(j)=-1
          cycle
        endif
        simplest(j)=simplest(j)+1
        cycle
      endif
      if(work(j,i).eq.ma) then
        simplest(j)=-1
        cycle
      endif
    enddo
  enddo

  do i=1,p
    if(simplest(i).gt.n/2) then
      if(c.gt.0) then
        write(*,"(a,$)")," "
      endif
      write(*,"(i0,$)"),i
      c=c+1
    endif
  enddo
  if(c.eq.0) then
    write(*,"(i1,$)"),0
  endif
end