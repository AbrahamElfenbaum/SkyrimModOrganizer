#pragma once
#include "Defines.h"


#pragma region Main Functions
//Adds a mod to the Mods vector
void AddMod()
{
	/*
	To Do:
		1. What happens when a mod is not on Nexus? (SKSE)
	*/
	Mod newMod;
	SetModNumber(newMod);
	SetModLink(newMod);
	SetModName(newMod);
	//SetModDependencies(newMod);
	SetModCategory(newMod);
	SetModAuthor(newMod);
	
	//SetModInstallStatus(newMod);
	DisplayMod(newMod);

	Mods.push_back(newMod);
}

//Shows all mods in the Mods vector
void ShowMods()
{

}

//Finds a specific mod, if it exists
void FindMod()
{

}

//Removes a mod from the Mods vector
void RemoveMod()
{

}

//Edits a specific mod in the Mods vector
void EditMod()
{

}
#pragma endregion

#pragma region Set Functions
void SetModNumber(Mod m)
{
	/*
	To Do:
		1. Check to see if the mod number (thus the mod) already exists. If it does, stop the function
	*/

	std::cout << "Enter Mod Number: ";
	std::cin >> m.mNumber;
	while (!std::cin.good() || m.mNumber < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> m.mNumber;
	}
	std::cout << "Mod Number: " << m.mNumber << '\n';
}

void SetModName(Mod m)
{
	/*
	To Do:
		1. See if there is a way to make a string more compact to save space on a .txt file
		2. Convert the string into all caps
	*/
	m.mName = EnterString("Enter Mod Name: ");
	std::cout << "Mod Name: " << m.mName << '\n';
}

void SetModDependencies(Mod m)
{
	/*
	To Do:
		Ask the user to input the mod number. If the mod exists, put said mod into the dependencies vector.
		If the mod does not exist, ask the user if they want to add this mod or skip it.
	*/
}

void SetModCategory(Mod m)
{
	/*
	To Do:
	*/

	int category;
	std::cout << "Here are the mod categories.\n";
	ShowAllCategories();
	std::cout << "Enter Mod Category : ";
	std::cin >> category;
	while (!std::cin.good() || category < 0 || category > 48)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Entry. Enter Mod Category: ";
		std::cin >> category;
	}
	m.mCategory = (Category)category;
}

void SetModAuthor(Mod m)
{
	/*
	To Do:
		1. See if there is a way to make a string more compact to save space on a .txt file
		2. Convert the string into all caps
	*/
	m.mAuthor = EnterString("Enter Mod Author: ");
	std::cout << "Mod Author: " << m.mAuthor << '\n';
}

void SetModLink(Mod m)
{
	/*
	To Do:
		1. See if there is a way to make a string more compact to save space on a .txt file
	*/
	//auto v = std::to_string(m.mNumber);
	//m.mLink = "https://www.nexusmods.com/skyrimspecialedition/mods/" + v;
	//std::cout << "Mod Link: " << m.mLink << '\n';
}

void SetModInstallStatus(Mod m)
{
	/*
	To Do:
		1. See if there is a better way to make this smoother.
	*/
	std::cout << "Is the mod installed? ";
	std::cin >> m.isInstalled;
	while (m.isInstalled != 0 && m.isInstalled != 1)
	{
		std::cout << "Invalid Entry. Is the mod installed? ";
		std::cin >> m.isInstalled;
	}
}
#pragma endregion

#pragma region Display Functions
void DisplayMod(Mod m)
{

}

void DisplayAllMods()
{

}

/// <summary>
/// Depending on the input of the function, the output will be the actual name of
/// the mod category, rather than the enum value.
/// </summary>
/// <param name="category">Enum Value</param>
/// <returns>Category Name</returns>
std::string ShowCategoryName(int category)
{
	switch (category)
	{
	case NoCategory:
		return "No Category";
	case Alchemy:
		return "Alchemy";
	case Animation:
		return "Animation";
	case Armour:
		return "Armour";
	case Armour_Shields:
		return "Armour - Shields";
	case Audio:
		return "Audio";
	case Body_Face_Hair:
		return "Body, Face, and Hair";
	case Bug_Fixes:
		return "Bug Fixes";
	case Buildings:
		return "Buildings";
	case Cheats_GodItems:
		return "Cheats and God items";
	case Cities_Towns_Villages_Hamlets:
		return "Cities, Towns, Villages, and Hamlets";
	case Clothing_Accessories:
		return "Clothing and Accessories";
		break;
	case Collectables_Treasure_Hunts_Puzzles:
		return "Collectables, Treasure Hunts, and Puzzles";
	case Combat:
		return "Combat";
	case Crafting:
		return "Crafting";
	case Creatures_Mounts:
		return "Creatures and Mounts";
	case Dungeons:
		return "Dungeons";
	case Environmental:
		return "Environmental";
	case Followers_Companions:
		return "Followers & Companions";
	case Followers_Companions_Creatures:
		return "Followers & Companions - Creatures";
	case Gameplay:
		return "Gameplay";
	case Guilds_Factions:
		return "Guilds/Factions";
	case Immersion:
		return "Immersion";
	case Items_ObjectsPlayer:
		return "Items and Objects - Player";
	case Items_ObjectsWorld:
		return "Items and Objects - World";
	case Locations_New:
		return "Locations - New";
	case Locations_Vanilla:
		return "Locations - Vanilla";
	case Magic_Gameplay:
		return "Magic - Gameplay";
	case Magic_Spells_Enchantments:
		return "Magic - Spells & Enchantments";
	case Miscellaneous:
		return "Miscellaneous";
	case Modders_Resources:
		return "Modders Resources";
	case Models_Textures:
		return "Models and Textures";
	case NPC:
		return "NPC";
	case Overhauls:
		return "Overhauls";
	case Patches:
		return "Patches";
	case Player_Homes:
		return "Player Homes";
	case Presets_ENB_ReShade:
		return "Presets - ENB and ReShade";
	case Quests_Adventures:
		return "Quests and Adventures";
	case Races_Classes_Birthsigns:
		return "Races, Classes, and Birthsigns";
	case Save_Games:
		return "Save Games";
	case Shouts:
		return "Shouts";
	case Skills_Leveling:
		return "Skills and Leveling";
	case Stealth:
		return "Stealth";
	case User_Interface:
		return "User Interface";
	case Utilities:
		return "Utilities";
	case Visuals_Graphics:
		return "Visuals and Graphics";
	case VR:
		return "VR";
	case Weapons:
		return "Weapons";
	case Weapons_Armour:
		return "Weapons and Armour";
	default:
		return "Default";
	}
}

/// <summary>
/// Displays the list of all possible mod categories.
/// </summary>
void ShowAllCategories()
{
	for (int i = 0; i < 49; i++)
	{
		std::cout << i << ". " << ShowCategoryName(i) << '\n';
	}
}
#pragma endregion

#pragma region Helper Functions
std::string EnterString(std::string prompt)
{
	ClearCIN();
	std::string tempString;
	std::cout << prompt;

	while (getline(std::cin, tempString))
	{
		if (tempString.size() > 0)
		{
			break;
		}
		std::cout << "Invalid Entry! " << prompt;
	}
	return tempString;
}

/// <summary>
/// Calls the necessary to clear cin's error flag and goes to the next line to read
/// </summary>
void ClearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#pragma endregion







