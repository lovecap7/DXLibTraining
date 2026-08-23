#pragma once
class Car
{
public:
	/// <summary>
	/// virtualを付けるとこのクラスを継承した先で
	/// Initの処理を書き換える事ができる
	/// </summary>
	virtual void Init();

	void Update();
	void Draw();

protected:
	/// <summary>
	/// protectedのメンバ変数は
	/// 継承先のクラスのみアクセスできる
	/// </summary>
	int m_handle;	//画像ハンドル
	int m_speed;	//速度
	int m_x;		//座標X
	int m_y;		//座標Y
};

