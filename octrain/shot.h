#pragma once

#define PL_BULLET_MAX   (50)
#define PL_BULLET_SPEED (20)
#define BOSS_BULLET_MAX (256)


class BULLET //弾
{
public:
    float posX = 0;
    float posY = 0;
    float speed = 0;
    int timer = 0;
    int angle = 0;

    void init(BULLET* p);       // 初期設定
    void pl_update(BULLET* p);  // 更新処理
    void pl_draw(BULLET* p);    // 描画処理
    void boss_updete(BULLET* p, int pattern_num);
    void boss_draw(BULLET* p, int pattern_num);
    void end(BULLET* p);        // 終了処理
    int get_posX(BULLET* p);
    int get_posY(BULLET* p);
    bool get_pl_exist(BULLET* p);
    bool get_boss_exist(BULLET* p);
    void set_pl_exist(BULLET* p, bool b);
    void set_boss_exist(BULLET* p, bool b);
    void judgeTurningDirection(BULLET* p);

private:
    int state = 0;
    int range = 0;
    int angle_speed = 0;
    float fsin[360] = { 0 };
    float fcos[360] = { 0 };
    bool pl_exist = false;
    bool boss_exist = false;
    bool reverse_buf = false;

};