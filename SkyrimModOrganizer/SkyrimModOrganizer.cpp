#include "Functions.h"
int main()
{
	/*
	// Enables memory leak detection
	#define _CRTDBG_MAP_ALLOC
	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function call will set a breakpoint at the location of a leaked block
	// Set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);
	*/

	const char* path = "12345";
	std::string url = combineURL(12345);
	std::cout << "Combined URL: " << url << std::endl;
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