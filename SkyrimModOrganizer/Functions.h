#pragma once
#include "Defines.h"

#pragma region Main Functions
void AddMod()
{
	//Step 1: Ask for a mod number. Once the input is a valid number,
	//check to see if a mod with that number alreay exists. If it does,
	//end the code. In not, continue inputting information
	//STATUS: COMPLETE
	int mNumber = SetModNumber(ModList);
	if (mNumber == -1)
	{
		std::cout << "A Mod With This Number Already Exists\n";
		return;
	}
	AddModToModList(mNumber);
}
void DisplayAllMods()
{
	//Calls the DisplayMod function for each mod that exists in the ModList vector
	for (const auto& m : ModList)
	{
		DisplayMod(m);
		std::cout << std::endl;
	}
}
#pragma endregion

#pragma region Set Functions
SSECategory         SetModCategory()
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

bool                SetModInstalled()
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
std::string         SetModLink(int mNumber)
{
	std::string numString = std::to_string(mNumber);
	const char* path = numString.c_str();
	const char* baseURL = "https://www.nexusmods.com/skyrimspecialedition/mods/";
	int len = 52 + strlen(path) + 1;
	char* result = new char[len];
	strcpy_s(result, len, baseURL);
	strcat_s(result, len, path);
	std::string url(result);
	delete[] result;
	return url;
}
std::string         SetModNameAuthor(const char* prompt)
{
	ClearCIN();
	std::string input;
	std::cout << prompt;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Invalid Entry. " << prompt;
		getline(std::cin, input);
	}
	return input;
}
int                 SetModNumber(std::vector<SSEMod>& mList)
{
	int mNumber;
	std::cout << "Enter Mod Number: ";
	std::cin >> mNumber;
	while (!std::cin.good() || mNumber < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> mNumber;
	}

	auto result = FindMod(mList, mNumber);
	if (result.first)//A mod that has the number mNumber has been found
	{
		return -1;
	}
	return mNumber;
}
#pragma endregion

#pragma region Display Functions
void        DisplayAllCategories()
{
	std::cout << "If the mod has no category, enter 0\n";
	// Calculate the number of rows needed
	int num_rows = (categories.size() + 3) / 4;

	// Loop over each row
	for (int i = 0; i < num_rows; i++) {
		// Loop over each column in the row
		for (int j = 0; j < 4; j++) {
			// Calculate the index of the current category
			int index = i * 4 + j;
			// Check if we've gone past the end of the vector
			if (index >= categories.size()) {
				break;
			}
			// Output the category number and name with some formatting
			if (index + 1 < 10)
			{
				std::cout << std::setw(1) << std::left << (index + 1) << ")  " << std::setw(37) << std::left << categories[index];
			}
			else
			{
				std::cout << std::setw(1) << std::left << (index + 1) << ") " << std::setw(37) << std::left << categories[index];
			}
		}
		std::cout << std::endl;
	}
}
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
void        DisplayChoices(std::vector<const char*> options)
{
	for (int i = 0; i < options.size(); i++)
	{
		std::cout << i + 1 << ") " << options[i] << std::endl;
	}
}
void		DisplayDependencies(std::vector<SSEMod> mDependencies)
{
	std::cout << "----------Dependencies----------\n";
	for (auto d : mDependencies)
	{
		std::cout << d.mNumber << ": " << d.mName << std::endl;
	}
	std::cout << "--------------------------------\n";
}
const char* DisplayIsInstalled(bool mInstalled)
{
	if (mInstalled)
	{
		return "Is Installed";
	}
	else
	{
		return "Is Not Installed";
	}
}
void        DisplayMod(SSEMod mod)
{

	std::cout << "Mod Name: "           << mod.mName                          << '\n' <<
		         "Mod Number: "         << mod.mNumber                        << '\n' <<
		         "Mod Author: "         << mod.mAuthor                        << '\n' <<
		         "Mod Category: "       << DisplayCategoryName(mod.mCategory) << '\n' <<
		         "Mod Install Status: " << DisplayIsInstalled(mod.mInstalled) << '\n' <<
				 "Mod Link: "           << mod.mLink                          << '\n';
	DisplayDependencies(mod.mDependencies);
}
#pragma endregion

#pragma region Helper Functions
void                 AddModToModList(int mNumber)
{
	std::string mLink = SetModLink(mNumber);
	std::string mName = SetModNameAuthor("Enter Mod Name: ");
	SSECategory mCategory = SetModCategory();
	std::string mAuthor = SetModNameAuthor("Enter Mod Author: ");
	bool mInstalled = SetModInstalled();
	std::vector<SSEMod> mDependencies;// = SetModDependencies();
	SSEMod mod = SSEMod{ mName, mNumber, mAuthor, mCategory, mInstalled, mLink, mDependencies };
	ModList.emplace_back(mod);
}
void                 ClearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
std::pair<bool, int> FindMod(std::vector<SSEMod>& mList, int mNumber)
{
	int i = 0;
	for (const auto& mod : mList)
	{
		if (mod.mNumber == mNumber)
		{
			return std::make_pair(true, i);//Mod Found
		}
		i++;
	}
	return std::make_pair(false, -1);//Mod Not Found
}
std::pair<bool, int> FindMod(std::vector<SSEMod>& mList, std::string mName)
{
	int i = 0;
	for (const auto& mod : mList)
	{
		if (mod.mName == mName)
		{
			return std::make_pair(true, i);//Mod Found
		}
		i++;
	}
	return std::make_pair(false, -1);//Mod Not Found
}
void	             WriteToModList(SSEMod mod)
{
	std::ofstream outFile("ModList.txt", std::ios_base::app);
	if (outFile.is_open())
	{
		outFile << mod.mName << '\n' <<
			mod.mNumber << '\n' <<
			mod.mAuthor << '\n' <<
			DisplayCategoryName(mod.mCategory) << '\n' <<
			DisplayIsInstalled(mod.mInstalled) << '\n' <<
			mod.mLink << '\n' <<
			"----------Dependencies----------\n";
		for (auto d : mod.mDependencies)
		{
			outFile << d.mNumber << std::endl;
		}
		outFile << "--------------------------------\n";
		outFile.close();
	}
	else
	{
		std::cout << "Unable to open file!" << std::endl;
		return;
	}
}
#pragma endregion





/*
std::vector<SSEMod> SetModDependencies()
{
	//Step 1: Ask the user to input whetehr or not the mod has any dependencies and ensure that what was entered is a valid input.
	//STATUS: IN PROGRESS
}
*/

void AddDependencyMod(std::vector<SSEMod>& mDependencies)
{
	//Step 1: Ask the user to enter in the mod's number and ensure that what was entered is a valid input.
	//STATUS: COMPLETE
	int mNumber;
	std::cout << "Enter Mod Number: ";
	std::cin >> mNumber;
	while (!std::cin.good() || mNumber < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> mNumber;
	}

	//Step 2: Determine if the mod already exists in the mDependecies vector. If it does, end the function.
	//STATUS: COMPLETE
	auto result = FindMod(mDependencies, mNumber);
	if (result.first)//Mod Found in mDependencies
		return;
	
	//Step 3: Determine if the mod already exists in the ModList vector. If it does put that mod into mDependencies and exit out of the function.
	//STATUS: COMPLETE
	result = FindMod(ModList, mNumber);
	if (result.first)//Mod Found in ModList
	{
		mDependencies.push_back(ModList[result.second]);
		return;
	}
	
	//Step 4: If there is no such mod, create it, put the mod first into Modlist, then take the pointer to that mod in ModList and put it in mDependencies.
	//STATUS: IN PROGRESS
	AddModToModList(mNumber);
	mDependencies.push_back(ModList.back());

}

