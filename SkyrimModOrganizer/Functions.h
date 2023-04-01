#pragma once
#include "Defines.h"

#pragma region Main Functions
void AddMod()
{
	//int mNumber = -1;
	//SSECategory mCategory = NoCategory;
	int mNumber = SetModNumber();
	if (mNumber == -1)
	{
		std::cout << "This Mod Already Exists\n";
	}
	else
	{
		SSECategory mCategory = SetModCategory();
		bool mInstalled = SetModInstalled();
		CreateMod(mNumber, mCategory, mInstalled);
	}
	std::cout << "Number of Mods: " << ModList.size() << std::endl;
}
#pragma endregion

#pragma region Set Functions
int SetModNumber()
{
	/*
	To Do:
		1. Check to see if the mod number (thus the mod) already exists. If it does, stop the function
	*/
	//ClearCIN();
	int mNumber;
	std::cout << "Enter Mod Number: ";
	std::cin >> mNumber;
	while (!std::cin.good() || mNumber < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> mNumber;
	}
	if (FindMod(mNumber) == -1) 
	{
		return mNumber;
	}
	else
	{
		return -1;
	}
}

SSECategory SetModCategory()
{

	int mCategory;
	std::cout << "Here are the mod categories.\n";
	DisplayAllCategories();
	std::cout << "Enter Mod Category: ";
	std::cin >> mCategory;
	while (!std::cin.good() || mCategory < 0 || mCategory > 48)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Category: ";
		std::cin >> mCategory;
	}
	return (SSECategory)mCategory;
}

bool SetModInstalled()
{
	bool mInstalled;
	std::cout << "Is the mod installed? (1 = Yes, 0 = No): ";
	std::cin >> mInstalled;
	while (!std::cin.good() || (mInstalled != 0 && mInstalled != 1))
	{
		ClearCIN();
		std::cout << "Invalid Entry. Is the mod installed? (1 = Yes, 0 = No): ";
		std::cin >> mInstalled;
	}
	return mInstalled;
}
#pragma endregion

#pragma region Display Functions
const char* DisplayCategoryName(int category)
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

void DisplayUserOptions()
{
	for (int i = 0; i < UserOptions.size(); i++)
	{
		std::cout << i + 1 << ": " << UserOptions[i] << std::endl;
	}
}

void DisplayMod(SSEMod mod)
{
	
	std::cout << "Mod Number: " << mod.mNumber << '\n' <<
				 "Mod Category: " << DisplayCategoryName(mod.mCategory) << '\n' <<
				 "Mod Install Status: " << DisplayIsInstalled(mod.mInstalled) << std::endl;
}

const char* DisplayIsInstalled(bool mInstalled)
{
	if (mInstalled)
	{
		return "True";
	}
	else
	{
		return "False";
	}
}
#pragma endregion

#pragma region Helper Functions
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
	return -1;
}

void CreateMod(int mNumber, SSECategory mCategory, bool mInstalled)
{
	ModList.push_back(SSEMod{ mNumber, mCategory, mInstalled });
}
#pragma endregion
