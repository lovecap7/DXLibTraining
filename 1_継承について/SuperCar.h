#pragma once
#include "Car.h"
/// <summary>
/// クラスの横の: public Car　で継承完了
/// </summary>
class SuperCar : public Car
{
public:
	/// <summary>
	/// 初期化だけ変更
	/// これをオーバーライドといいます。
	/// overrideは付けなくてもvirtualの付いた関数は
	/// オーバーライドできます。
	/// </summary>
	void Init() override;
};

