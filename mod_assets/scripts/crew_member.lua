local roles = {
	"FrogTreat - Director & Lead Artist & Lead Animator",
	"Dificuz - Artist & Animator & Charter",
	"JustFeeshy - Lead Programmer",
	"Varsavi - Musician",
	"FLX - Freeplay Menu Programmer"
}

function onCreate()
	createText("role", 0, 12, windowWidth, roles[1], 32)
	setTextAlign("role", "center")
    setTextFont("role", "cheese.otf")
    setTextBorder("role", "OUTLINE", 2, "0xFF000000")
	addTextToState("role")
end

function changeDev(curSelected)
	setText("role", roles[curSelected + 1])
end
