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
    int  isDiscount=0;
};

/*ɽ�����ϵͳ֮�û�����*/
enum class UserType
{
    undefine, //δ��¼
    waiter,   //����Ա
    admin     //����Ա
};

/*ɽ�����ϵͳ֮��λ*/
struct Seat
{
    int isSeated;   //��λ�Ƿ�ռ��
    int isSelected; //��λ�Ƿ�Ԥ��
    int row;        //��λ�к�
    int col;        //��λ�к�
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

/*ɽ�����ϵͳ֮��Ʒ����*/
struct node_v
{
    struct VIP data;
    struct node_v* next;
};
typedef struct node_v NODE_V;


/*ɽ�����ϵͳ֮��Ʒ����*/
struct node_f
{
    struct food data;
    struct node_f* next;
};
typedef struct node_f NODE_F;

/*ɽ�����ϵͳ֮����Ա����*/
struct node_w
{
    struct Waiter data;
    struct node_w* next;
};
typedef struct node_w NODE_W;

/*ɽ�����ϵͳ֮�˿�����*/
struct node_c
{
    struct Customer data;
    struct node_c* next;
};
typedef struct node_c NODE_C;

/*ɽ�����ϵͳ֮��Ʒ����*/
struct node_d
{
    struct Date data;
    struct node_d* next;
};

typedef struct node_d NODE_D;
/*ɽ�����ϵͳ֮��������*/
struct SDU_Restaurant_Data
{
    /*����ӯ��*/
    double Day_Profit = 0;//��������
    NODE_D* current_date; //ָ�����ڵĽṹ������ռ��ָ��
    int dateCount;//������������

    /*����Ա*/
    struct Waiter* waiter_Login; //Ŀǰ��¼�ķ���Ա
    NODE_W* current_waiters;     //ָ�����Ա�Ľṹ������ռ��ָ��
    int waitersCount;            //���з���Ա����

    /*�˿�*/
    NODE_C* current_customer; //ָ��˿͵Ľṹ������ռ��ָ��
    int customerCount;        //���й˿�����
    
    /*��Ʒ*/
    NODE_F* current_foods; //ָ���Ʒ�Ľṹ������ռ��ָ��
    int foodsCount;        //���в�Ʒ����

    /*����Ա*/
    char Admin_password[ADMINPAS_LENGTH_MAX + 1] = { 0 };    //ϵͳ����Ա����

    /*��λ*/
    struct Seat seatsMap[SEATINFO_HEIGHT][SEATINFO_WIDTH]; //������λͼ��Ϣ

    /*�û�*/
    UserType user;

    /*VIP*/
    NODE_V* current_vip; //ָ��VIP�Ľṹ������ռ��ָ��
    int vipsCount;        //����VIP����
};


/*�����������֡���*/

/*����*/
void Save_Date_Inform(void); //��������Ϣ������ת��Ϊ����洢���ļ�

NODE_D* Load_Profit_Inform(struct Date* dates, int num);//���������ݴ�����¼������

NODE_D* Add_To_Tail(NODE_D* pHead_d, struct Date Data);//������������ӵ���������β��

NODE_D* Add_To_Head(NODE_D* pHead_d, struct Date data);//������������ӵ���������ͷ��


/*��λ*/
void Leave_Seat(int num); //�����˺��Զ�ȡ��ռ�����

void printSeatsMap(void); //��ӡ��ǰ��������λ��Ϣͼ

void Clear_Seat_Inform(void); //���������λ��Ϣ


/*����Ա*/
void Print_Daily_Profit(NODE_D* pHead_d); //��ӡÿ��Ӫҵ��


/*��Ʒ*/
NODE_F* Add_To_Tail(NODE_F* pHead_f, struct food data); //����Ʒ������ӵ���Ʒ����β��

NODE_F* Add_To_Head(NODE_F* pHead_f, struct food data); //����Ʒ������ӵ���Ʒ����ͷ��

void Order_By_ID(NODE_F* pHead_f); //��ID��1��ʼ��������

NODE_F* SDU_Delete_Food(NODE_F* pHead_f, int id); //�������ֵ,ɾ����Ӧ�Ĳ�Ʒ����

NODE_F* Load_Food_Inform(struct food* foods, int num); //����Ʒ���ݴ�����¼������

int Add_Food_To_Order(int foodID, struct Order* order,double discount); //�Ѳ�Ʒ������ӵ�����

int Delet_Food_From_Order(int foodID, struct Order* order,double discount);//�ѴӶ�����ɾ���Ѷ���Ʒ����

void Save_Food_Inform(void); //����Ʒ��Ϣ������ת��Ϊ����洢���ļ�

void Print_LinkTable(NODE_F* pHead_f); //��ӡ��Ʒ����
void Show_LinkTable(NODE_F* pHead_f);

void SDU_Add_Food(NODE_F* pHead_f, struct food& newFood); //��������Ʒ��ӵ���Ʒ����

void SDU_Add_Date(NODE_D* pHead_d, struct Date& newDate); //��������Ʒ��ӵ���Ʒ����


/*����Ա*/
NODE_W* Add_To_Tail(NODE_W* pHead_w, struct Waiter data); //������Ա������ӵ�����Ա����β��

NODE_W* Add_To_Head(NODE_W* pHead_w, struct Waiter data); //������Ա������ӵ�����Ա����ͷ��

void Order_By_ID(NODE_W* pHead_w); //��ID�ӵ����������Ա

NODE_W* SDU_Delete_Waiter(NODE_W* pHead_w, char* id); //���ݹ���,ɾ����Ӧ�ķ���Ա����

NODE_W* Load_Waiter_Inform(struct Waiter* waiters, int num); //������Ա���ݴ�����¼������

void Save_Waiter_Inform(void); //������Ա��Ϣ������ת��Ϊ����洢���ļ�

void Print_LinkTable(NODE_W* pHead_w); //��ӡ����Ա����

void SDU_Add_Waiter(NODE_W* pHead_w, struct Waiter& newWaiter); //����������Ա��ӵ�����Ա����


/*�˿�*/
NODE_C* Add_To_Tail(NODE_C* pHead_c, struct Customer data); //���˿�������ӵ��˿�����β��

NODE_C* Order_By_Seatnum(NODE_C* pHead_c); //�����Ŵӵ�������

NODE_C* Order_Merge_Sort_By_Seatnum(NODE_C* head1, NODE_C* head2); //�鲢����

NODE_C* SDU_Delete_Customer(NODE_C* pHead_c, int seatnum); //��������ֵ,ɾ����Ӧ�Ĺ˿�����

NODE_C* Load_Customer_Inform(struct Customer* customer, int num); //���˿����ݴ�����¼������

void Save_Customer_Inform(void); //���˿���Ϣ������ת��Ϊ����洢���ļ�

void SDU_Add_Customer(NODE_C* pHead_c, struct Customer& newcustomer); //�������˿���ӵ��˿�����

/*VIP*/
NODE_V* Load_VIP_Inform(struct VIP* vips, int num);

NODE_V* Add_To_Tail(NODE_V* pHead_v, struct VIP data); //��VIP������ӵ�VIP����β��

NODE_V* Order_By_Cardnum(NODE_V* pHead_v); //�����Ŵӵ�������

NODE_V* Order_Merge_Sort_By_Cardnum(NODE_V* head1, NODE_V* head2); //�鲢����

NODE_V* SDU_Delete_VIP(NODE_V* pHead_v, int cardnum); //���ݿ���,ɾ����Ӧ��VIP����

void Save_VIP_Inform(void); //��VIP��Ϣ������ת��Ϊ����洢���ļ�

void Print_LinkTable(NODE_V* pHead_v); //��ӡVIP����

void SDU_Add_VIP(NODE_V* pHead_v, struct VIP& newVIP); //����������Ա��ӵ�VIP����

int Judge_VIP(long long int phonenum);//����Ƿ���VIP

/*������*/
void SDU_Restaurant_Sleep(unsigned long Milliseconds); //����������ָͣ������ʱ��

void Assert_Program(void* ptr); //������ռ�����򱨴���������

void SDU_Restaurant_Init(int argc, char const* argv[]); //�����ļ���ʼ���������ļ���ȡ��ȫ�ֱ�����ʼ��

void SDU_Restaurant_Console_Init(void); //��ʼ������̨����


/*δ����*/

//�����û����趨ָ���û����˻����
void setUserMoneyFromUsersHistory(char userNick[], int Money);

//��ӡǰn�����ܻ�ӭ��ʳ��
void printPopularFood(int maxOutNum);

//��ӡǰn������Ǯ���û�?
void printRichUser(int maxOutNum);
