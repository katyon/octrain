#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class TITLE
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// �v���g�^�C�v�錾 -----------------------------------------------------
void title_init(void);      // �����ݒ�
void title_update(void);    // �X�V����
void title_draw(void);      // �`�揈��
void title_end(void);       // �I������