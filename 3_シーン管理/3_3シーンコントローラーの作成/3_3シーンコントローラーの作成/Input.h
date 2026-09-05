#pragma once

#include <DxLib.h>

// シーンをクラス単位で分けることになったため、どこでも取得できるようにキーボード押下判定をグローバルにする
// 皆は良い感じにシングルトンにするとかしような！
namespace Input
{
	// スペースキーを押した瞬間をとるための変数
	// ちなみにinlineはグローバルにするためのおまじない
	inline bool beforePushSpaceKey = false;

	inline bool isTriggerSpaceKey = false;

	inline bool beforePushPKey = false;

	inline bool isTriggerPKey = false;

	// このフレームでスペースキーが押されたかを判定
	// mainでやる
	inline void Update()
	{
		// スペースキーを押した瞬間かどうかを今ここで判定しておく
		bool isPushSpaceKey = CheckHitKey(KEY_INPUT_SPACE);

		isTriggerSpaceKey = isPushSpaceKey && !beforePushSpaceKey;
		// 今の押されている状況を記憶しておく(次のボタン判定に使う)
		beforePushSpaceKey = isPushSpaceKey;

		// 同じようにPキーも判定
		bool isPushPKey = CheckHitKey(KEY_INPUT_P);

		isTriggerPKey = isPushPKey && !beforePushPKey;
		beforePushPKey = isPushPKey;
	}
};

