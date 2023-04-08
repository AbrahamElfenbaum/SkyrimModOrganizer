#pragma once
#include "Defines.h"

#pragma region Main Functions
void AddMod()
{

	int mNumber = SetModNumber();//Sets the int that will become the mod's number
	if (mNumber == -1)//-1 means that the mod already exists in ModList
	{
		//Informs the user that the mod already exists and exits out of the function
		std::cout << "This Mod Already Exists\n";
		return;
	}
	//The following only happens if the mod number was not found in ModList
	std::string         mLink         = CreateModLink(mNumber);//creates the link to the mod on Nexus.com using the mod's number to complete the url
	std::string         mName         = SetModNameAuthor("Enter Mod Name: ");//Sets the string that will become the name of the mod
	SSECategory         mCategory     = SetModCategory();//Sets the SSECategory that will become the category of the mod
	std::string         mAuthor       = SetModNameAuthor("Enter Mod Author: ");//Sets the string that will become the author of the mod
	bool                mInstalled    = SetModInstalled();//Sets the bool that will tell if the mod is installed or not
	std::vector<SSEMod> mDependencies = SetModDependencies();//Sets the SSEMod vector that will become the list of the mod's dependecies
	ModList.push_back(CreateMod(mName, mNumber, mAuthor, mCategory,  mInstalled, mLink, mDependencies));//Pushes the created mod into the ModList vector.
}
void DisplayAllMods()
{
	//Calls the DisplayMod function for each mod that exists in the ModList vector
	for (auto m : ModList)
	{
		DisplayMod(m);
		std::cout << std::endl;
	}
}
void EditMod(int mNumber)
{
	if (FindMod(ModList, mNumber) == -1)
	{
		std::cout << "No Such Mod Exists\n";
		return;
	}
}
void RemoveMod(int mNumber)
{
	if (FindMod(ModList, mNumber) == -1)
	{
		std::cout << "No Such Mod Exists\n";
		return;
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
std::vector<SSEMod> SetModDependencies()
{
	bool loop;
	std::vector<SSEMod> mDependencies;
	std::cout << "Does the mod have any dependencies? (1 = Yes, 0 = No): ";
	std::cin >> loop;
	while (!std::cin.good() || (loop != 0 && loop != 1))
	{
		ClearCIN();
		std::cout << "Invalid Entry. Does the mod have any dependencies? (1 = Yes, 0 = No): ";
		std::cin >> loop;
	}
	while (loop)
	{
		AddDependencyMod(mDependencies);
		std::cout << "Does the mod have another dependency? (1 = Yes, 0 = No): ";
		std::cin >> loop;
		while (!std::cin.good() || (loop != 0 && loop != 1))
		{
			ClearCIN();
			std::cout << "Invalid Entry. Does the mod have another dependency? (1 = Yes, 0 = No): ";
			std::cin >> loop;
		}
	}
	return mDependencies;
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
int                 SetModNumber()
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
	if (FindMod(ModList, mNumber) == -1) 
	{
		//Mod Doesn't Exist
		return mNumber;
	}
	//Mod Exists
	return -1;
}
#pragma endregion

#pragma region Display Functions
void        DisplayAllCategories()
{
	// Define a vector of Skyrim mod categories
	std::vector<std::string> categories =
	{
		"Alchemy",               "Animation",                            "Armour",
		"Armour - Shields",                          "Audio",                 "Body, Face, and Hair",                 "Bug Fixes",
		"Buildings",                                 "Cheats and God items",  "Cities, Towns, Villages, and Hamlets", "Clothing and Accessories",
		"Collectables, Treasure Hunts, and Puzzles", "Combat",                "Crafting",                             "Creatures and Mounts",
		"Dungeons",                                  "Environmental",         "Followers & Companions",               "Followers & Companions - Creatures",
		"Gameplay",                                  "Guilds/Factions",       "Immersion",                            "Items and Objects - Player",
		"Items and Objects - World",                 "Locations - New",       "Locations - Vanilla",                  "Magic - Gameplay",
		"Magic - Spells & Enchantments",             "Miscellaneous",         "Modders Resources",                    "Models and Textures",
		"NPC",                                       "Overhauls",             "Patches",                              "Player Homes",
		"Presets - ENB and ReShade",                 "Quests and Adventures", "Races, Classes, and Birthsigns",       "Save Games",
		"Shouts",                                    "Skills and Leveling",   "Stealth",                              "User Interface",
		"Utilities",                                 "Visuals and Graphics",  "VR",                                   "Weapons",
		"Weapons and Armour"
	};
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
}
void        DisplayUserOptions(std::vector<const char*> options)
{
	for (int i = 0; i < options.size(); i++)
	{
		std::cout << i + 1 << ": " << options[i] << std::endl;
	}
}
#pragma endregion

#pragma region Helper Functions
void        AddDependencyMod(std::vector<SSEMod>& mDependencies)
{
	int nmNumber;
	std::cout << "Enter Mod Number: ";
	std::cin >> nmNumber;
	while (!std::cin.good() || nmNumber < 0)
	{
		ClearCIN();
		std::cout << "Invalid Entry. Enter Mod Number: ";
		std::cin >> nmNumber;
	}
	if (FindMod(ModList, nmNumber) > -1)//The mod already exists in ModList
	{
		if (FindMod(mDependencies, nmNumber))//The mod is already in mDependencies
		{
			return;
		}
		mDependencies.push_back(ModList[FindMod(ModList, nmNumber)]);
		return;
	}
	std::string         nmLink         = CreateModLink(nmNumber);
	std::string         nmName         = SetModNameAuthor("Enter Mod Name: ");
	SSECategory         nmCategory     = SetModCategory();
	std::string         nmAuthor       = SetModNameAuthor("Enter Mod Author: ");
	bool                nmInstalled    = SetModInstalled();
	std::vector<SSEMod> nmDependencies = SetModDependencies();
	SSEMod              newMod        = CreateMod(nmName, nmNumber, nmAuthor, nmCategory, nmInstalled, nmLink, nmDependencies);
	ModList.push_back(newMod);
	mDependencies.push_back(newMod);
}
void        ClearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
SSEMod      CreateMod(std::string mName, int mNumber,       std::string mAuthor, SSECategory mCategory, 
					  bool mInstalled,   std::string mLink, std::vector<SSEMod> mDependencies)
{
	return SSEMod{ mName, mNumber, mAuthor, mCategory, mInstalled, mLink, mDependencies };
}
std::string CreateModLink(int mNumber)
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
int         FindMod(std::vector<SSEMod> mList, int mNumber)
{
	for (int i = 0; i < mList.size(); i++)
	{
		if (mList[i].mNumber == mNumber)
		{
			//Mod Exists
			return i;
		}
	}
	//Mod Doesn't Exits
	return -1;
}
#pragma endregion