#include "Player.h"
#include "Input.h"
#include "ScreenSize.h"
#include <DxLib.h>

namespace
{
	constexpr int kSpeed = 5;
	constexpr int kFirstPosX = Size::kWidth / 2;
	constexpr int kFirstPosY = Size::kHeight - 80;

	//画像サイズ
	constexpr int kImgWidth = 64;
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_normalH = LoadGraph(L"img/Player_N.png");
	m_leftH = LoadGraph(L"img/Player_L.png");
	m_rightH = LoadGraph(L"img/Player_R.png");

	//通常状態
	m_imgH = m_normalH;

	//初期位置
	m_x = kFirstPosX;
	m_y = kFirstPosY;
}

void Player::Update()
{
	//初期化
	m_imgH = m_normalH;

	//右と左入力
	bool isLeft = CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT);
	bool isRight = CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT);
	
	//左だけ押したとき
	if (isLeft && !isRight)
	{
		//左に移動
		m_x -= kSpeed;
		//左に傾いた画像
		m_imgH = m_leftH;
	}
	//右だけ押したとき
	if (isRight && !isLeft)
	{
		//右に移動
		m_x += kSpeed;
		//右に傾いた画像
		m_imgH = m_rightH;
	}
	
	//画面外には出ないように
	if (m_x < kImgWidth / 2)
	{
		m_x = kImgWidth / 2;
	}
	if (m_x > Size::kWidth - kImgWidth / 2)
	{
		m_x = Size::kWidth - kImgWidth / 2;
	}
}

void Player::Draw() const
{
	DrawRotaGraph(m_x, m_y, 1.0, 0.0, m_imgH, true);
}

void Player::End()
{
	DeleteGraph(m_normalH);
	DeleteGraph(m_leftH);
	DeleteGraph(m_rightH);
}
