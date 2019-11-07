#pragma once
// ’è” ----------------------------------------------------------------

// ƒNƒ‰ƒX --------------------------------------------------------------
class TITLE
{
public:
    static void init(void);
    static void update(void);
    static void draw(void);
    static void end(void);

private:
    int state = 0;
    int timer = 0;
    int bgHND = 0;

};