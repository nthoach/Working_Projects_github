#include "Webserv.hpp"
#include <math.h>

int main(int argc, char **argv, char **env)
{
	Config conf;
	IOmultiplexing io;
	signal(SIGPIPE, SIG_IGN); //TCP connections, SIGPIPE sentwhen writing to a closed socket
							 // SIG_IGN to ignore it
	if (argc != 1 && argc != 2)
	{
		std::cerr << "Usage: ./webserv [config file path]" << std::endl;
		return (1);
	}
	else if (argc == 1)
	{
		conf.SetConfigFile("./config.d/default.config");
	}
}