#include "GameOver.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"

void GameOver::Init()
{
	
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
	DrawString(0, 0, L"Gameover", 0xffffff);
}

void GameOver::End()
{
	
}
