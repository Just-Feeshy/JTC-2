local member = ""

function onCreate()
	createSprite("member")
	loadGraphic("member", "credits/menu/FeshyFeeshy")
	scaleSprite("member", 1.4, 1.4)
	setSpritePosition("member", windowWidth, windowHeight)
	setSpriteToCamera("member", "crewInfoCam")
	addSpriteToState("member")
end

function openCrewMenu(curSelected, fileName)
	setSpriteX("member", windowWidth)

	if member ~= fileName then
		print(fileName)
		loadGraphic("member", "credits/menu/" .. fileName)
		setSpriteX("member", windowWidth)
	end

	doTweenX("memberTwn", "member", windowWidth - getSpriteWidth("member") - 20, 0.45, "elasticout")
	member = fileName
end

function backInfo()
	doTweenX("memberTwn", "member", windowWidth, 0.45, "elasticout")
end
