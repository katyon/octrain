#pragma once
// �萔 ----------------------------------------------------------------
#define GAME_SCREEN_WIDTH	(1920)  // �Q�[����ʂ̕�
#define GAME_SCREEN_HEIGHT	(1080)  // �Q�[����ʂ̍���
#define PI          (3.1415926535)  // �~����
#define CHIP_SIZE           (64)    // �}�b�v�`�b�v�̈������̑傫��

enum SCENE_CASE
{
    SCENE_TITLE, SCENE_GAME, SCENE_RESULT
};

enum STATE
{
    INIT, UPDATE, NEXT, POSE
};

enum PL_NUM
{
    PL_1, PL_2
};

class COMMON
{
public:
    static int curScene;
    static int nextScene;
    int font;

private:

};