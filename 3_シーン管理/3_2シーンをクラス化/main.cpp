#include "DxLib.h"

#include "Input.h"
#include "Scene.h"
#include "Title.h"

// シーンを作ってみようその2
// Switch文ではシーンを追加するたび分岐処理を書き加える必要がある
// そこでシーンをクラスにして、2番で学んだ抽象クラスを使ってきれいにしよう

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモードで起動
    ChangeWindowMode(TRUE);

    // DXライブラリ初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 裏画面に描画
    SetDrawScreen(DX_SCREEN_BACK);

    // 現在のシーンを入れる入れ物
    // シーン基底クラスから派生したものならなんでも入る
    Scene* scene = new Title();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // Inputの更新
        Input::Update();

        // 現在のシーンの更新
        // これが何のシーンなのかはmainは考えなくていい
        // いくら新しいシーンを追加しても無限に対応できる
        scene->Update();

        // もし
        scene->Draw();



        // 描画内容を画面に反映
        ScreenFlip();
    }

    // DXライブラリ終了
    DxLib_End();

    return 0;
}