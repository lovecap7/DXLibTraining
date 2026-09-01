#include "Title.h"

#include <DxLib.h>

void Title::Init()
{
	// タイトルシーン用の画像を読み込み

}

Scene* Title::Update()
{
	// スペースキーが押されたらゲームシーンへ遷移
	if ()
}

void Title::Draw()
{
	// 画像描画
	DrawGraph(0,0, imgH, false);
}

void Title::End()
{
	// 画像の解放
	DeleteGraph(imgH);
}
