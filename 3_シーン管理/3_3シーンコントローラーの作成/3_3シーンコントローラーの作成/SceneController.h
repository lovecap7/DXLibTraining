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
	
	// デストラクタ
	// このオブジェクトが消えたときに実行される特別な関数
	~SceneController();

	// 最初のシーンを設定する
	void Init(Scene* startScene);

	// シーンを更新
	void Update();

	// シーンを描画
	void Draw();

	// シーンの切り替え処理を確定する
	void CommitScenes();

	// 一番上のシーンを切り替える
	// 渡されたシーンの初期化処理を関数内で行っている
	void ChangeScene(Scene* nextScene);

	// 今あるシーンを消さずに新しいシーンを上乗せ
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




	// この辺の変数はスマートポインタでシーンのポインタを管理したら必要なくなる
	// 気に食わなかったら自分で改造してほしい
	// 僕も正直あまり納得いってない

	// シーン変更を保留しておくバッファ
	std::list<Scene*> changedScenes;

	// 削除済みで、後でdeleteするシーンを覚えておく配列
	std::list<Scene*> deleteScenes;
};

