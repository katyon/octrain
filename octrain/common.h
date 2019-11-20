#pragma once
// �萔 ----------------------------------------------------------------
#define GAME_SCREEN_WIDTH	(1920)  // �Q�[����ʂ̕�
#define GAME_SCREEN_HEIGHT	(1080)  // �Q�[����ʂ̍���
#define PI          (3.1415926535f) // �~����
#define ROOT2       (1.41421356f)   // ��2
#define ROOT5       (2.2360679f)    // ��5

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