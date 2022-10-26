#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/yokohamarb/103mask/
#https://qiita.com/Nabetani/items/35e83eb39fed3c75d586

def bits_to_num(bits)
    bits.sum{|b|1<<b}
end
def output(r)
    if r.size>15
        puts [*r[0...13],'...',*r[-2..-1]]*','
    else
        puts r*','
    end
end
while gets
    msk=$_.to_i(16)
    # b=msk.digits(2).each_with_index.select{|e,i|e==1}.map(&:last)
    b=msk.bit_length.times.select{|i|msk[i]>0}
    r={bits_to_num(b)=>1,bits_to_num(b[1..-1])=>1}
    (1...1<<[b.size,4].min).each{|bit_searcher|
        r[bits_to_num(b.select.with_index{|e,i|bit_searcher[i]>0})]=1
    }
    output(r.keys.sort)
    STDOUT.flush
end
