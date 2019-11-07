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
void player_init(void)
{
    player.state = 0;
    player.timer = 0;
    player.pl_posX = 0;
    player.pl_posY = 0;
    player.pl_speed = 5;
    player.plHND = LoadGraph("Data\\Images\\player.png");
}

// �X�V����
void player_update(void)
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
}

// �`�揈��
void player_draw(void)
{
    DrawGraph(player.pl_posX, player.pl_posY, player.plHND, true);
}

// �I������
void player_end(void)
{
    DeleteGraph(player.plHND);
}
