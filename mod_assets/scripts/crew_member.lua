
function onCreate()
	createText("role", 0, 0, windowWidth * 0.5, "Lead Programmer", 48)

	setTextPosition("role", windowWidth - getTextWidth("role"), 0)
	setsetTextToCamera("role", "crewInfoCam")
	addTextToState("role")
end

function openCrewMenu(curSelected, fileName)
end

function backInfo()
end
