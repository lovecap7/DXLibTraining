#include "SceneController.h"

// cppは実装を細かく知らないといけないのでSceneをインクルードする
#include "Scene.h"

SceneController::~SceneController()
{
	// 今あるシーンをすべて解放
	for (auto scene : scenes)
	{
		scene->End();
		delete scene;
	}

	// changedSceneも同じシーンを参照していて、そのシーンはすでにdelete済みなのでこれでOK
}

void SceneController::Init(Scene* startScene)
{
	// シーンを初期化する
	startScene->Init();
	startScene->RecieveSceneController(this);

	// listに要素を追加するときにはpush_back関数を使う
	scenes.push_back(startScene);

	// 今のシーンの写しを持っておく
	// この写しをいじることでシーンの切り替えを実装する
	changedScenes.push_back(startScene);
}

void SceneController::Update()
{
	// シーンの更新処理
	// 一番上のシーンのみ更新するようにすれば、ポーズシーンを上乗せしたとき自動的にゲームシーンが止まって便利
	// もちろん必ずそうする必要はない
	// すべて更新したいときは範囲for文などを使おう
	scenes.back()->Update();

	// ★シーンを更新し終わった後にシーンの切り替え処理を行う
	// 理由はシーンの更新中(Update関数の中)でシーンそのものを消すとヤバいから
}

void SceneController::Draw()
{
	// すべてのシーンを描画
	// 範囲for文
	for (auto scene : scenes)
	{
		scene->Draw();
	}
}

void SceneController::CommitScenes()
{
	// UpdateとDrawが終わった後にシーンの切り替え処理を行う必要がある
	// そうしないと描画がちらついたりメモリエラーを起こしたりする
	scenes = changedScenes;

	// 削除したシーンを本当に削除
	for (auto scene : deleteScenes)
	{
		scene->End();
		delete scene;
	}

	// 削除したのでリストを空に
	deleteScenes.clear();
}

void SceneController::ChangeScene(Scene* nextScene)
{
	// (ないと思うけど)シーンが一つもないときは無効
	if (changedScenes.empty()) return;

	// シーンを削除
	deleteScenes.push_back(changedScenes.back());

	// シーンを切り替える
	changedScenes.back() = nextScene;

	// 初期化
	// 自分のポインタを渡すのでthisキーワードを使う
	changedScenes.back()->Init();
	changedScenes.back()->RecieveSceneController(this);
}

void SceneController::PushScene(Scene* pushScene)
{
	// 初期化してあげる
	pushScene->Init();
	pushScene->RecieveSceneController(this);

	// 上乗せ
	changedScenes.push_back(pushScene);
}

void SceneController::PopScene()
{
	// シーンが一つしかない時は無効
	if (changedScenes.size() < 2) return;

	// 後ろのシーンを削除リストへ登録
	deleteScenes.push_back(changedScenes.back());

	// 一番上のシーンを配列から取り除く
	changedScenes.pop_back();
}

void SceneController::ResetScene(Scene* restartScene)
{
	// すべてのシーンを削除する
	for (auto scene : changedScenes)
	{
		scene->End();
		delete scene;
	}

	// restartScene一つで開始
	changedScenes.clear();
	changedScenes.push_back(restartScene);
}
