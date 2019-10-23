#pragma once
#include "Common.h"
// �萔 ----------------------------------------------------------------


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
    // �����Ă����TRUE��Ԃ�
    bool GetButton(PL_NUM playerNum, int inputKey);


private:
    XINPUT_STATE input[2] = {};
    int key[2][16] = {};	// ���͏��
    enum
    {
        NOT, DOWN, STAY
    };

protected:
    Input() {};
    virtual ~Input() {};
    static Input* instance;
};