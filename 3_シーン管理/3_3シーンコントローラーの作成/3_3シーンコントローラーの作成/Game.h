#pragma once
#include "Scene.h"

class Game : public Scene
{
public:

	// ƒˆ‰¼‘zŠÖ”‚ğÀ‘•‚µ‚Ä‚¢‚­

	void Init() override;

	Scene* Update() override;

	void Draw() override;

	void End() override;

private:

	int imgH = -1;
};

