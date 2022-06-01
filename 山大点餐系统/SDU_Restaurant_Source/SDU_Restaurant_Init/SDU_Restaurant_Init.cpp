#include"SDU_Restaurant_Init.h"
#include<stdio.h>
#include<windows.h>
#include <graphics.h>    
extern struct SDU_Restaurant_Data SDU_Restaurant;

//�����ļ���ʼ��
void Create_DataBaseFiles(void)
{
    /*��ʼ��DataBase_SeatsMap����*/
    int row, col;
    for (row = 0; row < SEATINFO_HEIGHT; row++)
    {
        for (col = 0; col < SEATINFO_WIDTH; col++)
        {

            SDU_Restaurant.seatsMap[row][col].isSelected = 0;
            SDU_Restaurant.seatsMap[row][col].row = row;
            SDU_Restaurant.seatsMap[row][col].col = col;
        }
    }
    Write_SeatMap_Inform((struct Seat*)&SDU_Restaurant.seatsMap);

    /*��ʼ��DataBase_Food����*/
    Write_Food_Inform((struct food*)0, 0);

    /*��ʼ��DataBase_Waiter����*/
    Write_Waiter_Inform((struct Waiter*)0, 0);

    /*��ʼ��DataBase_Customer����*/
    Write_Customer_Inform((struct Customer*)0, 0);

    /*��ʼ��DataBase_Admin����*/
    Write_Admin_Inform("admin", "admin");

    /*��ʼ��DataBase_Date����*/
    Write_Date_Inform((struct Date*)0, 0);

    /*��ʼ��DataBase_VIP����*/
    Write_VIP_Inform((struct VIP*)0, 0);
}
/*����Ʒ������Ϣд���ļ�*/
void Write_Food_Inform(struct food foods[], int num)
{
    FILE* fp;
    errno_t err;
    if ((err = fopen_s(&fp, "DataBase_Food.txt", "wb")) == 0)
    {
        fwrite(&num, sizeof(int), 1, fp);
        fwrite(foods, sizeof(struct food), num, fp);

        fclose(fp);
    }
    else
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*������Ա������Ϣд���ļ�*/
void Write_Waiter_Inform(struct Waiter waiters[], int num)
{
    FILE* fp;
    errno_t err;
    if ((err = fopen_s(&fp, "DataBase_Waiter.txt", "wb")) == 0)
    {
        fwrite(&num, sizeof(int), 1, fp);
        fwrite(waiters, sizeof(struct Waiter), num, fp);
        fclose(fp);
    }
    else
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*���˿�������Ϣд���ļ�*/
void Write_Customer_Inform(struct Customer customer[], int num)
{
    FILE* fp;
    errno_t err;

    if ((err = fopen_s(&fp, "DataBase_Customer.txt", "wb")) == 0)
    {
        fwrite(&num, sizeof(int), 1, fp);
        if (customer != NULL)
            fwrite(customer, sizeof(struct Customer), num, fp);
        else
            fwrite((struct Customer*)0, sizeof(struct Customer), 0, fp);
        fclose(fp);
    }
    else
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*��VIP������Ϣд���ļ�*/
void Write_VIP_Inform(struct VIP vips[], int num)
{
    FILE* fp;
    errno_t err;

    if ((err = fopen_s(&fp, "DataBase_VIP.txt", "wb")) == 0)
    {
        fwrite(&num, sizeof(int), 1, fp);
        if (vips != NULL)
            fwrite(vips, sizeof(struct VIP), num, fp);
        else
            fwrite((struct VIP*)0, sizeof(struct VIP), 0, fp);
        fclose(fp);
    }
    else
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*����������Ϣд���ļ�*/
void Write_Date_Inform(struct Date date[], int num)
{
    FILE* fp;
    errno_t err;
    if ((err = fopen_s(&fp, "DataBase_Date.txt", "wb")) == 0)
    {
        fwrite(&num, sizeof(int), 1, fp);

        fwrite(date, sizeof(struct Date), num, fp);
        fclose(fp);
    }
    else
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*������Ա������Ϣд���ļ���Ŀǰֻ��һλ����Աconst char id[]����δ�����Ա���Ϊstruct Admin admin[]*/
void Write_Admin_Inform(const char id[], const char ps[])
{

    FILE* fp;
    errno_t err;
    if ((err = fopen_s(&fp, "DataBase_Admin.txt", "wb")) == 0)
    {
        fputs(id, fp);
        fputs(" ", fp);
        fputs(ps, fp);
        fclose(fp);
    }
    else
    {
        printf("�� �� �� �� ʧ �ܣ�\n");
        exit(EXIT_FAILURE);
    }
}

/*����λ��Ϣд���ļ�*/
void Write_SeatMap_Inform(struct Seat* pSeatsMap)
{
    FILE* fp;
    errno_t err;
    if ((err = fopen_s(&fp, "DataBase_SeatsMap.txt", "wb")) == 0)
    {
        fwrite(pSeatsMap, sizeof(struct Seat), SEATINFO_HEIGHT * SEATINFO_WIDTH, fp);
        fclose(fp);
    }
    else
    {
        printf("�� �� �� �� ʧ �ܣ�\n");
        exit(EXIT_FAILURE);
    }
}


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
    SetConsoleTitle(TEXT("ɽ �� �� �� ϵ ͳ �� ʼ ��"));
    system("mode con cols=60 lines=35");
    //��ȡ��ǰ���ھ��
    HWND hwnd = GetHWnd();
    //�Ѻ�ɫ�ı�������Ϊ͸��
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 150, LWA_ALPHA);
}