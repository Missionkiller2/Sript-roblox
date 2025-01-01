local Rayfield = loadstring(game:HttpGet('https://sirius.menu/rayfield'))()

local Window = Rayfield:CreateWindow({
   Name = "🔥 Example Script Hub | Game 🔫",
   LoadingTitle = "🔫 Gun Simulator 💥",
   LoadingSubtitle = "by 1_F0",
   ConfigurationSaving = {
      Enabled = false,
      FolderName = nil, -- Create a custom folder for your hub/game
      FileName = "Example Hub"
   },
   Discord = {
      Enabled = false,
      Invite = "noinvitelink", -- The Discord invite code, do not include discord.gg/. E.g. discord.gg/ABCD would be ABCD
      RememberJoins = true -- Set this to false to make them join the discord every time they load it up
   },
   KeySystem = true, -- Set this to true to use our key system
   KeySettings = {
      Title = "Key | Youtube Hub",
      Subtitle = "Key System",
      Note = "Key In Discord Server",
      FileName = "YoutubeHubKey1", -- It is recommended to use something unique as other scripts using Rayfield may overwrite your key file
      SaveKey = false, -- The user's key will be saved, but if you change the key, they will be unable to use your script
      GrabKeyFromSite = true, -- If this is true, set Key below to the RAW site you would like Rayfield to get the key from
      Key = {"https://pastebin.com/raw/SXsjxw62"} -- List of keys that will be accepted by the system, can be RAW file links (pastebin, github etc) or simple strings ("hello","key22")
   }
})


Rayfield:Notify({
   Title = "You executed the script",
   Content = "Very cool gui",
   Duration = 5,
   Image = 13047715178,
   Actions = { -- Notification Buttons
      Ignore = {
         Name = "Okay!",
         Callback = function()
         print("The user tapped Okay!")
      end
   },
},
})
local MainTab = Window:CreateTab("🏠 Home", nil) -- Title, Image
local MainSection = MainTab:CreateSection("Main")

Rayfield:Notify({
   Title = "You executed the script",
   Content = "Very cool gui",
   Duration = 5,
   Image = 13047715178,
   Actions = { -- Notification Buttons
      Ignore = {
         Name = "Okay!",
         Callback = function()
         print("The user tapped Okay!")
      end
   },
},
})

local Button = MainTab:CreateButton({
   Name = "Infinite Jump Toggle",
   Callback = function()
       --Toggles the infinite jump between on or off on every script run
_G.infinjump = not _G.infinjump

if _G.infinJumpStarted == nil then
	--Ensures this only runs once to save resources
	_G.infinJumpStarted = true
	
	--Notifies readiness
	game.StarterGui:SetCore("SendNotification", {Title="Youtube Hub"; Text="Infinite Jump Activated!"; Duration=5;})

	--The actual infinite jump
	local plr = game:GetService('Players').LocalPlayer
	local m = plr:GetMouse()
	m.KeyDown:connect(function(k)
		if _G.infinjump then
			if k:byte() == 32 then
			humanoid = game:GetService'Players'.LocalPlayer.Character:FindFirstChildOfClass('Humanoid')
			humanoid:ChangeState('Jumping')
			wait()
			humanoid:ChangeState('Seated')
			end
		end
	end)
end
   end,
})

local Slider = MainTab:CreateSlider({
   Name = "WalkSpeed Slider",
   Range = {1, 350},
   Increment = 1,
   Suffix = "Speed",
   CurrentValue = 16,
   Flag = "sliderws", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
   Callback = function(Value)
        game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = (Value)
   end,
})

local Slider = MainTab:CreateSlider({
   Name = "JumpPower Slider",
   Range = {1, 350},
   Increment = 1,
   Suffix = "Speed",
   CurrentValue = 16,
   Flag = "sliderjp", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
   Callback = function(Value)
        game.Players.LocalPlayer.Character.Humanoid.JumpPower = (Value)
   end,
})

local Dropdown = MainTab:CreateDropdown({
   Name = "Select Area",
   Options = {"Starter World","Pirate Island","Pineapple Paradise"},
   CurrentOption = {"Starter World"},
   MultipleOptions = false,
   Flag = "dropdownarea", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
   Callback = function(Option)
        print(Option)
   end,
})

local Input = MainTab:CreateInput({
   Name = "Walkspeed",
   PlaceholderText = "1-500",
   RemoveTextAfterFocusLost = true,
   Callback = function(Text)
        game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = (Text)
   end,
})

local Button = MainTab:CreateButton({
   Name = "noclip",
   Callback = function()
_G.noclip = not _G.noclip

if not game:GetService('Players').LocalPlayer.Character:FindFirstChild("LowerTorso") then
	while _G.noclip do
		game:GetService("RunService").Stepped:wait()
		game.Players.LocalPlayer.Character.Head.CanCollide = false
		game.Players.LocalPlayer.Character.Torso.CanCollide = false
	end
else
	if _G.InitNC ~= true then     
		_G.NCFunc = function(part)      
			local pos = game:GetService('Players').LocalPlayer.Character.LowerTorso.Position.Y  
			if _G.noclip then             
				if part.Position.Y > pos then                 
					part.CanCollide = false             
				end        
			end    
		end      
		_G.InitNC = true 
	end 
	 
	game:GetService('Players').LocalPlayer.Character.Humanoid.Touched:connect(_G.NCFunc) 
end
end,
})

local Button = MainTab:CreateButton({
   Name = "tptool",
   Callback = function()
mouse = game.Players.LocalPlayer:GetMouse()
tool = Instance.new("Tool")
tool.RequiresHandle = false
tool.Name = "Click Teleport"
tool.Activated:connect(function()
local pos = mouse.Hit+Vector3.new(0,2.5,0)
pos = CFrame.new(pos.X,pos.Y,pos.Z)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = pos
end)
tool.Parent = game.Players.LocalPlayer.Backpack
end,
})

local Button = MainTab:CreateButton({
   Name = "trool tools",
   Callback = function()

backpack = game:GetService("Players").LocalPlayer.Backpack

hammer = Instance.new("HopperBin")
hammer.Name = "Hammer"
hammer.BinType = 4
hammer.Parent = backpack

cloneTool = Instance.new("HopperBin")
cloneTool.Name = "Clone"
cloneTool.BinType = 3
cloneTool.Parent = backpack

grabTool = Instance.new("HopperBin")
grabTool.Name = "Grab"
grabTool.BinType = 2
grabTool.Parent = backpack
   end,
})

local Button = MainTab:CreateButton({
   Name = "Aim bot And Esp Fly",
   Callback = function()
_G.FRIEND_LIST = {"ROBLOX","builderman"} --Add players you want to ignore
 
_G.IGNORE_TEAM = true
_G.START_AIMBOT = Enum.KeyCode.H
_G.MAX_DIST = 5000
_G.TARGET_PART = "Head"
 
_G.START_ESP = Enum.KeyCode.RightAlt
_G.PREFIX = "/e " --If you want a space between the command and pref, you need to type a space! Ex: /ehelp . /e help
 
 
 
local startTime = tick()
local AIMBOT = false
local EspEnabled = false
 
local Players = game:GetService("Players")
local StarterGui = game:GetService("StarterGui")
local CoreGui = game:GetService("CoreGui")
local UIS = game:GetService("UserInputService")
local RunService = game:GetService("RunService")
 
local plr = Players.LocalPlayer
local camera = workspace.CurrentCamera
local mouse = plr:GetMouse()
local newray = Ray.new
 
local function RandomCharacters(length)
	local STR = ''
 
	for i = 1, length do
		STR = STR .. string.char(math.random(65,90))
	end
 
	return STR
end
local faces = {
	"Back",
	"Bottom",
	"Front",
	"Left",
	"Right",
	"Top"
}
local EspObjects = Instance.new("Folder")
EspObjects.Parent = CoreGui
EspObjects.Name = RandomCharacters(8)
 
local function SendMessage(txt,title,dur,size,color)
	print(txt)
	StarterGui:SetCore("ChatMakeSystemMessage",{
		Text = txt,
		Color = color,
		FontSize = size
	})
	StarterGui:SetCore("SendNotification",{
		Title = title,
		Text = txt,
		Duration = dur
	})
end
local function ChangeColor(player, color)
	if EspObjects:FindFirstChild(player) then
		for i,v in pairs(EspObjects:FindFirstChild(player):GetChildren()) do
			if v:IsA("SurfaceGui") then
				for _,x in pairs(v:GetChildren()) do
					if x:IsA("Frame") then
						x.BackgroundColor3 = color
					end
				end
			elseif v:IsA("BillboardGui") then
				for _,x in pairs(v:GetChildren()) do
					if x:IsA("TextLabel") then
						x.TextColor = color
					end
				end
			end
		end
	end
end
local function GetClosestPlayer(returnPlr,ignoreList)
	ignoreList = _G.FRIEND_LIST
	returnPlr = returnPlr or false
 
	local ignoreTeam = _G.IGNORE_TEAM
	local maxdist = _G.MAX_DIST
	local targetpart = _G.TARGET_PART
 
	if ignoreTeam == true then
		if #game:GetService("Teams"):GetChildren() <= 1 then
			ignoreTeam = false
		end
		if plr.Neutral == true then
			ignoreTeam = false
		end
	end
 
	local temp1 = (maxdist)
	local FoundPlr
	local FoundPart
 
	local Table = game.Players:GetPlayers()
	for _,v in pairs(Table) do
		local skip = false
		for _,i in pairs(ignoreList) do
			if i:lower() == v.Name:lower() then
				skip = true
			end
		end
		if ignoreTeam == true then
			if v.Team == plr.Team then
				skip = true
			end
		end
		if v.Character == nil or v.Character:FindFirstChild(targetpart) == nil then 
			skip = true
		end
 
		if skip == false then
			if (temp1 ~= nil and v.Character:FindFirstChild(targetpart) and plr.Character ~= nil and plr.Character:FindFirstChild(targetpart)) then
				if temp1 > (plr.Character.Head.Position - v.Character:FindFirstChild(targetpart).Position).magnitude then
					local vChar = v.Character
					if vChar:FindFirstChild("Humanoid") then
						local vHuman = vChar:FindFirstChild("Humanoid")
						if vHuman.Health > 0 then
							local dist = (plr.Character.Head.Position - vChar:FindFirstChild(targetpart).Position).magnitude
							if dist <= maxdist then
								local ray = newray(plr.Character.Head.CFrame.p, (vChar:FindFirstChild(targetpart).CFrame.p - plr.Character.Head.CFrame.p).unit * _G.MAX_DIST)
								local hitPart,position = workspace:FindPartOnRay(ray,plr.Character)
 
								if hitPart then
									if hitPart:IsDescendantOf(vChar) then
										temp1 = dist
										FoundPlr = v
										FoundPart = vChar:FindFirstChild(targetpart)
									end
								end
							end
						end	
					end
				end
			end
		end
	end
	if returnPlr == false then
		return FoundPart
	elseif returnPlr == true then
		return FoundPlr
	end
end
local function CreateEspBox(pObj, color)
	if (pObj:IsA("Part") and pObj.Parent:IsA("Model") and pObj.Parent ~= workspace) then
		for i,v in pairs(EspObjects:GetChildren()) do 
			if v.Name == pObj.Parent.Name then
				return nil
			end
		end
		local newFlder = Instance.new("Folder")
		newFlder.Parent = EspObjects
		newFlder.Name = pObj.Parent.Name
 
		for i,v in pairs(faces) do
			local surfGui = Instance.new("SurfaceGui")
			surfGui.AlwaysOnTop = true
			surfGui.Adornee = pObj
			surfGui.Face = v
 
			local frme = Instance.new("Frame")
			frme.Size = UDim2.new(1,0,1,0)
			frme.BackgroundColor3 = color
			frme.BackgroundTransparency = .5
			frme.BorderSizePixel = 0
			frme.Parent = surfGui
 
			surfGui.Parent = newFlder
		end
		local bbGui = Instance.new("BillboardGui")
		bbGui.Adornee = pObj
		bbGui.Size = UDim2.new(5.5,0,1.75,0)
		bbGui.ExtentsOffset = Vector3.new(0,2.5,0)
		bbGui.AlwaysOnTop = true
		local txtLab = Instance.new("TextLabel")
		txtLab.Text = pObj.Parent.Name
		txtLab.TextColor3 = color
		txtLab.TextScaled = false
		txtLab.TextSize = 17
		txtLab.Size = UDim2.new(1,0,1,0)
		txtLab.BackgroundTransparency = 1
		txtLab.BorderSizePixel = 0
		txtLab.Parent = bbGui
		bbGui.Parent = newFlder
 
		local objPar = Instance.new("ObjectValue")
		objPar.Value = pObj
		objPar.Parent = newFlder
		objPar.Name = "pObj"
 
		return newFlder
	end
	return nil
end
local function ClearEsp()
	EspObjects:ClearAllChildren()
end
local function ConnectEsp(player)
	local func1
	local func2
	if player.Character ~= nil and player.Character:FindFirstChild("Head") then
		if plr.Team == nil or player.Team == nil or plr.Neutral == true or player.Neutral == true then
			local fldr = CreateEspBox(player.Character:FindFirstChild("Head"), Color3.fromRGB(255,0,0))
			if fldr ~= nil then
				local func3
				func3 = fldr.pObj.Changed:Connect(function()
					if fldr.pObj.Value == nil then
						if EspObjects:FindFirstChild(player.Name) then
							EspObjects:FindFirstChild(player.Name):Destroy()
						end
						func3:Disconnect()
					end
				end)
			end
		elseif plr.Team == player.Team then 
			CreateEspBox(player.Character:FindFirstChild("Head"), Color3.fromRGB(0,255,0))
		elseif plr.Team ~= player.Team then 
			CreateEspBox(player.Character:FindFirstChild("Head"), Color3.fromRGB(255,0,0))
		end
	end
	func1 = player.CharacterAdded:Connect(function(char)
		wait(1)
		if player.Character ~= nil then
			func2 = player.Character:WaitForChild("Humanoid").Died:Connect(function()
				if EspObjects:FindFirstChild(player.Name) then
					EspObjects:FindFirstChild(player.Name):Destroy()
				end
			end)
		end
		if EspEnabled == true then
			if plr.Team == nil or player.Team == nil or plr.Neutral == true or player.Neutral == true then
				CreateEspBox(char:FindFirstChild("Head"), Color3.fromRGB(255,0,0))
			elseif plr.Team == player.Team then 
				CreateEspBox(char:FindFirstChild("Head"), Color3.fromRGB(0,255,0))
			elseif plr.Team ~= player.Team then 
				CreateEspBox(char:FindFirstChild("Head"), Color3.fromRGB(255,0,0))
			end
		else
			if EspObjects:FindFirstChild(player.Name) then
				EspObjects:FindFirstChild(player.Name):Destroy()
			end
			func2:Disconnect()
			func1:Disconnect()
		end
	end)
	if player.Character ~= nil then
		func2 = player.Character:WaitForChild("Humanoid").Died:Connect(function()
			if EspObjects:FindFirstChild(player.Name) then
				EspObjects:FindFirstChild(player.Name):Destroy()
			end
		end)
	end
	return
end
local function EnableEsp()
	if EspEnabled == true then
		for i,v in pairs(Players:GetPlayers()) do
			if v ~= plr then
				ConnectEsp(v)
			end
		end
	end
end
Players.PlayerAdded:Connect(function(player)
	if EspEnabled == true then
		ConnectEsp(player)
	end
end)
Players.PlayerRemoving:Connect(function(player)
	if EspObjects:FindFirstChild(player.Name) then
		EspObjects:FindFirstChild(player.Name):Destroy()
	end
end)
UIS.InputBegan:Connect(function(KEY, gpe)
	if gpe then return end;
	if KEY.KeyCode == _G.START_AIMBOT then
		if AIMBOT == false then
			AIMBOT = true
			SendMessage("Aimbot enabled.",
				"AimHot has been enabled.",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		elseif AIMBOT == true then
			AIMBOT = false
			SendMessage("Aimbot disabled.",
				"AimHot has been disabled.",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end
	end
	if KEY.KeyCode == _G.START_ESP then
		if EspEnabled == false then
			SendMessage("ESP has been enabled.",
				"ESP enabled;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
			EspEnabled = true
			EnableEsp()
			while EspEnabled == true do
				ClearEsp()
				EnableEsp()
				wait(1)
			end
		elseif EspEnabled == true then
			SendMessage("ESP has been disabled.",
				"ESP disabled;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
			EspEnabled = false
			ClearEsp()
		end
	end
end)
 
RunService.RenderStepped:Connect(function()
	if (AIMBOT == true and plr.Character ~= nil and plr.Character:FindFirstChild("Humanoid") and plr.Character.Humanoid.Health > 0) then
		local closestPart = GetClosestPlayer(false,{})
		if closestPart ~= nil then
			camera.CoordinateFrame = CFrame.new(camera.CoordinateFrame.p, closestPart.CFrame.p)
			if _G.AUTO_TRIGGER == true then
				mouse1click()
			end
		end
	end
end)
_G.AIMHOT_SECRETKEY = "dF10qLMn" --Not kind of secret but..
 
local helptxt = (
		"AimHot loaded. Time taken: ".. tick()-startTime .."\n"..
		"AimHot made by Herrtt#3868." .."\n"..
		"	Command prefix are: "..(_G.PREFIX) .."\n"..
		"	Commands are;" .."\n"..
		"	<prefix>maxdist <number> (counted in studs)" .."\n"..
		"	<prefix>ignoreteam <bool> (true/false)" .."\n"..
		"	<prefix>targetpart <string> (Head, Torso etc.)" .."\n"..
		"	<prefix>addfriend <plrname> (ROBLOX, etc.)" .."\n"..
		"	<prefix>removefriend <plrname> (ROBLOX, etc.)" .."\n"..
		"	<prefix>changepref <newprefix>" .."\n"..
		"	<prefix>friends" .."\n"..
		"	<prefix>help" .."\n"..
		"	/e reset (will set all settings to regular.)" .."\n"..
		"	Have fun!"
		)
 
plr.Chatted:Connect(function(msg)
	local pref = _G.PREFIX
	if type(pref) ~= "string" then
		print("Prefix must be a string!")
	end
 
	if string.sub(msg,1,8+pref:len()) == pref.."maxdist " then
		local maxdist = tonumber(string.sub(msg,9,msg:len()))
		if type(maxdist) == "number" then
			_G.MAX_DIST = maxdist
			SendMessage("Changed maxdist to; "..(tostring(maxdist)),
				"Setting Changed;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end
	end
	if string.sub(msg,1,11+pref:len()) == pref.."ignoreteam " then 
		local setting = string.sub(msg,12,msg:len()):lower()
		print(setting)
		if setting == "true" or "false" then 
			_G.IGNORE_TEAM = setting
 
			SendMessage("Changed ignoreteam to; "..(tostring(setting)),
				"Setting Changed;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end
	end
	if string.sub(msg,1,11+pref:len()) == pref.."targetpart " then
		local setting = string.sub(msg,12,msg:len())
		if type(setting) == "string" then 
			_G.TARGET_PART = setting
 
			SendMessage("Changed targetpart to; "..(tostring(setting)),
				"Setting Changed;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end	
	end
	if string.sub(msg,1,13+pref:len()) == pref.."removefriend " then
		local setting = string.sub(msg,14,msg:len())
		if type(setting) == "string" then 
			for i,v in pairs(_G.FRIEND_LIST) do
				if v:lower() == setting:lower() then
					table.remove(_G.FRIEND_LIST,i)
				end
			end
			SendMessage("Removed player from friend list; "..(tostring(setting)),
				"Friend removed;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end	
	end
	if string.sub(msg,1,10+pref:len()) == pref.."addfriend " then
		local setting = string.sub(msg,11,msg:len())
		if type(setting) == "string" then 
			for i,v in pairs(_G.FRIEND_LIST) do
				if v == setting:lower() then
					return
				end
			end
			table.insert(_G.FRIEND_LIST,setting:lower())
			SendMessage("Added player to friend list; "..(tostring(setting)),
				"Friend added;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end	
	end
	if string.sub(msg,1,7+pref:len()) == pref.."friends" then
		local friends = ""
		for i,v in pairs(_G.FRIEND_LIST) do
			if i == 1 then
				friends = v
			else
				friends = friends..", "..v
			end
		end
		SendMessage("Your friends are; " .."\n".. friends,
			"Your friends;",
			3,
			Enum.FontSize.Size28,
			Color3.fromRGB(200,50,50)
		)
	end
	if string.sub(msg,1,11+pref:len()) == pref.."changepref " then
		local setting = string.sub(msg,12+pref:len(),msg:len())
		if type(setting) == "string" then
			_G.PREFIX = setting
			SendMessage("Changed prefix to; "..setting,
				"Setting changed;",
				3,
				Enum.FontSize.Size28,
				Color3.fromRGB(200,50,50)
			)
		end
	end
	if string.sub(msg,1,4+pref:len()) == pref.."help" then
		SendMessage(helptxt,
			"AimHot by Herrtt#3868;",
			3,
			Enum.FontSize.Size28,
			Color3.fromRGB(200,50,50)
		)
	end
	if msg == "/e reset" then
		_G.FRIEND_LIST = {"ROBLOX","builderman"}
 
		_G.IGNORE_TEAM = true
		_G.START_AIMBOT = Enum.KeyCode.H
		_G.MAX_DIST = 5000
		_G.TARGET_PART = "Head"
		_G.PREFIX = "/e "
 
		SendMessage("All settings are set back to regular.",
			"Settings reseted.",
			Enum.FontSize.Size28,
			Color3.fromRGB(200,50,50)
		)
	end
end)
 
SendMessage(helptxt,
	"AimHot by Herrtt#3868;",
	3,
	Enum.FontSize.Size28,
	Color3.fromRGB(200,50,50)
)
_G.AIMHOT_VERSION = "4.0"
 
--[[
	Made by PresidentIvan!
--]]
 
   end,
})

local Button = MainTab:CreateButton({
   Name = "god mode",
   Callback = function()
   game.Players.LocalPlayer.Character.Humanoid.Name = 1
local l = game.Players.LocalPlayer.Character["1"]:Clone()
l.Parent = game.Players.LocalPlayer.Character
l.Name = "Humanoid"
wait(0.1)
game.Players.LocalPlayer.Character["1"]:Destroy()
game.Workspace.CurrentCamera.CameraSubject = game.Players.LocalPlayer.Character
game.Players.LocalPlayer.Character.Animate.Disabled = true
wait(0.1)
game.Players.LocalPlayer.Character.Animate.Disabled = false
game.Players.LocalPlayer.Character.Humanoid.DisplayDistanceType = "None"
end,
})

local Button = MainTab:CreateButton({
   Name = "ESP",
   Callback = function()
      local playerGui = game.Players.LocalPlayer:WaitForChild("PlayerGui")
 
-- check if the ScreenGui already exists, if it does, destroy it and remove BillboardGuis
if playerGui:FindFirstChild("TadachiisESP") then
    playerGui:FindFirstChild("TadachiisESP"):Destroy()
 
    for _, player in ipairs(game.Players:GetPlayers()) do
        local billboardGui = player.Character and player.Character:FindFirstChild("Head") and player.Character.Head:FindFirstChild("PlayerBillboardGui")
        if billboardGui then
            billboardGui:Destroy()
        end
    end
end
 
-- create ScreenGui
local screenGui = Instance.new("ScreenGui")
screenGui.Name = "TadachiisESP"
screenGui.Parent = playerGui
screenGui.DisplayOrder = 1
 
-- create Frame
local holder = Instance.new("Frame")
holder.Name = "Holder"
holder.Parent = screenGui
holder.Size = UDim2.new(0, 200, 0, 100) -- size of the frame
holder.Position = UDim2.new(0.5, -100, 0.5, -50) -- position of the frame at the center of the screen
holder.BackgroundColor3 = Color3.new(1, 1, 1) -- white background
holder.BackgroundTransparency = 0.5 -- semi-transparent
holder.Draggable = true -- makes the frame draggable
holder.Active = true
 
-- create TextLabel
local titleLabel = Instance.new("TextLabel")
titleLabel.Name = "TitleLabel"
titleLabel.Text = "Tadachii's ESP GUI"
titleLabel.TextScaled = true
titleLabel.Parent = holder
titleLabel.Size = UDim2.new(1, 0, 0.5, 0) -- fills half of the frame
titleLabel.BackgroundColor3 = Color3.new(1, 1, 1) -- white background
titleLabel.TextColor3 = Color3.new(0, 0, 0) -- black text
titleLabel.BackgroundTransparency = 0.5 -- semi-transparent
 
-- create TextLabel for Status
local statusLabel = Instance.new("TextLabel")
statusLabel.Name = "StatusLabel"
statusLabel.Text = ""
statusLabel.Parent = holder
statusLabel.Size = UDim2.new(1, 0, 0.25, 0) -- fills one-fourth of the frame below the TitleLabel
statusLabel.Position = UDim2.new(0, 0, 0.5, 0) -- aligns the text label to the bottom of the frame
statusLabel.BackgroundColor3 = Color3.new(1, 1, 1) -- white background
statusLabel.TextColor3 = Color3.new(0, 0, 0) -- black text
statusLabel.BackgroundTransparency = 0.5 -- semi-transparent
statusLabel.TextScaled = true -- enable text scaling for the status label
 
-- create TextButton for Status
local statusButton = Instance.new("TextButton")
statusButton.Name = "StatusButton"
statusButton.Text = "Off"
statusButton.Parent = holder
statusButton.Size = UDim2.new(1, 0, 0.25, 0) -- fills one-fourth of the frame below the StatusLabel
statusButton.Position = UDim2.new(0, 0, 0.75, 0) -- aligns the button to the bottom of the frame
statusButton.BackgroundColor3 = Color3.new(1, 1, 1) -- white background
statusButton.TextColor3 = Color3.new(0, 0, 0) -- black text
statusButton.BackgroundTransparency = 0.5 -- semi-transparent
statusButton.TextScaled = true -- enable text scaling for the button
 
-- Function to create BillboardGui for a player with name and distance
local function createBillboardGuiForPlayer(player, distance)
    local billboardGui = Instance.new("BillboardGui")
    billboardGui.Name = "PlayerBillboardGui"
    billboardGui.Adornee = player.Character.Head
    billboardGui.Size = UDim2.new(0, 100, 0, 50) -- fixed size for the BillboardGui
    billboardGui.StudsOffset = Vector3.new(0, 2, 0) -- adjust the vertical offset as needed
    billboardGui.AlwaysOnTop = true
    billboardGui.LightInfluence = 1
    billboardGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
    billboardGui.Parent = player.Character.Head
 
    local textLabel = Instance.new("TextLabel")
    textLabel.Name = "PlayerNameLabel"
    textLabel.Text = player.Name .. "\nDistance: " .. math.floor(distance)
    textLabel.Size = UDim2.new(1, 0, 1, 0)
    textLabel.BackgroundTransparency = 1 -- transparent background
    textLabel.TextColor3 = Color3.new(1, 0, 0) -- red text for the player's name
    textLabel.TextScaled = true
    textLabel.TextStrokeColor3 = Color3.new(0, 0, 0) -- black text stroke
    textLabel.TextStrokeTransparency = 0 -- fully opaque text stroke (visible through walls)
    textLabel.Visible = statusButton.Text == "On" -- Hide the text if StatusButton is "Off"
    textLabel.Parent = billboardGui
end
 
-- Function to update player ESP distance
local function updatePlayerESP()
    local localCharacter = game.Players.LocalPlayer.Character
    if not localCharacter then
        return
    end
 
    for _, player in ipairs(game.Players:GetPlayers()) do
        if player ~= game.Players.LocalPlayer and player.Character and player.Character:FindFirstChild("Head") then
            local distance = (localCharacter.Head.Position - player.Character.Head.Position).Magnitude
            local billboardGui = player.Character.Head:FindFirstChild("PlayerBillboardGui")
            if billboardGui then
                billboardGui.PlayerNameLabel.Text = player.Name .. "\nDistance: " .. math.floor(distance)
                billboardGui.PlayerNameLabel.TextColor3 = Color3.new(1, 0, 0) -- Set the text color to red
                billboardGui.PlayerNameLabel.Visible = statusButton.Text == "On" -- Update visibility based on StatusButton
            else
                createBillboardGuiForPlayer(player, distance)
            end
        end
    end
end
 
-- Call updatePlayerESP() initially and then schedule it to be called every 0.01 seconds
updatePlayerESP()
game:GetService("RunService").Heartbeat:Connect(function()
    updatePlayerESP()
end)
 
-- Now, you can add functionality to the button, for example:
local function onButtonClicked()
    if statusButton.Text == "Off" then
        statusButton.Text = "On"
        -- Add code to enable the player ESP here
    else
        statusButton.Text = "Off"
        -- Add code to disable the player ESP here
        
        -- Remove BillboardGui for each player's head when disabling the ESP
        for _, player in ipairs(game.Players:GetPlayers()) do
            local billboardGui = player.Character and player.Character:FindFirstChild("Head") and player.Character.Head:FindFirstChild("PlayerBillboardGui")
            if billboardGui then
                billboardGui:Destroy()
            end
        end
    end
    -- Update the visibility of BillboardGui elements after clicking the button
    for _, player in ipairs(game.Players:GetPlayers()) do
        local billboardGui = player.Character and player.Character:FindFirstChild("Head") and player.Character.Head:FindFirstChild("PlayerBillboardGui")
        if billboardGui then
            billboardGui.PlayerNameLabel.Visible = statusButton.Text == "On"
        end
    end
end
 
statusButton.MouseButton1Click:Connect(onButtonClicked)          
   end,
})
