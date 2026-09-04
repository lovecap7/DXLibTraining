#pragma once
#include "GameObject.h"
class Star :
    public GameObject
{
public:
    Star();
    ~Star();
    void Init()override;
    void Update() override;
    void Draw()const override;
    void End()override;

private:
    //‘¬“x
    int m_speed;
};

