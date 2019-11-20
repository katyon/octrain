#pragma once
// �萔 ----------------------------------------------------------------
#define BOSS_WIDTH    (168)
#define BOSS_HEIGHT   (248)
#define BOSS_HP (600)

// �N���X --------------------------------------------------------------
class BOSS
{
public:
    static float posX;
    static float posY;
    static bool detect_hit;     // true�œ������Ă�
    static bool detect_deth;    // true�Ŏ��S
    static bool detect_reverse; // true�Ŕ��]

    static void init(void);     // �����ݒ�
    static void update(void);   // �X�V����
    static void draw(void);     // �`�揈��
    static void end(void);      // �I������

private:
    int state = 0;
    int hit_timer = 0;
    int at_timer = 0;
    float pivot_posX = 0;   // boss�̒��S���W
    float pivot_posY = 0;
    float speed = 0;
    int hp = 0;
    int sub_hp = 0;
    bool detect_attack = false;
};