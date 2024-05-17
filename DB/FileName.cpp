#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
#define MAX 20
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
	cin>>vibor;
	return vibor;
}
void ClearScreen() {
	system("cls");
}
void ContinueProgramm() {
	cout << "\n" << "\n" << "������� Enter ��� �����������...";
	int c=0;
	while ((c = getchar()) != '\n' && c != EOF) { //�� ���������� �� ������� �������, �������� ������ (�������), �� ��� ���, ���� �� �������� �� ����� ������ ��� ����� �����.
	}												
	getchar(); 
	ClearScreen();
}
void RussLang(void) {
	SetConsoleCP(1251); // ������������ ��������� ��������� �� windows 1251
	SetConsoleOutputCP(1251);
}
void InitDB(struct Footballer Footballers[]) {
	for (int i = 0; i < MAX; i++) {
		memset(&Footballers[i],0,sizeof(Footballer));
	}
}
int FindSlot(struct Footballer Footballers[]) {
	for (int i = 0; i < MAX; i++) {
		if (strlen(Footballers[i].Surname) == 0) {
			return i;
		}
	}
	return -1;
} 
void AddFootballer(struct Footballer Footballers[]) {
	int n = FindSlot(Footballers);
	if (n == -1) {
		cout<<"���� ������ ���������."<<"\n";
		return;
	}
	
	Footballer fb;
	int c = 0;
	cout<<"\n"<<"������� ����� ���������� : ";
	cin>>fb.Number;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	cout<<"\n"<<"������� ������� : ";
	fgets(fb.Surname,70,stdin); // stdin - ����������� ����� �����
	char* newsurnameline = strrchr(fb.Surname,'\n'); // strrchr - ��������� �� ��������� ��������� ������� � ������
	if (newsurnameline) { // �������� �� ������������� ���������� ��������� \n
		*newsurnameline = '\0'; // * - �������������(��������� ��������) � ��������� �������� �� \0 (����� ������)
	}
	cout<<"\n"<<"������� ��� : ";
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	cout<<"\n"<<"������� ������� ���������� : ";
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	cout<<"\n"<<"������� �������������� : ";
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	cout<<"\n"<<"������� ������� : ";
	cin>>fb.Age;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	cout<<"\n"<<"������� ���������� ����, � ������� ������ ��������� : ";
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	cout<<"\n"<<"������� ��������� ���������� �� ����������� ����� : ";
	cin>>fb.Price;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	cout << "\n" << "��������� ��������" << "\n" << "\n";
}
void PrintDB(struct Footballer Footballers[]){
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	cout<<" ����� | �������              | ���                  | �������                                  | ��������������       | ������� | ����                           | ����      |"<<"\n";
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	for (int i = 0; i < MAX; i++) {
		if (strlen(Footballers[i].Surname) != 0) {
			printf(" %5d | %-20s | %-20s | %-40s | %-20s | %7d | %-30s | %9d |\n", Footballers[i].Number, Footballers[i].Surname, Footballers[i].Name, 
				Footballers[i].Role, Footballers[i].Nation, Footballers[i].Age, Footballers[i].Club, Footballers[i].Price);
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
		}
	}
	ContinueProgramm();
}
void printmenu(void) {
	cout<<"������� ����� ��������, ������� ������ ������������:"<<"\n"<<"\n";
	cout<<"1. ���� ������ � ������ ��."<<"\n";
	cout<<"2. ����� ��."<<"\n";
	cout<<"3. ���������� 1-�� ������."<<"\n";
	cout<<"4. ����� �� ������ �������."<<"\n";
	cout<<"5. �������� ������."<<"\n";
	cout<<"6. ���������� �� � ���� (.txt)."<<"\n";
	cout<<"7. �������� �� �����."<<"\n";
	cout<<"8. �����."<<"\n";
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	cout<<"������� ����� ���������� ��� ��������: ";
	cin>>del;
	int c = 0;
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number == del) {
			memset(&Footballers[i],0,sizeof(Footballer));
			cout << "��������� �����" << "\n";
			return;
		}
	}
	printf("��������� ��� %d ������� �� ������",del);
}
void ColumnMenu(void) {
	cout << "�������� �� ������ ������� ����� ������������� �����" << "\n";
	cout << "1. �����" << "\n";
	cout << "2. �������" << "\n";
	cout << "3. ���" << "\n";
	cout << "4. �������" << "\n";
	cout << "5. ��������������" << "\n";
	cout << "6. �������" << "\n";
	cout << "7. ���������� ����" << "\n";
	cout << "8. ����" << "\n";
}
void ColumnSearch(struct Footballer Footballers[]) {
	ColumnMenu();
	struct Footballer temp[MAX];
	InitDB(temp);
	int vibor = GetVibor();
	ClearScreen();
	switch (vibor) {
	case 1:
	{
		cout << "������� ����� �� 1 �� 99" << "\n";
		int NumberColumn = GetVibor();
		for (int i = 0; i < MAX; i++) {
			if (Footballers[i].Number == NumberColumn) {
				temp[i] = Footballers[i];
			}
			
		}
		PrintDB(temp);
		break;
	}
	case 2:
	{
		cout << "������� �������" << "\n";
		char SurnameColumn[52];
		cin >> SurnameColumn;
		for (int i = 0; i < MAX; i++) {
			if (strcmp(Footballers[i].Surname, SurnameColumn) == 0) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 3:
	{
		cout << "������� ���" << "\n";
		char NameColumn[52];
		cin >> NameColumn;
		for (int i = 0; i < MAX;i++) {
			if (strcmp(Footballers[i].Name, NameColumn) == 0) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 4:
	{
		cout << "������� �������" << "\n";
		char RoleColumn[52];
		cin >> RoleColumn;
		for (int i = 0; i < MAX; i++) {
			if (strcmp(Footballers[i].Role, RoleColumn) == 0) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 5:
	{
		cout << "������� ��������������" << "\n";
		char NationColumn[52];
		cin >> NationColumn;
		for (int i = 0; i < MAX; i++) {
			if (strcmp(Footballers[i].Nation, NationColumn) == 0) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 6:
	{
		cout << "������� �������" << "\n";
		int AgeColumn = GetVibor();
		for (int i = 0; i < MAX; i++) {
			if (Footballers[i].Age == AgeColumn) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 7:
	{
		cout << "������� ���������� ����" << "\n";
		char ClubColumn[52];
		cin >> ClubColumn;
		for (int i = 0; i < MAX;i++) {
			if (strcmp(Footballers[i].Club, ClubColumn)) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	case 8:
	{
		cout << "������� ����" << "\n";
		int PriceColumn = GetVibor();
		for (int i = 0; i < MAX;i++) {
			if (Footballers[i].Price == PriceColumn) {
				temp[i] = Footballers[i];
			}
		}
		PrintDB(temp);
		break;
	}
	default:
		break;
	}
}
void SaveDB(struct Footballer Footballers[]) {
	FILE* file = fopen("����������.txt","w");
	if (file == NULL) {
		cout<<"�� ������� ������� ����";
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	cout<<"\n"<<"���� ������ ��������� � ����������.txt"<<"\n";
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("����������.txt","r");
	if (file==NULL){
	cout<<"�� ������� ������� ���� ��� ������"<<"\n";
		return;
	}
	cout<<"�������� ���� ������ �� ����������.txt ������� � ������ ������� ������� ���� ������. �������, ��� ������ ����������?(1 - ��, 0 - ���)"<<"\n";
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	cout<<"\n"<<"���� ������ ������� ��������� � ����������.txt"<<"\n";
}
void main() {
	struct Footballer Footballers[MAX];
	InitDB(Footballers);
	RussLang();
	int m = 0;
	while (1) {
		printmenu();
		int vibor = GetVibor();
		ClearScreen();
		switch (vibor) {
		case 1:
			cout<<"�� ������ �������� ��?(1 - ��, 0 - ���)" << "\n" << "\n";
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				cout<< "\n" << "���� ������ ������ � ������." << "\n";
				while (1) {
					AddFootballer(Footballers);
					cout<<"�������� ����������? (1 - ��, 0 - ���):" << "\n";
					if (GetVibor() != 1) {
						m = 1;
						break;
					}
				}
			}
			ContinueProgramm();
			break;
		case 7:
			LoadDB(Footballers);
			m = 1;
			ContinueProgramm();
			break;
		case 8:
			cout<<"����� �� ���������." << "\n";
			exit(0);
		default:
			if (m == 0) {
				cout << "���� ������ �����" << "\n" << "\n";
				continue;
			}
			switch (vibor) {
			case 2:
				PrintDB(Footballers);
				break;
			case 3:
				AddFootballer(Footballers);
				ContinueProgramm();
				break;
			case 4:
				ColumnSearch(Footballers);
				break;
			case 5:
				DeleteRow(Footballers);
				ContinueProgramm();
				break;
			case 6:
				SaveDB(Footballers);
				ContinueProgramm();
				break;
			default:
				cout << "�� ����� ��������, �� �������� � ���������� �� 1-8, ���������� ��� ���";
			}
		}

	}
}


