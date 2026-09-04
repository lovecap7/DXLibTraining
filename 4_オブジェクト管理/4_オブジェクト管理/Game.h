#pragma once
#include "Scene.h"
#include <vector>

class GameObject;
class Game : public Scene
{
public:

	// 純粋仮想関数を実装していく

	void Init() override;

	Scene* Update() override;

	void Draw() override;

	void End() override;

private:

	//★ゲームオブジェクトを一括で管理
	//このときvector(動的配列)を使います
	//動的配列は通常の配列と違ってゲーム実行中に
	//要素の追加や削除ができます。
	std::vector<GameObject*> m_gameObjects;
};

