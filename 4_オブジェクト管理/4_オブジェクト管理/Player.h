#pragma once
#include "GameObject.h"
#include <vector>
class Player :
    public GameObject
{
public:
    Player();
    ~Player();
    void Init() override;
    void Update()override;
    void Draw()const override;
    void End()override;
private:
    //ƒnƒ“ƒhƒ‹
    int m_normalH;
    int m_leftH;
    int m_rightH;

};

