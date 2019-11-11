// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

#include <math.h>

// �ϐ� --------------------------------------------------------------------------------------------

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
GAME game;

int GAME::timer = 0;
// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void GAME::init(void)
{
    game.state = 0;
    game.timer = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");

    PLAYER::init();
}

// �X�V����
void GAME::update(void)
{
    switch (game.state)
    {
    case INIT:

        game.state++;
        break;
    case UPDATE:

        PLAYER::update();

        game.timer++;
        // debug
        if (CheckHitKey(KEY_INPUT_1))
        {
            COMMON::nextScene = SCENE_TITLE;
        }
        if (CheckHitKey(KEY_INPUT_2))
        {
            COMMON::nextScene = SCENE_GAME;
        }
        if (CheckHitKey(KEY_INPUT_3))
        {
            COMMON::nextScene = SCENE_RESULT;
        }
        //------
        break;
    }
}

// �`�揈��
void GAME::draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);

    PLAYER::draw();
    // debug-----------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(0, 0, Cr, "�^�C�g��:1");
    DrawFormatString(0, 20, Cr, "�Q�[��:2");
    DrawFormatString(0, 40, Cr, "���U���g:3");
    //-----------------
}

// �I������
void GAME::end(void)
{
    DeleteGraph(game.bgHND);

    PLAYER::end();
}

bool GAME::hitcheck_rect(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh)
{
    if (bx < (ax + aw) && ax < (bx + bw) && by < (ay + ah) && ay < (by + bh))
    {
        return true;
    }
    return false;
}

bool GAME::hitcheck_circle(int ax, int ay, int ar, int bx, int by, int br)
{
    float a = ax - bx;
    float b = ay - by;
    int c = a * a + b * b;
    c = sqrt(c);

    if (c <= ar + br)
    {
        return true;
    }
    return false;
}