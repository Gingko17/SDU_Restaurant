#include"SDU_Restaurant_Init.h"
#include<stdio.h>
#include<windows.h>
struct SDU_Restaurant_Data SDU_Restaurant;

int main()
{
	SDU_Restaurant_Console_Init();

	Create_DataBaseFiles();
	printf("\n\n\n\n\n\n\t     ɽ �� �� �� ϵ ͳ �� ӭ �� �� ʹ �� \n\n\n\t       �� �� �� �� �� �� ʼ �� �� �� �� ");
	SDU_Restaurant_Sleep(4000);
	return 0;
}