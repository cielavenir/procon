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

	proc {Main2 N}
		if N>0 then
			case {List.map {String.tokens {Stdin getS($)} 32} String.toInt} of Y|M|D|_ then
				local X in
					if Y mod 3==0 then
						X=0
					else
						X=(M-1) div 2
					end
					{Stdout write(vs:196471-((Y-1)*195)-((Y-1) div 3)*5-(M-1)*20+X-D#"\n")}
					{Main2 (N-1)}
				end
			end
		end
	end

	
	{Main2 {String.toInt {Stdin getS($)}}}
	{Application.exit 0}
end