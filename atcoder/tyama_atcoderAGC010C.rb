#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
def f(v,c)
	s=m=H[v].size==1?A[v-1]:0
	H[v].any?{|e|
		e==c&&next
		s+=n=f(e,v)
		m=[m,n].max
		n<0		
	}||s<(x=2*A[v-1]-s)||x<2*m-s ?-1:x
end
G=->{gets.split.map &:to_i}
n,_=G[]
A=G[]
H=Hash.new{|h,k|h[k]=[]}
(n-1).times{x,y=G[];H[x]<<y;H[y]<<x}
puts f(1,0)==0?:YES: :NO
