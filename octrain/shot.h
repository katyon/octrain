#pragma once
#include <math.h>

struct BULLET //弾
{
private:
    int bullet_posX;
    int bullet_posY;
    int bullet_subposX;
    int bullet_subposY;
    int bullet_speed;
    int angle;
    int range;
    float fsin[360];
    float fcos[360];
    int bulletHND;

public:
    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理
};