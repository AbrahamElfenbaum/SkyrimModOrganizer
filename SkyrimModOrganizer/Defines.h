#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

/// <summary>
/// 
/// </summary>
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

/// <summary>
/// 
/// </summary>
struct SSEMod
{
	int mNumber;
	SSECategory mCategory;
	bool mInstalled;
	//mName, mAuthor, mLink;
	//std::vector<SSEMod> mDependencies;
};

#pragma region Main Functions
void AddMod();
void EditMod(int mNumber);
void RemoveMod(int mNumber);

/// <summary>
/// Calls the DisplayMod function on all of the mods in the ModList vector
/// </summary>
void DisplayAllMods();
#pragma endregion

#pragma region Set Functions
/// <summary>
/// 
/// </summary>
/// <returns></returns>
int SetModNumber();

//void SetModName();
//void SetModAuthor();

/// <summary>
/// 
/// </summary>
/// <returns></returns>
SSECategory SetModCategory();
//void SetModDependencies();

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool SetModInstalled();
//void SetModLink();
#pragma endregion

#pragma region Display Functions
/// <summary>
/// 
/// </summary>
/// <param name="category"></param>
/// <returns></returns>
const char* DisplayCategoryName(int category);

/// <summary>
/// 
/// </summary>
void DisplayAllCategories();

/// <summary>
/// 
/// </summary>
void DisplayUserOptions();

/// <summary>
/// 
/// </summary>
/// <param name="mod"></param>
void DisplayMod(SSEMod mod);

/// <summary>
/// 
/// </summary>
/// <param name="mInstalled"></param>
/// <returns></returns>
const char* DisplayIsInstalled(bool mInstalled);
#pragma endregion

#pragma region Helper Functions
/// <summary>
/// Calls the necessary to clear cin's error flag and goes to the next line to read
/// </summary>
void ClearCIN();

/// <summary>
/// Searches a vector of mods and, if mNumber is found, returns the location of the mod in the list
/// </summary>
/// <param name="mList">The Mod List to search</param>
/// <param name="mNumber">The Mod number to find</param>
/// <returns>The location of the mod in the list, or -1 if the mod is not found</returns>
int FindMod(std::vector<SSEMod> mList, int mNumber);

/// <summary>
/// Takes in all the parameters that maks up the SSEMod struct, creates a new instance of the struct,
/// and adds it to the ModList vector
/// </summary>
/// <param name="mNumber">Mod's Number</param>
/// <param name="mCategory"> Mod's Category</param>
/// <param name="mInstalled">Mod's Install Status</param>
void CreateMod(int mNumber, SSECategory mCategory, bool mInstalled);
#pragma endregion

std::vector<const char*> UserOptions{ "Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit" };
std::vector<SSEMod> ModList;