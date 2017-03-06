#!/usr/bin/ruby
STDOUT.sync = true

Factoryn = gets.to_i
Linkn = gets.to_i
Links = Hash.new{|h,k|h[k]={}}
Linkn.times{
    f1,f2,distance = gets.split.map(&:to_i)
	Links[f1][f2]=Links[f2][f1]=distance
}

i=0
loop{
	factories = {}
    entity_count = gets.to_i
    entity_count.times{
        entity_id, entity_type, arg_1, arg_2, arg_3, arg_4, arg_5 = gets.split
        entity_id = entity_id.to_i
        arg_1 = arg_1.to_i
        arg_2 = arg_2.to_i
        arg_3 = arg_3.to_i
        arg_4 = arg_4.to_i
        arg_5 = arg_5.to_i
		if entity_type=='FACTORY'
			factories[entity_id]||={player:0,number:0,production:0,broken:0}
			factories[entity_id][:player]+=arg_1
			factories[entity_id][:number]+=arg_2
			factories[entity_id][:production]+=arg_3
			factories[entity_id][:broken]+=arg_4
		elsif entity_type=='TROOP'
			factories[arg_3]||={player:0,number:0,production:0,broken:0}
			factories[arg_3][:number]+=arg_4*arg_1
		end
    }
	r=[]
	if i==0
		factories.any?{|k1,v1|
			next if v1[:player]!=1
			factories.any?{|k2,v2|
				if Links[k1][k2]&&v2[:player]==0&&v2[:production]==3
					r<<'MOVE %d %d %d'%[k1,k2,v1[:number]]
				end
			} or v1[:production]==0&&factories.any?{|k2,v2|
				if Links[k1][k2]&&v2[:player]==0&&v2[:production]==2
					r<<'MOVE %d %d %d'%[k1,k2,v1[:number]]
				end
			}
			factories.any?{|k2,v2|
				if Links[k1][k2]&&v2[:player]==-1
					r<<'BOMB %d %d'%[k1,k2]
				end
			}
		}
	else
		factories.each{|k1,v1|
			next if v1[:player]!=1
			factories.any?{|k2,v2|
				next if k1==k2 || !Links[k1][k2] || v2[:player]!=0
				if v2[:production]>0&&v2[:number]>=0&&v1[:number]>v2[:number]*2
					r<<'MOVE %d %d %d'%[k1,k2,v2[:number]*1+1]
				end
			} or factories.any?{|k2,v2|
				next if k1==k2 || !Links[k1][k2] || v2[:player]!=-1
				if v2[:production]>0&&v2[:number]>=0&&v1[:number]>v2[:number]*3+Links[k1][k2]*v2[:production]
					r<<'MOVE %d %d %d'%[k1,k2,v2[:number]*2+Links[k1][k2]*v2[:production]+1]
				end
			}
		}
	end
	puts r.empty? ? 'WAIT' : r*';'
	i+=1
}
