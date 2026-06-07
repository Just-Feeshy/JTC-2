local cursed_queue = {}

local queue = 0
local active = false
local character = "dad"
local animation = "cursed"

local function playNext()
	queue = queue - 1
	active = true
	playAnim(character, animation, true)
	setCharacterSpecialAnim(character, true)
end

function cursed_queue.setCharacter(name)
	character = name
end

function cursed_queue.setAnimation(name)
	animation = name
end

function cursed_queue.enqueue(count)
	queue = queue + (count or 1)
end

function cursed_queue.clear()
	queue = 0

	if active then
		setCharacterSpecialAnim(character, false)
	end

	active = false
end

function cursed_queue.pending()
	return queue
end

function cursed_queue.isActive()
	return active
end

function cursed_queue.onBeatHit()
	if active or queue <= 0 then
		return
	end

	playNext()
end

function cursed_queue.onUpdate(elapsed)
	if not active then
		return
	end

	if not sprAnimFinished(character) then
		return
	end

	if queue > 0 then
		playNext()
	else
		active = false
		setCharacterSpecialAnim(character, false)
	end
end

return cursed_queue
