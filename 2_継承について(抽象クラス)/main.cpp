#include "DxLib.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

//継承を使って猫クラスを実装しよう
//Dog(犬クラス)を参考にしよう


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


    //犬クラスを作成
    Animal* animal1 = new Dog();
    animal1->Init();

    //★書いてみよう
    //猫クラスを作成


    //抽象クラスはインスタンス化できません。エラーを吐きます。
    //Animal* animal = new Animal();


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        DrawString(100, 30, L"Animal(動物クラス)を継承してCat(猫クラス)を実装しよう!!", 0xffffff);
        DrawString(100, 430, L"余裕があるなら新しい動物を実装しよう!!", 0xffffff);

        //描画(中身は継承先で実装済み)
        animal1->Draw();
        //★書いてみよう


        // 描画内容を画面に反映
        ScreenFlip();
    }

    delete animal1;
    animal1 = NULL;

    // DXライブラリ終了
    DxLib_End();

    return 0;
}