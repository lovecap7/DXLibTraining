#pragma once

/// <summary>
/// 動物クラス(抽象クラス)
/// 抽象クラスはインスタンス化できません。概念だからね。
/// 動物って動物はいないからね。
/// C++では、クラス内に純粋仮想関数 = 0 が1つでもあれば、
/// そのクラスは抽象クラスになります。
/// </summary>
class Animal
{
public:
	/// <summary>
	/// 関数() = 0;
	/// 中身の実装は継承先で行います。
	/// これを純粋仮想関数といいます。
	/// </summary>
	virtual void Init() = 0;
	virtual void Draw() = 0;

protected:	//これより下は継承先のみアクセスできる変数

	/// <summary>
	/// 画像ハンドル
	/// </summary>
	int m_handle;

};

