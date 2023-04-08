#include "Functions.h"
int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//												     TO DO:                                                      //
	// 1. Complete the Add, Edit and Remove Mod functions, and any helper functions needed for them to work correctly// 
	// 2. See if I can find a way to change all of the strings in the SSEMod struct into const char*				 //
	// 2. See if I can find a way to encode the names, authors and links into smaller codes and back again			 //
	// 3. Find blocks of repeated code and see if they can be made into functions to avoid duplication				 //
	// 4. Look to see if there are other ways to make the code more efficient/elegant								 //
	// 5. Make a proper UI for the code																				 //
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
	bool loop = true;
	int option = -1;
	while (loop)
	{
		DisplayUserOptions(UserOptions);
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