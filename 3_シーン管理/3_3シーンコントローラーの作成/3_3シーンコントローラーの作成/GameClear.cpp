#include "GameClear.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"
#include "SceneController.h"

void GameClear::Init()
{
	// クリアシーン用の画像を読み込み
	imgH = LoadGraph(L"img/GameClear.png");
}

void GameClear::Update()
{
	// スペースキーが押されたらタイトルシーンへ遷移
	if (Input::isTriggerSpaceKey)
	{
		controller->ChangeScene(new Title());
	}
}

void GameClear::Draw()
{
	// 画像描画
	DrawGraph(0, 0, imgH, false);
}

void GameClear::End()
{
	// 画像の解放
	DeleteGraph(imgH);
}
