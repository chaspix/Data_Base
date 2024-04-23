#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
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
	std::cin>>vibor;
	return vibor;
}
void ClearScreen() {
	system("cls");
}
void ContinueProgramm() {
	std::cout << "\n" << "\n" << "������� Enter ��� �����������....";
	int c=0;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	getchar(); 
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
		std::cout<<"���� ������ ���������."<<"\n";
		return;
	}
	
	Footballer fb;
	int c = 0;
	std::cout<<"\n"<<"������� ����� ���������� : ";
	std::cin>>fb.Number;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	std::cout<<"\n"<<"������� ������� : ";
	fgets(fb.Surname,70,stdin);
	char* newsurnameline = strrchr(fb.Surname,'\n'); //����� ���������� \n
	if (newsurnameline) {
		*newsurnameline = '\0';
	}
	std::cout<<"\n"<<"������� ��� : ";
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	std::cout<<"\n"<<"������� ������� ���������� : ";
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	std::cout<<"\n"<<"������� �������������� : ";
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	std::cout<<"\n"<<"������� ������� : ";
	std::cin>>fb.Age;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	std::cout<<"\n"<<"������� ���������� ����, � ������� ������ ��������� : ";
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	std::cout<<"\n"<<"������� ��������� ���������� �� ����������� ����� : ";
	std::cin>>fb.Price;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	std::cout << "\n" << "��������� ��������" << "\n" << "\n";
}
void PrintDB(struct Footballer Footballers[]){
	std::cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	std::cout<<" ����� | �������              | ���                  | �������                                  | ��������������       | ������� | ����                           | ����      |"<<"\n";
	std::cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	for (int i = 0; i < MAX; i++) {
		if (strlen(Footballers[i].Surname) != 0) {
			printf(" %5d | %-20s | %-20s | %-40s | %-20s | %7d | %-30s | %9d |\n", Footballers[i].Number, Footballers[i].Surname, Footballers[i].Name, 
				Footballers[i].Role, Footballers[i].Nation, Footballers[i].Age, Footballers[i].Club, Footballers[i].Price);
			std::cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
		}

	}
	ContinueProgramm();
}
void printmenu(void) {
	std::cout<<"������� ����� ��������, ������� ������ ������������:"<<"\n"<<"\n";
	std::cout<<"1. ���� ������ � ������ ��."<<"\n";
	std::cout<<"2. ����� ��."<<"\n";
	std::cout<<"3. ���������� 1-�� ������."<<"\n";
	std::cout<<"4. ����� �� ������ �������."<<"\n";
	std::cout<<"5. �������� ������."<<"\n";
	std::cout<<"6. ���������� �� � ���� (.txt)."<<"\n";
	std::cout<<"7. �������� �� �����."<<"\n";
	std::cout<<"8. �����."<<"\n";
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	std::cout<<"������� ����� ���������� ��� ��������: ";
	std::cin>>del;
	int c = 0;
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
			printf("��������� ��� %d ������� �����",del);
			return;
		}
	}
	printf("��������� ��� %d ������� �� ������",del);
}
void ColumnMenu(void) {
	std::cout << "�������� �� ������ ������� ����� ������������� �����" << "\n";
	std::cout << "1. �����" << "\n";
	std::cout << "2. �������" << "\n";
	std::cout << "3. ���" << "\n";
	std::cout << "4. �������" << "\n";
	std::cout << "5. ��������������" << "\n";
	std::cout << "6. �������" << "\n";
	std::cout << "7. ���������� ����" << "\n";
	std::cout << "8. ����" << "\n";
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
		std::cout << "������� ����� �� 1 �� 99" << "\n";
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
		std::cout << "������� �������" << "\n";
		char SurnameColumn[52];
		std::cin >> SurnameColumn;
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
		std::cout << "������� ���" << "\n";
		char NameColumn[52];
		std::cin >> NameColumn;
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
		std::cout << "������� �������" << "\n";
		char RoleColumn[52];
		std::cin >> RoleColumn;
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
		std::cout << "������� ��������������" << "\n";
		char NationColumn[52];
		std::cin >> NationColumn;
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
		std::cout << "������� �������" << "\n";
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
		std::cout << "������� ���������� ����" << "\n";
		char ClubColumn[52];
		std::cin >> ClubColumn;
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
		std::cout << "������� ����" << "\n";
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
		std::cout<<"�� ������� ������� ����";
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	std::cout<<"\n"<<"���� ������ ��������� � ����������.txt"<<"\n";
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("����������.txt","r");
	if (file==NULL){
	std::cout<<"�� ������� ������� ���� ��� ������"<<"\n";
		return;
	}
	std::cout<<"�������� ���� ������ �� ����������.txt ������� � ������ ������� ������� ���� ������. �������, ��� ������ ����������?(1 - ��, 0 - ���)"<<"\n";
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	std::cout<<"\n"<<"���� ������ ������� ��������� � ����������.txt"<<"\n";
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
			std::cout<<"�� ������ �������� ��?(1 - ��, 0 - ���)" << "\n" << "\n";
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				std::cout<< "\n" << "���� ������ ������ � ������." << "\n";
				while (1) {
					AddFootballer(Footballers);
					std::cout<<"�������� ����������? (1 - ��, 0 - ���):" << "\n";
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
		case 7:
			LoadDB(Footballers);
			ContinueProgramm();
			break;
		case 8:
			std::cout<<"����� �� ���������." << "\n";
			exit(0);
		default:
			std::cout<<"�� ����� ��������, �� �������� � ���������� �� 1-8, ���������� ��� ���";
		}

	}
}
