#include <iostream>
// #include <thread> Commented because I cannot figure out how to run each script on a separate thread
#include <string>
#include <unistd.h>

int startSrv(std::string exec) // Function to start the services in the specified directory
{
	exec = "run-parts --regex '.*sh$' " + exec + "/";
	return system(exec.c_str());;
}

int main(int argc, char** argv)
{
	// check if there is more than one argument and use the second one(the second one is the one after the executable)
	  if (argc > 1)
	  {
	  	std::string arg1(argv[1]);
		int returnvalue;
		returnvalue = startSrv(arg1);
		
		if(returnvalue != 0)
		{
			// Let the user know whether there was an error while running the services
			std::cout << "An error occured while running scripts, EXITING!\n";
		}
	  }
	else 
	{
		std::cout << "Expected an argument, EXITING!\n"; // Output an error when there's no argument instead of crashing outright.
		return 1;
	}
}
