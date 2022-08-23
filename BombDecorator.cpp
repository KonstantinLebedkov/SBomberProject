#include <iostream>
#include "BombDecorator.h"
#include "MyTools.h"

void BombDecorator::Draw() const
{
	bomb->Draw();
	MyTools::ScreenSingleton::getInstance().GotoXY(bomb->GetX(), bomb->GetY() - 1);
	std::cout << "|";
}

void BombDecorator::Move(uint16_t time)
{
	bomb->Move(time*1.6);
}
