#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

enum Category
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

struct Mod
{
	int mNumber;
	std::string mName, mAuthor, mLink;
	Category mCategory;
	std::vector<Mod> mDependencies;
	bool isInstalled;
};

#pragma region Functions
//Main Functions
void AddMod();
void EditMod();
void FindMod();
void RemoveMod();
void ShowMods();

//Set Functions
void SetModNumber(Mod m);
void SetModName(Mod m);
void SetModDependencies(Mod m);
void SetModCategory(Mod m);
void SetModAuthor(Mod m);
void SetModLink(Mod m);
void SetModInstallStatus(Mod m);

//Display Functions
std::string ShowCategoryName(int category);
void ShowAllCategories();
void DisplayMod(Mod m);
void DisplayAllMods();

//Helper Functions
std::string EnterString(std::string prompt);
void ClearCIN();
#pragma endregion

std::vector<Mod> Mods;