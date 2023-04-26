#include "Functions.h"
int main()
{	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//												      TO DO:                                                      | STATUS:     //
	// 1. Complete the Add, Edit and Remove Mod functions, and any helper functions needed for them to work correctly | IN PROGRESS //
	// 2. Save the ModList vector into a .txt file. Change the code as needed to support this function                | IN PROGRESS // 
	// 2. See if ther is a way to change all of the strings in the SSEMod struct into const char*				      | IN PROGRESS //
	// 3. See if ther is a way to encode the names, authors and links into smaller codes and back again			      | IN PROGRESS //
	// 4. Find blocks of repeated code and see if they can be made into functions to avoid duplication				  | IN PROGRESS //
	// 5. Look to see if there are other ways to make the code more efficient/elegant								  | IN PROGRESS //
	// 6. Make a proper UI for the code																				  | IN PROGRESS //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::vector<SSEMod> Empty;
	SSEMod mod1 = SSEMod{ "T1", 1,"Me", (SSECategory)1, 1, SetModLink(1), Empty };
	SSEMod mod2 = SSEMod{ "T2", 2,"Me", (SSECategory)2, 1, SetModLink(2), Empty };
	SSEMod mod3 = SSEMod{ "T3", 3,"Me", (SSECategory)3, 1, SetModLink(3), Empty };

	ModList.emplace_back(mod1);
	ModList.emplace_back(mod2);
	ModList.emplace_back(mod3);
	DisplayAllMods();
	
	//std::cout << FindMod(ModList).second << std::endl;

	AddMod();
	DisplayAllMods();
	
#if 0
	bool loop = true;
	int option = -1;
	while (loop)
	{
		DisplayChoices(UserOptions);
		std::cout << "Enter Choice: ";
		std::cin >> option;
		while (!std::cin.good() || option < 1 || option > 5)
		{
			ClearCIN();
			std::cout << "Invalid Entry. Enter Choice: ";
			std::cin >> option;
		}
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