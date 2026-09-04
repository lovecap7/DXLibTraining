#pragma once
/// <summary>
/// ゲームに登場するオブジェクトはこれを継承する
/// 初期化、更新、描画、終了処理を持つ
/// </summary>
class GameObject abstract
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Draw() const abstract;
	virtual void End() abstract;
protected:
	//画像ハンドル
	int m_imgH = -1;
	//座標
	int m_x = 0;
	int m_y = 0;
};

