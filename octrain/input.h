#pragma once
#include "Common.h"
// 定数 ----------------------------------------------------------------
enum THUMB
{
    Not,
    Up, Before_Upper_Right, Upper_Right, After_Upper_Right,
    Right, Before_Lower_Right, Lower_Right, After_Lower_Right,
    Down, Before_Lower_Left, Lower_Left, After_Lower_Left,
    Left, Before_Upper_Left, Upper_Left, After_Upper_Left,
    Little_Up, Little_Right, Little_Down, Little_Left,
    Little_Upper_Right, Little_Lower_Right, Little_Lower_Left, Little_Upper_Left
};

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
    // 左スティックを倒している方向の値を返す
    bool GetLeftThumb(PL_NUM plNum, int  LeftThumb);
    // 右スティックを倒している方向の値を返す
    bool GetRightThumb(PL_NUM plNum, int  RightThumb);

private:
    XINPUT_STATE input[2] = {};
    int key[2][16] = {};	// 入力情報
    int ThumbLX[2] = {};
    int ThumbLY[2] = {};
    int ThumbRX[2] = {};
    int ThumbRY[2] = {};
    enum BUTTON_STATE
    {
        Not, Down, Stay
    };
    enum THUMB_STATE
    {
        Zero, Mid, Max
    };

protected:


    Input() {};
    virtual ~Input() {};
    static Input* instance;
};