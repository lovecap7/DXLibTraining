#include "Car.h"
#include <DxLib.h>

void Car::Init()
{
	//車の画像
	m_handle = LoadGraph(L"img/Car.png");
	//速度
	m_speed = 5;
	//座標
	m_x = 500;
	m_y = 100;
}

void Car::Update()
{
	//移動
	m_x -= m_speed;


	//画面外に出たら右に戻る処理
	if (m_x < -500)
	{
		m_x = 500;
	}
}

void Car::Draw()
{
	DrawGraph(m_x, m_y, m_handle, true);
}
