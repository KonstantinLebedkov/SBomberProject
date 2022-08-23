#pragma once
#include "DynamicObject.h"
#include "Bomb.h"
class BombDecorator :
    public DynamicObject, public Bomb
{
    Bomb* bomb;
public:
    BombDecorator(Bomb* bomb) :bomb(bomb) {};
    void Draw() const override;
    void Move(uint16_t time) override;
    void SetDirection(double nx, double ny) { bomb->SetDirection(nx, ny); }
    void SetSpeed(double speed) { bomb->SetSpeed(speed); }
    void SetPos(double nx, double ny) { bomb->SetPos(nx, ny); }
    uint16_t GetWidth() const { return bomb->GetWidth(); }
    inline double GetX() const { return bomb->GetX(); }
    inline double GetY() const { return bomb->GetY(); }
    inline void SetWidth(uint16_t widthN) { bomb->SetWidth(widthN); }
    ~BombDecorator() { bomb->~Bomb(); }
};

