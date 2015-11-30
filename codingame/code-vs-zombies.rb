#!/usr/bin/ruby
STDOUT.sync = true
# Save humans, destroy zombies!

# game loop
f=false
arrived=false
(0..1/0.0).each{|iter|
	x, y = gets.split.map(&:to_i)
	human_count = gets.to_i
	humans = human_count.times.map{
		gets.split.map(&:to_i)
	}
	zombie_count = gets.to_i
	zombies = zombie_count.times.map{
		gets.split.map(&:to_i)
	}

	humans=humans.select{|human_id, human_x, human_y|
		dist=Math.hypot(human_x-x,human_y-y)
		dist_n=dist/1000-2
		dist_n<=1 || !zombies.any?{|zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext|
			dist2=Math.hypot(zombie_x-human_x,zombie_y-human_y)
			dist2_n=dist2/400
			dist_n>dist2_n # I need to give up this
		}
	}
	human=humans.min_by{|human_id, human_x, human_y|
		Math.hypot(human_x-x,human_y-y)
	}

	zombie=zombies.min_by{|zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext|
		Math.hypot(zombie_x-x,zombie_y-y)
	}

	#get the nearest

	if human[1]==x and human[2]==y
		arrived=true
	end
	if arrived
		f=!f
	end
	if iter==0 || (humans.size==1&&!arrived) || f
		puts "%d %d"%[human[1],human[2]]
	else
		puts "%d %d"%[zombie[1],zombie[2]]
	end
}