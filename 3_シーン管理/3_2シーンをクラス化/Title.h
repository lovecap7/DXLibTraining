#pragma once
#include "Scene.h"

// タイトルシーン
class Title : public Scene
{
public:

	// 純粋仮想関数を実装していく

	void Init() override;

	Scene* Update() override;

	void Draw() override;

	void End() override;

private:

	int imgH;
};

