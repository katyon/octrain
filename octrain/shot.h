#pragma once
#include <math.h>

struct BULLET //�e
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
    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������
};