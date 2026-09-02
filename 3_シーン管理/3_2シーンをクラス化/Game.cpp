#include "Game.h"

#include <DxLib.h>
#include "Input.h"

#include "GameOver.h"
#include "GameClear.h"

void Game::Init()
{
	// 画像読み込み
	imgH = LoadGraph(L"img/Game.png");
}

Scene* Game::Update()
{
	// スペースキーを押したら50%の確率でクリアできる
	if (Input::isTriggerSpaceKey)
	{
		// 3_1と同じです
		if (GetRand(1))
		{
			Scene* nextScene = new GameClear();
			nextScene->Init();

			return nextScene;
		}
		else
		{
			Scene* nextScene = new GameOver();
			nextScene->Init();

			return nextScene;
		}
	}

	return this;
}

void Game::Draw()
{
	// 画像描画
	DrawGraph(0, 0, imgH, false);
}

void Game::End()
{
	// 画像解放
	DeleteGraph(imgH);
}
