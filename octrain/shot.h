#pragma once

#define PL_BULLET_MAX  (256)
#define BOSS_BULLET_MAX  (256)


class BULLET //�e
{
public:
    void init(BULLET* p);       // �����ݒ�
    void pl_update(BULLET* p);  // �X�V����
    void pl_draw(BULLET* p);    // �`�揈��
    void boss_updete(BULLET* p, int pattern_num);
    void boss_draw(BULLET* p, int pattern_num);
    void end(BULLET* p);        // �I������
    void set_pl_exist(BULLET* p, bool b);
    void set_boss_exist(BULLET* p, bool b);
    bool get_pl_exist(BULLET* p);
    bool get_boss_exist(BULLET* p);
    void TurningDirection(BULLET* p, int angle_speed, float posX, float posY);

private:
    int state = 0;
    float posX = 0;
    float posY = 0;
    float speed = 0;
    int range = 0;
    int angle = 0;
    int angle_speed = 0;
    float fsin[360] = { 0 };
    float fcos[360] = { 0 };
    bool pl_exist = false;
    bool boss_exist = false;
};