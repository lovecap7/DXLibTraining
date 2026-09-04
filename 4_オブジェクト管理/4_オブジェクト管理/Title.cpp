#include "Title.h"

#include <DxLib.h>
#include "Input.h"
#include "Game.h"

void Title::Init()
{
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
	DrawString(0, 0, L"Title", 0xffffff);
}

void Title::End()
{
	
}
