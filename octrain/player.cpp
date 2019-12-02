// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "boss.h"
#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"
#include "shot.h"

// インスタンス宣言 ---------------------------------------------------------------------------------
PLAYER player;
BULLET pl_bullet[PL_BULLET_MAX];

float PLAYER::posX = 0;
float PLAYER::posY = 0;
float PLAYER::pivot_posX = 0;
float PLAYER::pivot_posY = 0;
int PLAYER::hp = 0;
int PLAYER::guard_timer = 0;
bool PLAYER::detect_hit = false;
bool PLAYER::detect_closerange = false;
bool PLAYER::detect_deth = false;
bool PLAYER::detect_reverse = false;

int PLAYER::zangeki_seHND = 0;
int PLAYER::shot_seHND = 0;
int PLAYER::guard_seHND = 0;
int PLAYER::reload_seHND = 0;
// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void PLAYER::init(void)
{
    for (int i = 0; i < PL_BULLET_MAX; i++)
    {
        pl_bullet[i].init(&pl_bullet[i]);
    }

    player.state = 0;
    player.hit_timer = 0;
    player.at_timer = 0;
    player.close_at1_timer = 0;
    player.close_at2_timer = 0;
    player.posX = 0;
    player.posY = 0;
    player.sub_posX = 0;
    player.sub_posY = 0;
    player.pivot_posX = 0;
    player.pivot_posY = 0;
    player.speed = 15;
    player.init_hp = 500;
    player.hp = player.init_hp;
    player.sub_hp = player.init_hp;
    player.init_bullet = 10;
    player.bullet = player.init_bullet;
    player.bullet_count = 0;
    player.power = 10;
    player.detect_hit = false;
    player.detect_closerange = false;
    player.detect_deth = false;
    player.detect_reverse = true;
    player.detect_attack = false;
    player.detect_close_attack1 = false;
    player.detect_close_attack2 = false;
    player.efHND = LoadGraph("Data\\Images\\zangeki_effect.png");
    player.ef_timer = 0;
    player.ef = false;
    player.guard_timer = 0;

    player.zangeki_seHND = LoadSoundMem("Data\\Sounds\\zangeki.wav");
    player.shot_seHND = LoadSoundMem("Data\\Sounds\\shot.wav");
    player.guard_seHND = LoadSoundMem("Data\\Sounds\\guard.wav");
    player.reload_seHND = LoadSoundMem("Data\\Sounds\\reload.wav");
}

// 更新処理
void PLAYER::update(void)
{
    switch (GAME::state)
    {
    case TITLE:
#pragma region TITLE
        // 移動
#pragma region LeftThumb
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
        {
            player.posY -= player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Right))
        {
            player.posX += player.speed / ROOT5;
            player.posY -= player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
        {
            player.posX += player.speed / ROOT2;
            player.posY -= player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
        {
            player.posX += player.speed / ROOT5 * 2;
            player.posY -= player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
        {
            player.posX += player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
        {
            player.posX += player.speed / ROOT5 * 2;
            player.posY += player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
        {
            player.posX += player.speed / ROOT2;
            player.posY += player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
        {
            player.posX += player.speed / ROOT5;
            player.posY += player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
        {
            player.posY += player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
        {
            player.posX -= player.speed / ROOT5;
            player.posY += player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
        {
            player.posX -= player.speed / ROOT2;
            player.posY += player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
        {
            player.posX -= player.speed / ROOT5 * 2;
            player.posY += player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
        {
            player.posX -= player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
        {
            player.posX -= player.speed / ROOT5 * 2;
            player.posY -= player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
        {
            player.posX -= player.speed / ROOT2;
            player.posY -= player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
        {
            player.posX -= player.speed / ROOT5;
            player.posY -= player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Up))
        {
            player.posY -= player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Right))
        {
            player.posX += player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Down))
        {
            player.posY += player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Left))
        {
            player.posX -= player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Right))
        {
            player.posX += player.speed / ROOT2 / 3;
            player.posY -= player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Right))
        {
            player.posX += player.speed / ROOT2 / 3;
            player.posY += player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Left))
        {
            player.posX -= player.speed / ROOT2 / 3;
            player.posY += player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Left))
        {
            player.posX -= player.speed / ROOT2 / 3;
            player.posY -= player.speed / ROOT2 / 3;
        }
#pragma endregion

        // 移動制限
        if (player.detect_reverse == true)
        {
            if (player.posX < -88)
            {
                player.posX = -88;
            }
            if (player.posX > GAME_SCREEN_WIDTH - PL_WIDTH + 24)
            {
                player.posX = GAME_SCREEN_WIDTH - PL_WIDTH + 24;
            }
            if (player.posY < -52)
            {
                player.posY = -52;
            }
            if (player.posY > GAME_SCREEN_HEIGHT - PL_HEIGHT + 32)
            {
                player.posY = GAME_SCREEN_HEIGHT - PL_HEIGHT + 32;
            }
        }
        else
        {
            if (player.posX < -24)
            {
                player.posX = -24;
            }
            if (player.posX > GAME_SCREEN_WIDTH - PL_WIDTH + 148)
            {
                player.posX = GAME_SCREEN_WIDTH - PL_WIDTH + 148;
            }
            if (player.posY < -52)
            {
                player.posY = -52;
            }
            if (player.posY > GAME_SCREEN_HEIGHT - PL_HEIGHT + 32)
            {
                player.posY = GAME_SCREEN_HEIGHT - PL_HEIGHT + 32;
            }
        }
        // hit
        if (player.detect_hit == true)
        {
            player.hit_timer++;
            if (player.hit_timer > 100)
            {
                player.hit_timer = 0;
                player.detect_hit = false;
            }
        }
        // reverse
        if (PLAYER::posX < BOSS::posX)
        {
            player.detect_reverse = true;
        }
        else
        {
            player.detect_reverse = false;
        }

        // closerange
        // attack
        if (player.detect_close_attack1 == true)
        {
            player.close_at1_timer++;
            if (player.close_at1_timer > 20)
            {
                player.close_at1_timer = 0;
                player.detect_close_attack1 = false;
            }
        }
        if (player.detect_close_attack2 == true)
        {
            player.close_at2_timer++;
            if (player.close_at2_timer > 20)
            {
                player.close_at2_timer = 0;
                player.detect_close_attack2 = false;
            }
        }
        if (player.detect_attack == true)
        {
            player.at_timer++;
            if (player.at_timer > 20)
            {
                player.at_timer = 0;
                player.detect_attack = false;
            }
        }

        for (int i = 0; i < PL_BULLET_MAX; i++)
        {
            if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == false)
            {
                continue;
            }
            if (GAME::hitcheck_rect(pl_bullet[i].get_posX(&pl_bullet[i]), pl_bullet[i].get_posY(&pl_bullet[i]), 64, 64, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                pl_bullet[i].set_pl_exist(&pl_bullet[i], false);
                BOSS::hp -= player.power;
            }
        }

        if (player.detect_closerange == true)
        {
            if (player.detect_close_attack1 == false)
            {
                if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
                {
                    player.power += 1;
                    player.detect_close_attack1 = true;
                }
            }
            else
            {
                if (player.detect_close_attack2 == false)
                {
                    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
                    {
                        player.power += 2;
                        player.detect_close_attack2 = true;
                    }
                }
            }
        }

        if (player.detect_attack == false)
        {
            if (player.bullet > 0 && Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))
            {
                PlaySoundMem(player.shot_seHND, DX_PLAYTYPE_BACK, TRUE);
                player.bullet -= 1;
                player.detect_attack = true;
                for (int i = 0; i < PL_BULLET_MAX; i++)
                {
                    if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == true)
                    {
                        continue;
                    }
                    pl_bullet[i].set_pl_exist(&pl_bullet[i], true);
                    player.bullet_count++;
                    break;
                }
            }
        }

        if (player.bullet <= 0)
        {
            player.bullet = 0;
        }
        else if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))
        {
            PlaySoundMem(player.guard_seHND, DX_PLAYTYPE_BACK, FALSE);
            guard_timer++;
            player.bullet -= 2;
        }
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_X))
        {
            PlaySoundMem(player.reload_seHND, DX_PLAYTYPE_BACK, FALSE);
            player.bullet = player.init_bullet;
            player.power = 10;
        }

        // 調整
        player.sub_posX = player.posX + PL_WIDTH - 1;
        player.sub_posY = player.posY + PL_HEIGHT - 1;
        player.pivot_posX = player.posX + PL_WIDTH / 2;
        player.pivot_posY = player.posY + PL_HEIGHT / 2;

        // bullet
        for (int i = 0; i < PL_BULLET_MAX; i++)
        {
            if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == false)
            {
                continue;
            }
            pl_bullet[i].pl_update(&pl_bullet[i]);
        }
#pragma endregion
        break;

    case UPDATE:
#pragma region UPDATE
        //// debug--------------------------------------------------------
        //if (CheckHitKey(KEY_INPUT_A))
        //{
        //    player.posX -= player.speed;
        //}
        //if (CheckHitKey(KEY_INPUT_D))
        //{
        //    player.posX += player.speed;
        //}
        //if (CheckHitKey(KEY_INPUT_W))
        //{
        //    player.posY -= player.speed;
        //}
        //if (CheckHitKey(KEY_INPUT_S))
        //{
        //    player.posY += player.speed;
        //}
        ////----------------------------------------------------------------
        // 移動
#pragma region LeftThumb
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
        {
            player.posY -= player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Right))
        {
            player.posX += player.speed / ROOT5;
            player.posY -= player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
        {
            player.posX += player.speed / ROOT2;
            player.posY -= player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
        {
            player.posX += player.speed / ROOT5 * 2;
            player.posY -= player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
        {
            player.posX += player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
        {
            player.posX += player.speed / ROOT5 * 2;
            player.posY += player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
        {
            player.posX += player.speed / ROOT2;
            player.posY += player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
        {
            player.posX += player.speed / ROOT5;
            player.posY += player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
        {
            player.posY += player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
        {
            player.posX -= player.speed / ROOT5;
            player.posY += player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
        {
            player.posX -= player.speed / ROOT2;
            player.posY += player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
        {
            player.posX -= player.speed / ROOT5 * 2;
            player.posY += player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
        {
            player.posX -= player.speed;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
        {
            player.posX -= player.speed / ROOT5 * 2;
            player.posY -= player.speed / ROOT5;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
        {
            player.posX -= player.speed / ROOT2;
            player.posY -= player.speed / ROOT2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
        {
            player.posX -= player.speed / ROOT5;
            player.posY -= player.speed / ROOT5 * 2;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Up))
        {
            player.posY -= player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Right))
        {
            player.posX += player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Down))
        {
            player.posY += player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Left))
        {
            player.posX -= player.speed / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Right))
        {
            player.posX += player.speed / ROOT2 / 3;
            player.posY -= player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Right))
        {
            player.posX += player.speed / ROOT2 / 3;
            player.posY += player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Left))
        {
            player.posX -= player.speed / ROOT2 / 3;
            player.posY += player.speed / ROOT2 / 3;
        }
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Left))
        {
            player.posX -= player.speed / ROOT2 / 3;
            player.posY -= player.speed / ROOT2 / 3;
        }
#pragma endregion

        // 移動制限
        if (player.detect_reverse == true)
        {
            if (player.posX < -88)
            {
                player.posX = -88;
            }
            if (player.posX > GAME_SCREEN_WIDTH - PL_WIDTH + 24)
            {
                player.posX = GAME_SCREEN_WIDTH - PL_WIDTH + 24;
            }
            if (player.posY < -52)
            {
                player.posY = -52;
            }
            if (player.posY > GAME_SCREEN_HEIGHT - PL_HEIGHT + 32)
            {
                player.posY = GAME_SCREEN_HEIGHT - PL_HEIGHT + 32;
            }
        }
        else
        {
            if (player.posX < -24)
            {
                player.posX = -24;
            }
            if (player.posX > GAME_SCREEN_WIDTH - PL_WIDTH + 148)
            {
                player.posX = GAME_SCREEN_WIDTH - PL_WIDTH + 148;
            }
            if (player.posY < -52)
            {
                player.posY = -52;
            }
            if (player.posY > GAME_SCREEN_HEIGHT - PL_HEIGHT + 32)
            {
                player.posY = GAME_SCREEN_HEIGHT - PL_HEIGHT + 32;
            }
        }

        // hit
        if (player.detect_hit == true)
        {
            player.hit_timer++;
            if (player.hit_timer > 90)
            {
                player.hit_timer = 0;
                player.detect_hit = false;
            }
        }

        // deth
        if (player.hp <= 0)
        {
            player.hp = 0;
            player.detect_deth = true;
        }

        // reverse
        if (PLAYER::posX < BOSS::posX)
        {
            player.detect_reverse = true;
        }
        else
        {
            player.detect_reverse = false;
        }

        // closerange
        // attack
        if (player.detect_close_attack1 == true)
        {
            player.close_at1_timer++;
            if (player.close_at1_timer > 20)
            {
                player.close_at1_timer = 0;
                player.detect_close_attack1 = false;
            }
        }
        if (player.detect_close_attack2 == true)
        {
            player.close_at2_timer++;
            if (player.close_at2_timer > 20)
            {
                player.close_at2_timer = 0;
                player.detect_close_attack2 = false;
            }
        }
        if (player.detect_attack == true)
        {
            player.at_timer++;
            if (player.at_timer > 20)
            {
                player.at_timer = 0;
                player.detect_attack = false;
            }
        }

        for (int i = 0; i < PL_BULLET_MAX; i++)
        {
            if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == false)
            {
                continue;
            }
            if (GAME::hitcheck_rect(pl_bullet[i].get_posX(&pl_bullet[i]), pl_bullet[i].get_posY(&pl_bullet[i]), 64, 64, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                pl_bullet[i].set_pl_exist(&pl_bullet[i], false);
                BOSS::hp -= player.power;
                BOSS::detect_damaged = true;
            }
        }

        if (player.detect_closerange == true)
        {
            if (player.detect_close_attack1 == false)
            {
                if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
                {
                    BOSS::hp -= 10;
                    player.power += 1;
                    player.detect_close_attack1 = true;
                    BOSS::detect_close_damaged = true;
                }
            }
            else
            {
                if (player.detect_close_attack2 == false)
                {
                    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
                    {
                        player.power += 2;
                        player.detect_close_attack2 = true;
                        BOSS::detect_close_damaged = true;
                        BOSS::hp -= 10;
                    }
                }
            }
        }

        if (player.detect_attack == false)
        {
            if (player.bullet > 0 && Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))
            {
                player.bullet -= 1;
                player.detect_attack = true;
                for (int i = 0; i < PL_BULLET_MAX; i++)
                {
                    if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == true)
                    {
                        continue;
                    }
                    pl_bullet[i].set_pl_exist(&pl_bullet[i], true);
                    player.bullet_count++;
                    break;
                }
            }
        }

        if (player.bullet <= 0)
        {
            player.bullet = 0;
        }
        else if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))
        {
            player.bullet -= 2;
            player.ef = true;
        }

        if (player.ef == true)
        {
            player.ef_timer++;
            if (player.ef_timer > 20)
            {
                player.ef_timer = 0;
                player.ef = false;
            }
        }

        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_X))
        {
            player.bullet = player.init_bullet;
            player.power = 10;
        }

        // 調整
        player.sub_posX = player.posX + PL_WIDTH - 1;
        player.sub_posY = player.posY + PL_HEIGHT - 1;
        player.pivot_posX = player.posX + PL_WIDTH / 2;
        player.pivot_posY = player.posY + PL_HEIGHT / 2;

        // bullet
        for (int i = 0; i < PL_BULLET_MAX; i++)
        {
            if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == false)
            {
                continue;
            }
            pl_bullet[i].pl_update(&pl_bullet[i]);
        }
#pragma endregion
        break;
    }
}

// 描画処理
void PLAYER::draw(void)
{
    if (player.detect_reverse == true)
    {
        if (player.detect_hit == true)
        {
            if (player.hit_timer / 10 % 2)
            {
                if (player.detect_close_attack1 == true)
                {
                    if (player.detect_close_attack2 == true)
                    {
                        if (player.close_at2_timer < 10)
                        {
                            // close_attack2(reverse,hit)
                            DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 52) * (player.close_at2_timer / 5 % 3), 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, true, false);
                        }
                        else
                        {
                            DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 52) * 2, 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, true, false);
                        }
                    }
                    else
                    {
                        if (player.close_at1_timer < 10)
                        {
                            // close_attack1(reverse,hit)
                            DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                        }
                        else
                        {
                            DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * 2, 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                        }
                    }
                }
                else
                {
                    if (player.ef == true)
                    {
                        DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 996, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                        DrawRectGraphF(player.posX + 265, player.posY, 160 * (player.ef_timer / 4 % 5), 0, 160, 350, player.efHND, true, true, false);
                    }
                    else
                    {
                        // wait(reverse,hit)
                        DrawRectGraphF(player.posX, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    }
                }
            }
        }
        else
        {
            if (player.detect_close_attack1 == true)
            {
                if (player.detect_close_attack2 == true)
                {
                    if (player.close_at2_timer < 10)
                    {
                        // close_attack2(reverse)
                        DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 52) * (player.close_at2_timer / 5 % 3), 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    }
                    else
                    {
                        DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 52) * 2, 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    }
                }
                else
                {
                    if (player.close_at1_timer < 10)
                    {
                        //close_attack1(reverse)
                        DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    }
                    else
                    {
                        DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * 2, 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    }
                }
            }
            else
            {
                if (player.ef == true)
                {
                    DrawRectGraphF(player.posX, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 996, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, true, false);
                    DrawRectGraphF(player.posX + 265, player.posY, 160 * (player.ef_timer / 4 % 5), 0, 160, 350, player.efHND, true, true, false);
                }
                else
                {
                    // wait(reverse)
                    DrawRectGraphF(player.posX, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, true, false);
                }
            }
        }
    }
    else
    {
        if (player.detect_hit == true)
        {
            if (player.hit_timer / 15 % 2)
            {
                if (player.detect_close_attack1 == true)
                {
                    if (player.detect_close_attack2 == true)
                    {
                        if (player.close_at2_timer < 10)
                        {
                            // close_attack2(hit)
                            DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 52) * (player.close_at2_timer / 5 % 3), 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, false, false);
                        }
                        else
                        {
                            DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 52) * 2, 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, false, false);
                        }
                    }
                    else
                    {
                        if (player.close_at1_timer < 10)
                        {
                            //close_attack1(hit)
                            DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                        }
                        else
                        {
                            DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * 2, 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                        }
                    }
                }
                else
                {
                    if (player.ef == true)
                    {
                        DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 996, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                        DrawRectGraphF(player.posX - 190, player.posY, 160 * (player.ef_timer / 4 % 5), 0, 160, 350, player.efHND, true, false, false);
                    }
                    else
                    {
                        // wait(hit)
                        DrawRectGraphF(player.posX - 60, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    }
                }
            }
        }
        else
        {
            if (player.detect_close_attack1 == true)
            {
                if (player.detect_close_attack2 == true)
                {
                    if (player.close_at2_timer < 10)
                    {
                        // close_attack2
                        DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 52) * (player.close_at2_timer / 5 % 3), 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    }
                    else
                    {
                        DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 52) * 2, 665, PL_WIDTH + 52, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    }
                }
                else
                {
                    if (player.close_at1_timer < 10)
                    {
                        //close_attack1
                        DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    }
                    else
                    {
                        DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * 2, 332, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    }
                }
            }
            else
            {
                if (player.ef == true)
                {
                    DrawRectGraphF(player.posX - 110, player.posY, (PL_WIDTH + 50) * (player.close_at1_timer / 5 % 3), 996, PL_WIDTH + 50, PL_HEIGHT, GAME::spriteHND, true, false, false);
                    DrawRectGraphF(player.posX - 190, player.posY, 160 * (player.ef_timer / 4 % 5), 0, 160, 350, player.efHND, true, false, false);
                }
                else
                {
                    // wait
                    DrawRectGraphF(player.posX - 60, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, false, false);

                }
            }
        }
    }

    // UI
    DrawRectGraph(0, 0, 2088, 64, player.init_hp, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(0, 0, 2088, 0, player.hp, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(PLAYER::posX, PLAYER::posY, 2088, 168, GAME::spriteHND, true, false, false);
    for (int i = 0; i < player.bullet; i++)
    {
        DrawRectGraph(i * 70, 70, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
    }

    // debug------------------------------------------------------------------------
    //unsigned int  Cr = GetColor(200, 0, 0), Cr2 = GetColor(230, 0, 0), Cr3 = GetColor(0, 0, 230);

    //DrawFormatString(600, 0, Cr, "player.hp:%d", player.hp);
    //DrawFormatString(600, 20, Cr, "player.sub_hp:%d", player.sub_hp);
    //DrawFormatString(600, 40, Cr, "bullet:%d", player.bullet);
    //DrawFormatString(600, 60, Cr, "power:%d", player.power);
    //DrawFormatString(600, 80, Cr, "hit_timer:%d", player.hit_timer);
    //DrawFormatString(600, 100, Cr, "at_timer:%d", player.at_timer);
    //DrawFormatString(600, 120, Cr, "close_at_timer:%d", player.close_at1_timer);
    //DrawFormatString(600, 140, Cr, "detect_attack:%d", player.detect_attack);
    //DrawFormatString(600, 160, Cr, "detect_close_attack1:%d", player.detect_close_attack1);
    //DrawFormatString(600, 180, Cr, "detect_close_attack2:%d", player.detect_close_attack2);
    //DrawFormatString(600, 200, Cr, "nuw_bullet:%d", player.bullet_count);
    //DrawFormatString(600, 220, Cr, "detect_damaged:%d", BOSS::detect_damaged);

    //if (player.detect_reverse == true)
    //{
    //    DrawBox(player.posX + 88, player.posY + 52, player.posX + PL_WIDTH - 83, player.posY + PL_HEIGHT - 31, Cr2, false);
    //    DrawBox(player.posX + 88 - CLOSE_RANGE, player.posY + 52, player.posX + PL_WIDTH - 83 + CLOSE_RANGE, player.posY + PL_HEIGHT - 31, Cr3, false);
    //}
    //else
    //{
    //    DrawBox(player.posX + 24, player.posY + 52, player.posX + PL_WIDTH - 149, player.posY + PL_HEIGHT - 31, Cr2, false);
    //    DrawBox(player.posX + 24 - CLOSE_RANGE, player.posY + 52, player.posX + PL_WIDTH - 149 + CLOSE_RANGE, player.posY + PL_HEIGHT - 31, Cr3, false);
    //}

    for (int i = 0; i < PL_BULLET_MAX; i++)
    {
        if (pl_bullet[i].get_pl_exist(&pl_bullet[i]) == false)
        {
            continue;
        }
        pl_bullet[i].pl_draw(&pl_bullet[i]);
    }

    //---------------------------------------------------------------------------------------------------------
}

// 終了処理
void PLAYER::end(void)
{

}
