#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
typedef struct guest {   //�ṹ�嶨��
	struct guest* pre;
	char num[13];
	char name[10];
	char call[12];
	char time[6];
	int sum;
	char whether[4];
	char table1[4];
	int table2;
	struct guest* next;
}gue, * pointer;         //����
extern int i, table_number[5], time_number[7];
extern IMAGE start, img, b,l;
void Copy_head(pointer head, pointer h[])
{
	printf("copy\n");
	int i = 0;
	for (pointer p = head; p != NULL; p = p->next, i++)
	{
		h[i] = (pointer)calloc(1, sizeof(guest));
		if (h[i] == NULL)
		{
			printf("����ռ�ʧ��!");
			return; //��������
		}
		h[i] = p;
	}
}
//������ĵ�ַ����ָ������[100]�����������ڼ�¼˳��
int check_num(pointer head, char num[])
{
	pointer p = head; int flag = 0;
	//�����
	while (p != NULL)
	{
		if (strcmp(p->num, num) == 0)
		{
			//printf("������ͬ�ı�ţ�");

			putimage(0, 0, &start);
			settextcolor(RED);
			outtextxy(250, 200, "������ͬ�ı��");
			settextcolor(RGB(250, 100, 100));
			Sleep(1000);
			return 1;
		}
		else
		{
			p = p->next;
		}
	}
	return 0;
}
int check_name(char num[])
{
	//�������
	int flag = 0, s = 0;
	for (int n = 0; n < 10; n++)
	{
		if ((num[n] > 64 && num[n] < 91) || (num[n] > 96 && num[n] < 123) || (num[n] <= 0 && num[n] > -90))
		{
	
			flag = 0;
		}
		else
		{
			
			flag = 1; break;
		}
	}
	for (int n = 0; n < 9; n++)
	{
		if (num[n] == num[n + 1])
		{
			s++;
		}
	}
	if (flag || s == 9)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(100, 200, "����ֻ���Ǻ��ֻ�Ӣ����ĸ���ݲ����ܲ����ú��֣�");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
int check_call(char num[])
{
	int flag = 0;
	for (int n = 0; n < 11; n++)
	{
		if (num[n] >= '0' && num[n] <= '9');
		else { flag = 1; break; }
	}
	if (flag)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(250, 200, "�绰ֻ����11Ϊ������");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
int check_time(char num[])
{
	int flag = 0;
	for (int n = 0; n < 5 && flag != 1; n++)
	{
		switch (n)
		{
		case 0:if (num[n] >= '0' && num[n] <= '2'); else flag = 1; break;
		case 1:if (num[n] >= '0' && num[n] <= '9'); else flag = 1; break;
		case 2:if (num[n] == ':' || num[n] == '��'); else flag = 1; break;
		case 3:if (num[n] >= '0' && num[n] <= '5'); else flag = 1; break;
		case 4:if (num[n] >= '0' && num[n] <= '9'); else flag = 1; break;
		}
	}
	if (flag)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(250, 200, "ʱ���ʽ**:**��24Сʱ�ƣ�");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
//�ĸ���麯����������أ��������ʽ
void Input(pointer* head, pointer* tail, char write[], int YN)//���뺯������ѭ��ִ��
{
	char n[13] = { '\0' }, people[3] = { '\0' }, b[1] = { '\0' };
	pointer p, q, r;
	int check, j = 0; bool tf;
	for (int s = 1; s == 1; i++)//ѭ�����룬i���ڼ��ܶ�������
	{
		for (check = 1; check == 1;)
		{
		
			q = *head; p = *tail;
			if (YN == 1)
			{
				for (int x = 0; x < 13; x++)
				{
					n[x] = '\0';
				}
				InputBox(n, 13, "��������", "����", "FPY201900001", 0);
				check = check_num(*head, n);
			}
			else
			{
				int k = 0;
				if (j == 0)
				{
					for (; k < 12 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
						n[k] = write[j];
					check = 0;
				}
				else
				{
					for (; write[j] != 10 && write[j] != '\0'; j++);
					for (j++; k < 12 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
						n[k] = write[j];
					check = 0;

				}
			}
			printf("%s\n", n);
		}
		r = (pointer)calloc(1, sizeof(guest));
		if (r == NULL)
		{
			printf("����ռ�ʧ��!");
			return; //��������
		}
		else printf("succse\n");
		if (q == NULL) { *tail = *head = r; }
		else {
			p->next = r;
			r->pre = p;
			(*tail) = r;
		}
		strcpy_s(r->num, n);
		for (check = 1; check == 1;)
		{
			printf("check\n");
			if (YN == 1)
			{
				for (int x = 0; x < 10; x++)
				{
					r->name[x] = '\0';
				}
				InputBox(r->name, 10, "����������", "����", "����", 0);
				check = check_name(r->name);
				printf("%d\n", check_name(r->name));
				printf("%d\n", check);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 10 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
					r->name[k] = write[j];
				check = 0;
			}
			printf("%s\n", r->name);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				for (int x = 0; x < 12; x++)
				{
					r->call[x] = '\0';
				}
				InputBox(r->call, 12, "������绰", "����", "15137607332", 0);
				check = check_call(r->call);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10&&write[j]!='\0'; j++);
				for (j++; k < 11 && write[j] != 9 && write[j] != 13; j++, k++)
					r->call[k] = write[j];
				check = 0;
			}

			printf("%s\n", r->call);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				for (int x = 0; x < 6; x++)
				{
					r->time[x] = '\0';
				}
				InputBox(r->time, 6, "������ʱ��", "����", "12:30", 0);
				check = check_time(r->time);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 5 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
					r->time[k] = write[j];
				check = 0;
			}

			printf("%s\n", &r->time);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				InputBox(people, 3, "����������", "����", "0<����<11", 0);
				if (people[1] == '\0')
				{
					r->sum = people[0] - 48;
				}
				else r->sum = (people[0] - 48) * 10 + people[1] - 48;
				if (r->sum > 0 && r->sum <= 10) check = 0;
				else check = 1;
			}
			else
			{
				int k = 0;	people[1] = { '\0' };
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 2 && write[j] != 13 && write[j] != 9 && write[j] != 0 && write[j] != '\0'; j++, k++)
					people[k] = write[j];
				printf("%s\n", people);
				if (people[1] == '\0')
				{
					r->sum = (int)people[0] - 48;
				}
				else r->sum = ((int)people[0] - 48) * 10 + (int)people[1] - 48;
				printf("%d\n", r->sum);
				check = 0;
			}
		}
		if (YN == 1)
		{
			tf = InputBox(b, 0, "�Ƿ����¼������", "��ʾ", "ȷ�ϼ���,ȡ���˳�", 0, 0, false);
			if (tf);
			else  s = 0;;
		}
		else
		{
			if (write[j] == 0) s = 0;//�ж��Ƿ������ȡ
		}
	}
}
//���뺯������𲽺��������빦�ܡ���YN��ֵ[0��1]����ʹ���ĸ����ܡ�write����������ʱ��������
void Output_p(pointer head, int n, int i)
{
	for (pointer p = head; p != NULL && i > 0; p = p->next, i--, n++)
	{
		char s[3] = { '\0' };
		outtextxy(55, 60 + n * 25, p->num);
		outtextxy(160, 60 + n * 25, p->name);
		outtextxy(202, 60 + n * 25, p->call);
		outtextxy(300, 60 + n * 25, p->time);
		if (p->sum == 10)
		{
			s[0] = '1', s[1] = '0';
		}
		else
		{
			s[0] = p->sum + 48;
		}
		outtextxy(358, 60 + n * 25, s);
		s[1] = '\0';
		outtextxy(413, 60 + n * 25, p->whether);
		outtextxy(482, 60 + n * 25, p->table1);
		s[0] = p->table2 + 48;
		outtextxy(490, 60 + n * 25, s);
		line(50, 78 + n * 25, 515, 78 + n * 25);
	}
	n--;
	line(50, 55, 50, 78 + n * 25);
	line(156, 55, 156, 78 + n * 25);
	line(197, 55, 197, 78 + n * 25);
	line(298, 55, 298, 78 + n * 25);
	line(341, 55, 341, 78 + n * 25);
	line(386, 55, 386, 78 + n * 25);
	line(460, 55, 460, 78 + n * 25);
	line(515, 55, 515, 78 + n * 25);
}
//���������Ϣ��head�������ַ����Search������ѯ����ʼ��i���Ƹ�����n��������
void Output_h(pointer h[], int n,int j, int i)
{
	for (; h[n]!=NULL && i>0; n++,i--,j++)
	{
		char s[3] = { '\0' };
		outtextxy(55, 60 + j * 25, h[n]->num);
		outtextxy(160, 60 + j * 25, h[n]->name);
		outtextxy(202, 60 + j * 25, h[n]->call);
		outtextxy(300, 60 + j * 25, h[n]->time);
		if (h[n]->sum == 10)
		{
			s[0] = '1', s[1] = '0';
		}
		else
		{
			s[0] = h[n]->sum + 48;
		}
		outtextxy(358, 60 + j * 25, s);
		s[1] = '\0';
		outtextxy(413, 60 + j * 25, h[n]->whether);
		outtextxy(482, 60 + j * 25, h[n]->table1);
		s[0] = h[n]->table2 + 48;
		outtextxy(490, 60 + j * 25, s);
		line(50, 78 + j * 25, 515, 78 + j * 25);
	}
	j--;
	line(50, 55, 50, 78 + j * 25);
	line(156, 55, 156, 78 + j * 25);
	line(197, 55, 197, 78 + j * 25);
	line(298, 55, 298, 78 + j * 25);
	line(341, 55, 341, 78 + j * 25);
	line(386, 55, 386, 78 + j * 25);
	line(460, 55, 460, 78 + j * 25);
	line(515, 55, 515, 78 + j * 25);
}
//���h[]��������Ϣ������ͬ��
void Swap(pointer p, pointer q)//�ṹ�����ݽ���
{
	pointer e;
	e = (pointer)calloc(1, sizeof(guest));
	if (e == NULL)
	{
		printf("����ռ�ʧ��!");
		return; //��������
	}

	strcpy_s(e->name, p->name);
	e->sum = p->sum;
	strcpy_s(e->call, p->call);
	strcpy_s(e->time, p->time);

	strcpy_s(p->name, q->name);
	p->sum = q->sum;
	strcpy_s(p->call, q->call);
	strcpy_s(p->time, q->time);

	strcpy_s(q->name, e->name);
	q->sum = e->sum;
	strcpy_s(q->call, e->call);
	strcpy_s(q->time, e->time);
}
//���������ṹ��Ĳ���ֵ�������޸Ĺ���
pointer Search_num(pointer head, char s[])//��ѯ�������ڵ�ַ
{
	pointer p = head;
	while (p != NULL)
	{
		if (strcmp(p->num, s) == 0)
		{
			return p;
		}
		else
			p = p->next;
	}
	return NULL;
}
pointer Search_name(pointer head, char s[])//�ַ���ѯ
{
	//char name[15] = { '\0' }, 
	pointer p = head;
	//printf("������:");
	//scanf_s("%s", name, sizeof(name));
	while (p != NULL)
	{
		if (strcmp(p->name, s) == 0)
		{
			return p;
		}
		else
			p = p->next;
	}
	return NULL;

}
pointer Search_time(pointer head, char s1[], char s2[])
{
	pointer p = head;
	while (p != NULL)
	{
		if (strcmp(p->time, s1) >= 0 && strcmp(p->time, s2) < 0)
		{
			printf("name\n");
			return p;
		}
		else
			p = p->next;
	}
	return NULL;
}
//�������ѯ��Ϣ��������Ϣ���ڵ�ַ���޷���NULL
void Insert(pointer* head, pointer* s)//����*head֮ǰ
{
	pointer p, q, r; char n[15]; int check;
	r = (pointer)calloc(1, sizeof(guest));
	if (r == NULL)
	{
		printf("����ռ�ʧ��!");
		return; //��������
	}
label1:
	printf("��������룺");
	scanf_s("%s", &n, sizeof(n));
	check = check_num(*head, n);
	if (check == 1)goto label1;
	strcpy_s(r->num, n);
	printf("������������");
	scanf_s("%s", r->name, sizeof(r->name));
	printf("�������ò���������");
	scanf_s("%d", &r->sum);
	printf("�������ò�ʱ�䣺");
	scanf_s("%s", &r->time, sizeof(r->time));
	i++;//��¼������
	if (*head == *s)
	{
		p = *head; q = r;
		q->next = p; p->pre = q;
		(*head) = q;
	}
	else
	{
		q = *s, q = q->pre;
		p = *s;
		q->next = r, r->pre = q;
		r->next = p, p->pre = r;
	}

}
//����Search���������Ϣ��δ����
void Modify(pointer s, pointer p)
{
	/*pointer p; char b = '\0';
	p = (pointer)calloc(1, sizeof(guest));
	if (p == NULL)
	{
		printf("����ռ�ʧ��!");
		return; //��������
	}*/

	/*printf("������������");
	scanf_s("%s", p->name, sizeof(p->name));
	printf("�������ò���������");
	scanf_s("%d", &p->sum);
	printf("�������ò�ʱ�䣺");
	scanf_s("%s", &p->time, sizeof(p->time));
	printf("ȷ���޸�!");*/
	/*label2:
		scanf_s("%c", &b);
		if (b == 'n' || b == 'N')
		{
			return;
		}
		else if (b == 'y' || b == 'Y')
		{*/
	strcpy_s(s->name, p->name);
	strcpy_s(s->call, p->call);
	s->sum = p->sum;
	strcpy_s(s->time, p->time);
	//printf("�Ѹ���");
/*}
else
{
	printf("������y��������n���˳���"); goto label2;//�ص�y/n�������
}*/
}
//����������ƣ���Ϊ���ӻ�ֻ��ʵ�ֽ�p�ڵ�ֵ����s
void Delete(pointer* head, pointer* s)
{
	pointer p, q;
	q = p = *s;
	i--;
	if (p == *head)//ɾȥͷ��ַ
	{
		p = p->next;
		if (p != NULL) { p->pre = NULL; }
		free(*head);
		*head = p;
	}
	else
	{
		if (p->next == NULL)//ɾȥβ��ַ
		{
			q = q->pre; q->next = NULL;
		}
		else//ɾȥ�м��ַ
		{
			q = q->pre; p = p->next;
			q->next = p; p->pre = q;
		}
		free(*s);
	}
}
//ɾ��s�ڵ���Ϣ
void Sort_num(pointer h[])
{
	char min[20]; int n = 0; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->num);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->num) > 0)
			{
				strcpy_s(min, h[n]->num);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_name(pointer h[])
{
	char min[20]; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->name);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->name) > 0)
			{
				strcpy_s(min, h[n]->name);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_time(pointer h[])
{
	char min[20]; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->time);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->time) > 0)
			{
				strcpy_s(min, h[n]->time);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_sum(pointer h[])
{
	int min; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; min = h[s]->sum;
		for (n = s + 1; n < i; n++)
		{
			if (min > h[n]->sum)
			{
				min = h[n]->sum;
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
//ѡ����������h[]�е�ָ��˳��
void Arrange(pointer h[], int i)//��¼���ͽ��,ͳ�Ʋ���������ʱ������
{
	printf("arrange\n");
	char Time[8][6] = { {"11:00"} ,{"11:30"}, {"12:00"}, {"12:30"}, {"13:00"}, {"13:30"} ,{"2:00"} };
	//char Timew[8][6] = { {"17:00"} ,{"17:30"}, {"18:00"}, {"18:30"}, {"19:00"}, {"19:30"} ,{"2:00"} };���ʱ��
	int A = 5, B = 5, C = 5;
	for (int n = 0; n < 6; n++)
	{
		time_number[n] = 0;
	}
	for (int n = 0; n < i; n++)
	{
		for (int t = 0; t < 6; t++)
		{
			if (strcmp(h[n]->time, Time[t]) >= 0 && strcmp(h[n]->time, Time[t + 1]) < 0)
			{
				time_number[t]++;
			}
		}
		if (h[n]->sum <= 4)
		{
			if (C > 0)
			{
				strcpy_s(h[n]->whether, "��"); C--;
				strcpy_s(h[n]->table1, "C");
				h[n]->table2 = 5 - C;
			}
			else strcpy_s(h[n]->whether, "��");
		}
		else if (h[n]->sum >= 8)
		{
			if (A > 0)
			{
				strcpy_s(h[n]->whether, "��"); A--;
				strcpy_s(h[n]->table1, "A");
				h[n]->table2 = 5 - A;
			}
			else strcpy_s(h[n]->whether, "��");
		}
		else
		{
			if (B > 0)
			{
				strcpy_s(h[n]->whether, "��"); B--;
				strcpy_s(h[n]->table1, "B");
				h[n]->table2 = 5 - B;
			}
			else strcpy_s(h[n]->whether, "��");
		}
	}
	table_number[1] = 5 - A;
	table_number[2] = 5 - B;
	table_number[3] = 5 - C;
	table_number[4] = 15 - A - B - C;
}
//���Ŷ����Ĳ�����ͬʱ��ȫ�ֱ�����¼ʱ��Ͳ�������Ϣ
void Statisics(pointer h[])//�������ͳ�ƽ����ͳ�ƽ����Arrange�����ṩ
{
	int i;//�ַ�ת����
	char c[3];
	char Time[8][6] = { {"11:00"} ,{"11:30"}, {"12:00"}, {"12:30"}, {"13:00"}, {"13:30"} ,{"14:00"} };
	outtextxy(80, 70, "ʱ��ֶ�ͳ�ƣ�ԲȦ�����ֱ�ʾ���ڵ���ǰһ��С�ں�һ���ĸ���");
	rectangle(95, 95, 532, 120);
	for (int show = 0; show < 7; show++)
	{
		outtextxy(100 + 65 * show, 100, Time[show]);
	}
	for (int show = 0; show < 6; show++)
	{
		i = time_number[show];
		if (i < 0) break;
		sprintf_s(c, "%d", i);//�ַ�ת����
		if (i < 10)	outtextxy(147 + 65 * show, 100, c);
		else	outtextxy(143 + 65 * show, 100, c);
		circle(150 + 65 * show, 107, 11);
	}
	outtextxy(100, 200, "�������A����");
	outtextxy(100, 225, "�в�����B����");
	outtextxy(100, 250, "С������C����");
	outtextxy(100, 275, "�ܲ������� ��");

	for (int show = 1; show <= 4; show++)
	{
		i = table_number[show];
		if (i < 0) break;
		sprintf_s(c, "%d", i);
		outtextxy(200, 175 + show * 25, c);
	}
}
//�������ͳ����Ϣ����Ϣ��Arrange�ṩ
//---------------------------------------------����Ϊ���ܺ���
//---------------------------------------------����Ϊ�����������
void Output_code()
{
	putimage(0, 0, &b);
	setbkcolor(GREEN);
	outtextxy(140, 100, "��");
	Sleep(300);
	outtextxy(240, 100, "ӭ");
	Sleep(300);
	outtextxy(340, 100, "ʹ");
	Sleep(300);
	outtextxy(440, 100, "��");
	Sleep(500);
	outtextxy(140, 200, "��");
	Sleep(300);
	outtextxy(240, 200, "��");
	Sleep(300);
	outtextxy(340, 200, "��");
	Sleep(300);
	outtextxy(440, 200, "ѧ");
	Sleep(500);
	outtextxy(40, 300, "��");
	Sleep(300);
	outtextxy(140, 300, "��");
	Sleep(300);
	outtextxy(240, 300, "��");
	Sleep(300);
	outtextxy(340, 300, "��");
	Sleep(300);
	outtextxy(440, 300, "ϵ");
	Sleep(300);
	outtextxy(540, 300, "ͳ");
	Sleep(500);
	setbkcolor(BLACK);
}
//���붯��
void start_output(void)
{
	putimage(0, 0, &start);
	setbkmode(TRANSPARENT);//�ַ�����͸��
	settextcolor(RGB(250, 100, 100));//����������ɫ
	setlinecolor(RGB(200, 10, 10));//����������ɫ
	for (int x = 45, y = 70; y <= 280; x += 30, y += 30)//������ο�
	{
		rectangle(275, x, 377, y);
	}
	outtextxy(305, 50, "���˵�");
	outtextxy(280, 80, "����ͻ���Ϣ");
	outtextxy(280, 110, "���ҿͻ���Ϣ");
	outtextxy(280, 140, "ɾ���ͻ���Ϣ");
	outtextxy(280, 170, "���Ŀͻ���Ϣ");
	outtextxy(288, 200, "��������ʾ");
	outtextxy(280, 230, "ͳ���û���Ϣ");
	outtextxy(295, 260, "�˳�ϵͳ");
}
//�˵�
void SR_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(295, 80, "��������");
	rectangle(275, 105, 377, 130);
	outtextxy(295, 110, "�������");
	rectangle(275, 135, 377, 160);
	outtextxy(310, 140, "����");
}
//����
void PX_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(295, 80, "ԭʼ˳��");
	rectangle(275, 105, 377, 130);
	outtextxy(295, 110, "��Ž���");
	rectangle(275, 135, 377, 160);
	outtextxy(295, 140, "��������");
	rectangle(275, 165, 377, 190);
	outtextxy(295, 170, "ʱ�併��");
	rectangle(275, 195, 377, 220);
	outtextxy(295, 200, "��������");
	rectangle(275, 225, 377, 250);
	outtextxy(310, 230, "����");
}
//����
void CX_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(279, 80, "���ձ�Ų�ѯ");
	rectangle(275, 105, 377, 130);
	outtextxy(279, 110, "����������ѯ");
	rectangle(275, 135, 377, 160);
	outtextxy(279, 140, "����ʱ���ѯ");
	rectangle(275, 165, 377, 190);
	outtextxy(310, 170, "����");
}
//��ѯ
void Output_gailan(void)
{
	putimage(0, 0, &start);
	outtextxy(95, 60, "���");
	outtextxy(160, 60, "����");
	outtextxy(230, 60, "�绰");
	outtextxy(303, 60, "ʱ��");
	outtextxy(347, 60, "����");
	outtextxy(390, 60, "�Ƿ�ɹ�");
	outtextxy(465, 60, "���Ӻ�");
	line(50, 55, 515, 55);
	line(50, 78, 515, 78);
	line(50, 55, 50, 78);
	line(156, 55, 156, 78);
	line(197, 55, 197, 78);
	line(298, 55, 298, 78);
	line(341, 55, 341, 78);
	line(386, 55, 386, 78);
	line(460, 55, 460, 78);
	line(515, 55, 515, 78);

}
//Ŀ¼
void last_output(void)
{
	putimage(0, 0, &l);
	Sleep(1500);
}
//��βthanks
//----------------------------------------------��������غ���
void Return_(void)
{
	settextcolor(RGB(250, 100, 100));
	rectangle(560, 440, 630, 470);
	outtextxy(582, 448, "����");
	while (1)
	{
		MOUSEMSG tj = GetMouseMsg();
		if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
		{
			break;
		}
	}
}
//�ṩһ�����ذ�ť
void Return_output(void)
{
	rectangle(560, 360, 630, 390);
	outtextxy(572, 368, "��һҳ");
	rectangle(560, 400, 630, 430);
	outtextxy(572, 408, "��һҳ");
	rectangle(560, 440, 630, 470);
	outtextxy(582, 448, "����");
}
/*�ṩ������ť��Ŀǰֻʵ���˷��ع���
������Ļ��С���ޣ���ҳ������δʵ�֣���������ֻ����ʾ15�����ݣ����ԼӴ���Ļ����ֻ����ǿ�����*/


