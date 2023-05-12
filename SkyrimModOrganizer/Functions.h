#pragma once
#include "Defines.h"

#pragma region Main Functions
void AddMod()
{
	auto mNumber = SetModNumber();
	if (mNumber == -1)
	{
		std::cout << "A Mod With This Number Already Exists\n";
		return;
	}
	AddModToModList(mNumber);
}

void DisplayAllMods()
{
	for (auto it = ModList.begin(); it != ModList.end(); it++)
	{
		DisplayMod(it);
	}
}

void EditMod()
{
	auto modIter = FindMod("Enter the name or number of the mod you want to edit: ");
	if (modIter == ModList.end())
	{
		std::cout << "No Such Mod Exists\n";
		return;
	}

	DisplayMod(modIter);
	DisplayChoices(ModProperties);
	int mNumber;
	auto option = GetValidInput<int>("Enter Choice: ", [](int n) { return n >= 1 && n <= 7; });
	switch (option)
	{
	case 1:
		//Edit Name
		const_cast<SSEMod&>(modIter->first).mName = SetModAuthorName("Enter Mod Name: ");
		break;
	case 2:
		//Edit Number
		mNumber = SetModNumber();
		if (mNumber == -1)
		{
			std::cout << "A Mod With This Number Already Exists\n";
			return;
		}
		const_cast<SSEMod&>(modIter->first).mNumber = mNumber;
		break;
	case 3:
		//Edit Author
		const_cast<SSEMod&>(modIter->first).mName = SetModAuthorName("Enter Mod Author: ");
		break;
	case 4:
		//Edit Category
		const_cast<SSEMod&>(modIter->first).mCategory = SetModCategory();
		break;
	
	case 5:
		//Edit Install Status
		const_cast<SSEMod&>(modIter->first).mInstalled = SetModEnabledInstalled("Is the mod installed? (1 = Yes, 0 = No): ");
		break;
	case 6:
		//Edit Enable Status
		const_cast<SSEMod&>(modIter->first).mEnabled = SetModEnabledInstalled("Is the mod enabled? (1 = Yes, 0 = No): ");
		break;
	case 7:
		//Edit Dependencies
		EditDependencies(modIter);
		break;
	default:
		break;
	}
}

void RemoveMod()
{
	auto modIter = FindMod("Enter the name or number of the mod you want to remove: ");
	if (modIter == ModList.end())
	{
		std::cout << "No Such Mod Exists\n";
		return;
	}
	DisplayMod(modIter);
	auto confirm = GetValidInput<bool>("Are you sure you want to delete this mod? (1 = Yes, 0 = No): ", [](bool b) {return b == 0 || b == 1; });
	if (confirm)
	{
		if (FindDependency(modIter->first.mNumber))
		{
			std::cout << "This mod cannot be removed. It is a dependency for another mod.\n";
			return;
		}
		ModList.erase(modIter);
	}
}
#pragma endregion

#pragma region Set Functions
std::string SetModAuthorName(const char* prompt)
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

SSECategory SetModCategory()
{
	std::cout << "Here are the mod categories.\n";
	DisplayAllCategories();
	return static_cast<SSECategory>(GetValidInput<int>("Enter Mod Category: ", [](int n) { return n >= 0 && n <= 48; }));
}

std::vector<const SSEMod*> SetModDependencies(int mNumber)
{
	std::vector<const SSEMod*> mDependencies;
	char prompt[256];
	sprintf_s(prompt, sizeof(prompt), "Does Mod %d have any dependencies? (1 = Yes, 0 = No): ", mNumber);
	auto hasDependency = GetValidInput<bool>(prompt, [](bool b) {return b == 0 || b == 1; });
	if (hasDependency == false)
	{
		return mDependencies;
	}
	sprintf_s(prompt, sizeof(prompt), "Does Mod %d have any more dependencies? (1 = Yes, 0 = No): ", mNumber);
	while (hasDependency)
	{
		AddDependencyMod(mDependencies, mNumber);
		hasDependency = GetValidInput<bool>(prompt, [](bool b) {return b == 0 || b == 1; });
	}
	return mDependencies;
}

bool SetModEnabledInstalled(const char* prompt)
{
	return GetValidInput<bool>(prompt, [](bool b) {return b == 0 || b == 1; });
}

std::string SetModLink(int mNumber)
{
	auto numString = std::to_string(mNumber);
	auto path = numString.c_str();
	int len = 52 + strlen(path) + 1;
	auto result = new char[len];
	strcpy_s(result, len, "https://www.nexusmods.com/skyrimspecialedition/mods/");
	strcat_s(result, len, path);
	std::string url(result);
	delete[] result;
	return url;
}

int SetModNumber()
{
	auto mNumber = GetValidInput<int>("Enter Mod Number: ", [](int n) { return n >= 0; });
	auto result = FindMod(mNumber);
	if (result != ModList.end())//A mod that has the number mNumber has been found
	{
		return -1;
	}
	return mNumber;
}
#pragma endregion

#pragma region Display Functions

void DisplayAllCategories()
{
	std::cout << "If the mod has no category, enter 0\n";
	// Calculate the number of rows needed
	int num_rows = (Categories.size() + 3) / 4;

	// Loop over each row
	for (int i = 0; i < num_rows; i++) {
		// Loop over each column in the row
		for (int j = 0; j < 4; j++) {
			// Calculate the index of the current category
			int index = i * 4 + j;
			// Check if we've gone past the end of the vector
			if (index >= Categories.size()) {
				break;
			}
			// Output the category number and name with some formatting
			if (index + 1 < 10)
			{
				FormatCategoryDisplay(index, ")  ");
			}
			else
			{
				FormatCategoryDisplay(index, ") ");
			}
		}
		std::cout << '\n';
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

void DisplayChoices(const std::vector<const char*>& options)
{
	auto i = 0;
	for (auto option : options)
	{
		std::cout << i + 1 << ") " << options[i] << '\n';
		i++;
	}
}

const char* DisplayBoolValue(bool b, const char* boolT, const char* boolF)
{
	if (b)
	{
		return boolT;
	}
	else
	{
		return boolF;
	}
}

void DisplayMod(MODLISTITERATOR it)
{
	std::cout << "Mod Name: "           << it->first.mName                                                            << '\n' <<
				 "Mod Number: "         << it->first.mNumber                                                          << '\n' <<
				 "Mod Author: "         << it->first.mAuthor                                                          << '\n' <<
				 "Mod Category: "       << DisplayCategoryName(it->first.mCategory)                                   << '\n' <<
				 "Mod Install Status: " << DisplayBoolValue(it->first.mInstalled, "Is Installed", "Is Not Installed") << '\n' <<
				 "Mod Enable Status: "  << DisplayBoolValue(it->first.mEnabled, "Enabled", "Disabled")                << '\n' <<
				 "Mod Link: "           << it->first.mLink                                                            << '\n' << 
		         "Mod Address: "        << &(it->first) << '\n';
	std::cout << "----------Dependencies----------\n";
	
	for (const auto& d : it->second)
	{
		
		std::cout << d->mNumber << ": "     << d->mName << '\n' << 
			         "Dependency Address: " << d        << '\n';

	}
	std::cout << "--------------------------------\n";
}
#pragma endregion

#pragma region Helper Functions
void AddDependencyMod(std::vector<const SSEMod*>& mDependencies, int n)
{
	auto mNumber = GetValidInput<int>("Enter Mod Number: ", [](int n) { return n >= 0; });
	if (mNumber == n)
	{
		std::cout << "Error: Mod cannot be a dependency of itself\n";
		return;
	}

	for (const auto& mod : mDependencies)
	{
		if (mod->mNumber == mNumber)
		{
			std::cout << "This Mod Already Exists in the Dependencies.\n";
			return;
		}
	}

	auto result = FindMod(mNumber);
	if (result != ModList.end())
	{
		std::cout << "Mod Found in ModList\n";
		mDependencies.emplace_back(&(result->first));
		return;
	}

	std::cout << "New Mod Added\n";
	AddModToModList(mNumber);
	mDependencies.emplace_back(&(FindMod(mNumber)->first));
}

void AddModToModList(int mNumber)
{
	auto mLink = SetModLink(mNumber);
	auto mName = SetModAuthorName("Enter Mod Name: ");
	auto mCategory = SetModCategory();
	auto mAuthor = SetModAuthorName("Enter Mod Author: ");
	auto mInstalled = SetModEnabledInstalled("Is the mod installed? (1 = Yes, 0 = No): ");
	auto mEnabled = SetModEnabledInstalled("Is the mod enabled? (1 = Yes, 0 = No): ");
	auto mod = SSEMod{ mName, mNumber, mAuthor, mCategory, mInstalled, mEnabled, mLink};
	auto mDependencies = SetModDependencies(mNumber);
	ModList.insert(std::make_pair(mod, mDependencies));
}

void ClearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void EditDependencies(MODLISTITERATOR it)
{
	int mNumber;
	DisplayChoices(AddRemoveDependency);
	auto option = GetValidInput<int>("Enter Choice: ", [](int n) { return n == 1 || n == 2; });
	int i = 0;
	switch (option)
	{
	case 1:
		AddDependencyMod(it->second, it->first.mNumber);
		break;
	case 2:
		mNumber = GetValidInput<int>("Enter the number of the mode you wish to remove: ", [](int n) { return n >= 0; });
		for (const auto& d : it->second)
		{
			if (d->mNumber == mNumber)
			{
				it->second.erase(it->second.begin() + i);
			}
			i++;
		}
		break;
	default:
		break;
	}
}

bool FindDependency(int mNumber)
{
	for (auto it = ModList.begin(); it != ModList.end(); it++)
	{
		for (const auto& mod : it->second)
		{
			if (mod->mNumber == mNumber)
			{
				return true;//mod mNumber is a dependency
			}
		}
	}
	return false;//mod mNumber is not a dependency
}

MODLISTITERATOR FindMod(const char* prompt)
{
	std::string input;
	std::cout << prompt;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Invalid Entry. " << prompt;
		getline(std::cin, input);
	}
	try
	{
		auto num = std::stoi(input);
		return FindMod(num);
	}
	catch (...)
	{
		return FindMod(input);
	}
	return ModList.end();//Mod Not Found
}

MODLISTITERATOR FindMod(int mNumber)
{
	for (auto it = ModList.begin(); it != ModList.end(); it++)
	{
		if (it->first.mNumber == mNumber)
		{
			return it;
		}
	}
	return ModList.end();
}

MODLISTITERATOR FindMod(std::string mName)
{
	for (auto it = ModList.begin(); it != ModList.end(); it++)
	{
		if (it->first.mName == mName)
		{
			return it;
		}
	}
	return ModList.end();
}

void FormatCategoryDisplay(int index, const char* c)
{
	std::cout << std::setw(1) << std::left << (index + 1) << c << std::setw(37) << std::left << Categories[index];
}

template<typename T>
T GetValidInput(const std::string& prompt, const std::function<bool(T)>& isValid)
{
	T input;
	std::cout << prompt;
	std::cin >> input;
	while (!std::cin.good() || !isValid(input))
	{
		ClearCIN();
		std::cout << "Invalid Entry. " << prompt;
		std::cin >> input;
	}
	return input;
}
#pragma endregion

#pragma region Test Functions
void TEST_AddModsToModList()
{
	bool loop;
	do
	{
		AddMod();
		DisplayAllMods();
		loop = GetValidInput<bool>("Add Another Mod? (1 = Yes, 0 = No): ", [](bool b) {return b == 0 || b == 1; });
	} while (loop);
}
#pragma endregion

void SaveModListToFile()
{
	std::ofstream outFile("ModList.txt");

	// Write each SSEMod object and its associated vector to a line in the file
	for (auto& mod : ModList)
	{
		const SSEMod& mInfo = mod.first;
		const std::vector<const SSEMod*>& mDependencies = mod.second;

		// Write SSEMod fields
		outFile << mInfo.mName << ","
			    << mInfo.mNumber << ","
			    << mInfo.mAuthor << ","
			    << mInfo.mCategory << ","
			    << mInfo.mInstalled << ","
			    << mInfo.mEnabled << ","
			    << mInfo.mLink;

		// Write dependencies (if any)
		if (!mDependencies.empty())
		{
			outFile << ",\"";
			for (size_t i = 0; i < mDependencies.size(); i++)
			{
				outFile << mDependencies[i]->mNumber;
				if (i < mDependencies.size() - 1)
					outFile << ";";
			}
			outFile << "\"";
		}
		outFile << "\n";

	}
	outFile.close();
}

void LoadModListFromFile()
{
	std::ifstream inFile("ModList.txt");
	std::string line;
	std::vector<std::string> tokens;
	std::string token;
	
	//read each line of the file
	while (std::getline(inFile, line))
	{
		std::istringstream ss(line);
		//parse the current line by commas into individual strings
		while (std::getline(ss, token, ','))
		{
			tokens.push_back(token);
			//tokens[0] = mName: string
			//tokens[1] = mNumber: int
			//tokens[2] = mAuthor:string
			//tokens[3] = mCatagory: SSECategory
			//tokens[4] = mInstalled: bool
			//tokens[5] = mEnabled: bool
			//tokens[6] = mLink: string
			//tokens[7] = mDependencies: vector<const SSEMod*>
		}
	}
}
