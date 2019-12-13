#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{//student���c
	char name[6];//�W��
	int chinese,english,math;//��^�Ʀ��Z
	int sum;//�`�M
	float avg;//����(=sum/3)
} student;

void main()
{
	student data[5];//�ŧi5��student
	FILE *st1, *st2;//����ɮ�
	int i;

	fopen_s(&st1,"c://gradedata.txt", "r");//�}���ɮ�gradedata.txt(Ū)
	fopen_s(&st2,"c://gradeoutput.txt", "w");//�}���ɮ�gradeoutput.txt(�g)

	if (st1 == NULL || st2 == NULL)
	{//���@�ɮפ��s�b
		printf("�ɮ׶}�ҥ���\n");
	}
	else
	{//���s�b�����p�U
		fprintf(st2, "�m�W\t���\t�^��\t�ƾ�\t�`�X\t����\n");//�b�ɮ�st2���L�X�r��
		for (i = 0; i < 5; i++)
		{//�]5�����
			fscanf_s(st1, "%s", data[i].name,6);//�q�ɮ�st1��Ū�J �W�� ����6
			fscanf_s(st1, "%d", &data[i].chinese);//�q�ɮ�st1��Ū�J ��妨�Z
			fscanf_s(st1, "%d", &data[i].english);//�q�ɮ�st1��Ū�J �^�妨�Z
			fscanf_s(st1, "%d", &data[i].math);//�q�ɮ�st1��Ū�J �ƾǦ��Z

			data[i].sum = data[i].chinese + data[i].english + data[i].math;//�[�`�T�즨�Z�s�Jsum
			data[i].avg = data[i].sum / 3.0;//�p�⥭����s�Javg

			fprintf(st2, "%s\t%d\t%d\t%d\t%d\t%.2f\n"
				, data[i].name, data[i].chinese
				, data[i].english, data[i].math
				, data[i].sum, data[i].avg);//���ƿ�X���ɮ�st2��
		}
		fclose(st1);//�����ɮ�st1
		fclose(st2);//�����ɮ�st2
	}
	system("PAUSE");
}