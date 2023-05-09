#include "Functions.h"
#define TEST 1
#define MAIN 0
int main()
{
#if TEST
	TEST_AddModsToModList();
	RemoveMod();
	DisplayAllMods();
#endif // TEST

#if MAIN
	auto mainLoop = true;
	auto option = -1;
	while (mainLoop)
	{
		DisplayChoices(UserOptions);
		option = GetValidInput<int>("Enter Choice: ", [](int n) { return n >= 1 && n <= 5; });
		switch (option)
		{
		case 1:
			AddMod();
			break;
		case 2:
			EditMod();
			break;
		case 3:
			RemoveMod();
			break;
		case 4:
			DisplayAllMods();
			break;
		case 5:
			mainLoop = false;
			break;
		default:
			break;
		}
	}
#endif // 0
}