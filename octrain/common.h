#pragma once
// 定数 ----------------------------------------------------------------
#define GAME_SCREEN_WIDTH	(1920)  // ゲーム画面の幅
#define GAME_SCREEN_HEIGHT	(1080)  // ゲーム画面の高さ
#define PI          (3.1415926535)  // 円周率
#define CHIP_SIZE           (64)    // マップチップの一つ当たりの大きさ

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