#pragma once

// ヘッダで、他ファイルの型ポインターを使うときは
// includeではなくプロトタイプ宣言で事足りる
class Scene;

// 実体で使用する型はインクルードが必要
#include <List>

// 今までmainでやっていたシーン管理をこれで行う
class SceneController
{
public:

	// シーンを更新
	void Update();

	// シーンを描画
	void Draw();

	// シーンを切り替える
	void ChangeScene(Scene* nextScene);

	void PushScene(Scene* pushScene);

	// 今一番上にあるシーンを消す
	// シーンが一つしかないときは無効
	void PopScene();

	// 今あるシーンをすべて消してrestartSceneだけにする
	// ポーズからタイトルに戻るときにほしいから僕はいつも作ってる
	void ResetScene(Scene* restartScene);

private:

	// 動的配列
	// 要素数を実行中に変えられる配列
	std::list<Scene*> scenes;
};

