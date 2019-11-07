// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_result.h"

// �ϐ� --------------------------------------------------------------------------------------------
// �V�[���J�ڗp�ϐ�
extern int nextScene;

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
RESULT result;


// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void result_init(void)
{
    result.state = 0;
    result.timer = 0;
    result.bgHND = LoadGraph("Data\\Images\\result_bg.png");
}

// �X�V����
void result_update(void)
{
    switch (result.state)
    {
    case INIT:

        result.state++;
        break;
    case UPDATE:
        // debug
        if (CheckHitKey(KEY_INPUT_1))
        {
            nextScene = SCENE_TITLE;
        }
        if (CheckHitKey(KEY_INPUT_2))
        {
            nextScene = SCENE_GAME;
        }
        if (CheckHitKey(KEY_INPUT_3))
        {
            nextScene = SCENE_RESULT;
        }
        //------

        break;
    }
}

// �`�揈��
void result_draw(void)
{
    DrawGraph(0, 0, result.bgHND, true);
}

// �I������
void result_end(void)
{
    DeleteGraph(result.bgHND);
}
