#pragma once
#include "DefinesOLD.h"


#pragma region Main Functions
void AddMod()
{
	/*
	To Do:
		1. What happens when a mod is not on Nexus? (SKSE)
	*/
	SSEMod newMod{};
	SetModNumber(newMod);
	//SetModName(newMod);
	//SetModCategory(newMod);
	//SetModDependencies(newMod);
	//SetModAuthor(newMod);
	//SetModLink(newMod);
	//SetModInstallStatus(newMod);
	//DisplayMod(newMod);
	ModList.push_back(newMod);
}

void EditMod()
{

}

void RemoveMod()
{

}

void DisplayAllMods()
{

}
#pragma endregion

#pragma region Set Functions
void SetModNumber(SSEMod m)
{
	/*
	To Do:
		1. Check to see if the mod number (thus the mod) already exists. If it does, stop the function
	*/
	ClearCIN();
	int temp;
	std::cout << "Enter Mod Number: ";
	std::cin >> temp;
	while (!std::cin.good() || temp < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> temp;
	}

	if (ModList.empty() || (FindMod(temp) == -1))//The mod does not exist
	{
		m.mNumber = temp;
		std::cout << "Mod Number: " << m.mNumber << '\n';
	}
	else
	{
		std::cout << "Mod Already Exists.\n";
	}
		
}

void SetModCategory(SSEMod m)
{
	/*
	To Do:
	*/

	int category;
	std::cout << "Here are the mod categories.\n";
	DisplayAllCategories();
	std::cout << "Enter Mod Category : ";
	std::cin >> category;
	while (!std::cin.good() || category < 0 || category > 48)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Entry. Enter Mod Category: ";
		std::cin >> category;
	}
	m.mCategory = (SSECategory)category;
}

/*
void SetModName(SSEMod m)
{
	
	//To Do:
		//1. See if there is a way to make a string more compact to save space on a .txt file
		//2. Convert the string into all caps

	m.mName = EnterString("Enter Mod Name: ");
	std::cout << "Mod Name: " << m.mName << '\n';
	
}

void SetModDependencies(SSEMod m)
{

	To Do:
		Ask the user to input the mod number. If the mod exists, put said mod into the dependencies vector.
		If the mod does not exist, ask the user if they want to add this mod or skip it.

}

void SetModAuthor(SSEMod m)
{
	To Do:
		1. See if there is a way to make a string more compact to save space on a .txt file
		2. Convert the string into all caps

	m.mAuthor = EnterString("Enter Mod Author: ");
	std::cout << "Mod Author: " << m.mAuthor << '\n';

}

void SetModLink(SSEMod m)
{
	To Do:
		1. See if there is a way to make a string more compact to save space on a .txt file

	auto v = std::to_string(m.mNumber);
	m.mLink = "https://www.nexusmods.com/skyrimspecialedition/mods/" + v;
	std::cout << "Mod Link: " << m.mLink << '\n';
}

void SetModInstallStatus(SSEMod m)
{
	To Do:
		1. See if there is a better way to make this smoother.

	std::cout << "Is the mod installed? ";
	std::cin >> m.isInstalled;
	while (m.isInstalled != 0 && m.isInstalled != 1)
	{
		std::cout << "Invalid Entry. Is the mod installed? ";
		std::cin >> m.isInstalled;
	}
}
*/
#pragma endregion

#pragma region Display Functions
//void DisplayMod(SSEMod m) {}

std::string DisplayCategoryName(int category)
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

void DisplayAllCategories()
{
	for (int i = 0; i < 49; i++)
	{
		std::cout << i << ". " << DisplayCategoryName(i) << '\n';
	}
}

void DisplayUserChoices()
{
	for (int i = 0; i < UserChoices.size(); i++)
	{
		std::cout << i + 1 << ": " << UserChoices[i] << std::endl;
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

void ClearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int FindMod(int mNumber)
{
	for (int i = 0; i < ModList.size(); i++)
	{
		if (ModList[i].mNumber == mNumber)
		{
			return i;
		}
	}
	return -1;//Mod does not exist
}
#pragma endregion







