#include "GameClear.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"

void GameClear::Init()
{
	// クリアシーン用の画像を読み込み
	imgH = LoadGraph(L"img/GameClear.png");
}

Scene* GameClear::Update()
{
	// スペースキーが押されたらゲームシーンへ遷移
	if (Input::isTriggerSpaceKey)
	{
		Scene* nextScene = new Title();
		nextScene->Init();

		return nextScene;
	}

	// 何も入力していないときはこのシーンを続行
	// このインスタンスのポインタを自分で取得したいときはthisキーワードを使用する
	return this;
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
