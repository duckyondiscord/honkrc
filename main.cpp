#include <iostream>
#include <thread> // This is for later use when we add multithreading support
#include <string>
#include <unistd.h>

int startSrv(std::string exec) // Function to start the services in the specified directory
{
	exec = "sh" + exec + "/*";
	return system(exec.c_str());;
}

int main(int argc, char** argv)
{
	// check if there is more than one argument and use the second one
	  if (argc > 1)
	  {
	  	std::string arg1(argv[1]);
		int returnvalue;
		returnvalue = startSrv(arg1);
		
		if(returnvalue != 0)
		{
			// Let the user know whether there was an error while running the services
			std::cout << "An error occured while running services, EXITING!";
		}
	  }
	else 
	{
		std::cout << "Expected an argument, EXITING!\n"; // Output an error when there's no argument instead of crashing outright.
		return 1;
	}
}
