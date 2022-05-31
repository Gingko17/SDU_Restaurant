#pragma once

/*�����궨�岿�֡���*/

#define EMPTY_ADDRESS "EMPTY_ADDRESS"//�Ƿ�ͼƬ_��ʶ

#define GRAPHIC_LENGTH_MAX 50 //ͼƬ��ַ_��󳤶�

#define USERNICK_LENGTH_MAX 30 //�û��ǳ�_��󳤶�

#define FOODNAME_LENGTH_MAX 30 //ʳ������_��󳤶�

#define ADMINID_LENGTH_MAX 30  //����Ա����_��󳤶�

#define ADMINPAS_LENGTH_MAX 30 //����Ա����_��󳤶�

#define USRID_LENGTH_MAX 30 //����Ա����_��󳤶�

#define USRPAS_LENGTH_MAX 30 //����Ա����_��󳤶�

#define WAITERID_LENGTH_MAX 30 //����Ա����_��󳤶�

#define WAITERPAS_LENGTH_MAX 30 //����Ա����_��󳤶�

#define WAITERNICK_LENGTH_MAX 30 //����Ա����_��󳤶�

#define ORDERFOODS_LENGTH_MAX 30 //������Ʒ��Ŀ_��󳤶�

#define SEATINFO_HEIGHT 7 //��λ����_����

#define SEATINFO_WIDTH 9 //��λ����_����


/*�����ṹ�岿�֡���*/

/*ɽ�����ϵͳ֮����*/
struct Date
{
    int year;
    int month;
    int day;
    int orderCount;
    double profit;
};

/*ɽ�����ϵͳ֮��Ʒ*/
struct food
{
    int id;                           //��Ʒ���
    char name[FOODNAME_LENGTH_MAX];   //��Ʒ����
    double price;                     //��Ʒ�۸�
    int orderCount;                   //��Ʒ����
    char address[GRAPHIC_LENGTH_MAX]; //��ƷͼƬ
};

/*ɽ�����ϵͳ֮����Ա*/
struct Waiter
{
    int NO;
    double profit;                             //����Աӯ��
    char id[WAITERID_LENGTH_MAX];            //����ԱID
    char waiterNick[WAITERNICK_LENGTH_MAX];  //����Ա�ǳ�
    char passwd[ADMINPAS_LENGTH_MAX];        //����Ա����
    char waiter_address[GRAPHIC_LENGTH_MAX]; //����ԱͼƬ��ַ
};

/*ɽ�����ϵͳ֮����*/
struct Order
{
    int foodCount; //��ǰ������ʳ����
    struct food foods[ORDERFOODS_LENGTH_MAX];
    double ExpensesToBePaid; //��ǰ����Ӧ������
    int  isDiscount = 0;
};
/*ɽ�����ϵͳ֮��λ*/
struct Seat
{
    int isSeated;   //��λ�Ƿ�ռ��
    int isSelected; //��λ�Ƿ�Ԥ��
    int row;        //��λ�к�
    int col;        //��λ�к�
};

/*ɽ�����ϵͳ֮��������*/
struct SDU_Restaurant_Data
{
    /*��λ*/
    struct Seat seatsMap[SEATINFO_HEIGHT][SEATINFO_WIDTH]; //������λͼ��Ϣ
};
/*ɽ�����ϵͳ֮�˿�*/
struct Customer
{
    int Seatnum;                      //����
    struct Order order;               //����
    char address[GRAPHIC_LENGTH_MAX]; //Ŀ���ǽ�TXT�ļ��ı����ʽ��UTF-8ת��ΪANSI����Ȼ�ᵼ�±������
};

/*ɽ�����ϵͳ֮VIP*/
struct VIP
{
    int cardnum;
    long long int phonenum;
};


void Create_DataBaseFiles(void);

void Write_SeatMap_Inform(struct Seat* pSeatsMap); //����λͼ��Ϣд���ļ�

void Write_Food_Inform(struct food foods[], int num); //����Ʒ��Ϣд���ļ�

void Write_Waiter_Inform(struct Waiter waiters[], int num); //������Ա��Ϣд���ļ�

void Write_Admin_Inform(const char id[], const char ps[]); //������Ա��Ϣд���ļ�

void Write_Customer_Inform(struct Customer customer[], int num); //���˿���Ϣд���ļ�

void Write_VIP_Inform(struct VIP vips[], int num); //���˿���Ϣд���ļ�

void Write_Date_Inform(struct Date dates[], int num); //����������Ϣд���ļ�

void SDU_Restaurant_Sleep(unsigned long Milliseconds); //����������ָͣ������ʱ��

void SDU_Restaurant_Console_Init(void);
