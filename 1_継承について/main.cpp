#include "DxLib.h"
#include "Car.h"
#include "SuperCar.h"

// 継承について
// 継承はあるクラスの機能を引き継いだ
// 新しいクラスを作る際に使います
// また、子供側で新たな機能や既存の機能の上書きもできます。
// Car(車クラス)を継承したSuperCar(スーパーカークラス)を作ります
// ★Initをオーバーライドして見た目と速度を変更しよう


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

    //車クラス
    Car* car1 = new Car();
    car1->Init();

    //スーパーカークラス
    Car* car2 = new SuperCar();
    //オーバーライドしているのでCarではなくSuperCarのInitが呼ばれる
    car2->Init();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        DrawString(10, 10, L"スーパーカークラスのInitをovrrideしてスーパーカーを走らせよう",0xffffff,true);

        //更新
        car1->Update();
        //描画
        car1->Draw();

        //更新(これはオーバーライドしていないのでCarのUpdate)
        car2->Update();
        //描画(これはオーバーライドしていないのでCarのDraw)
        car2->Draw();

        // 描画内容を画面に反映
        ScreenFlip();
    }

    delete car1;
    car1 = NULL;
    delete car2;
    car2 = NULL;

    // DXライブラリ終了
    DxLib_End();

    return 0;
}