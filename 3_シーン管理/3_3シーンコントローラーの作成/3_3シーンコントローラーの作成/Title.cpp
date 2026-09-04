#include "Title.h"

#include <DxLib.h>
#include "Input.h"
#include "Game.h"
#include "SceneController.h"

void Title::Init()
{
	// タイトルシーン用の画像を読み込み
	imgH = LoadGraph(L"img/Title.png");
}

void Title::Update()
{
	// スペースキーが押されたらゲームシーンへ遷移
	if (Input::isTriggerSpaceKey)
	{
		controller->ChangeScene(new Game());
	}
}

void Title::Draw()
{
	// 画像描画
	DrawGraph(0,0, imgH, false);
}

void Title::End()
{
	// 画像の解放
	DeleteGraph(imgH);
}
