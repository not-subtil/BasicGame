#include "main.h"

void update(HWND window)
{
    HDC handle = GetDC(window);
    ReleaseDC(window, handle);
}

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
    window_class.lpszClassName = "basic game";
    window_class.hCursor = LoadCursorA(0, IDC_ARROW);
    
    if(!RegisterClassA(&window_class))
    { return(0); }

    HWND window = CreateWindowExA(
        0,
    	window_class.lpszClassName,
    	"basic game",
    	WS_OVERLAPPEDWINDOW|WS_VISIBLE,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	CW_USEDEFAULT,
    	0,
    	0,
    	instance,
    	0);

  	if(!window)
  	{ return(0); }
  	
  	MSG message = {};
  	bool is_running = true;
  	while(is_running)
  	{
      	if(GetMessageA(&message, window, 0, 0))
      	{
            TranslateMessage(&message);
            DispatchMessage(&message);
      	}
      	
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
    LRESULT result = 0;
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
		{ break; }
    	default:
		{
			result = DefWindowProcA(window, message, wparam, lparam); 
		}
	}

	return(result);
}

