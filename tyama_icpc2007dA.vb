module icpc2007dA
    sub Main(ByVal args() as String)
        dim i,n,s,ma,mi,sum as integer
        while(true)
          ma=0:mi=1000:sum=0
          n=Console.ReadLine()
          if n=0 then
            exit while
          end if
          for i=1 to n
            s=Console.ReadLine()
            ma=if(ma>s,ma,s) 'VB2008only: for VB2005 use if ma<s then \n ma=s \n end if
            mi=if(mi<s,mi,s)
            sum=sum+s
          next
          Console.WriteLine(int((sum-ma-mi)/(n-2)))
        end while
    end sub
end module