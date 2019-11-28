#include "DxLib.h"

#include "boss.h"
#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"
#include "shot.h"

#include <math.h>

void BULLET::init(BULLET* p)
{
    p->timer = 0;
    p->state = 0;
    p->pl_exist = 0;
    p->boss_exist = 0;
}

void BULLET::pl_update(BULLET* p)
{
    switch (p->state)
    {
    case INIT:
        if (PLAYER::detect_reverse == true)
        {
            p->posX = PLAYER::posX;
            p->posY = PLAYER::posY;
            p->speed = -PL_BULLET_SPEED;

            p->reverse_buf = true;
        }
        else
        {
            p->posX = PLAYER::posX + 160;
            p->posY = PLAYER::posY;
            p->speed = PL_BULLET_SPEED;

            p->reverse_buf = false;
        }
        p->angle = 0;
        p->angle_speed = 5;
        for (int i = 0; i < 360; i++)
        {
            p->fsin[i] = sin(i * PI / 180);
            p->fcos[i] = cos(i * PI / 180);
        }

        p->state = UPDATE;
        break;
    case UPDATE:
        // debug--------------------------------------

        //if (CheckHitKey(KEY_INPUT_Z))
        //{
        //    p->posX += p->fcos[p->angle] * p->speed;
        //    p->posY -= p->fsin[p->angle] * p->speed;
        //}
        //// �����v���
        //if (CheckHitKey(KEY_INPUT_X))
        //{
        //    p->angle -= p->angle_speed;
        //}
        //// ���v���
        //if (CheckHitKey(KEY_INPUT_C))
        //{
        //    p->angle += p->angle_speed;
        //}

        //p->angle = -atan2f(PLAYER::posY - p->posY, PLAYER::posX - p->posX) * 180 / PI + p->angle_speed;

        p->posX += p->fcos[p->angle] * p->speed;
        p->posY -= p->fsin[p->angle] * p->speed;

        //�e����v���C���[�ւ̃x�N�g��(���[���h��̃O���t�A����x�Ł���y�̂�����)
        float world_x = BOSS::posX + BOSS_WIDTH / 2 - p->posX;
        float world_y = BOSS::posY + BOSS_HEIGHT / 2 - p->posY;

        //�e�̐i�s������ver(ver_x��ver_y���琬��x�N�g��)�A����ɒ�������hor(hor_x��hor_y���琬��x�N�g��)
        //ver��x���Ahor��y���Ƃ������W�n�̃O���t�ŕΊp���v�Z����
        float ver_x = cos(p->angle * PI / 180);
        float ver_y = sin(p->angle * PI / 180);
        float hor_x = -ver_y; //������ւ�͕�����+�ɂ�����-�ɂ����肵���瓮����(���m)
        float hor_y = -ver_x; // ��ƈꏏ
        if (p->reverse_buf == true)
        {
            hor_x = ver_y;
            hor_y = ver_x;
        }
        else
        {
            hor_x = -ver_y;
            hor_y = -ver_x;
        }

        //����world��ver�Aworld��hor�̓��ς�����Ă�
        float rel_ver = world_x * ver_x + world_y * ver_y;
        float rel_hor = world_x * hor_x + world_y * hor_y;

        //�e����v���C���[�ւ̃x�N�g��(���W�n�Ŏ�蒼�����O���t�A�e�̐i�s������x�ŁA���s����x�N�g����y)
        float angle_RL = atan2f(rel_hor, rel_ver);

        //angle_RL��0�ȉ��̎��͍�����A0�ȏ�̎��͉E����
        if (angle_RL < 0)
        {
            p->angle -= p->angle_speed;
        }
        else
        {
            p->angle += p->angle_speed;
        }
        //bool judgeTurningDirection(Character Player, Bullet HormingTest)
        //{
        //    //�e����v���C���[�ւ̃x�N�g��(���[���h��̃O���t�A����x�Ł���y�̂�����)
        //    float world_x = Player.x + 64 - HormingTest.cal_x;
        //    float world_y = Player.y + 64 - HormingTest.cal_y;

        //    //�e�̐i�s������ver(ver_x��ver_y���琬��x�N�g��)�A����ɒ�������hor(hor_x��hor_y���琬��x�N�g��)
        //    //ver��x���Ahor��y���Ƃ������W�n�̃O���t�ŕΊp���v�Z����
        //    float ver_x = cos(HormingTest.angle * PI / 180);
        //    float ver_y = sin(HormingTest.angle * PI / 180);
        //    float hor_x = -ver_y; //������ւ�͕�����+�ɂ�����-�ɂ����肵���瓮����(���m)
        //    float hor_y = -ver_x; // ��ƈꏏ

        //    //����world��ver�Aworld��hor�̓��ς�����Ă�
        //    float rel_ver = world_x * ver_x + world_y * ver_y;
        //    float rel_hor = world_x * hor_x + world_y * hor_y;

        //    //�e����v���C���[�ւ̃x�N�g��(���W�n�Ŏ�蒼�����O���t�A�e�̐i�s������x�ŁA���s����x�N�g����y)
        //    float angle_RL = atan2(rel_ver, rel_hor);

        //    //angle_RL��0�ȉ��̎��͍�����A0�ȏ�̎��͉E����
        //    if (angle_RL < 0)
        //    {
        //        return false;
        //    }
        //    else
        //    {
        //        return true;
        //    }
        //}

        p->angle = (p->angle + 360) % 360;
        break;
    }
}

void BULLET::judgeTurningDirection(BULLET* p)
{
    p->posX += p->fcos[p->angle] * p->speed*3;
    p->posY -= p->fsin[p->angle] * p->speed*3;

    //�e����v���C���[�ւ̃x�N�g��(���[���h��̃O���t�A����x�Ł���y�̂�����)
    float world_x = PLAYER::pivot_posX - p->posX;
    float world_y = PLAYER::pivot_posY - p->posY;

    //�e�̐i�s������ver(ver_x��ver_y���琬��x�N�g��)�A����ɒ�������hor(hor_x��hor_y���琬��x�N�g��)
    //ver��x���Ahor��y���Ƃ������W�n�̃O���t�ŕΊp���v�Z����
    float ver_x = cos(p->angle * PI / 180);
    float ver_y = sin(p->angle * PI / 180);
    float hor_x = -ver_y; //������ւ�͕�����+�ɂ�����-�ɂ����肵���瓮����(���m)
    float hor_y = -ver_x; // ��ƈꏏ

    hor_x = -ver_y;
    hor_y = -ver_x;


    //����world��ver�Aworld��hor�̓��ς�����Ă�
    float rel_ver = world_x * ver_x + world_y * ver_y;
    float rel_hor = world_x * hor_x + world_y * hor_y;

    //�e����v���C���[�ւ̃x�N�g��(���W�n�Ŏ�蒼�����O���t�A�e�̐i�s������x�ŁA���s����x�N�g����y)
    float angle_RL = atan2f(rel_hor, rel_ver);

    //angle_RL��0�ȉ��̎��͍�����A0�ȏ�̎��͉E����
    if (angle_RL < 0)
    {
        p->angle -= p->angle_speed;
    }
    else
    {
        p->angle += p->angle_speed;
    }

    p->angle = (p->angle + 360) % 360;
}

void BULLET::pl_draw(BULLET* p)
{
    DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
}

void BULLET::boss_updete(BULLET* p, int pattern_num)
{
    switch (pattern_num)
    {
    case BOSS::PATTERN::N_Diffusion:
        switch (p->state)
        {
        case INIT:
            p->timer = 0;
            p->posX = BOSS::posX + BOSS_WIDTH / 2;
            p->posY = BOSS::posY + BOSS_HEIGHT / 2;
            p->angle = 0;
            p->range = 0;
            p->speed = 5;
            p->angle_speed = 5;
            for (int i = 0; i < 360; i++)
            {
                p->fsin[i] = sin(i * PI / 180);
                p->fcos[i] = cos(i * PI / 180);
            }

            p->state = UPDATE;
            break;
        case UPDATE:
            break;
        }
        break;
    case BOSS::PATTERN::N_Homing:
        switch (p->state)
        {
        case INIT:
            p->timer = 0;
            p->posX = BOSS::posX + BOSS_WIDTH / 2;
            p->posY = BOSS::posY + BOSS_HEIGHT / 2;
            p->angle = 0;
            p->range = 0;
            p->speed = 4;
            p->angle_speed = 2;
            for (int i = 0; i < 360; i++)
            {
                p->fsin[i] = sin(i * PI / 180);
                p->fcos[i] = cos(i * PI / 180);
            }

            p->state = UPDATE;
            break;
        case UPDATE:
            break;
        case BOSS::PATTERN::N_Column:
            break;
        case BOSS::PATTERN::SPK_1:
            break;
        case BOSS::PATTERN::SPK_2:
            break;
        case BOSS::PATTERN::SPK_3:
            break;
        }
    }
}

void BULLET::boss_draw(BULLET* p, int pattern_num)
{
    switch (pattern_num)
    {
    case BOSS::PATTERN::N_Diffusion:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    case BOSS::PATTERN::N_Homing:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    case BOSS::PATTERN::N_Column:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    case BOSS::PATTERN::SPK_1:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    case BOSS::PATTERN::SPK_2:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    case BOSS::PATTERN::SPK_3:
        DrawRectGraphF(p->posX, p->posY, 2088, 188, 64, 64, GAME::spriteHND, true, false, false);
        break;
    }
}

void BULLET::end(BULLET* p)
{

}

int BULLET::get_posX(BULLET* p)
{
    return p->posX;
}

int BULLET::get_posY(BULLET* p)
{
    return p->posY;
}


bool BULLET::get_pl_exist(BULLET* p)
{
    return p->pl_exist;
}

bool BULLET::get_boss_exist(BULLET* p)
{
    return p->boss_exist;
}

void BULLET::set_pl_exist(BULLET* p, bool b)
{
    if (b == false)
    {
        p->state = 0;
    }
    p->pl_exist = b;
}

void BULLET::set_boss_exist(BULLET* p, bool b)
{
    if (b == false)
    {
        p->state = 0;
    }
    p->boss_exist = b;
}