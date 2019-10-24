// インクルード --------------------------------------------------
#include "DxLib.h"

#include "Input.h"
// 実態宣言 ------------------------------------------------------

// 関数実体 ------------------------------------------------------

Input* Input::instance = NULL;

void Input::Create()
{
    if (!instance)
    {
        instance = new Input;
    }
}

void Input::Destroy()
{
    delete instance;
    instance = NULL;
}

void Input::Init()
{
    SetJoypadDeadZone(DX_INPUT_PAD1, 0.35);
    SetJoypadDeadZone(DX_INPUT_PAD2, 0.35);
}

void Input::Updata()
{
    GetJoypadXInputState(DX_INPUT_PAD1, &input[0]);
    GetJoypadXInputState(DX_INPUT_PAD2, &input[1]);


    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            if (input[j].Buttons[i])
            {
                if (key[j][i] == NOT)
                    key[j][i] = DOWN;
                else if (key[j][i] == DOWN)
                    key[j][i] = STAY;
            }
            else key[j][i] = NOT;
        }
        if (input[j].ThumbLX > 1)
        {
            LThumbX[j] = PLUS;
        }
        else if (input[j].ThumbLX < -1)
        {
            LThumbX[j] = MINUS;
        }
        else
        {
            LThumbX[j] = NOT;
        }
        if (input[j].ThumbLY > 1)
        {
            LThumbY[j] = PLUS;
        }
        else if (input[j].ThumbLY < -1)
        {
            LThumbY[j] = MINUS;
        }
        else
        {
            LThumbY[j] = NOT;
        }
    }
}

// 押した瞬間だけTRUEを返す
bool Input::GetButtonDown(PL_NUM plNum, int inputKey)
{
    if (key[plNum][inputKey] == DOWN)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 押した瞬間だけTRUEを返す(全てのボタン)
bool Input::GetALLButtonDown(PL_NUM plNum)
{
    for (int inputKey = 0; inputKey < 16; inputKey++)
    {
        if (key[plNum][inputKey] == DOWN)
        {
            return true;
        }
    }

    return false;
}

// 押している間TRUEを返す
bool Input::GetButton(PL_NUM plNum, int inputKey)
{
    if (key[plNum][inputKey] == STAY || key[plNum][inputKey] == DOWN)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 左スティックを倒しているX方向の値を返す
int Input::GetLThumbX(PL_NUM plNum)
{
    switch (LThumbX[plNum])
    {
    case PLUS:
        return 1;
        break;
    case MINUS:
        return -1;
        break;
    case NOT:
        return 0;
        break;
    }
}

// 左スティックを倒しているY方向の値を返す
int Input::GetLThumbY(PL_NUM plNum)
{
    switch (LThumbY[plNum])
    {
    case PLUS:
        return 1;
        break;
    case MINUS:
        return -1;
        break;
    case NOT:
        return 0;
        break;
    }
}
