% ozc -x
functor
import
	Application Open
define
	class TextFile from Open.file Open.text end
	Stdin  = {New TextFile init(name:stdin)}
	Stdout = {New Open.file init(name:stdout)}

	fun {Calc R I N K}
		if I==N then
			R
		else
			{Calc ((R+K) mod I) (I+1) N K}
		end
	end

	proc {Main2}
		case {List.map {String.tokens {Stdin getS($)} 32} String.toInt} of N|K|M|_ then
			if N>0 then
				{Stdout write(vs:({Calc 0 1 N K}+M) mod N+1#"\n")}
				{Main2}
			end
		end
	end

	{Main2}
	{Application.exit 0}
end
