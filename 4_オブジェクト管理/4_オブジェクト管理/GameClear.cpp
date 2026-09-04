#include "GameClear.h"

#include <DxLib.h>
#include "Input.h"
#include "Title.h"

void GameClear::Init()
{

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
	DrawString(0, 0, L"Clear", 0xffffff);
}

void GameClear::End()
{
	
}
