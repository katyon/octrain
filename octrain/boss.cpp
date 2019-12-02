// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include <math.h>

#include "boss.h"
#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"
#include "shot.h"

// インスタンス宣言 ---------------------------------------------------------------------------------
BOSS boss;
BULLET boss_bullet[BOSS_BULLET_MAX];

// debug---------------
int rad = 0;
int rad01 = 0;
int rad02 = 0;
int rad03 = 0;

int effect_HND = 0;
int zangeki_HND = 0;

float flash = 0;
float flashing_timer = 0;


//------------------------------

float BOSS::posX = 0;
float BOSS::posY = 0;
int BOSS::hp = 0;
bool BOSS::detect_hit = false;
bool BOSS::detect_deth = false;
bool BOSS::detect_reverse = false;
bool BOSS::detect_damaged = false;
bool BOSS::detect_close_damaged = false;
// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void BOSS::init(void)
{
    for (int i = 0; i < BOSS_BULLET_MAX; i++)
    {
        boss_bullet[i].init(&boss_bullet[i]);
    }

    boss.state = 0;
    boss.state = 0;
    boss.hit_timer = 0;
    boss.damaged_timer = 0;
    boss.close_damaged_timer = 0;
    boss.at_timer = 0;
    boss.move_timer = 0;
    boss.posX = GAME_SCREEN_WIDTH / 2;
    boss.posY = 0;
    boss.pivot_posX = 0;
    boss.pivot_posY = 0;
    boss.speed = 15;
    boss.hp = BOSS_HP;
    boss.sub_hp = BOSS_HP;
    boss.N_attack = N_Column;
    boss.SPK_attack = 0;
    boss.rnd_move_pattern = 0;
    boss.detect_hit = false;
    boss.detect_deth = false;
    boss.detect_attack = false;
    boss.detect_reverse = false;
    boss.detect_damaged = false;
    boss.detect_close_damaged = false;
    boss.detect_useSPK = false;
    boss.once_damaged = false;
    boss.once_close_damaged = false;
    boss.once_at = false;

    effect_HND = LoadGraph("Data\\Images\\zangeki.png");

}

// 更新処理
void BOSS::update(void)
{
    // debug------------------------
//#pragma region RightThumb
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Up))
//    {
//        boss.posY -= boss.speed;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Right))
//    {
//        boss.posX += boss.speed / ROOT5;
//        boss.posY -= boss.speed / ROOT5 * 2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Right))
//    {
//        boss.posX += boss.speed / ROOT2;
//        boss.posY -= boss.speed / ROOT2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Right))
//    {
//        boss.posX += boss.speed / ROOT5 * 2;
//        boss.posY -= boss.speed / ROOT5;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Right))
//    {
//        boss.posX += boss.speed;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Right))
//    {
//        boss.posX += boss.speed / ROOT5 * 2;
//        boss.posY += boss.speed / ROOT5;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Right))
//    {
//        boss.posX += boss.speed / ROOT2;
//        boss.posY += boss.speed / ROOT2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Right))
//    {
//        boss.posX += boss.speed / ROOT5;
//        boss.posY += boss.speed / ROOT5 * 2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Down))
//    {
//        boss.posY += boss.speed;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Left))
//    {
//        boss.posX -= boss.speed / ROOT5;
//        boss.posY += boss.speed / ROOT5 * 2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Left))
//    {
//        boss.posX -= boss.speed / ROOT2;
//        boss.posY += boss.speed / ROOT2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Left))
//    {
//        boss.posX -= boss.speed / ROOT5 * 2;
//        boss.posY += boss.speed / ROOT5;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Left))
//    {
//        boss.posX -= boss.speed;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Left))
//    {
//        boss.posX -= boss.speed / ROOT5 * 2;
//        boss.posY -= boss.speed / ROOT5;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Left))
//    {
//        boss.posX -= boss.speed / ROOT2;
//        boss.posY -= boss.speed / ROOT2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Left))
//    {
//        boss.posX -= boss.speed / ROOT5;
//        boss.posY -= boss.speed / ROOT5 * 2;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Up))
//    {
//        boss.posY -= boss.speed / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Right))
//    {
//        boss.posX += boss.speed / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Down))
//    {
//        boss.posY += boss.speed / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Left))
//    {
//        boss.posX -= boss.speed / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Right))
//    {
//        boss.posX += boss.speed / ROOT2 / 3;
//        boss.posY -= boss.speed / ROOT2 / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Right))
//    {
//        boss.posX += boss.speed / ROOT2 / 3;
//        boss.posY += boss.speed / ROOT2 / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Left))
//    {
//        boss.posX -= boss.speed / ROOT2 / 3;
//        boss.posY += boss.speed / ROOT2 / 3;
//    }
//    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Left))
//    {
//        boss.posX -= boss.speed / ROOT2 / 3;
//        boss.posY -= boss.speed / ROOT2 / 3;
//    }
//#pragma endregion

    flashing_timer++;
    flash = sinf(flashing_timer);

    switch (GAME::state)
    {
    case TITLE:
#pragma region TITLE
        // 遠距離攻撃
        if (false)
        {
            //mg_debug
            rad = GetRand(248);
            rad01 = GetRand(248);
            rad02 = GetRand(248);
            rad03 = GetRand(248);
            flashing_timer = 0;

            //-----------------

            boss.detect_damaged = true;
        }
        if (boss.detect_damaged == true)
        {
            boss.damaged_timer++;
            if (boss.damaged_timer > 15)
            {
                boss.damaged_timer = 0;
                boss.detect_damaged = false;
            }
        }
        // 近距離攻撃
        if (false)
        {
            //mg_debug---------
            rad = GetRand(360);
            flashing_timer = 0;

            //------------------

            boss.detect_close_damaged = true;
        }
        if (boss.detect_close_damaged == true)
        {
            boss.close_damaged_timer++;
            if (boss.close_damaged_timer > 10)
            {
                boss.close_damaged_timer = 0;
                boss.detect_close_damaged = false;
            }
        }
        //------------------------------
        if (BOSS::posX < PLAYER::posX)
        {
            boss.detect_reverse = true;
        }
        else
        {
            boss.detect_reverse = false;
        }
        // hp
        if (boss.detect_hit == true)
        {
            boss.hp -= 50;
        }


        // 移動制限
        if (boss.posX < 0)
        {
            boss.posX = 0;
        }
        if (boss.posX > GAME_SCREEN_WIDTH - BOSS_WIDTH)
        {
            boss.posX = GAME_SCREEN_WIDTH - BOSS_WIDTH;
        }
        if (boss.posY < 0)
        {
            boss.posY = 0;
        }
        if (boss.posY > GAME_SCREEN_HEIGHT - BOSS_HEIGHT)
        {
            boss.posY = GAME_SCREEN_HEIGHT - BOSS_HEIGHT;
        }

#pragma endregion
        break;
    case UPDATE:
#pragma region UPDATE
        if (BOSS::posX < PLAYER::posX)
        {
            boss.detect_reverse = true;
        }
        else
        {
            boss.detect_reverse = false;
        }
        if (boss.detect_useSPK == true)
        {
            // SPK
            switch (boss.SPK_attack)
            {
            case SPK_1:
                break;
            case SPK_2:
                break;
            case SPK_3:
                break;
            }
        }
        else
        {
            // N_attack
            switch (boss.N_attack)
            {
            case N_Diffusion:
                if (boss.once_at == false)
                {
                    for (int i = 0; i < 40; i++)
                    {
                        boss_bullet[i].set_boss_exist(&boss_bullet[i], true);
                    }
                    boss.once_at = true;
                }
                for (int i = 0; i < BOSS_BULLET_MAX; i++)
                {
                    if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
                    {
                        continue;
                    }
                    boss_bullet[i].boss_updete(&boss_bullet[i], BOSS::PATTERN::N_Diffusion);
                }
                if (boss_bullet[0].timer > 0)
                {
                    boss_bullet[0].posX += boss_bullet[0].speed;
                    boss_bullet[1].posX += boss_bullet[1].speed / ROOT2;
                    boss_bullet[1].posY += boss_bullet[1].speed / ROOT2;
                    boss_bullet[2].posY += boss_bullet[2].speed;
                    boss_bullet[3].posX -= boss_bullet[3].speed / ROOT2;
                    boss_bullet[3].posY += boss_bullet[3].speed / ROOT2;
                    boss_bullet[4].posX -= boss_bullet[4].speed;
                    boss_bullet[5].posX -= boss_bullet[5].speed / ROOT2;
                    boss_bullet[5].posY -= boss_bullet[5].speed / ROOT2;
                    boss_bullet[6].posY -= boss_bullet[6].speed;
                    boss_bullet[7].posX += boss_bullet[7].speed / ROOT2;
                    boss_bullet[7].posY -= boss_bullet[7].speed / ROOT2;

                }
                if (boss_bullet[0].timer > 50)
                {
                    boss_bullet[0].posX += boss_bullet[0].speed * 3;
                    boss_bullet[1].posX += boss_bullet[1].speed / ROOT2 * 3;
                    boss_bullet[1].posY += boss_bullet[1].speed / ROOT2 * 3;
                    boss_bullet[2].posY += boss_bullet[2].speed * 3;
                    boss_bullet[3].posX -= boss_bullet[3].speed / ROOT2 * 3;
                    boss_bullet[3].posY += boss_bullet[3].speed / ROOT2 * 3;
                    boss_bullet[4].posX -= boss_bullet[4].speed * 3;
                    boss_bullet[5].posX -= boss_bullet[5].speed / ROOT2 * 3;
                    boss_bullet[5].posY -= boss_bullet[5].speed / ROOT2 * 3;
                    boss_bullet[6].posY -= boss_bullet[6].speed * 3;
                    boss_bullet[7].posX += boss_bullet[7].speed / ROOT2 * 3;
                    boss_bullet[7].posY -= boss_bullet[7].speed / ROOT2 * 3;

                    boss_bullet[8].posX += boss_bullet[8].speed;
                    boss_bullet[9].posX += boss_bullet[9].speed / ROOT2;
                    boss_bullet[9].posY += boss_bullet[9].speed / ROOT2;
                    boss_bullet[10].posY += boss_bullet[10].speed;
                    boss_bullet[11].posX -= boss_bullet[11].speed / ROOT2;
                    boss_bullet[11].posY += boss_bullet[11].speed / ROOT2;
                    boss_bullet[12].posX -= boss_bullet[12].speed;
                    boss_bullet[13].posX -= boss_bullet[13].speed / ROOT2;
                    boss_bullet[13].posY -= boss_bullet[13].speed / ROOT2;
                    boss_bullet[14].posY -= boss_bullet[14].speed;
                    boss_bullet[15].posX += boss_bullet[15].speed / ROOT2;
                    boss_bullet[15].posY -= boss_bullet[15].speed / ROOT2;
                }
                if (boss_bullet[0].timer > 100)
                {
                    boss_bullet[8].posX += boss_bullet[8].speed * 3;
                    boss_bullet[9].posX += boss_bullet[9].speed / ROOT2 * 3;
                    boss_bullet[9].posY += boss_bullet[9].speed / ROOT2 * 3;
                    boss_bullet[10].posY += boss_bullet[10].speed * 3;
                    boss_bullet[11].posX -= boss_bullet[11].speed / ROOT2 * 3;
                    boss_bullet[11].posY += boss_bullet[11].speed / ROOT2 * 3;
                    boss_bullet[12].posX -= boss_bullet[12].speed * 3;
                    boss_bullet[13].posX -= boss_bullet[13].speed / ROOT2 * 3;
                    boss_bullet[13].posY -= boss_bullet[13].speed / ROOT2 * 3;
                    boss_bullet[14].posY -= boss_bullet[14].speed * 3;
                    boss_bullet[15].posX += boss_bullet[15].speed / ROOT2 * 3;
                    boss_bullet[15].posY -= boss_bullet[15].speed / ROOT2 * 3;

                    boss_bullet[16].posX += boss_bullet[16].speed;
                    boss_bullet[17].posX += boss_bullet[17].speed / ROOT2;
                    boss_bullet[17].posY += boss_bullet[17].speed / ROOT2;
                    boss_bullet[18].posY += boss_bullet[18].speed;
                    boss_bullet[19].posX -= boss_bullet[19].speed / ROOT2;
                    boss_bullet[19].posY += boss_bullet[19].speed / ROOT2;
                    boss_bullet[20].posX -= boss_bullet[20].speed;
                    boss_bullet[21].posX -= boss_bullet[21].speed / ROOT2;
                    boss_bullet[21].posY -= boss_bullet[21].speed / ROOT2;
                    boss_bullet[22].posY -= boss_bullet[22].speed;
                    boss_bullet[23].posX += boss_bullet[23].speed / ROOT2;
                    boss_bullet[23].posY -= boss_bullet[23].speed / ROOT2;
                }
                if (boss_bullet[0].timer > 150)
                {
                    boss_bullet[16].posX += boss_bullet[16].speed * 3;
                    boss_bullet[17].posX += boss_bullet[17].speed / ROOT2 * 3;
                    boss_bullet[17].posY += boss_bullet[17].speed / ROOT2 * 3;
                    boss_bullet[18].posY += boss_bullet[18].speed * 3;
                    boss_bullet[19].posX -= boss_bullet[19].speed / ROOT2 * 3;
                    boss_bullet[19].posY += boss_bullet[19].speed / ROOT2 * 3;
                    boss_bullet[20].posX -= boss_bullet[20].speed * 3;
                    boss_bullet[21].posX -= boss_bullet[21].speed / ROOT2 * 3;
                    boss_bullet[21].posY -= boss_bullet[21].speed / ROOT2 * 3;
                    boss_bullet[22].posY -= boss_bullet[22].speed * 3;
                    boss_bullet[23].posX += boss_bullet[23].speed / ROOT2 * 3;
                    boss_bullet[23].posY -= boss_bullet[23].speed / ROOT2 * 3;

                    boss_bullet[24].posX += boss_bullet[24].speed;
                    boss_bullet[25].posX += boss_bullet[25].speed / ROOT2;
                    boss_bullet[25].posY += boss_bullet[25].speed / ROOT2;
                    boss_bullet[26].posY += boss_bullet[26].speed;
                    boss_bullet[27].posX -= boss_bullet[27].speed / ROOT2;
                    boss_bullet[27].posY += boss_bullet[27].speed / ROOT2;
                    boss_bullet[28].posX -= boss_bullet[28].speed;
                    boss_bullet[29].posX -= boss_bullet[29].speed / ROOT2;
                    boss_bullet[29].posY -= boss_bullet[29].speed / ROOT2;
                    boss_bullet[30].posY -= boss_bullet[30].speed;
                    boss_bullet[31].posX += boss_bullet[31].speed / ROOT2;
                    boss_bullet[31].posY -= boss_bullet[31].speed / ROOT2;
                }
                if (boss_bullet[0].timer > 200)
                {
                    boss_bullet[24].posX += boss_bullet[24].speed * 3;
                    boss_bullet[25].posX += boss_bullet[25].speed / ROOT2 * 3;
                    boss_bullet[25].posY += boss_bullet[25].speed / ROOT2 * 3;
                    boss_bullet[26].posY += boss_bullet[26].speed * 3;
                    boss_bullet[27].posX -= boss_bullet[27].speed / ROOT2 * 3;
                    boss_bullet[27].posY += boss_bullet[27].speed / ROOT2 * 3;
                    boss_bullet[28].posX -= boss_bullet[28].speed * 3;
                    boss_bullet[29].posX -= boss_bullet[29].speed / ROOT2 * 3;
                    boss_bullet[29].posY -= boss_bullet[29].speed / ROOT2 * 3;
                    boss_bullet[30].posY -= boss_bullet[30].speed * 3;
                    boss_bullet[31].posX += boss_bullet[31].speed / ROOT2 * 3;
                    boss_bullet[31].posY -= boss_bullet[31].speed / ROOT2 * 3;

                    boss_bullet[32].posX += boss_bullet[32].speed;
                    boss_bullet[33].posX += boss_bullet[33].speed / ROOT2;
                    boss_bullet[33].posY += boss_bullet[33].speed / ROOT2;
                    boss_bullet[34].posY += boss_bullet[34].speed;
                    boss_bullet[35].posX -= boss_bullet[35].speed / ROOT2;
                    boss_bullet[35].posY += boss_bullet[35].speed / ROOT2;
                    boss_bullet[36].posX -= boss_bullet[36].speed;
                    boss_bullet[37].posX -= boss_bullet[37].speed / ROOT2;
                    boss_bullet[37].posY -= boss_bullet[37].speed / ROOT2;
                    boss_bullet[38].posY -= boss_bullet[38].speed;
                    boss_bullet[39].posX += boss_bullet[39].speed / ROOT2;
                    boss_bullet[39].posY -= boss_bullet[39].speed / ROOT2;
                }
                if (boss_bullet[0].timer > 250)
                {
                    boss_bullet[32].posX += boss_bullet[32].speed * 3;
                    boss_bullet[33].posX += boss_bullet[33].speed / ROOT2 * 3;
                    boss_bullet[33].posY += boss_bullet[33].speed / ROOT2 * 3;
                    boss_bullet[34].posY += boss_bullet[34].speed * 3;
                    boss_bullet[35].posX -= boss_bullet[35].speed / ROOT2 * 3;
                    boss_bullet[35].posY += boss_bullet[35].speed / ROOT2 * 3;
                    boss_bullet[36].posX -= boss_bullet[36].speed * 3;
                    boss_bullet[37].posX -= boss_bullet[37].speed / ROOT2 * 3;
                    boss_bullet[37].posY -= boss_bullet[37].speed / ROOT2 * 3;
                    boss_bullet[38].posY -= boss_bullet[38].speed * 3;
                    boss_bullet[39].posX += boss_bullet[39].speed / ROOT2 * 3;
                    boss_bullet[39].posY -= boss_bullet[39].speed / ROOT2 * 3;
                }
                if (boss_bullet[0].timer > 500)
                {
                    for (int i = 0; i < 40; i++)
                    {
                        boss_bullet[i].set_boss_exist(&boss_bullet[i], false);
                    }
                    boss.once_at = false;
                    boss_bullet[0].timer = 0;
                    boss.N_attack = GetRand(3);
                }
                boss_bullet[0].timer++;
                break;
            case N_Homing:
                if (boss.once_at == false)
                {
                    boss_bullet[80].set_boss_exist(&boss_bullet[80], true);
                    boss_bullet[81].set_boss_exist(&boss_bullet[81], true);
                    boss_bullet[82].set_boss_exist(&boss_bullet[82], true);
                    boss_bullet[83].set_boss_exist(&boss_bullet[83], true);
                    boss_bullet[84].set_boss_exist(&boss_bullet[84], true);
                    boss_bullet[85].set_boss_exist(&boss_bullet[85], true);

                    boss.once_at = true;
                }
                for (int i = 0; i < BOSS_BULLET_MAX; i++)
                {
                    if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
                    {
                        continue;
                    }
                    boss_bullet[i].boss_updete(&boss_bullet[i], BOSS::PATTERN::N_Homing);
                }
                if (boss_bullet[80].timer > 0)
                {
                    boss_bullet[80].posY -= boss_bullet[80].speed;
                    boss_bullet[81].posX += boss_bullet[81].speed / ROOT2;
                    boss_bullet[81].posY -= boss_bullet[81].speed / ROOT2;
                    boss_bullet[82].posX -= boss_bullet[82].speed / ROOT2;
                    boss_bullet[82].posY -= boss_bullet[82].speed / ROOT2;
                }
                if (boss_bullet[80].timer > 150)
                {
                    boss_bullet[80].judgeTurningDirection(&boss_bullet[80]);
                    boss_bullet[81].judgeTurningDirection(&boss_bullet[81]);
                    boss_bullet[82].judgeTurningDirection(&boss_bullet[82]);

                    boss_bullet[83].posY -= boss_bullet[83].speed;
                    boss_bullet[84].posX += boss_bullet[84].speed / ROOT2;
                    boss_bullet[84].posY -= boss_bullet[84].speed / ROOT2;
                    boss_bullet[85].posX -= boss_bullet[85].speed / ROOT2;
                    boss_bullet[85].posY -= boss_bullet[85].speed / ROOT2;
                }
                if (boss_bullet[80].timer > 300)
                {
                    boss_bullet[83].judgeTurningDirection(&boss_bullet[83]);
                    boss_bullet[84].judgeTurningDirection(&boss_bullet[84]);
                    boss_bullet[85].judgeTurningDirection(&boss_bullet[85]);
                }
                if (boss_bullet[80].timer > 600)
                {
                    boss_bullet[80].set_boss_exist(&boss_bullet[80], false);
                    boss_bullet[81].set_boss_exist(&boss_bullet[81], false);
                    boss_bullet[82].set_boss_exist(&boss_bullet[82], false);
                    boss_bullet[83].set_boss_exist(&boss_bullet[83], false);
                    boss_bullet[84].set_boss_exist(&boss_bullet[84], false);
                    boss_bullet[85].set_boss_exist(&boss_bullet[85], false);

                    boss.once_at = false;
                    boss_bullet[80].timer = 0;
                    boss.N_attack = GetRand(3);
                }
                boss_bullet[80].timer++;
                break;
            case N_Column:
                if (boss_bullet[220].timer > 150)
                {
                    boss_bullet[220].timer = 0;
                    boss.N_attack = GetRand(2);
                }
                boss_bullet[220].timer++;
                break;
            }

            // 移動制限
            if (boss.posX < 0)
            {
                boss.posX = 0;
            }
            if (boss.posX > GAME_SCREEN_WIDTH - BOSS_WIDTH)
            {
                boss.posX = GAME_SCREEN_WIDTH - BOSS_WIDTH;
            }
            if (boss.posY < 0)
            {
                boss.posY = 0;
            }
            if (boss.posY > GAME_SCREEN_HEIGHT - BOSS_HEIGHT)
            {
                boss.posY = GAME_SCREEN_HEIGHT - BOSS_HEIGHT;
            }
        }

        // move
        switch (boss.rnd_move_pattern)
        {
        case 0:
            // 接近
            if (boss.move_timer > 200)
            {
                if (boss.posX < PLAYER::posX - 100)
                {
                    boss.posX += 3;
                }
                else if (boss.posX > PLAYER::posX + 100)
                {
                    boss.posX -= 3;
                }
                if (boss.posY < PLAYER::posY - 100)
                {
                    boss.posY += 2;
                }
                else if (boss.posY > PLAYER::posY + 100)
                {
                    boss.posY -= 2;
                }
                if (boss.move_timer > 500)
                {
                    boss.move_timer = 0;
                    boss.rnd_move_pattern = GetRand(3);
                }
            }
            break;
        case 1:
            // 離脱
            if (boss.move_timer > 200)
            {
                if (boss.posX > PLAYER::posX - 100)
                {
                    boss.posX += 3;
                }
                else if (boss.posX < PLAYER::posX + 100)
                {
                    boss.posX -= 3;
                }
                if (boss.posY < PLAYER::posY - 100)
                {
                    boss.posY += 2;
                }
                else if (boss.posY > PLAYER::posY + 100)
                {
                    boss.posY -= 2;
                }
                if (boss.move_timer > 500)
                {
                    boss.move_timer = 0;
                    boss.rnd_move_pattern = GetRand(3);
                }
            }
            break;
        case 2:
            if (boss.move_timer > 300)
            {
                boss.move_timer = 0;
                boss.rnd_move_pattern = GetRand(3);
            }
            break;
        }
        boss.move_timer++;
        // 移動制限
        if (boss.posX < 0)
        {
            boss.posX = 0;
        }
        if (boss.posX > GAME_SCREEN_WIDTH - BOSS_WIDTH)
        {
            boss.posX = GAME_SCREEN_WIDTH - BOSS_WIDTH;
        }
        if (boss.posY < 0)
        {
            boss.posY = 0;
        }
        if (boss.posY > GAME_SCREEN_HEIGHT - BOSS_HEIGHT)
        {
            boss.posY = GAME_SCREEN_HEIGHT - BOSS_HEIGHT;
        }
#pragma endregion
        break;
    }
}

// 描画処理
void BOSS::draw(void)
{
    if (boss.detect_reverse == true)
    {
        DrawRectGraphF(boss.posX, boss.posY, 1416 + BOSS_WIDTH * (GAME::timer / 7 % 4), 0, BOSS_WIDTH, BOSS_HEIGHT, GAME::spriteHND, true, true, false);
    }
    else
    {
        DrawRectGraphF(boss.posX, boss.posY, 1416 + BOSS_WIDTH * (GAME::timer / 7 % 4), 0, BOSS_WIDTH, BOSS_HEIGHT, GAME::spriteHND, true, false, false);
    }

    if (boss.hp < 0)
    {
        COMMON::nextScene = SCENE_RESULT;
    }
    //Mg_debug(hit effect)-------------
    flashing_timer++;
    flash = sinf(flashing_timer * 0.175f) - 0.1;

    if (boss.detect_close_damaged == true)
    {
        // 近距離攻撃
        if (boss.once_close_damaged == false)
        {
            //mg_debug---------
            rad = GetRand(360);
            flashing_timer = 0;
            //------------------
            boss.once_close_damaged = true;
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);















































        DrawRotaGraph3(boss.posX + BOSS_WIDTH / 2, boss.posY + BOSS_HEIGHT / 2, 100, 25, 5, flash, rad, effect_HND, TRUE);
        //DrawRotaGraph3(boss.posX + BOSS_WIDTH / 2, boss.posY + BOSS_HEIGHT / 2, 100, 25, 3, flash, rad + 50, effect_HND, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        boss.close_damaged_timer++;
        if (boss.close_damaged_timer > 10)
        {
            boss.close_damaged_timer = 0;
            boss.detect_close_damaged = false;
            boss.once_close_damaged = false;
        }
    }

    if (boss.detect_damaged == true)
    {
        // 遠距離攻撃
        if (boss.once_damaged == false)
        {
            //mg_debug
            rad = GetRand(248);
            rad01 = GetRand(248);
            rad02 = GetRand(248);
            rad03 = GetRand(248);
            flashing_timer = 0;
            //-----------------
            boss.once_damaged = true;
        }
        unsigned int  Cr = GetColor(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawCircle(boss.posX + 5, boss.posY + rad, flash * 45, Cr, TRUE);
        DrawCircle(boss.posX + 40, boss.posY + rad01, flash * 35, Cr, TRUE);
        DrawCircle(boss.posX + 90, boss.posY + rad02, flash * 60, Cr, TRUE);
        DrawCircle(boss.posX + 140, boss.posY + rad03, flash * 25, Cr, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        boss.damaged_timer += 1;
        if (boss.damaged_timer > 15)
        {
            boss.damaged_timer = 0;
            boss.once_damaged = false;
            boss.detect_damaged = false;
        }
    }
    //----------------------
    DrawRectGraph(GAME_SCREEN_WIDTH / 2, 0, 2088, 64, BOSS_HP, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(GAME_SCREEN_WIDTH / 2 + BOSS_HP - boss.hp, 0, 2088, 0, boss.hp, 64, GAME::spriteHND, true, false, false);
    //debug-----
    //unsigned int  Cr = GetColor(200, 0, 0);
    //DrawFormatString(200, 60, Cr, "boss.detect_damaged:%d", boss.detect_damaged);
    //DrawFormatString(200, 80, Cr, "boss.detect_close_damaged:%d", boss.detect_close_damaged);

    //DrawBox(boss.posX, boss.posY, boss.posX + BOSS_WIDTH, boss.posY + BOSS_HEIGHT, GetColor(0, 200, 0), false);
    //--------

    // SPK
    switch (boss.SPK_attack)
    {
    case SPK_1:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 3);
        }
        break;
    case SPK_2:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 4);
        }
        break;
    case SPK_3:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 5);
        }
        break;
    }
    // N_attack
    switch (boss.N_attack)
    {
    case N_Diffusion:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 0);
        }
        break;
    case N_Homing:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 1);
        }
        break;
    case N_Column:
        for (int i = 0; i < BOSS_BULLET_MAX; i++)
        {
            if (boss_bullet[i].get_boss_exist(&boss_bullet[i]) == false)
            {
                continue;
            }
            boss_bullet[i].boss_draw(&boss_bullet[i], 2);
        }
        break;
    }
}

// 終了処理
void BOSS::end(void)
{
    DeleteGraph(effect_HND);
}

