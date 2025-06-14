#include "log.h"

Logger& Logger::getInstance()
{
    static Logger log;
    return log;
}

void Logger::initialize(const MyString& filename)
{
    
    file.open(filename.ToCharArray(), std::ios::out);
}

void Logger::cleanup()
{
    file.flush();
    file.clear();
    file.close();
}

void Logger::writeError(const MyString& error_message)
{
    time_t timestamp;
    time(&timestamp);
    file << error_message << "  ";
    file << ctime(&timestamp);

}