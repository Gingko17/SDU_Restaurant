#include "SDU_Restaurant_Core.h"
#include "SDU_Restaurant_IO.h"
#include "SDU_Restaurant_UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SDU_Restaurant_Data SDU_Restaurant;
bool EXIT;

int main(int argc, char const* argv[])
{
    /*�����ļ���ȡ��ȫ�ֱ�����ʼ��*/
    SDU_Restaurant_Init(argc, argv);

    while (1)
    {
        EXIT = false;
        
        /*�û�ѡ�����(����ԱOR����Ա)*/
        enum class UserType userType = SDU_Restaurant_Welcome();

        /*����Ա*/
        if (userType == UserType::admin)
        {
            while (1)
            {
                if (EXIT == true)
                    break;
                int choice = Admin_Menu();
                switch (choice)
                {
                case 1: //�鿴��λ��Ϣ.
                    Admin_Seat_Infom();
                    break;
                case 2: //�鿴Ӫҵ�ܶ�
                    Admin_Daily_Profit();
                    break;
                case 3: //���Ĳ�Ʒ��Ϣ
                    Admin_Food_Change();
                    break;
                case 4: //���ķ���Ա��Ϣ
                    Admin_Waiter_Change();
                    break;
                case 5://����VIP��Ϣ
                    Admin_VIP_Change();
                    break;
                case 6: //�޸Ĺ���Ա����
                    Admin_Passwd_Change();
                    break;
                case 7:  //��Ʒ��������.
                    Admin_Statistics_Analysis();
                    break;
                case 8: //����Ա�˺ŵǳ�
                    EXIT = 1;
                    break;
                case 0: //�˳�����
                    Show_Exit_Program();
                    break;
                }
            }
        }

        /*����Ա*/
        else if (userType == UserType::waiter)
        {
            while (1)
            {
                if (EXIT == true)
                    break;
                int choice = Waiter_Menu();
                switch (choice)
                {
                case 1: //ѡ����λ
                    Waiter_Seat_Select();
                    break;
                case 2: //չʾ�˵�
                    Waiter_Food_Show();
                    break;
                case 3: //�Ǽǵ��
                    Waiter_Food_Order();
                    break;
                case 4: //�����˵�
                    Waiter_Food_Check();
                    break;
                case 5: //ȡ������Ԥ��
                    Waiter_Seat_Cancel();
                    break;
                case 6: //�޸ķ���Ա����
                    Waiter_Passwd_Change();
                    break;
                case 7: //����Ա�˺ŵǳ�
                    EXIT = 1;
                    break;
                case 0: //�˳�����
                    Show_Exit_Program();
                    break;
                }
            }
        }
    }
    return 0;
}
