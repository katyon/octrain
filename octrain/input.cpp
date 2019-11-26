// �C���N���[�h --------------------------------------------------
#include "DxLib.h"

#include "Input.h"

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
                if (key[j][i] == Not)
                    key[j][i] = Down;
                else if (key[j][i] == Down)
                    key[j][i] = Stay;
            }
            else key[j][i] = Not;
        }
#pragma region Thumb
        if (input[j].ThumbLX > 0)
        {
            if (input[j].ThumbLX < 8000)
                ThumbLX[j] = Not;
            else if (input[j].ThumbLX < 20000)
                ThumbLX[j] = Mid;
            else if (input[j].ThumbLX < 35000)
                ThumbLX[j] = Max;
        }
        if (input[j].ThumbLX < 0)
        {
            if (input[j].ThumbLX > -8000)
                ThumbLX[j] = Not;
            else if (input[j].ThumbLX > -20000)
                ThumbLX[j] = -Mid;
            else if (input[j].ThumbLX > -35000)
                ThumbLX[j] = -Max;
        }

        if (input[j].ThumbLY > 0)
        {
            if (input[j].ThumbLY < 8000)
                ThumbLY[j] = Not;
            else if (input[j].ThumbLY < 20000)
                ThumbLY[j] = Mid;
            else if (input[j].ThumbLY < 35000)
                ThumbLY[j] = Max;
        }
        if (input[j].ThumbLY < 0)
        {
            if (input[j].ThumbLY > -8000)
                ThumbLY[j] = Not;
            else if (input[j].ThumbLY > -20000)
                ThumbLY[j] = -Mid;
            else if (input[j].ThumbLY > -35000)
                ThumbLY[j] = -Max;
        }

        if (input[j].ThumbRX > 0)
        {
            if (input[j].ThumbRX < 8000)
                ThumbRX[j] = Not;
            else if (input[j].ThumbRX < 20000)
                ThumbRX[j] = Mid;
            else if (input[j].ThumbRX < 35000)
                ThumbRX[j] = Max;
        }
        if (input[j].ThumbRX < 0)
        {
            if (input[j].ThumbRX > -8000)
                ThumbRX[j] = Not;
            else if (input[j].ThumbRX > -20000)
                ThumbRX[j] = -Mid;
            else if (input[j].ThumbRX > -35000)
                ThumbRX[j] = -Max;
        }

        if (input[j].ThumbRY > 0)
        {
            if (input[j].ThumbRY < 8000)
                ThumbRY[j] = Not;
            else if (input[j].ThumbRY < 20000)
                ThumbRY[j] = Mid;
            else if (input[j].ThumbRY < 35000)
                ThumbRY[j] = Max;
        }
        if (input[j].ThumbRY < 0)
        {
            if (input[j].ThumbRY > -8000)
                ThumbRY[j] = Not;
            else if (input[j].ThumbRY > -20000)
                ThumbRY[j] = -Mid;
            else if (input[j].ThumbRY > -35000)
                ThumbRY[j] = -Max;
        }
#pragma endregion
    }
}

// �������u�Ԃ���TRUE��Ԃ�
bool Input::GetButtonDown(PL_NUM plNum, int inputKey)
{
    if (key[plNum][inputKey] == Down)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// �������u�Ԃ���TRUE��Ԃ�(�S�Ẵ{�^��)
bool Input::GetALLButtonDown(PL_NUM plNum)
{
    for (int inputKey = 0; inputKey < 16; inputKey++)
    {
        if (key[plNum][inputKey] == Down)
        {
            return true;
        }
    }

    return false;
}

// �����Ă����TRUE��Ԃ�
bool Input::GetButton(PL_NUM plNum, int inputKey)
{
    if (key[plNum][inputKey] == Stay || key[plNum][inputKey] == Down)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ���X�e�B�b�N��|���Ă�������̒l��Ԃ�
bool Input::GetLeftThumb(PL_NUM plNum, int  LeftThumb)
{
    switch (LeftThumb)
    {
    case THUMB::Not:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Zero && ThumbLY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Up:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Zero && ThumbLY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Before_Upper_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Upper_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Upper_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Before_Lower_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Max && ThumbLY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Lower_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Max && ThumbLY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Lower_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Mid && ThumbLY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Down:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Zero && ThumbLY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Before_Lower_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Mid && ThumbLY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Lower_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Max && ThumbLY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Lower_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Max && ThumbLY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Before_Upper_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Upper_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Max && ThumbLY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Upper_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Little_Up:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Zero && ThumbLY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Little_Down:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Zero && ThumbLY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Little_Upper_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Lower_Right:
        if (ThumbLX[plNum] == Input::THUMB_STATE::Mid && ThumbLY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Lower_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Mid && ThumbLY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Upper_Left:
        if (ThumbLX[plNum] == -Input::THUMB_STATE::Mid && ThumbLY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    }
    return false;
}

// �E�X�e�B�b�N��|���Ă�������̒l��Ԃ�
bool Input::GetRightThumb(PL_NUM plNum, int  RightThumb)
{
    switch (RightThumb)
    {
    case THUMB::Not:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Zero && ThumbRY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Up:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Zero && ThumbRY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Before_Upper_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Upper_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Upper_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Before_Lower_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Max && ThumbRY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Lower_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Max && ThumbRY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Lower_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Mid && ThumbRY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Down:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Zero && ThumbRY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Before_Lower_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Mid && ThumbRY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Lower_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Max && ThumbRY[plNum] == -Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Lower_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Max && ThumbRY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Before_Upper_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Upper_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Max && ThumbRY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::After_Upper_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Max)
            return true;
        break;
    case THUMB::Little_Up:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Zero && ThumbRY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Little_Down:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Zero && ThumbRY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Zero)
            return true;
        break;
    case THUMB::Little_Upper_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Lower_Right:
        if (ThumbRX[plNum] == Input::THUMB_STATE::Mid && ThumbRY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Lower_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Mid && ThumbRY[plNum] == -Input::THUMB_STATE::Mid)
            return true;
        break;
    case THUMB::Little_Upper_Left:
        if (ThumbRX[plNum] == -Input::THUMB_STATE::Mid && ThumbRY[plNum] == Input::THUMB_STATE::Mid)
            return true;
        break;
    }
    return false;
}