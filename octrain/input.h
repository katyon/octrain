#pragma once
#include "Common.h"
// 定数 ----------------------------------------------------------------


/// InputClass How to
// 1.Input.hをインクルードする
// 2. Input::GetInstance()でインスタンスを経由してpublic関数を呼び出す。
// 例）　Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_Y);

class Input
{
public:
    // シングルトン
    static Input* GetInstance()
    {
        return instance;
    }
    static void Create();
    static void Destroy();

    // 初期化
    void Init();
    // 入力更新
    void Updata();
    // 押した瞬間だけTRUEを返す
    bool GetButtonDown(PL_NUM playerNum, int inputKey);
    // 押した瞬間だけTRUEを返す(全てのボタン)
    bool GetALLButtonDown(PL_NUM plNum);
    // 押している間TRUEを返す
    bool GetButton(PL_NUM playerNum, int inputKey);
    // 左スティックを倒しているX方向の値を返す
    int GetLThumbX(PL_NUM plNum);
    // 左スティックを倒しているY方向の値を返す
    int GetLThumbY(PL_NUM plNum);

private:
    XINPUT_STATE input[2] = {};
    int key[2][16] = {};	// 入力情報
    int LThumbX[2] = {};
    int LThumbY[2] = {};
    enum
    {
        NOT, DOWN, STAY, PLUS, MINUS
    };

protected:
    Input() {};
    virtual ~Input() {};
    static Input* instance;
};