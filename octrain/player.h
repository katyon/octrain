#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class PLAYER
{
public:
    int state = 0;
    int timer = 0;
    int pl_posX = 0;
    int pl_posY = 0;
    int pl_speed = 0;
    int plHND = 0;
};

// �v���g�^�C�v�錾 -----------------------------------------------------
void player_init(void);      // �����ݒ�
void player_update(void);    // �X�V����
void player_draw(void);      // �`�揈��
void player_end(void);       // �I������