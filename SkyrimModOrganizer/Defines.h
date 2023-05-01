#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>

enum SSECategory
{
	NoCategory,
	Alchemy,           Animation,                     Armour,                         Armour_Shields,
	Audio,             Body_Face_Hair,                Bug_Fixes,                      Buildings,
	Cheats_GodItems,   Cities_Towns_Villages_Hamlets, Clothing_Accessories,           Collectables_Treasure_Hunts_Puzzles,
	Combat,            Crafting,                      Creatures_Mounts,               Dungeons,
	Environmental,     Followers_Companions,          Followers_Companions_Creatures, Gameplay,
	Guilds_Factions,   Immersion,                     Items_ObjectsPlayer,            Items_ObjectsWorld,
	Locations_New,     Locations_Vanilla,             Magic_Gameplay,                 Magic_Spells_Enchantments,
	Miscellaneous,     Modders_Resources,             Models_Textures,                NPC,
	Overhauls,         Patches,                       Player_Homes,                   Presets_ENB_ReShade,
	Quests_Adventures, Races_Classes_Birthsigns,      Save_Games,                     Shouts,
	Skills_Leveling,   Stealth,                       User_Interface,                 Utilities,
	Visuals_Graphics,  VR,                            Weapons,                        Weapons_Armour
};

struct SSEMod
{
	std::string          mName;
	int                  mNumber;
	std::string          mAuthor;
	SSECategory          mCategory;
	bool                 mInstalled;
	bool                 mEnabled;
	std::string          mLink;
	std::vector<SSEMod*> mDependencies;
	bool				 mIsDependency;
};

#pragma region Vectors
std::vector<SSEMod> ModList;
std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };
std::vector<const char*> ModProperties{ "Name", "Number", "Author", "Category", "Install Status", "Dependencies" };
std::vector<std::string> categories =
{
	"Alchemy",             "Animation",                          "Armour",                             "Armour - Shields",
	"Audio",               "Body, Face, & Hair",                 "Bug Fixes",                          "Buildings",
	"Cheats & God Items",  "Cities, Towns, Villages, & Hamlets", "Clothing & Accessories",             "Collectables, Treasure Hunts, & Puzzles",
	"Combat",              "Crafting",                           "Creatures & Mounts",                 "Dungeons",
	"Environmental",       "Followers & Companions",             "Followers & Companions - Creatures", "Gameplay",
	"Guilds/Factions",     "Immersion",                          "Items & Objects - Player",           "Items & Objects - World",
	"Locations - New",     "Locations - Vanilla",                "Magic - Gameplay",                   "Magic - Spells & Enchantments",
	"Miscellaneous",       "Modders Resources",                  "Models & Textures",                  "NPC",
	"Overhauls",           "Patches",                            "Player Homes",                       "Presets - ENB & ReShade",
	"Quests & Adventures", "Races, Classes, & Birthsigns",       "Save Games",                         "Shouts",
	"Skills & Leveling",   "Stealth",                            "User Interface",                     "Utilities",
	"Visuals & Graphics",  "VR",                                 "Weapons",                            "Weapons & Armour"
};
#pragma endregion

#pragma region Main Functions
void AddMod();
void DisplayAllMods();
//void EditMod(int mNumber);
//void RemoveMod(int mNumber);
#pragma endregion

#pragma region Set Functions
SSECategory          SetModCategory();
std::vector<SSEMod*> SetModDependencies(int mNumber);
bool                 SetModEnabledInstalled(const char* prompt);
std::string          SetModAuthorName(const char* prompt);
int                  SetModNumber(const std::vector<SSEMod>& mList);
std::string          SetModLink(int mNumber);
#pragma endregion

#pragma region Display Functions
void        DisplayAllCategories();
const char* DisplayCategoryName(int category);
void        DisplayChoices(const std::vector<const char*>& options);
void		DisplayDependencies(const std::vector<SSEMod>& mDependencies);
const char* DisplayBoolValue(bool b, const char* boolT, const char* boolF);
void        DisplayMod(SSEMod& mod);
#pragma endregion

#pragma region Helper Functions
void                 AddDependencyMod(std::vector<SSEMod*>& mDependencies, int n);
void				 AddModToModList(int mNumber);
void                 ClearCIN();
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList);
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList, int mNumber);
std::pair<bool, int> FindMod(const std::vector<SSEMod*>& mList, int mNumber);
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList, std::string mName);
void                 FormatCategoryDisplay(int index, const char* c);
#pragma endregion

#pragma region Not Implemented
void WriteToModList(SSEMod mod);
#pragma endregion

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