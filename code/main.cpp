#include "main.h"
/*
TODO::
*Terminate executable process successfuly
*Handle user input
*render object {ball, player}

first commit:: 
solid base only simple rendering don't over do stuff
*/
int CALLBACK
WinMain(
    HINSTANCE instance,
    HINSTANCE prev_instance,
    PSTR cmd_line,
    int nshow_cmd)
{
    WNDCLASSA window_class = {};
    window_class.hInstance = instance;
    window_class.lpfnWndProc = win_proc_callback;
    window_class.style = CS_HREDRAW|CS_VREDRAW;
    window_class.lpszClassName = "basic game";
    
    if(!RegisterClassA(&window_class))
    { return(0); }
    
    HWND window = CreateWindowExA(
        0,
        window_class.lpszClassName,
        "C with windows.h",
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        instance,
        NULL);
    
    if(!window)
    { return(0); }
    
    MSG message = {};
    COLORREF color = 0x000000FF;
    while(GetMessageA(&message, window, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
        
        HDC device_context = GetDC(window);
        RECT window_rect = {};
        if(!GetWindowRect(window, &window_rect))
        { /*HANDLE THIS CASE*/ }
        
        int window_width = window_rect.right - window_rect.left;
        int window_height = window_rect.bottom - window_rect.top;
        
        HDC source_device_context = CreateCompatibleDC(device_context);
        
        BITMAPINFO bitmap_info = {};
                
        BITMAPINFOHEADER bitmap_header = {};
        bitmap_header.biSize = sizeof(BITMAPINFOHEADER);
        bitmap_header.biWidth = 100;
        bitmap_header.biHeight = 100;
        bitmap_header.biPlanes = 1;
        bitmap_header.biBitCount = 100;
        bitmap_header.biCompression = BI_RGB;
        bitmap_header.biSizeImage = 0;
        bitmap_header.biXPelsPerMeter = 100;
        bitmap_header.biYPelsPerMeter = 100;
        bitmap_header.biClrUsed = 0;
        bitmap_header.biClrImportant = 0;
        
        byte pixels[100][100];
        bitmap_info.bmiHeader = bitmap_header;
        // bitmap_info.bmiColors = {};
        
        HBITMAP source_bitmap = CreateDIBSection(source_device_context, &bitmap_info, DIB_RGB_COLORS, (void**)pixels, NULL, 0);
        
        BOOL blt_success = BitBlt(device_context, 0, 0, 100, 100, source_device_context, 0, 0, SRCCOPY);
        ReleaseDC(window, device_context);
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
    // TODO:: 
    // check if theres more messages related to application shutdown
    // sometimes the application doesnt quit properly
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
            
            break;
        }
    }
    
    return(DefWindowProcA(window, message, wparam, lparam));
}



// void first_approach_to_render()
// {
//     // NOTE :: this isnt the flavour i like.. i want lower level instructions
//     PAINTSTRUCT ps;
//     RECT client_rectangle = {};
//     GetClientRect(window, &client_rectangle);
//     HDC dc = BeginPaint(window, &ps);
//     ps.rcPaint.left = 0;
//     ps.rcPaint.top = 0;
//     ps.rcPaint.right = client_rectangle.right;
//     ps.rcPaint.right = client_rectangle.bottom;
//     FillRect(dc, &ps.rcPaint, CreateSolidBrush(0x00000000));

//     long window_width = ps.rcPaint.right - ps.rcPaint.left;
//     long window_height = ps.rcPaint.bottom - ps.rcPaint.top;
//     long player_width = window_width * 0.01;
//     long player_height = window_height * 0.16;

//     RECT left_player_pos = {};
//     left_player_pos.left = 50;
//     left_player_pos.top = window_height / 2;
//     left_player_pos.right = left_player_pos.left + player_width;
//     left_player_pos.bottom = left_player_pos.top + player_height;
//     FillRect(dc, &left_player_pos, CreateSolidBrush(0x00FFFFFF));

//     RECT right_player_pos = {};
//     right_player_pos.left = window_width - 50 - player_width;
//     right_player_pos.top = window_height / 2;
//     right_player_pos.right = right_player_pos.left + player_width;
//     right_player_pos.bottom = right_player_pos.top + player_height;
//     FillRect(dc, &right_player_pos, CreateSolidBrush(0x00FFFFFF));

//     RECT ball_pos = {};
//     ball_pos.left = window_width /  2 -  5;
//     ball_pos.top = window_height / 2 - 5;
//     ball_pos.right = ball_pos.left + 10;
//     ball_pos.bottom = ball_pos.top + 10;
//     FillRect(dc, &ball_pos, CreateSolidBrush(0x00FFFFFF));

//     EndPaint(window, &ps);
// }
