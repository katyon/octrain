// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "boss.h"

// �ϐ� --------------------------------------------------------------------------------------------

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
BOSS boss;

// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void BOSS::init(void)
{
    boss.state = 0;
    boss.timer = 0;
    boss.bs_posX = 100;
    boss.bs_posY = 100;
    boss.bs_subposX = 0;
    boss.bs_subposY = 0;
    boss.bs_speed = 10;
    boss.bsHND = LoadGraph("Data\\Images\\boss.png");
}

// �X�V����
void BOSS::update(void)
{
    // debug
    if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A))
    {
        boss.bs_posX -= boss.bs_speed;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))
    {
        boss.bs_posX += boss.bs_speed;
    }
    if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))
    {
        boss.bs_posY -= boss.bs_speed;
    }
    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))
    {
        boss.bs_posY += boss.bs_speed;
    }
    //--------

    // �ړ�
    if (Input::GetInstance()->GetLThumbX(PL_1) < 0)
    {
        boss.bs_posX -= boss.bs_speed;
    }
    if (Input::GetInstance()->GetLThumbX(PL_1) > 0)
    {
        boss.bs_posX += boss.bs_speed;
    }
    if (Input::GetInstance()->GetLThumbY(PL_1) > 0)
    {
        boss.bs_posY -= boss.bs_speed;
    }
    if (Input::GetInstance()->GetLThumbY(PL_1) < 0)
    {
        boss.bs_posY += boss.bs_speed;
    }

    // �ړ�����
    if (boss.bs_posX < 0)
    {
        boss.bs_posX = 0;
    }
    if (boss.bs_posX > GAME_SCREEN_WIDTH - 200 + 1)
    {
        boss.bs_posX = GAME_SCREEN_WIDTH - 200 + 1;
    }
    if (boss.bs_posY < 0)
    {
        boss.bs_posY = 0;
    }
    if (boss.bs_posY > GAME_SCREEN_HEIGHT - 320 + 1)
    {
        boss.bs_posY = GAME_SCREEN_HEIGHT - 320 + 1;
    }

    boss.bs_subposX = boss.bs_posX + 200 - 1;
    boss.bs_subposY = boss.bs_posY + 320 - 1;
}

// �`�揈��
void BOSS::draw(void)
{
    DrawExtendGraph(boss.bs_posX, boss.bs_posY, boss.bs_subposX, boss.bs_subposY, boss.bsHND, true);
}

// �I������
void BOSS::end(void)
{
    DeleteGraph(boss.bsHND);
}

