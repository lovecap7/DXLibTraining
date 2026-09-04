#include "DxLib.h"

#include "Input.h"
#include "Title.h"
#include "SceneController.h"

// シーンを作ってみようその3
// シーンを管理する処理をクラスに分離してmainをさらに綺麗にしよう
// 複数シーンのスタックを実装しよう

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

    // 3_2で書いた処理をSceneControllerに委譲したのでSceneControllerを使っていく
    SceneController sceneController;
    // 最初のシーンを入れる
    // 今回、Sceneの初期化を内部でするようにしたのでnewだけでいい
    sceneController.Init(new Title());

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // Inputの更新
        Input::Update();

        // シーンの更新
        sceneController.Update();

        // 描画
        sceneController.Draw();

        // シーン切り替え処理
        sceneController.CommitScenes();

        // 描画内容を画面に反映
        ScreenFlip();
    }

    // シーンdelete処理はSceneControllerのデストラクタに移動しました

    // DXライブラリ終了
    DxLib_End();

    return 0;
}