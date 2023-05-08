#include "Functions.h"
int main()
{
	TEST_AddModsToModList();
	EditMod();
	DisplayAllMods();
#if 0
	auto mainLoop = true;
	auto option = -1;
	while (mainLoop)
	{
		DisplayChoices(UserOptions);
		option = GetValidInput<int>("Enter Choice: ", [](int n) { return n >= 1 && n <= 5; });
		switch (option)
		{
		case 1://Add Mod
			AddMod();
			break;
		case 2://Edit Mod
			break;
		case 3://Remove Mod
			break;
		case 4://Display Mods
			break;
		case 5://Exit
			break;
		default:
			break;
		}
	}
#endif // 0
}