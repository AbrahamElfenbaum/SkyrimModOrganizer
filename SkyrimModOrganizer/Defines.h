#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

#include <iomanip>

#define NEXUSLINK "https://www.nexusmods.com/skyrimspecialedition/mods/"
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
	const char* mName;
	int mNumber;
	const char* mAuthor;
	SSECategory mCategory;
	//std::vector<SSEMod> mDependencies;
	bool mInstalled;
	const char* mLink;
	
};

const size_t BUFFER_SIZE = 1024;
std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };
std::vector<SSEMod> ModList;

#pragma region Main Functions
void AddMod();
void EditMod(int mNumber);
void RemoveMod(int mNumber);
void DisplayAllMods();
#pragma endregion

#pragma region Set Functions
int SetModNumber();
char* SetModNameAuthor(const char* prompt);
SSECategory SetModCategory();
//void SetModDependencies();
bool SetModInstalled();
#pragma endregion

#pragma region Display Functions
const char* DisplayCategoryName(int category);
void DisplayAllCategories();
void DisplayUserOptions(std::vector<const char*> options);
void DisplayMod(SSEMod mod);
const char* DisplayIsInstalled(bool mInstalled);
#pragma endregion

#pragma region Helper Functions
void ClearCIN();
int FindMod(std::vector<SSEMod> mList, int mNumber);
SSEMod CreateMod(const char* mName, int mNumber, const char* mAuthor, SSECategory mCategory, bool mInstalled);
#pragma endregion

