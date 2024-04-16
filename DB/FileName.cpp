#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX 10
struct Footballer {
	int Number;
	char Surname[100];
	char Name[100];
	char Role[100];
	char Nation[100];
	int Age;
	char Club[100];
	int Price;
};

int GetVibor() {
	int vibor;
	scanf("%d",&vibor);
	return vibor;
}
void ClearScreen() {
	system("cls");
}
void ContinueProgramm() {
	printf("\n\n������� Enter ��� �����������....");
	int c=0;
	while ((c = getchar()) != '\n' && c != EOF) { 
	} //������� �����
	getchar(); //������ �������
	ClearScreen();
}
void RussLang(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void InitDB(struct Footballer Footballers[]) {
	for (int i = 0; i < MAX; i++) {
		Footballers[i].Number = 0;
		Footballers[i].Surname[0] = '\0';
		Footballers[i].Name[0] = '\0';
		Footballers[i].Role[0] = '\0';
		Footballers[i].Nation[0] = '\0';
		Footballers[i].Age = 0;
		Footballers[i].Club[0] = '\0';
		Footballers[i].Price = 0;
	}
}
int FindSlot(struct Footballer Footballers[]) {
	for (int i = 0; i < MAX; i++) {
		if (strlen(Footballers[i].Surname) == 0) {
			return i; 
		}
	}
	return -1;
} // ���������� ���������� ����� ��� �����
void AddFootballer(struct Footballer Footballers[]) {
	int n = FindSlot(Footballers);
	if (n == -1) {
		printf("���� ������ ���������.\n");
		return;
	}
	
	Footballer fb;
	int c = 0;
	printf("������� ����� ����������: ");
	scanf("%d",&fb.Number);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	printf("\n������� �������: ");
	fgets(fb.Surname,70,stdin);
	char* newsurnameline = strrchr(fb.Surname,'\n'); //����� ���������� \n
	if (newsurnameline) {
		*newsurnameline = '\0';
	}
	printf("\n������� ���: ");
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	printf("\n������� ������� ����������: ");
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	printf("\n������� ��������������: ");
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	printf("\n������� �������: ");
	scanf("%d",&fb.Age);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	printf("\n������� ���������� ����, � ������� ������ ���������: ");
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	printf("\n������� ��������� ���������� �� ����������� �����: ");
	scanf("%d",&fb.Price);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	printf("��������� ��������\n\n");
}
void PrintDB(struct Footballer Footballers[]){
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" ����� | �������              | ���                  | �������                                  | ��������������       | ������� | ����                           | ����      |\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < MAX; i++) {
		if (strlen(Footballers[i].Surname) != 0) {
			printf(" %5d | %-20s | %-20s | %-40s | %-20s | %7d | %-30s | %9d |\n", Footballers[i].Number, Footballers[i].Surname, Footballers[i].Name, 
				Footballers[i].Role, Footballers[i].Nation, Footballers[i].Age, Footballers[i].Club, Footballers[i].Price);
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		}

	}
	ContinueProgramm();
}
void printmenu(void) {
	printf("������� ����� ��������, ������� ������ ������������:\n\n");
	printf("1. ���� ������ � ������ ��.\n");
	printf("2. ����� ��.\n");
	printf("3. ���������� 1-�� ������.\n");
	printf("4. ����� �� ������ �������.\n");
	printf("5. �������� ������.\n");
	printf("6. ���������� �� � ���� (.txt).\n");
	printf("7. �������� �� �����.\n");
	printf("8. �����.\n");
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	printf("������� ����� ���������� ��� ��������: ");
	scanf("%d", &del);
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number == del) {
			Footballers[i].Number = 0;
			Footballers[i].Surname[0] = '\0';
			Footballers[i].Name[0] = '\0';
			Footballers[i].Role[0] = '\0';
			Footballers[i].Nation[0] = '\0';
			Footballers[i].Age = 0;
			Footballers[i].Club[0] = '\0';
			Footballers[i].Price = 0;
			printf("��������� ��� %d ������� �����.\n", del);
			return;
		}
	}
	printf("��������� ��� %d ������� �� ������.\n",del);
}
void SortColumns(struct Footballer Footballers[]) {
	Footballer a[MAX];
	for (int i = 0; i < MAX; i++) {
		a[i] = Footballers[i];
	}
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - i - 1; j++) {
			if (a[j].Price > Footballers[j + 1].Price) {
				Footballer temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	PrintDB(a);
}
void SaveDB(struct Footballer Footballers[]) {
	FILE* file = fopen("����������.txt","w");
	if (file == NULL) {
		printf("�� ������� ������� ����");
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	printf("���� ������ ��������� � ����������.txt");
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("����������.txt","r");
	if (file==NULL){
		printf("�� ������� ������� ���� ��� ������\n");
		return;
	}
	printf("�������� ���� ������ �� ����������.txt ������� � ������ ������� ������� ���� ������. �������, ��� ������ ����������?(1 - ��, 0 - ���)");
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	printf("���� ������ ������� ��������� � ����������.txt");
}
void main() {
	struct Footballer Footballers[MAX];
	InitDB(Footballers);
	RussLang();
	while (1) {
		printmenu();
		int vibor = GetVibor();
		ClearScreen();
		switch (vibor) {
		case 1:
			printf("�� ������ �������� ��?(1 - ��, 0 - ���)\n)");
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				printf("���� ������ ������ � ������.\n");
				while (1) {
					AddFootballer(Footballers);
					printf("�������� ����������? (1 - ��, 0 - ���):\n");
					if (GetVibor() != 1) 
						break;
				}
			}
			ContinueProgramm();
			break;
		case 2:
			PrintDB(Footballers);
			break;
		case 3:
			AddFootballer(Footballers);
			ContinueProgramm();
			break;
		case 4:
			SortColumns(Footballers);
			break;
		case 5:
			DeleteRow(Footballers);
			ContinueProgramm();
			break;
		case 6:
			SaveDB(Footballers);
			ContinueProgramm();
			break;
		case 7:
			LoadDB(Footballers);
			ContinueProgramm();
			break;
		case 8:
			printf("����� �� ���������.\n");
			exit(0);
		default:
			printf("�� ����� ��������, �� �������� � ���������� �� 1-8, ���������� ��� ���");
		}

	}
}
