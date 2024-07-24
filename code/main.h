#if !defined(MAIN_H)

#include <intrin.h>
#include <windows.h>

LRESULT CALLBACK win_proc_callback(HWND window,	UINT message, WPARAM wparam, LPARAM lparam);
int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prev_instance, PSTR cmd_line, int nshow_cmd);

#define MAIN_H
#endif