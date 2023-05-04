#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#define MODLISTITERATOR std::map<SSEMod, std::vector<const SSEMod*>>::iterator
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
	
	bool operator<(const SSEMod& other) const {
		return mNumber < other.mNumber;
	}
};
std::map<SSEMod, std::vector<const SSEMod*>> ModList;

#pragma region Vectors
std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };
std::vector<const char*> ModProperties{ "Name", "Number", "Author", "Category", "Install Status", "Dependencies" };
std::vector<std::string> Categories =
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
void EditMod(int mNumber);
void RemoveMod(int mNumber);
#pragma endregion

#pragma region Set Functions
SSECategory SetModCategory();
std::vector<const SSEMod*> SetModDependencies(int mNumber);
bool SetModEnabledInstalled(const char* prompt);
std::string SetModAuthorName(const char* prompt);
int SetModNumber();
std::string SetModLink(int mNumber);
#pragma endregion

#pragma region Display Functions
void DisplayAllCategories();
const char* DisplayCategoryName(int category);
void DisplayChoices(const std::vector<const char*>& options);
void DisplayDependencies(const std::vector<const SSEMod*>& mDependencies);
const char* DisplayBoolValue(bool b, const char* boolT, const char* boolF);
void DisplayMod(SSEMod mod);
#pragma endregion

#pragma region Helper Functions
void AddModToModList(int mNumber);
void AddDependencyMod(std::vector<const SSEMod*>& mDependencies, int n);
void ClearCIN();
MODLISTITERATOR FindMod();
MODLISTITERATOR FindMod(int mNumber);
MODLISTITERATOR FindMod(std::string mName);
void FormatCategoryDisplay(int index, const char* c);
template<typename T>
T GetValidInput(const std::string& prompt, const std::function<bool(T)>& isValid);
#pragma endregion