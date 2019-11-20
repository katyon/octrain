#pragma once
// �萔 ----------------------------------------------------------------
#define PL_WIDTH    (240)
#define PL_HEIGHT   (332)

// �N���X --------------------------------------------------------------
class PLAYER
{
public:
    static float posX;
    static float posY;
    static int hp;
    static bool detect_hit; // true�œ������Ă�
    static bool detect_deth; // true�Ŏ��S

    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������

private:
    int state = 0;
    int hit_timer = 0;
    int at_timer = 0;
    float sub_posX = 0; // player�̉E���̍��W
    float sub_posY = 0;
    float pivot_posX = 0; // player�̒��S���W
    float pivot_posY = 0;
    float speed = 0;
    int init_hp = 0;
    int sub_hp = 0;
    int init_bullet = 0;
    int bullet = 0;
    int power = 0;
    bool detect_attack = false;
};