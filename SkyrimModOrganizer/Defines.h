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
	Alchemy,
	Animation,
	Armour,
	Armour_Shields, //Armour - Shields
	Audio,
	Body_Face_Hair, //Body, Face, and Hair
	Bug_Fixes,
	Buildings,
	Cheats_GodItems, //Cheats and God items
	Cities_Towns_Villages_Hamlets, //Cities, Towns, Villages, and Hamlets
	Clothing_Accessories, //Clothing and Accessories
	Collectables_Treasure_Hunts_Puzzles, //Collectables, Treasure Hunts, and Puzzles
	Combat,
	Crafting,
	Creatures_Mounts, //Creatures and Mounts
	Dungeons,
	Environmental,
	Followers_Companions, //Followers & Companions
	Followers_Companions_Creatures, //Followers & Companions - Creatures
	Gameplay,
	Guilds_Factions, //Guilds/Factions
	Immersion,
	Items_ObjectsPlayer, //Items and Objects - Player
	Items_ObjectsWorld, //Items and Objects - World
	Locations_New, //Locations - New
	Locations_Vanilla, //Locations - Vanilla
	Magic_Gameplay, //Magic - Gameplay
	Magic_Spells_Enchantments, //Magic - Spells & Enchantments
	Miscellaneous,
	Modders_Resources,
	Models_Textures, //Models and Textures
	NPC,
	Overhauls,
	Patches,
	Player_Homes,
	Presets_ENB_ReShade, //Presets - ENB and ReShade
	Quests_Adventures, //Quests and Adventures
	Races_Classes_Birthsigns, //Races, Classes, and Birthsigns
	Save_Games,
	Shouts,
	Skills_Leveling,//Skills and Leveling
	Stealth,
	User_Interface,
	Utilities,//Utilities
	Visuals_Graphics,//Visuals and Graphics
	VR,
	Weapons,
	Weapons_Armour//Weapons and Armour
};

struct SSEMod
{
	std::string         mName;
	int                 mNumber;
	std::string         mAuthor;
	SSECategory         mCategory;
	bool                mInstalled;
	std::string         mLink;
	std::vector<SSEMod> mDependencies;
};

#pragma region Vectors
std::vector<SSEMod> ModList;
std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };
std::vector<const char*> ModProperties{ "Name", "Number", "Author", "Category", "Install Status", "Dependencies" };
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
#pragma endregion

#pragma region Main Functions
void AddMod();
void DisplayAllMods();
void EditMod(int mNumber);
void RemoveMod(int mNumber);
#pragma endregion

#pragma region Set Functions
SSECategory         SetModCategory();
std::vector<SSEMod> SetModDependencies();
bool                SetModInstalled();
std::string         SetModNameAuthor(const char* prompt);
int                 SetModNumber(const std::vector<SSEMod>& mList);
std::string         SetModLink(int mNumber);
#pragma endregion

#pragma region Display Functions
void        DisplayAllCategories();
const char* DisplayCategoryName(int category);
void        DisplayChoices(const std::vector<const char*>& options);
void		DisplayDependencies(const std::vector<SSEMod>& mDependencies);
const char* DisplayIsInstalled(bool mInstalled);
void        DisplayMod(SSEMod& mod);
#pragma endregion

#pragma region Helper Functions
void                 AddDependencyMod(std::vector<SSEMod>& mDependencies);
void				 AddModToModList(int mNumber);
void                 ClearCIN();
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList);
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList, int mNumber);
std::pair<bool, int> FindMod(const std::vector<SSEMod>& mList, std::string mName);
void	             WriteToModList(SSEMod mod);
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