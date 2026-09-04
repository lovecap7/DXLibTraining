#include "Title.h"

#include <DxLib.h>
#include "Input.h"
#include "Game.h"

void Title::Init()
{
	// タイトルシーン用の画像を読み込み
	imgH = LoadGraph(L"img/Title.png");
}

Scene* Title::Update()
{
	// スペースキーが押されたらゲームシーンへ遷移
	if (Input::isTriggerSpaceKey)
	{
		Scene* nextScene = new Game();
		nextScene->Init();

		return nextScene;
	}

	// 何も入力していないときはこのシーンを続行
	// このインスタンスのポインタを自分で取得したいときはthisキーワードを使用する
	return this;
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
