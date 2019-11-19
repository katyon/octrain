#include "DxLib.h"
#include <iostream>

#include "common.h"
#include "input.h"
#include "shot.h"

BULLET bullet;

void BULLET::init(void)
{
    bullet.bullet_posX = 0;
    bullet.bullet_posY = 0;
    bullet.angle = 0;
    bullet.range = 0;
    bullet.bullet_speed = 10;
    bullet.bulletHND = LoadGraph("Data\\Images\\shot.png");
    for (int i = 0; i < 360; i++)
    {
        bullet.fsin[i] = (float)sin(i * PI / 180);
        bullet.fcos[i] = (float)cos(i * PI / 180);
    };
}

void BULLET::update(void)
{
    if (CheckHitKey(KEY_INPUT_Z))
    {
        bullet.bullet_posX += bullet.fcos[bullet.angle] * bullet.bullet_speed;
        bullet.bullet_posY += bullet.fsin[bullet.angle] * bullet.bullet_speed;
    }
    if (CheckHitKey(KEY_INPUT_X))
    {
        bullet.angle -= 5;
        bullet.angle = (bullet.angle + 360) % 360;
    }
    if (CheckHitKey(KEY_INPUT_C))
    {
        bullet.angle += 5;
        bullet.angle = (bullet.angle + 360) % 360;
    }


    bullet.bullet_subposX = bullet.bullet_posX + 32 - 1;
    bullet.bullet_subposY = bullet.bullet_posY + 32 - 1;
}

void BULLET::draw(void)
{
    DrawExtendGraph(bullet.bullet_posX, bullet.bullet_posY, bullet.bullet_subposX, bullet.bullet_subposY, bullet.bulletHND, true);
}

void BULLET::end(void)
{
    DeleteGraph(bullet.bulletHND);
}


