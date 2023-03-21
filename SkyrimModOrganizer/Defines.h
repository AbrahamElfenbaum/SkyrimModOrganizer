#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct MOD
{
	int mNumber;
	std::string mNane, mAuthor, mLink;
	std::vector<MOD> mDependencies;
};

std::vector<MOD> Mods;