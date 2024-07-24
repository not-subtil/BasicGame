#include "main.h"

int CALLBACK
WinMain(
    HINSTANCE instance, 
	HINSTANCE prev_instance,
	PSTR cmd_line, 
	int nshow_cmd)
{
    WNDCLASSA window_class = {};
	window_class.style = CS_HREDRAW|CS_VREDRAW;
	window_class.lpfnWndProc = win_proc_callback;
	window_class.hInstance = instance;
    window_class.lpszClassName = "basic_game_window_class";
    window_class.hCursor = LoadCursorA(0, IDC_ARROW);
    
    if(!RegisterClassA(&window_class))
    {
        return(0);
    }
    HWND window_instance = CreateWindowExA(
        0, //WS_EX_TOPMOST|WS_EX_LAYERED,
    	window_class.lpszClassName,
    	"Basic Game",
    	WS_OVERLAPPEDWINDOW|WS_VISIBLE,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	0,
    	0,
    	instance,
    	0);
    // check PatBlt and DrawBitmap
  	if(!window_instance)
  	{
        return(0);
  	}
  	
    return(0);
}

LRESULT CALLBACK 
win_proc_callback(
    HWND window,
	UINT message,
	WPARAM wparam,
	LPARAM lparam)
{
    LRESULT Result = 0;
	switch(message) 
	{
    	case WM_DESTROY:
		{ 
		  PostQuitMessage(0);
		  break; 
		}
    	case WM_SETCURSOR:
		{ break; }
    	case WM_SYSKEYDOWN:
    	case WM_SYSKEYUP:
    	case WM_KEYDOWN:
    	case WM_KEYUP: 
		{ break; }
    	case WM_PAINT:
		{
		  LPMONITORINFO monitor_info = {};
		  monitor_info.cbSize = size_of(LPMONITORINFO);
		  if (!GetMonitorInfoA(, monitor_info))
		  { return(0); }
		  
		  LPPAINTSTRUCT paint = {};
          paint->hdc = GetDC(window);
          paint->fErase = 1;
          paint->rcPaint = monitor_info.rcMonitor;
		  
          HDC paint_result = BeginPaint(window, paint);
		  break; 
		}
    	default:
		{
			result = DefWindowProcA(window, message, wparam, lparam); 
		}
	}

	return(result);
}

