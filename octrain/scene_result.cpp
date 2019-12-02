// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_result.h"

// �ϐ� --------------------------------------------------------------------------------------------

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
RESULT result;


// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void RESULT::init(void)
{
    result.state = 0;
    result.timer = 0;
    result.bgHND = LoadGraph("Data\\Images\\result_bg.png");
}

// �X�V����
void RESULT::update(void)
{
    switch (result.state)
    {
    case INIT:

        result.state++;
        break;
    case UPDATE:
        // debug
        //if (CheckHitKey(KEY_INPUT_1))
        //{
        //    COMMON::nextScene = SCENE_TITLE;
        //}
        //if (CheckHitKey(KEY_INPUT_2))
        //{
        //    COMMON::nextScene = SCENE_GAME;
        //}
        //if (CheckHitKey(KEY_INPUT_3))
        //{
        //    COMMON::nextScene = SCENE_RESULT;
        //}
        //------
        if (Input::GetInstance()->GetALLButtonDown(PL_1))
        {
            COMMON::nextScene = SCENE_GAME;
        }

        break;
    }
}

// �`�揈��
void RESULT::draw(void)
{
    DrawRectGraph(0, 0, 0, 0, 1920, 1080, result.bgHND, true, false, false);
    // debug-----------
    //unsigned int  Cr = GetColor(200, 0, 0);
    //DrawFormatString(0, 0, Cr, "�^�C�g��(1)");
    //DrawFormatString(0, 20, Cr, "�Q�[��(2)");
    //DrawFormatString(0, 40, Cr, "���U���g(3)");

    //-----------------
}

// �I������
void RESULT::end(void)
{
    DeleteGraph(result.bgHND);
}
