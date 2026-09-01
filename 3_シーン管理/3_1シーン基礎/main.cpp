#include "DxLib.h"

// シーンを作ってみようその1
// まずは基礎的なシーンの実装から
// Switch文を使用して場面ごとに処理を分離する

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

    // 今回はシーンの種類を列挙体で表現する
    // 列挙体は通し番号に固有の名前を付けられると考えてくれていい
    enum class SceneKind
    {
        Title = 0,      // デフォルトで最初は0(0以外を指定することもできる)
        Game,           // 以降、内部的にIDが+1づつされていく
        GameOver,       // ちなみに、int型にキャストすることも可能
        GameClear,
    };

    // 現在のシーンを表す
    // 最初はTitleからスタートさせる
    SceneKind nowScene = SceneKind::Title;

    // それぞれのシーンに配置する画像を読み込み
    int titleImage = LoadGraph(L"img/Title.png");
    int gameImage = LoadGraph(L"img/Game.png");
    int gameOverImage = LoadGraph(L"img/GameOver.png");
    int gameClearImage = LoadGraph(L"img/GameClear.png");

    // スペースキーを押した瞬間をとるための変数
    bool beforePushSpaceKey = false;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // 更新前のシーンを記憶
        SceneKind beforeScene = nowScene;

        // スペースキーを押した瞬間かどうかを今ここで判定しておく
        bool isPushSpaceKey = CheckHitKey(KEY_INPUT_SPACE);
        bool isTriggerSpaceKey = isPushSpaceKey && !beforePushSpaceKey;
        // 今の押されている状況を記憶しておく(次のボタン判定に使う)
        beforePushSpaceKey = isPushSpaceKey;

        // nowSceneによって更新するシーンを変える
        switch (nowScene)
        {
        case SceneKind::Title:

            // この中がシーン
            // 好きに処理を書いても、他のシーンに影響を及ぼさない

            DrawGraph(0, 0, titleImage, false);

            // スペースキーが押されたらGameシーンに遷移
            if (isTriggerSpaceKey)
            {
                nowScene = SceneKind::Game;
            }

            break;

        case SceneKind::Game:

            DrawGraph(0, 0, gameImage, false);

            // スペースキーが押されたら50%の確率でクリアできるようにしよう
            if (isTriggerSpaceKey)
            {
                // 0からnまでのランダムなintが返ってくる関数
                // 今回は0か1にして50%ずつの確率でtrueかfalseになるようにした
                if (GetRand(1))
                {
                    nowScene = SceneKind::GameClear;
                }
                else
                {
                    nowScene = SceneKind::GameOver;
                }
            }

            break;

        case SceneKind::GameOver:

            DrawGraph(0, 0, gameOverImage, false);

            // スペースキーが押されたらTitleシーンに遷移
            if (isTriggerSpaceKey)
            {
                nowScene = SceneKind::Title;
            }

            break;

        case SceneKind::GameClear:

            DrawGraph(0, 0, gameClearImage, false);

            // スペースキーが押されたらTitleシーンに遷移
            if (isTriggerSpaceKey)
            {
                nowScene = SceneKind::Title;
            }

            break;
        }

        // 描画内容を画面に反映
        ScreenFlip();
    }

    // DXライブラリ終了
    DxLib_End();

    return 0;
}