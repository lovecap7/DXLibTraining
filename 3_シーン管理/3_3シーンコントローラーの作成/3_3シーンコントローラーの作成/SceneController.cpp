#include "SceneController.h"

void SceneController::Update()
{
	// シーンの更新処理
	// 一番上のシーンのみ更新するようにすれば、ポーズシーンを上乗せしたとき自動的にゲームシーンが止まって便利
	// もちろん必ずそうする必要はない


}

void SceneController::ChangeScene(Scene* nextScene)
{
}

void SceneController::PushScene(Scene* pushScene)
{
}

void SceneController::PopScene()
{
	// シーンが一つしかない時は無効
	if (scenes.size() < 2) return;

	// 一番上のシーンを削除
}

void SceneController::ResetScene(Scene* restartScene)
{
}
