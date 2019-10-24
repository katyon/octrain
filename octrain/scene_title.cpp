// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_title.h"

// �ϐ� --------------------------------------------------------------------------------------------
// �V�[���J�ڗp�ϐ�
extern int nextScene;

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
TITLE title;


// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void title_init(void)
{
    title.state = 0;
    title.timer = 0;
    title.bgHND = LoadGraph("Data\\Images\\title_bg.png");
}

// �X�V����
void title_update(void)
{
    switch (title.state)
    {
    case INIT:

        title.state++;
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
        if (Input::GetInstance()->GetALLButtonDown(PL_1))
        {
            nextScene = SCENE_GAME;
        }
        break;
    }
}

// �`�揈��
void title_draw(void)
{
    DrawGraph(0, 0, title.bgHND, true);
}

// �I������
void title_end(void)
{
    DeleteGraph(title.bgHND);
}
