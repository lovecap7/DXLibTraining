#include "DxLib.h"

#include "Input.h"
#include "Scene.h"
#include "Game.h"

#include "ScreenSize.h"

// オブジェクトを管理しよう
// ゲームシーンでGameObjectクラスの配列を持ち
// 初期化、更新、描画、終了処理をまとめて行いましょう
// *サンプルプログラムなのである程度完成しています

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //画面サイズ
    SetWindowSize(Size::kWidth, Size::kHeight);

    // ウィンドウモードで起動
    ChangeWindowMode(TRUE);

    // DXライブラリ初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 裏画面に描画
    SetDrawScreen(DX_SCREEN_BACK);

    // ★ Scene* scene;
    // 
    // 現在のシーンを入れる入れ物
    // シーン基底クラスから派生したものならなんでも入る
    // 基底クラスによって複数の種類のクラスをまとめて扱える性質を「多態性(ポリモーフィズム)」という

    Scene* game = new Game();
    game->Init();

    // 最初のシーンはゲーム
    Scene* scene = game;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // Inputの更新
        Input::Update();

        // 現在のシーンの更新
        // これが何のシーンなのかはmainは考えなくていい
        // いくら新しいシーンを追加しても無限に対応できる
        Scene* nextScene = scene->Update();

        // 描画
        scene->Draw();

        // もしシーンが切り替わっていたら、シーン切り替え処理
        if (nextScene != scene)
        {
            // 旧シーン終了処理
            scene->End();

            // 旧シーンをdelete
            delete scene;
            scene = nullptr;

            // 新シーン初期化
            nextScene->Init();

            // シーンを切り替え
            scene = nextScene;
        }

        // 描画内容を画面に反映
        ScreenFlip();
    }

    // 現在のシーンを破棄
    delete scene;
    scene = nullptr;

    // DXライブラリ終了
    DxLib_End();

    return 0;
}