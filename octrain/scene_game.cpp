// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

#include <math.h>

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
GAME game;

int GAME::timer = 0;
bool GAME::zoom_mode = false;
// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void GAME::init(void)
{
    GAME::timer = 0;
    game.state = 0;
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

        GAME::timer++;
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
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_DPAD_UP))
        {
            if (GAME::zoom_mode == false)
                GAME::zoom_mode = true;
            else
                GAME::zoom_mode = false;
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
    DrawFormatString(100, 20, Cr, "zoom_mode:%d", game.zoom_mode);
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