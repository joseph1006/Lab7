#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{//student結構
	char name[6];//名稱
	int chinese,english,math;//國英數成績
	int sum;//總和
	float avg;//平均(=sum/3)
} student;

void main()
{
	student data[5];//宣告5筆student
	FILE *st1, *st2;//兩個檔案
	int i;

	fopen_s(&st1,"c://gradedata.txt", "r");//開啟檔案gradedata.txt(讀)
	fopen_s(&st2,"c://gradeoutput.txt", "w");//開啟檔案gradeoutput.txt(寫)

	if (st1 == NULL || st2 == NULL)
	{//任一檔案不存在
		printf("檔案開啟失敗\n");
	}
	else
	{//都存在的情況下
		fprintf(st2, "姓名\t國文\t英文\t數學\t總合\t平均\n");//在檔案st2中印出字串
		for (i = 0; i < 5; i++)
		{//跑5筆資料
			fscanf_s(st1, "%s", data[i].name,6);//從檔案st1中讀入 名稱 長度6
			fscanf_s(st1, "%d", &data[i].chinese);//從檔案st1中讀入 國文成績
			fscanf_s(st1, "%d", &data[i].english);//從檔案st1中讀入 英文成績
			fscanf_s(st1, "%d", &data[i].math);//從檔案st1中讀入 數學成績

			data[i].sum = data[i].chinese + data[i].english + data[i].math;//加總三科成績存入sum
			data[i].avg = data[i].sum / 3.0;//計算平均後存入avg

			fprintf(st2, "%s\t%d\t%d\t%d\t%d\t%.2f\n"
				, data[i].name, data[i].chinese
				, data[i].english, data[i].math
				, data[i].sum, data[i].avg);//把資料輸出到檔案st2中
		}
		fclose(st1);//關閉檔案st1
		fclose(st2);//關閉檔案st2
	}
	system("PAUSE");
}