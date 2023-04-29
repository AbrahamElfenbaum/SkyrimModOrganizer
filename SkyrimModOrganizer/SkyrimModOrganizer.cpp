#include "Functions.h"
int main()
{

#if 1
	std::vector<SSEMod> Empty;
	SSEMod mod1 = SSEMod{ "T1", 1,"Me", (SSECategory)1, 1, 1,SetModLink(1), Empty };
	SSEMod mod2 = SSEMod{ "T2", 2,"Me", (SSECategory)2, 1, 1,SetModLink(2), Empty };
	SSEMod mod3 = SSEMod{ "T3", 3,"Me", (SSECategory)3, 1, 1,SetModLink(3), Empty };

	ModList.emplace_back(mod1);
	ModList.emplace_back(mod2);
	ModList.emplace_back(mod3);
	DisplayAllMods();

	bool loop;
	do
	{
		AddMod();
		DisplayAllMods();
		loop = GetValidInput<bool>("Add Another Mod? (1 = Yes, 0 = No): ", [](bool b) {return b == 0 || b == 1; });
	} while (loop);
#endif // 0

	
	
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