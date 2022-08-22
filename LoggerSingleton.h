#pragma once

#include "MyTools.h"

namespace MyTools {
	class LoggerSingleton 
	{
	public:
		static LoggerSingleton& getInstance();
		void __fastcall OpenLogFile(const std::string& FN);

		void CloseLogFile();

		void __fastcall WriteToLog(const std::string& str);

		void __fastcall WriteToLog(const std::string& str, int n);

		void __fastcall WriteToLog(const std::string& str, double d);
	private:
		int counter;
		LoggerSingleton() {};
		LoggerSingleton(const LoggerSingleton& root) = delete;
		LoggerSingleton& operator=(const LoggerSingleton&) = delete;
	};
}