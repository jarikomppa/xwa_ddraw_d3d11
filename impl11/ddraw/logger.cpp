#include "logger.h"

#if LOGGER

#include <fstream>
#include <ctime>

clock_t g_startTime = clock();

std::ofstream g_file;

void InitLogFile()
{
	if (g_file.is_open())
	{
		return;
	}

	const std::string filename("ddraw_log.txt");

	std::ofstream file;
	file.open(filename);

	if (file.is_open())
	{
		file.close();
	}

	g_file.open(filename, std::ios::app);
}

void LogText(std::string text)
{
	InitLogFile();

	int currentTime = clock() - g_startTime;

	g_file << currentTime << '\t' << text.c_str() << std::endl;
}

#endif // LOGGER
