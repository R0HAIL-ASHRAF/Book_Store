#pragma once
#pragma warning(disable : 4996)


#include <fstream>
#include "MyString.h"
#include<ctime>

class Logger {

public:
    static Logger& getInstance();
    void initialize(const MyString& filename);

    void cleanup();

    void writeError(const MyString& error_message);
    

private:
    Logger(){}
    ~Logger() {}
    std::ofstream file;
    
};
//
//// Usage example:
//int main() {
//    Logger& logger = Logger::getInstance();
//    logger.initialize("log.txt");
//    logger.writeError("This is an error message");
//    logger.cleanup();
//    return 0;
//}

