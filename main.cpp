#include <iostream>
#include <thread> // This is for later use when we add multithreading support
#include <string>

std::string startSrv(std::string exec)
{
	exec = "sh " + exec + "/*";
	system(exec.c_str());
	return exec;
}

int main(int argc, char** argv)
{
	// check if there is more than one argument and use the second one
	  if (argc > 1)
	  {
	  	std::string arg1(argv[1]);
	  	startSrv(arg1);
	  }
	else 
	{
		std::cout << "Expected an argument, EXITING!\n";
		return 1;
	}
}
