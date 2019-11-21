#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_game.h"
#include "shot.h"

#include <math.h>

//void BULLET::init(BULLET *p)
//{
//    bullet.posX = 0;
//    bullet.posY = 0;
//    bullet.angle = 0;
//    bullet.range = 0;
//    bullet.speed = 10;
//    for (int i = 0; i < 360; i++)
//    {
//        bullet.fsin[i] = sin(i * PI / 180);
//        bullet.fcos[i] = cos(i * PI / 180);
//    };
//}
//
//void BULLET::update(BULLET* p)
//{
//
//    if (CheckHitKey(KEY_INPUT_Z))
//    {
//        bullet.posX += bullet.fcos[bullet.angle] * bullet.speed;
//        bullet.posY += bullet.fsin[bullet.angle] * bullet.speed;
//    }
//    // ”½ŽžŒv‰ñ‚è
//    if (CheckHitKey(KEY_INPUT_X))
//    {
//        bullet.angle -= 5;
//        bullet.angle = (bullet.angle + 360) % 360;
//    }
//    // ŽžŒv‰ñ‚è
//    if (CheckHitKey(KEY_INPUT_C))
//    {
//        bullet.angle += 5;
//        bullet.angle = (bullet.angle + 360) % 360;
//    }
//}
//
//void BULLET::draw(BULLET* p)
//{
//    DrawRectGraphF(bullet.posX, bullet.posY, 960, 0, 66, 66, GAME::spriteHND, true, false, false);
//}
//
//void BULLET::end(BULLET* p)
//{
//
//}