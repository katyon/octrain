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
    static int hp;
    static bool detect_hit;     // true�œ������Ă�
    static bool detect_deth;    // true�Ŏ��S
    static bool detect_reverse; // true�Ŕ��]
    static bool detect_damaged;
    static bool detect_close_damaged;

    static void init(void);     // �����ݒ�
    static void update(void);   // �X�V����
    static void draw(void);     // �`�揈��
    static void end(void);      // �I������

    enum PATTERN
    {
        N_Diffusion, N_Homing, N_Column,
        SPK_1, SPK_2, SPK_3
    };

private:
    int state = 0;
    int hit_timer = 0;
    int damaged_timer = 0;
    int close_damaged_timer = 0;
    int at_timer = 0;
    int move_timer = 0;
    float pivot_posX = 0;   // boss�̒��S���W
    float pivot_posY = 0;
    float speed = 0;
    int sub_hp = 0;
    int N_attack = 0;
    int SPK_attack = 0;
    int rnd_move_pattern = 0;
    bool detect_attack = false;
    bool detect_useSPK = false;
};