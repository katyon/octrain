// �C���N���[�h --------------------------------------------------
#include "DxLib.h"

#include "Input.h"
// ���Ԑ錾 ------------------------------------------------------

// �֐����� ------------------------------------------------------

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
    }
}

// �������u�Ԃ���TRUE��Ԃ�
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

// �����Ă����TRUE��Ԃ�
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
