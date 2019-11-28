#pragma once

#include "shot.h"
// �萔 ----------------------------------------------------------------
#define PL_WIDTH    (300)
#define PL_HEIGHT   (332)
#define CLOSE_RANGE (140)

// �N���X --------------------------------------------------------------
class PLAYER
{
public:
    static float posX;
    static float posY;
    static float pivot_posX;
    static float pivot_posY;
    static int hp;
    static bool detect_hit;         // true:�������Ă�
    static bool detect_closerange;  // true:�ߐڔ͈͓�
    static bool detect_deth;        // true:���S
    static bool detect_reverse;     // true:���]

    static void init(void);     // �����ݒ�
    static void update(void);   // �X�V����
    static void draw(void);     // �`�揈��
    static void end(void);      // �I������

private:
    int state = 0;
    int hit_timer = 0;
    int at_timer = 0;
    int close_at1_timer = 0;
    int close_at2_timer = 0;
    float sub_posX = 0;     // player�̉E���̍��W
    float sub_posY = 0;
    float speed = 0;
    int init_hp = 0;
    int sub_hp = 0;
    int init_bullet = 0;
    int bullet = 0;
    int bullet_count = 0;
    int power = 0;
    bool detect_attack = false;         // true:�U����
    bool detect_close_attack1 = false;  // true:�U����
    bool detect_close_attack2 = false;  // true:�U����

    static int guard_timer; //�K�[�h�G�t�F�N�g�p
    static int zangeki_seHND;
    static int shot_seHND;
    static int guard_seHND;
    static int reload_seHND;
};