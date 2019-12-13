#include <stdio.h>
#include <stdlib.h>

struct clientData {//clientData���c
	int acctNum;
	char lName[15];//����15
	char fName[10];//����10
	double balance;
};

void main()
{
	FILE *pR, *pW, *cfPtr;//�ŧi�ɮ׫���
	int cnt = 0;
	struct clientData client = {0,"","",0.0};
	fopen_s(&pR, "c://credit.txt","r");//�}���ɮ�credit.txt(Ū)
	if (pR == NULL)
	{//�ɮפ��s�b
		return;//�j����}
	}
	fopen_s(&pW, "c://credit_bin.txt", "wb");//�}���ɮ�credit_bin.txt(�g�G�i����)
	if (pW == NULL)
	{//�ɮפ��s�b
		fclose(pR);//�����Ĥ@���ɮ�
		return;//�j����}
	}

	while (!feof(pR))
	{//�j�� ���ɮץ��F������
		fscanf_s(pR, "%d", &client.acctNum);//Ū����Ʀs�Jclient.acctNum
		fscanf_s(pR, "%s", client.lName,15);//Ū������15���r��s�Jclient.lName
		fscanf_s(pR, "%s", client.fName,10);//Ū������10���r��s�Jclient.lName
		fscanf_s(pR, "%f", &client.balance);//Ū���B�I�Ʀs�Jclient.balance
		fwrite(&client, sizeof(struct  clientData),1,pW);//�Nclient�g�J�ɮ�pW��
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lName, client.fName, client.balance);//��X���
	}
	fclose(pR);//�����ɮ�pR
	fclose(pW);//�����ɮ�pW
	printf("�wŪ����r�ɪ�ASCII��ơA����s���G�i�����ɮ�\n\n");
	system("PAUSE");//���N���~��...

	printf("\nŪ���G�i�����ɮסA�î榡�ƿ�X�p�U�G\n");
	fopen_s(&cfPtr, "c://credit_bin.txt", "rb");//�}���ɮ�credit_bin.txt(Ū�G�i��)
	if ((cfPtr) == NULL)
	{//�ɮפ��s�b
		printf("File could not be opened.");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);//Ū��clientData���ƶq
		
		while (cnt > 0)
		{//�j��]�X�C�@��clientData
			printf("%-6d%-16s%-11s%10.2f\n",client.acctNum,client.lName,client.fName,client.balance);//��X
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);//�����ɮ�
	}
	system("PAUSE");//�����N���~��
}