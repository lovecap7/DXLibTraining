#pragma once

#include <DxLib.h>

// シーンをクラス単位で分けることになったため、どこでも取得できるようにキーボード押下判定をグローバルにする
// 皆は良い感じにシングルトンにするとかしような！
namespace Input
{
	// スペースキーを押した瞬間をとるための変数
	bool beforePushSpaceKey = false;

	bool isTriggerSpaceKey = false;

	// このフレームでスペースキーが押されたかを判定
	// mainでやる
	void Update()
	{
		// スペースキーを押した瞬間かどうかを今ここで判定しておく
		bool isPushSpaceKey = CheckHitKey(KEY_INPUT_SPACE);
		isTriggerSpaceKey = isPushSpaceKey && !beforePushSpaceKey;
		// 今の押されている状況を記憶しておく(次のボタン判定に使う)
		beforePushSpaceKey = isPushSpaceKey;
	}

	// スペースキーが押されたか取得
	bool IsTriggerSpaceKey()
	{
		return isTriggerSpaceKey;
	}
};

