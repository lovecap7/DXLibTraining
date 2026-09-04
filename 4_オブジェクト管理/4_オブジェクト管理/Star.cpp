#include "Star.h"
#include <DxLib.h>
#include "ScreenSize.h"

namespace
{
	//半径
	constexpr int kRadius = 1;

	//ランダムな速度の最大値
	constexpr int kRandSpeedMax = 5;
}

Star::Star()
{
}

Star::~Star()
{
}

void Star::Init()
{
	//座標はランダムな位置に
	m_x = GetRand(Size::kWidth);
	m_y = GetRand(Size::kHeight);
	
	//ランダムな速度
	m_speed = 1 + GetRand(kRandSpeedMax - 1);
}

void Star::Update()
{
	//下に移動
	m_y += m_speed;

	//画面外なら画面上に移動
	if (m_y > Size::kHeight)
	{
		m_y = 0;
	}
}

void Star::Draw() const
{
	DrawCircle(m_x, m_y, kRadius, 0xffffff, true);
}

void Star::End()
{
}
