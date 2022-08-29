#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();
    class BombIterator
    {
        std::vector<DynamicObject*>& vecDynamicObj;
        DynamicObject* ptr;
    public:
        int curIndex;
        BombIterator(std::vector<DynamicObject*>& vecDynamicObj) :vecDynamicObj(vecDynamicObj), curIndex(-1), ptr(nullptr) { ++(*this); };
        BombIterator& operator++ ();
        BombIterator& operator-- ();
        BombIterator& setEnd ();
        Bomb* operator* ();
        bool operator!= (BombIterator OtherBomb);
        void reset() { curIndex = -1; ptr = nullptr; };
    };
    BombIterator begin();
    BombIterator end();
private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};