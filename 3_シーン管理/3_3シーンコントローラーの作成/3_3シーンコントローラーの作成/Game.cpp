#include "Game.h"

#include <DxLib.h>
#include "Input.h"

#include "Pause.h"
#include "GameOver.h"
#include "GameClear.h"
#include "SceneController.h"

void Game::Init()
{
	// 画像読み込み
	imgH = LoadGraph(L"img/Game.png");
}

void Game::Update()
{
	// スペースキーを押したら50%の確率でクリアできる
	if (Input::isTriggerSpaceKey)
	{
		// 3_1と同じです
		if (GetRand(1))
		{
			controller->ChangeScene(new GameClear());
		}
		else
		{
			controller->ChangeScene(new GameOver());
		}
	}

	// Pでポーズシーン
	if (Input::isTriggerPKey)
	{
		controller->PushScene(new Pause());
	}

	// タイマー加算
	++timer;
}

void Game::Draw()
{
	// 画像描画
	DrawGraph(0, 0, imgH, false);

	// 一時停止の文字を出す
	DrawString(10,460, L"Pキーで一時停止", 0x000000);

	// 今Gameシーンが何回Upateされたかを表示
	DrawFormatString(10, 440, 0x000000, L"現在%dフレーム経過", timer);
}

void Game::End()
{
	// 画像解放
	DeleteGraph(imgH);
}
