#!/usr/bin/ruby
TABLE={
	:start   => '5426528869786',
	:deep    => '4363616111476',
	:deeper  => '5092488161056',
	:deepest => '8838746292440',
}
DUMMY={
	'1814964223463'=>1,
	'4656383184179'=>1,
	'3351698485723'=>1,
	'7684149340544'=>1,
	'8262133957338'=>1,
}
#URL='http://www4023ui.sakura.ne.jp/deepest.cgi?id=__ID__&nth=__NTH__'
URL='http://133.242.134.37/deepest.cgi?id=__ID__&nth=__NTH__'
require 'net/http'
require 'uri'
def bfs(start,stop)
	bench_http=0
	bench_queue=0
	h={start=>true} #backtrack
	queue=[start]
	uri=URI.parse(URL)
	Net::HTTP.start(uri.host){|http|
		while !queue.empty?
			id=queue.shift
			(0..1/0.0).each{|nth|
				body=http.get(uri.path+'?'+uri.query.sub('__ID__',id).sub('__NTH__',nth.to_s)).body.chomp
				bench_http+=1
				sleep(1)
				raise if body[0,1]=='-'
				break if body=='0'
				if !h.has_key?(body)
					$stderr.puts "#{id} -> #{body}"
					if !DUMMY.include?(body)
						bench_queue+=1
						h[body]=id
						queue<<body
					end
				end
				break if h.has_key?(stop)
			}
			break if h.has_key?(stop)
		end
		raise 'queue exhausted' if queue.empty?
	}
	cur=stop
	result=[]
	while cur!=start
		result.unshift(cur)
		cur=h[cur]
	end
	$stderr.puts "HTTP attempts: #{bench_http}"
	$stderr.puts "Queueing:      #{bench_queue}"
	result
end
result=[TABLE[:start]]
result+=bfs(TABLE[:start],TABLE[:deep])
#HTTP attempts: 66
#Queueing:      31
#$stderr.puts result.inspect
#puts result*','
result+=bfs(TABLE[:deep],TABLE[:deeper])
#HTTP attempts: 465
#Queueing:      77
#$stderr.puts result.inspect
#puts result*','
result+=bfs(TABLE[:deeper],TABLE[:deepest])
#HTTP attempts: 755
#Queueing:      95
#$stderr.puts result.inspect
puts result*','
puts 'ENV: Ruby'

__END__
5426528869786,2484466449149,4326837688991,6021351385219,2114116223711,7713050646130,3014332099928,4363616111476,2615115005762,3492704769369,6101275938556,5793542169547,4217007177539,2970040126310,6218636660558,1563577571047,8742972189444,3971331745645,2979009521142,3437245100188,5833671447983,6714942513619,7049674030681,5813482662518,2547413633555,2966922227746,1843019516033,5092488161056,8250347815782,4775196002726,4494366137783,2780144620728,3031196364476,5591596393385,5865952095146,8838746292440
ENV: Ruby

表の代わりにWeb APIをコールする形で幅優先探索を行った。
幅優先なので最短経路であることが保証されている。
表を直接渡すことができない理由としてリストが無限に存在することが予想できた。
無限に値を返すダミーが存在するので実際にそういうことになる。
なのでダミーはキューに追加しないようにした。
HTTPリクエストは66+465+755=1286回発行する必要があった。