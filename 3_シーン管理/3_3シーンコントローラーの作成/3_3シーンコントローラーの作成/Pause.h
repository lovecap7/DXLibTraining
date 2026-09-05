#pragma once
#include "Scene.h"

// 上乗せするシーンのサンプル
class Pause : public Scene
{
public:

	void Init() override;

	void Update() override;

	void Draw() override;

	void End() override;

private:

	int imgH = -1;
};

