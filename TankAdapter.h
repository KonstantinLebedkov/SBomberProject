#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"
class TankAdapter :
    public DestroyableGroundObject
{
    TankAdaptee * Tank;
public:
    TankAdapter() { Tank = new TankAdaptee(); }
    ~TankAdapter() { Tank->~TankAdaptee(); }
    void SetPos(double nx, double ny) { Tank->SetPos(nx, ny); }
    uint16_t GetWidth() const { return Tank->GetWidth(); }
    void Draw() const 
    { 
        Tank->Paint(); 
    }
    bool __fastcall isInside(double x1, double x2) const { return Tank->isInRange(x1, x2); }
    inline uint16_t GetScore() const { return 25; };
};

