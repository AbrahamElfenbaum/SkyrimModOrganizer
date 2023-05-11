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
std::vector<const char*> ModProperties{ "Name", "Number", "Author", "Category", "Install Status", "Enable Status", "Dependencies"};
std::vector<const char*> AddRemoveDependency{ "Add Dependecny", "Remove Dependency" };
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
/// <summary>
/// Adds a new mod to the ModList. If the mod already exists, displays an error message and
/// returns.
/// </summary>
void AddMod();

/// <summary>
/// Displays all the mods in the ModList.
/// </summary>
void DisplayAllMods();

/// <summary>
///  Edits the properties of an existing mod.
/// </summary>
void EditMod();

/// <summary>
/// Removes a mod from the ModList. If the mod is a dependency for another mod, displays
/// an error message and returns.
/// </summary>
void RemoveMod();
#pragma endregion

#pragma region Set Functions
/// <summary>
/// Prompts the user to enter the name of the mod or mod author and returns it as a string.
/// </summary>
/// <param name="prompt">The prompt to display to the user.</param>
/// <returns>The name of the mod or mod author as a string.</returns>
std::string SetModAuthorName(const char* prompt);

/// <summary>
/// Prompts the user to enter a mod category and returns the selected category as an
/// SSECategory value.
/// </summary>
/// <returns>The selected mod category as an SSECategory value.</returns>
SSECategory SetModCategory();

/// <summary>
/// Prompts the user to enter any dependencies for the specified mod number and returns
/// them as a vector of SSEMod pointers.
/// </summary>
/// <param name="mNumber">The mod number to which the dependencies belong.</param>
/// <returns>A vector of SSEMod pointers representing the dependencies for the specified mod.</returns>
std::vector<const SSEMod*> SetModDependencies(int mNumber);

/// <summary>
/// Prompts the user to enter a boolean value and returns it.
/// </summary>
/// <param name="prompt">The prompt to display to the user.</param>
/// <returns>The boolean value entered by the user.</returns>
bool SetModEnabledInstalled(const char* prompt);

/// <summary>
/// Returns the Nexus Mods URL for the specified mod number as a string.
/// </summary>
/// <param name="mNumber">The mod number.</param>
/// <returns>The Nexus Mods URL for the specified mod number as a string.</returns>
std::string SetModLink(int mNumber);

/// <summary>
/// Prompts the user to enter a mod number and returns it if it does not already exist in
/// ModList.
/// </summary>
/// <returns>The entered mod number if it does not already exist in ModList, or -1 if it does.</returns>
int SetModNumber();
#pragma endregion

#pragma region Display Functions
/// <summary>
/// Displays all available categories in a formatted table with their corresponding category numbers.
/// </summary>
void DisplayAllCategories();

/// <summary>
/// Displays the name of a given category as a const char array (string).
/// </summary>
/// <param name="category">An integer representing the category to display.</param>
/// <returns>A const char pointer to the name of the category.</returns>
const char* DisplayCategoryName(int category);

/// <summary>
/// Displays a list of options to the console, along with their index numbers.
/// </summary>
/// <param name="options">A reference to a vector of constant character
/// pointers, each representing an option to display.</param>
void DisplayChoices(const std::vector<const char*>& options);

/// <summary>
/// Returns a string representation of a boolean value, given two constant
/// character pointers representing the true and false cases.
/// </summary>
/// <param name="b">The boolean value to convert to a string representation.</param>
/// <param name="boolT">A constant character pointer representing
/// the string representation of the true case.</param>
/// <param name="boolF">A constant character pointer
/// representing the string representation of the false case.</param>
/// <returns>A constant character pointer pointing to the string representation of the boolean
/// value.</returns>
const char* DisplayBoolValue(bool b, const char* boolT, const char* boolF);

/// <summary>
/// Displays information about a mod, including its name, number, author,
/// category, install and enable status, link, and dependencies, to the console.
/// </summary>
/// <param name="it">A MODLISTITERATOR pointing to the mod to display information about.</param>
void DisplayMod(MODLISTITERATOR it);
#pragma endregion

#pragma region Helper Functions
/// <summary>
/// Adds a dependency mod to the given vector of SSEMod pointers if it exists in the ModList.
/// Otherwise, creates a new mod with the given number and adds it to the ModList as well as
/// the vector of dependencies.
/// </summary>
/// <param name="mDependencies">A vector of SSEMod pointers representing the dependencies of a mod</param>
/// <param name="n">An integer representing the number of the mod whose dependencies are being edited</param>
void AddDependencyMod(std::vector<const SSEMod*>& mDependencies, int n);

/// <summary>
/// Adds a new mod to the ModList with the given mod number, name, author, category,
/// installation and enablement status, and dependencies.
/// </summary>
/// <param name="mNumber">An integer representing the number of the mod being added</param>
void AddModToModList(int mNumber);

/// <summary>
/// Clears the input stream buffer and ignores any remaining input on the current line.
/// </summary>
void ClearCIN();

/// <summary>
///  Edits the dependencies of a mod in the ModList. Allows the user to add or remove a
/// dependency mod from the vector of SSEMod pointers representing the dependencies.
/// </summary>
/// <param name="it">An iterator pointing to the mod in the ModList whose dependencies are being edited</param>
void EditDependencies(MODLISTITERATOR it);

/// <summary>
/// Searches the ModList for a mod with the given mod number and returns true if it is found
/// as a dependency of any other mod in the ModList. Otherwise, returns false.
/// </summary>
/// <param name="mNumber">An integer representing the number of the mod being searched for as a dependency</param>
/// <returns>A boolean value indicating whether the mod with the given mod number is a dependency of any other mod in the ModList</returns>
bool FindDependency(int mNumber);

/// <summary>
/// Finds a mod in the ModList based on user input. If the input is an integer, the mod with the
/// matching mNumber will be returned, otherwise the mod with the matching mName will be
/// returned.
/// </summary>
/// <param name="prompt">The prompt to display for user input</param>
/// <returns>The iterator for the mod in the ModList, or ModList.end() if not found</returns>
MODLISTITERATOR FindMod(const char* prompt);

/// <summary>
/// Finds a mod in the ModList based on mNumber.
/// </summary>
/// <param name="mNumber">The mNumber of the mod to find</param>
/// <returns>The iterator for the mod in the ModList, or ModList.end() if not found</returns>
MODLISTITERATOR FindMod(int mNumber);

/// <summary>
/// Finds a mod in the ModList based on mName.
/// </summary>
/// <param name="mName">The mName of the mod to find</param>
/// <returns>The iterator for the mod in the ModList, or ModList.end() if not found</returns>
MODLISTITERATOR FindMod(std::string mName);

/// <summary>
/// Formats and outputs the category number and name to the console. The category
/// number is left-aligned with width 1, followed by the given character string and the category
/// name, which is left-aligned with width 37.
/// </summary>
/// <param name="index">The index of the category to display</param>
/// <param name="c">The character string to use after the category number</param>
void FormatCategoryDisplay(int index, const char* c);


/// <summary>
/// Template function to get valid input of type T from the user, using a prompt and a
/// validation function.
/// </summary>
/// <typeparam name="T">Type of input to get from the user</typeparam>
/// <param name="prompt">The prompt message to show the user</param>
/// <param name="isValid">A validation function that takes input of type T and returns a
/// boolean indicating whether the input is valid or not</param>
/// <returns>The valid input of type T entered by the user</returns>
template<typename T>
T GetValidInput(const std::string& prompt, const std::function<bool(T)>& isValid);
#pragma endregion

#pragma region Test Functions
void TEST_AddModsToModList();
#pragma endregion