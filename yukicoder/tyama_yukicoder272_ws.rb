#!/usr/bin/ruby
#coding:utf-8

def f(s)
	@handle.print s if @handle
	s
end

def gen_label(n)
	raise 'gen_label' if !n.is_a?(Integer) || n<0
	n.to_s(2).tr('01'," \t")+"\n"
end

def gen_number(n)
	raise 'gen_number' if !n.is_a?(Integer)
	(n<0 ? "\t" : ' ')+gen_label(n.abs)
end

#stack
def push_stack(n)
	f " "+" "+gen_number(n)
end
def duplicate_stack
	f " "+"\n "
end
def copy_stack(n)
	f " "+"\t "+gen_number(n)
end
def swap_stack
	f " "+"\n\t"
end
def discard_stack
	f " "+"\n\n"
end
def slide_stack(n)
	f " "+"\t\n"+gen_number(n)
end

#arithmetic
def add
	f "\t "+"  "
end
def sub
	f "\t "+" \t"
end
def mul
	f "\t "+" \n"
end
def div
	f "\t "+"\t "
end
def mod
	f "\t "+"\t\t"
end

#heap
def store_heap(n=nil)
	s=''
	s=push_stack(n) if n
	f (@handle ? '' : s)+"\t\t"+" "
end
def retrive_heap(n=nil)
	s=''
	s=push_stack(n) if n
	f (@handle ? '' : s)+"\t\t"+"\t"
end

#flow
def set_label(n)
	f "\n"+"  "+gen_label(n)
end
def call(n)
	f "\n"+" \t"+gen_label(n)
end
def jmp(n)
	f "\n"+" \n"+gen_label(n)
end
def jz(n)
	f "\n"+"\t "+gen_label(n)
end
def jl(n)
	f "\n"+"\t\t"+gen_label(n)
end
def rtrn
	f "\n"+"\t\n"
end
def over
	f "\n"+"\n\n"
end

#IO
def printc
	f "\t\n"+"  "
end
def printn
	f "\t\n"+" \t"
end
def readc
	f "\t\n"+"\t "
end
def readn
	f "\t\n"+"\t\t"
end

@handle=STDOUT
push_stack(1)
push_stack(0)
readn
retrive_heap(0)
sub
printn
over