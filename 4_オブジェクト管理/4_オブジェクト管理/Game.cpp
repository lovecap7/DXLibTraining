#include "Game.h"

#include <DxLib.h>
#include "Input.h"

#include "GameOver.h"
#include "GameClear.h"
#include "GameObject.h"
#include "Star.h"
#include "Player.h"

void Game::Init()
{
	//スターを50個作る
	for (int i = 0; i < 50; i++)
	{
		//スター作成
		GameObject* obj = new Star();
		//初期化
		obj->Init();
		//配列に追加
		m_gameObjects.push_back(obj);
	}

	//プレイヤー作成
	GameObject* player = new Player();
	player->Init();
	m_gameObjects.push_back(player);
}

Scene* Game::Update()
{
	//// スペースキーを押したら50%の確率でクリアできる
	//if (Input::isTriggerSpaceKey)
	//{
	//	// 3_1と同じです
	//	if (GetRand(1))
	//	{
	//		Scene* nextScene = new GameClear();
	//		nextScene->Init();
	//		return nextScene;
	//	}
	//	else
	//	{
	//		Scene* nextScene = new GameOver();
	//		nextScene->Init();
	//		return nextScene;
	//	}
	//}

	//ゲームオブジェクトの更新
	//この書き方は範囲for文といって
	//配列の要素数だけ繰り返すという意味です。
	//例:配列が50個なら50回繰り返す
	for (GameObject* obj : m_gameObjects)
	{
		obj->Update();
	}
	//描画
	for (GameObject* obj : m_gameObjects)
	{
		obj->Draw();
	}

	return this;
}

void Game::Draw()
{
	// 画像描画
	DrawString(0, 0, L"Game", 0xffffff);
}

void Game::End()
{
	for (GameObject* obj : m_gameObjects)
	{
		obj->End();
	}
}
