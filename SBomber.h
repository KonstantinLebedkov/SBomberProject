#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "ICommand.h"

class DropBomb :ICommand
{
    const Plane* pPlane;
    vector<DynamicObject*>* vecDynamicObj;
    uint16_t* Bombs;
    int16_t* score;
public: 
    DropBomb(const Plane* pPlane, vector<DynamicObject*>* vecDynamicObj, uint16_t* Bombs, int16_t* score) :pPlane(pPlane), vecDynamicObj(vecDynamicObj), Bombs(Bombs),score(score) {};
    void Execute();
};
class DeleteDynamicObj :ICommand 
{
    DynamicObject* pObj;
    vector<DynamicObject*>* vecDynamicObj;
public: 
    __fastcall DeleteDynamicObj(DynamicObject* pObj,vector<DynamicObject*>* vecDynamicObj) :pObj(pObj),vecDynamicObj(vecDynamicObj) {};
    void Execute(); 
};
class DeleteStaticObj :ICommand 
{ 
    GameObject* pObj;
    vector<GameObject*>* vecStaticObj;
public: 
    __fastcall DeleteStaticObj(GameObject* pObj,vector<GameObject*>* vecStaticObj) :pObj(pObj),vecStaticObj(vecStaticObj) {};
    void Execute(); 
};

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

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //ICommand * DropBomb = new DropBomb(FindPlane(),&vecDynamicObj,&bombsNumber,&score);

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};