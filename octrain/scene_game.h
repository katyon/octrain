#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class GAME
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// �v���g�^�C�v�錾 -----------------------------------------------------
void game_init(void);      // �����ݒ�
void game_update(void);    // �X�V����
void game_draw(void);      // �`�揈��
void game_end(void);       // �I������