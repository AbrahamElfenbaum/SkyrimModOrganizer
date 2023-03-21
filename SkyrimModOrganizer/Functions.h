#pragma once
#include "Defines.h"

//Adds a mod to the Mods vector
void AddMod()
{
	Mod newMod;
	std::cout << "Mod Name: ";
	newMod.mNane = "Name";
	std::cout << "Mod Number: ";
	newMod.mNumber = 1;
	std::cout << "Mod Category: ";
	newMod.mCategory = Category::NoCategory;
	std::cout << "Mod Author: ";
	newMod.mAuthor = "Author";
	std::cout << "Mod Link: ";
	newMod.mLink = "Link";
	std::cout << "Is the mod installed? ";
	newMod.isInstalled = false;
	
	Mods.push_back(newMod);
}

//Removes a mod from the Mods vector
void RemoveMod()
{

}

//Edits a specific mod in the Mods vector
void EditMod()
{

}