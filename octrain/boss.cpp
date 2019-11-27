// ÉCÉìÉNÉãÅ[Éh -------------------------------------------------------------------------------------
#include "DxLib.h"

#include <math.h>

#include "boss.h"
#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// ÉCÉìÉXÉ^ÉìÉXêÈåæ ---------------------------------------------------------------------------------
BOSS boss;

// debug---------------
int rad = 0;
int rad01 = 0;
int rad02 = 0;
int rad03 = 0;

int effect_HND = 0;
int zangeki_HND = 0;

char key_buf[256];

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
// ä÷êîé¿ëÃ ----------------------------------------------------------------------------------------
// èâä˙ê›íË
void BOSS::init(void)
{
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
    boss.N_attack = 0;
    boss.SPK_attack = 0;
    boss.rnd_move_pattern = 0;
    boss.detect_hit = false;
    boss.detect_deth = false;
    boss.detect_attack = false;
    boss.detect_reverse = false;
    boss.detect_damaged = false;
    boss.detect_close_damaged = false;
    boss.detect_useSPK = false;

    effect_HND = LoadGraph("Data\\Images\\zangeki.png");

}

// çXêVèàóù
void BOSS::update(void)
{
    // debug------------------------
#pragma region RightThumb
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Up))
    {
        boss.posY -= boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Right))
    {
        boss.posX += boss.speed / ROOT5;
        boss.posY -= boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Right))
    {
        boss.posX += boss.speed / ROOT2;
        boss.posY -= boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Right))
    {
        boss.posX += boss.speed / ROOT5 * 2;
        boss.posY -= boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Right))
    {
        boss.posX += boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Right))
    {
        boss.posX += boss.speed / ROOT5 * 2;
        boss.posY += boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Right))
    {
        boss.posX += boss.speed / ROOT2;
        boss.posY += boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Right))
    {
        boss.posX += boss.speed / ROOT5;
        boss.posY += boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Down))
    {
        boss.posY += boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT5;
        boss.posY += boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Left))
    {
        boss.posX -= boss.speed / ROOT2;
        boss.posY += boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT5 * 2;
        boss.posY += boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Left))
    {
        boss.posX -= boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT5 * 2;
        boss.posY -= boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Left))
    {
        boss.posX -= boss.speed / ROOT2;
        boss.posY -= boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT5;
        boss.posY -= boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Up))
    {
        boss.posY -= boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Right))
    {
        boss.posX += boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Down))
    {
        boss.posY += boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Left))
    {
        boss.posX -= boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Right))
    {
        boss.posX += boss.speed / ROOT2 / 3;
        boss.posY -= boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Right))
    {
        boss.posX += boss.speed / ROOT2 / 3;
        boss.posY += boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT2 / 3;
        boss.posY += boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT2 / 3;
        boss.posY -= boss.speed / ROOT2 / 3;
    }
#pragma endregion

    flashing_timer++;
    flash = sinf(flashing_timer);

    // key-----
    char key[256] = { 0 };
    char key_trg[256] = { 0 };

    GetHitKeyStateAll(key);

    for (int n = 0; n < 256; n++)
    {
        if (key[n] && !(key_buf[n]))key_trg[n] = key[n];
        key_buf[n] = key[n];
    }
    // key_end-------
    switch (GAME::state)
    {
    case TITLE:
#pragma region TITLE
        // âìãóó£çUåÇ
        if (key_trg[KEY_INPUT_X])
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
        // ãﬂãóó£çUåÇ
        if (key_trg[KEY_INPUT_Z])
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


            // à⁄ìÆêßå¿
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
        // âìãóó£çUåÇ
        if (key_trg[KEY_INPUT_X])
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
        // ãﬂãóó£çUåÇ
        if (key_trg[KEY_INPUT_Z])
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

        if (boss.detect_attack == true)
        {
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
                    break;
                case N_Homing:
                    break;
                case N_Column:
                    break;
                }

                // à⁄ìÆêßå¿
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
        }
        else
        {
            // move
            switch (boss.rnd_move_pattern)
            {
            case 0:
                // ê⁄ãﬂ
                if (boss.move_timer > 200)
                {
                    if (boss.posX < PLAYER::posX - 100)
                    {
                        boss.posX += 5;
                    }
                    else if (boss.posX > PLAYER::posX + 100)
                    {
                        boss.posX -= 5;
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
                        boss.rnd_move_pattern = 1;
                    }
                }
                break;
            case 1:
                // ó£íE
                if (boss.move_timer > 200)
                {
                    if (boss.posX > PLAYER::posX - 100)
                    {
                        boss.posX += 5;
                    }
                    else if (boss.posX < PLAYER::posX + 100)
                    {
                        boss.posX -= 5;
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
                    }
                    if (boss.move_timer > 500)
                    {
                        boss.move_timer = 0;
                        boss.rnd_move_pattern = 0;
                    }
                }
                break;
            case 2:
                break;
            }
            boss.move_timer++;
            // à⁄ìÆêßå¿
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
#pragma endregion
        break;
    }
}


// ï`âÊèàóù
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

    //Mg_debug(hit effect)-------------
    flashing_timer++;
    flash = sinf(flashing_timer * 0.175) - 0.1;

    if (boss.detect_close_damaged == true)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
        DrawRotaGraph3(boss.posX + BOSS_WIDTH / 2, boss.posY + BOSS_HEIGHT / 2, 100, 25, 5, flash, rad, effect_HND, TRUE);
        //DrawRotaGraph3(boss.posX + BOSS_WIDTH / 2, boss.posY + BOSS_HEIGHT / 2, 100, 25, 3, flash, rad + 50, effect_HND, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

    }

    if (boss.detect_damaged == true)
    {
        unsigned int  Cr = GetColor(255, 255, 255);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawCircle(boss.posX + 5, boss.posY + rad, flash * 45, Cr, TRUE);
        DrawCircle(boss.posX + 40, boss.posY + rad01, flash * 35, Cr, TRUE);
        DrawCircle(boss.posX + 90, boss.posY + rad02, flash * 60, Cr, TRUE);
        DrawCircle(boss.posX + 140, boss.posY + rad03, flash * 25, Cr, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    }

    //----------------------

    DrawRectGraph(GAME_SCREEN_WIDTH / 2, 0, 2088, 64, BOSS_HP, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(GAME_SCREEN_WIDTH / 2 + BOSS_HP - boss.hp, 0, 2088, 0, boss.hp, 64, GAME::spriteHND, true, false, false);
    //debug-----
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(200, 60, Cr, "boss.detect_damaged:%d", boss.detect_damaged);
    DrawFormatString(200, 80, Cr, "boss.detect_close_damaged:%d", boss.detect_close_damaged);

    DrawBox(boss.posX, boss.posY, boss.posX + BOSS_WIDTH, boss.posY + BOSS_HEIGHT, GetColor(0, 200, 0), false);
    //--------
}

// èIóπèàóù
void BOSS::end(void)
{
    DeleteGraph(effect_HND);
}

