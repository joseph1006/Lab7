#include <stdio.h>
#include <stdlib.h>

struct clientData {//clientData結構
	int acctNum;
	char lName[15];//長度15
	char fName[10];//長度10
	double balance;
};

void main()
{
	FILE *pR, *pW, *cfPtr;//宣告檔案指標
	int cnt = 0;
	struct clientData client = {0,"","",0.0};
	fopen_s(&pR, "c://credit.txt","r");//開啟檔案credit.txt(讀)
	if (pR == NULL)
	{//檔案不存在
		return;//強制跳開
	}
	fopen_s(&pW, "c://credit_bin.txt", "wb");//開啟檔案credit_bin.txt(寫二進制資料)
	if (pW == NULL)
	{//檔案不存在
		fclose(pR);//關閉第一個檔案
		return;//強制跳開
	}

	while (!feof(pR))
	{//迴圈 當檔案未達結尾時
		fscanf_s(pR, "%d", &client.acctNum);//讀取整數存入client.acctNum
		fscanf_s(pR, "%s", client.lName,15);//讀取長度15的字串存入client.lName
		fscanf_s(pR, "%s", client.fName,10);//讀取長度10的字串存入client.lName
		fscanf_s(pR, "%f", &client.balance);//讀取浮點數存入client.balance
		fwrite(&client, sizeof(struct  clientData),1,pW);//將client寫入檔案pW中
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lName, client.fName, client.balance);//輸出資料
	}
	fclose(pR);//關閉檔案pR
	fclose(pW);//關閉檔案pW
	printf("已讀取文字檔的ASCII資料，並轉存成二進位資料檔案\n\n");
	system("PAUSE");//任意鍵繼續...

	printf("\n讀取二進位資料檔案，並格式化輸出如下：\n");
	fopen_s(&cfPtr, "c://credit_bin.txt", "rb");//開啟檔案credit_bin.txt(讀二進制)
	if ((cfPtr) == NULL)
	{//檔案不存在
		printf("File could not be opened.");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);//讀取clientData的數量
		
		while (cnt > 0)
		{//迴圈跑出每一個clientData
			printf("%-6d%-16s%-11s%10.2f\n",client.acctNum,client.lName,client.fName,client.balance);//輸出
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);//關閉檔案
	}
	system("PAUSE");//按任意鍵繼續
}