% ozc -x
functor
import
	Application Open
define
	class TextFile from Open.file Open.text end
	Stdin  = {New TextFile init(name:stdin)}
	Stdout = {New Open.file init(name:stdout)}

	fun {Sum N MA MI S Z}
		if N==0 then
			((S-MA-MI) div (Z-2))
		else
			local X in
				X={String.toInt {Stdin getS($)}}
				{Sum (N-1) {Max MA X} {Min MI X} (S+X) Z}
			end
		end
	end

	proc {Main2}
		local N in
			N={String.toInt {Stdin getS($)}}
			if N>0 then
				{Stdout write(vs:{Sum N 0 1000 0 N}#"\n")}
				{Main2}
			end
		end
	end

	{Main2}
	{Application.exit 0}
end
