#include "Dog.h"
#include <DxLib.h>

void Dog::Init()
{
	//protectedで親クラスからm_handleを継承しているので使えます
	//ここでは犬の画像を読み込みます
	m_handle = LoadGraph(L"img/Dog.png");
}

void Dog::Draw()
{
	//画面の左側に描画する
	DrawGraph(50, 0, m_handle, true);
}
