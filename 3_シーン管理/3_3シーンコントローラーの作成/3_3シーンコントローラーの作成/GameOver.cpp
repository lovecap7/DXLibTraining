#include "GameOver.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"
#include "SceneController.h"

void GameOver::Init()
{
	// ゲームオーバー用の画像を読み込み
	imgH = LoadGraph(L"img/GameOver.png");
}

void GameOver::Update()
{
	// スペースキーが押されたらタイトルへ遷移
	if (Input::isTriggerSpaceKey)
	{
		controller->ChangeScene(new Title());
	}
}

void GameOver::Draw()
{
	// 画像描画
	DrawGraph(0, 0, imgH, false);
}

void GameOver::End()
{
	// 画像の解放
	DeleteGraph(imgH);
}
