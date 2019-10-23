// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// �ϐ� --------------------------------------------------------------------------------------------
// �V�[���J�ڗp�ϐ�
extern int nextScene;

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
GAME game;


// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void game_init(void)
{
    game.state = 0;
    game.timer = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");

    player_init();
}

// �X�V����
void game_update(void)
{
    switch (game.state)
    {
    case INIT:

        game.state++;
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

        player_update();
        break;
    }
}

// �`�揈��
void game_draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);

    player_draw();
}

// �I������
void game_end(void)
{
    DeleteGraph(game.bgHND);

    player_end();
}
