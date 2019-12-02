#pragma once
#include "Common.h"
// �萔 ----------------------------------------------------------------
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
// 1.Input.h���C���N���[�h����
// 2. Input::GetInstance()�ŃC���X�^���X���o�R����public�֐����Ăяo���B
// ��j�@Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_Y);

class Input
{
public:
    // �V���O���g��
    static Input* GetInstance()
    {
        return instance;
    }
    static void Create();
    static void Destroy();

    // ������
    void Init();
    // ���͍X�V
    void Updata();
    // �������u�Ԃ���TRUE��Ԃ�
    bool GetButtonDown(PL_NUM playerNum, int inputKey);
    // �������u�Ԃ���TRUE��Ԃ�(�S�Ẵ{�^��)
    bool GetALLButtonDown(PL_NUM plNum);
    // �����Ă����TRUE��Ԃ�
    bool GetButton(PL_NUM playerNum, int inputKey);
    // ���X�e�B�b�N��|���Ă�������̒l��Ԃ�
    bool GetLeftThumb(PL_NUM plNum, int  LeftThumb);
    // �E�X�e�B�b�N��|���Ă�������̒l��Ԃ�
    bool GetRightThumb(PL_NUM plNum, int  RightThumb);

private:
    XINPUT_STATE input[2] = {};
    int key[2][16] = {};	// ���͏��
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