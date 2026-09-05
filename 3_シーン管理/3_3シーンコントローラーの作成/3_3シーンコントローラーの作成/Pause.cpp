#include "Pause.h"

#include <DxLib.h>
#include "SceneController.h"

#include "Input.h"

void Pause::Init()
{
	// ‰æ‘œ“Ç‚Ýž‚Ý
	imgH = LoadGraph(L"img/Pause.png");
}

void Pause::Update()
{
	// P‚ð‰Ÿ‚µ‚½‚çGame‚É–ß‚é
	if (Input::isTriggerPKey)
	{
		// Ž©•ª‚ðíœ‚µ‚Ä‚à‚ç‚¤
		controller->PopScene();
	}
}

void Pause::Draw()
{
	// ‰æ‘œ•`‰æ
	DrawGraph(0, 0, imgH, true);
}

void Pause::End()
{
	// ‰æ‘œ‰ð•ú
	DeleteGraph(imgH);
}
