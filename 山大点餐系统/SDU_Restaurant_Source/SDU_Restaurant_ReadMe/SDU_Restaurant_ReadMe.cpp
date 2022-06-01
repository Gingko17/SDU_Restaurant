#include"SDU_Restaurant_ReadMe.h"
#include<stdio.h>
#include<windows.h>
#include <graphics.h>    
/*������ͣ*/
void SDU_Restaurant_Sleep(unsigned long dwMilliseconds)
{
    Sleep((DWORD)dwMilliseconds); //��<window.h>�� typedef unsigned long DWORD
}

/*��ʼ������̨����������С*/
VOID ChangeConsoleForntsAndSize(VOID)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"����");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

/*���ع��*/
VOID HideConsoleCursor(VOID)
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

/*����ն˿��*/
LONG GetWindowWidth(HWND hwnd)
{
    RECT rect;
    GetWindowRect(hwnd, &rect);
    return (rect.right - rect.left);
}

/*����ն˸߶�*/
LONG GetWindowHeight(HWND hwnd)
{
    RECT rect;
    GetWindowRect(hwnd, &rect);
    return (rect.bottom - rect.top);
}

/*��ʼ������̨����*/
void SDU_Restaurant_Console_Init(void)
{
    // HideConsoleCursor();//���ع��
    ChangeConsoleForntsAndSize(); //�ı�����������С
    int nWidth = GetWindowWidth(GetConsoleWindow());
    int nHeight = GetWindowHeight(GetConsoleWindow());
    MoveWindow(GetConsoleWindow(), 520, 100, nWidth, nHeight, TRUE);
    SetConsoleTitle(TEXT("ɽ �� �� �� ϵ ͳ ˵ �� ��"));
    system("mode con cols=60 lines=35");
    //��ȡ��ǰ���ھ��
    HWND hwnd = GetHWnd();
    //�Ѻ�ɫ�ı�������Ϊ͸��
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 150, LWA_ALPHA);
}