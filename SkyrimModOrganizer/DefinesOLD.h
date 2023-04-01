#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

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
	int mNumber;
	//std::string mName, mAuthor, mLink;
	SSECategory mCategory;
	//std::vector<Mod> mDependencies;
	//bool isInstalled;
};

#pragma region Main Functions
void AddMod();
void EditMod();
void RemoveMod();
void DisplayAllMods();
#pragma endregion

#pragma region Set Functions
void SetModNumber(SSEMod m);
void SetModCategory(SSEMod m);
//void SetModName(SSEMod m);
//void SetModDependencies(SSEMod m);
//void SetModAuthor(SSEMod m);
//void SetModLink(SSEMod m);
//void SetModInstallStatus(SSEMod m);
#pragma endregion

#pragma region Display Functions
/// <summary>
/// Depending on the input of the function, the output will be the actual name of
/// the mod category, rather than the enum value.
/// </summary>
/// <param name="category">Enum Value</param>
/// <returns>Category Name</returns>
std::string DisplayCategoryName(int category);

/// <summary>
/// Displays the list of all possible mod categories.
/// </summary>
void DisplayAllCategories();
void DisplayMod(SSEMod m);
void DisplayUserChoices();
#pragma endregion

#pragma region Helper Functions
std::string EnterString(std::string prompt);

/// <summary>
/// Calls the necessary to clear cin's error flag and goes to the next line to read
/// </summary>
void ClearCIN();
int FindMod(int mNumber);
#pragma endregion

std::vector<SSEMod> ModList;
std::vector<const char*> UserChoices {"Add Mod", "Edit Mod", "Remove Mod", "Show Mods", "Exit"};