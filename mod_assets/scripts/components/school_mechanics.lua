local school_mechanics = {}

function school_mechanics.onStep(step)
	if step == 504 then
		callEvent("jumpspeed", "0.75", "7")
	end
end

return school_mechanics;
