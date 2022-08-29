#include <iostream>

#include "TankAdaptee.h"
#include "MyTools.h"

bool __fastcall TankAdaptee::isInRange(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void TankAdaptee::Paint()
{
	MyTools::SetColor(MyTools::ConsoleColor::CC_Brown);
	MyTools::ScreenSingleton::getInstance().GotoXY(x, y - 3);
	std::cout << "    #####";
	MyTools::ScreenSingleton::getInstance().GotoXY(x - 2, y - 2);
	std::cout << "#######   #";
	MyTools::ScreenSingleton::getInstance().GotoXY(x, y - 1);
	std::cout << "    #####";
	MyTools::ScreenSingleton::getInstance().GotoXY(x, y);
	std::cout << " ###########";
}