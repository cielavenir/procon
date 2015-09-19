#!/usr/bin/env lua
while true do
	enemy1 = io.read() -- name of enemy 1
	dist1 = tonumber(io.read()) -- distance to enemy 1
	enemy2 = io.read() -- name of enemy 2
	dist2 = tonumber(io.read()) -- distance to enemy 2
	if dist1<dist2 then
		print(enemy1)
	else
		print(enemy2)
	end
end