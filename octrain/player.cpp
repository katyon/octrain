// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"

// �ϐ� --------------------------------------------------------------------------------------------

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
PLAYER player;

// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void PLAYER::init(void)
{
    player.state = 0;
    player.timer = 0;
    player.pl_posX = 0;
    player.pl_posY = 0;
    player.pl_subposX = 0;
    player.pl_subposY = 0;
    player.pl_speed = 10;
    player.plHND = LoadGraph("Data\\Images\\player.png");
}

// �X�V����
void PLAYER::update(void)
{
    // debug
    if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A))
    {
        player.pl_posX -= player.pl_speed;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))
    {
        player.pl_posX += player.pl_speed;
    }
    if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))
    {
        player.pl_posY -= player.pl_speed;
    }
    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))
    {
        player.pl_posY += player.pl_speed;
    }
    //--------

    // �ړ�
    if (Input::GetInstance()->GetLThumbX(PL_1) < 0)
    {
        player.pl_posX -= player.pl_speed;
    }
    if (Input::GetInstance()->GetLThumbX(PL_1) > 0)
    {
        player.pl_posX += player.pl_speed;
    }
    if (Input::GetInstance()->GetLThumbY(PL_1) > 0)
    {
        player.pl_posY -= player.pl_speed;
    }
    if (Input::GetInstance()->GetLThumbY(PL_1) < 0)
    {
        player.pl_posY += player.pl_speed;
    }

    // �ړ�����
    if (player.pl_posX < 0)
    {
        player.pl_posX = 0;
    }
    if (player.pl_posX > GAME_SCREEN_WIDTH - 200 + 1)
    {
        player.pl_posX = GAME_SCREEN_WIDTH - 200 + 1;
    }
    if (player.pl_posY < 0)
    {
        player.pl_posY = 0;
    }
    if (player.pl_posY > GAME_SCREEN_HEIGHT - 320 + 1)
    {
        player.pl_posY = GAME_SCREEN_HEIGHT - 320 + 1;
    }

    player.pl_subposX = player.pl_posX + 200 - 1;
    player.pl_subposY = player.pl_posY + 320 - 1;
}

// �`�揈��
void PLAYER::draw(void)
{
    DrawExtendGraph(player.pl_posX, player.pl_posY, player.pl_subposX, player.pl_subposY, player.plHND, true);
}

// �I������
void PLAYER::end(void)
{
    DeleteGraph(player.plHND);
}
