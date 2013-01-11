!pku 1936
implicit none
character*100000::s,t
integer::i,j,ret,x,n
read(*,*)n
do x=1,n
  i=1
  j=1
  ret=0
  read(*,*),t,s

  do while(t(j:j).ne." ")
    if(s(i:i).eq.t(j:j)) then
      i=i+1
      if(s(i:i).eq." ") then
        ret=1
      endif
    endif
    j=j+1
  enddo

  i=1
  if(ret==0)then
  do while(j.ne.0)
    if(s(i:i).eq.t(j:j)) then
      i=i+1
      if(s(i:i).eq." ") then
        ret=1
      endif
    endif
    j=j-1
  enddo
  endif

  if (ret.eq.0) then
    write (*,"(a)"),"NO"
  else
    write (*,"(a)"),"YES"
  endif
enddo
end