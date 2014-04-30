#!/usr/bin/ruby
def lightsout(x,y)
  #now=Time.now.to_f
  succ=0
  a=Array.new(x*y)
  a.size.times{|i| a[i]=Array.new(2)}

  #create problem
  mode=:red

  if mode==:red
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]=0
        x.times{|b|a[i+j*x][1]|=1<<(b+j*x)}
        y.times{|b|a[i+j*x][1]|=1<<(i+b*x)}
      }
    }
  elsif mode==:blue
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]= 0 |
          (1<<(i+j*x)) |
          (i>0&&j>0     ? 1<<(i-1+(j-1)*x) : 0) |
          (i<x-1&&j>0   ? 1<<(i+1+(j-1)*x) : 0) |
          (i>0&&j>y-1   ? 1<<(i-1+(j+1)*x) : 0) |
          (i<x-1&&j<y-1 ? 1<<(i+1+(j+1)*x) : 0) |
          (i>0   ? 1<<(i-1+j*x) : 0) |
          (i<x-1 ? 1<<(i+1+j*x) : 0) |
          (j>0   ? 1<<(i+(j-1)*x) : 0) |
          (j<y-1 ? 1<<(i+(j+1)*x) : 0) |
          0
      }
    }
  elsif mode==:yellow
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]= 0 |
          (i>0&&j>0     ? 1<<(i-1+(j-1)*x) : 0) |
          (i<x-1&&j>0   ? 1<<(i+1+(j-1)*x) : 0) |
          (i>0&&j>y-1   ? 1<<(i-1+(j+1)*x) : 0) |
          (i<x-1&&j<y-1 ? 1<<(i+1+(j+1)*x) : 0) |
          0
      }
    }
  elsif mode==:green
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]= 0 |
          #(1<<(i+j*x)) |
          (i>0   ? 1<<(i-1+j*x) : 0) |
          (i<x-1 ? 1<<(i+1+j*x) : 0) |
          (j>0   ? 1<<(i+(j-1)*x) : 0) |
          0
      }
    }
  elsif mode==:lightsout
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]= 0 |
          (1<<(i+j*x)) |
          (i>0   ? 1<<(i-1+j*x) : 0) |
          (i<x-1 ? 1<<(i+1+j*x) : 0) |
          (j>0   ? 1<<(i+(j-1)*x) : 0) |
          (j<y-1 ? 1<<(i+(j+1)*x) : 0) |
          0
      }
    }
  elsif mode==:eight
    x.times{|i|
      y.times{|j|
        a[i+j*x][0]=1<<(i+j*x)
        a[i+j*x][1]= 0 |
          #(1<<(i+j*x)) |
          (i>0&&j>0     ? 1<<(i-1+(j-1)*x) : 0) |
          (i<x-1&&j>0   ? 1<<(i+1+(j-1)*x) : 0) |
          (i>0&&j>y-1   ? 1<<(i-1+(j+1)*x) : 0) |
          (i<x-1&&j<y-1 ? 1<<(i+1+(j+1)*x) : 0) |
          (i>0   ? 1<<(i-1+j*x) : 0) |
          (i<x-1 ? 1<<(i+1+j*x) : 0) |
          (j>0   ? 1<<(i+(j-1)*x) : 0) |
          (j<y-1 ? 1<<(i+(j+1)*x) : 0) |
          0
      }
    }
  end

  #solve
  (x*y).times{|i|
    if a[i][1]&1<<i==0
      (i+1).step(x*y-1) {|j|
        if a[j][1]&1<<i!=0
          a[i],a[j]=a[j],a[i]
          succ=1
          break
        end
      }
      if succ==0 then break end
      succ=0
    end

    (x*y).times{|j|
      if i!=j && a[j][1]&1<<i!=0
        a[j][0]^=a[i][0]
        a[j][1]^=a[i][1]
      end
    }

    $stderr.printf("%d/%d passes\r",i+1,x*y)
  }
  $stderr.puts

=begin
	gets.to_i.times{
		prob=[];ans=[0]*x*y
		y.times{prob+=gets.split.map(&:to_i)}
		(x*y).times{|i|if prob[i]>0 then (x*y).times{|j|ans[j]^=a[j][0][i]}end}
		y.times{|i|puts ans[i*x,x].map(&:to_s)*' '}
	}
=end

  p (1<<16).times.map{|i|
    s=0
    16.times{|j|s^=a[j][1] if (i&(1<<j))!=0}
    16.times.map{|j|s[j]}.reduce(:+)
  }.max
end

lightsout(4,4)