#include "GameOver.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"

void GameOver::Init()
{
	// ゲームオーバー用の画像を読み込み
	imgH = LoadGraph(L"img/GameOver.png");
}

Scene* GameOver::Update()
{
	// スペースキーが押されたらタイトルへ遷移
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
