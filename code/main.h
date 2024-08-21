#if !defined(MAIN_H)

#include <intrin.h>
#include <windows.h>

struct moving_object
{
    int speed;
    int width;
    int height;
    int left_pos;
    int top_pos;
};

struct game_state
{
    moving_object left_player;
    moving_object right_player;
    moving_object ball;
};

LRESULT CALLBACK win_proc_callback(HWND window,	UINT message, WPARAM wparam, LPARAM lparam);
int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prev_instance, PSTR cmd_line, int nshow_cmd);

#define MAIN_H
#endif