#pragma once
#include "Animal.h"

/// <summary>
/// クラスの横に : public Animalと書くことで継承完了！！
/// </summary>
class Dog : public Animal
{
public:
	/// <summary>
	/// 親から継承した関数はoverrideと書く
	/// 関数の中身はこのクラスで作成します。
	/// </summary>
	void Init() override;
	void Draw() override;
};

