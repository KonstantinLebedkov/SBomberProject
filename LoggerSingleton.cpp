#include "LoggerSingleton.h"

namespace MyTools {
//=============================================================================================

LoggerSingleton& LoggerSingleton::getInstance()
{
    static LoggerSingleton theInstance;
    return theInstance;
}

void __fastcall LoggerSingleton::OpenLogFile(const std::string& FN)
{
    FileLoggerSingletone::getInstance().OpenLogFile( FN);
}

void LoggerSingleton::CloseLogFile()
{
    FileLoggerSingletone::getInstance().CloseLogFile();
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str)
{
    FileLoggerSingletone::getInstance().WriteToLog(std::to_string(counter++) +" : " + str);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, int n)
{

        FileLoggerSingletone::getInstance().WriteToLog(std::to_string(counter++) + " : " + str,n);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, double d)
{
        FileLoggerSingletone::getInstance().WriteToLog(std::to_string(counter++) + " : " + str, d);
}

//=============================================================================================


} // namespace MyTools