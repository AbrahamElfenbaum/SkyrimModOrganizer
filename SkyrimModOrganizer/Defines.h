#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 
#include <cstring>
#include <iomanip>

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

std::vector<SSEMod> ModList;
std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };

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
int                 SetModNumber();
#pragma endregion

#pragma region Display Functions
void        DisplayAllCategories();
const char* DisplayCategoryName(int category);
void		DisplayDependencies(std::vector<SSEMod> mDependencies);
const char* DisplayIsInstalled(bool mInstalled);
void        DisplayMod(SSEMod mod);
void        DisplayUserOptions(std::vector<const char*> options);
#pragma endregion

#pragma region Helper Functions
void        AddDependencyMod(std::vector<SSEMod>& mDependencies);
void        ClearCIN();
SSEMod      CreateMod(std::string mName, int mNumber,       std::string mAuthor, SSECategory mCategory, 
					  bool mInstalled,   std::string mLink, std::vector<SSEMod> mDependencies);
std::string CreateModLink(int mNumber);
int         FindMod(std::vector<SSEMod> mList, int mNumber);
#pragma endregion