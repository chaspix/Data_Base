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
	cout << "\n" << "\n" << "Нажмите Enter для продолжения...";
	int c=0;
	while ((c = getchar()) != '\n' && c != EOF) { //мы проходимся по каждому символу, сдвигаем курсор (каретку), до тех пор, пока не наткнёмся на конец строки или конец файла.
	}												
	getchar(); 
	ClearScreen();
}
void RussLang(void) {
	SetConsoleCP(1251); // установление кодировки программы на windows 1251
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
		cout<<"База данных заполнена."<<"\n";
		return;
	}
	
	Footballer fb;
	int c = 0;
	cout<<"\n"<<"Введите номер футболиста : ";
	cin>>fb.Number;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	cout<<"\n"<<"Введите фамилию : ";
	fgets(fb.Surname,70,stdin); // stdin - стандартный поток ввода
	char* newsurnameline = strrchr(fb.Surname,'\n'); // strrchr - указатель на последнее вхождение символа в строку
	if (newsurnameline) { // проверка на существование последнего вхождения \n
		*newsurnameline = '\0'; // * - разименование(получение значения) и изменение значения на \0 (конец строки)
	}
	cout<<"\n"<<"Введите имя : ";
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	cout<<"\n"<<"Введите позицию футболиста : ";
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	cout<<"\n"<<"Введите национальность : ";
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	cout<<"\n"<<"Введите возраст : ";
	cin>>fb.Age;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	cout<<"\n"<<"Введите футбольный клуб, в котором играет футболист : ";
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	cout<<"\n"<<"Введите стоимость футболиста на трансферном рынке : ";
	cin>>fb.Price;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	cout << "\n" << "Футболист добавлен" << "\n" << "\n";
}
void PrintDB(struct Footballer Footballers[]){
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	cout<<" Номер | Фамилия              | Имя                  | Позиция                                  | Национальность       | Возраст | Клуб                           | Цена      |"<<"\n";
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
	cout<<"Введите номер действия, которое хотите использовать:"<<"\n"<<"\n";
	cout<<"1. Ввод данных в пустую БД."<<"\n";
	cout<<"2. Вывод БД."<<"\n";
	cout<<"3. Добавление 1-ой строки."<<"\n";
	cout<<"4. Поиск по любому столбцу."<<"\n";
	cout<<"5. Удаление строки."<<"\n";
	cout<<"6. Сохранение БД в файл (.txt)."<<"\n";
	cout<<"7. Выгрузка из файла."<<"\n";
	cout<<"8. Выход."<<"\n";
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	cout<<"Введите номер футболиста для удаления: ";
	cin>>del;
	int c = 0;
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number == del) {
			memset(&Footballers[i],0,sizeof(Footballer));
			cout << "Футболист удалён" << "\n";
			return;
		}
	}
	printf("Футболист под %d номером не найдем",del);
}
void ColumnMenu(void) {
	cout << "Выберите по какому столбцу будет производиться поиск" << "\n";
	cout << "1. Номер" << "\n";
	cout << "2. Фамилия" << "\n";
	cout << "3. Имя" << "\n";
	cout << "4. Позиция" << "\n";
	cout << "5. Национальность" << "\n";
	cout << "6. Возраст" << "\n";
	cout << "7. Футбольный клуб" << "\n";
	cout << "8. Цена" << "\n";
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
		cout << "Введите номер от 1 до 99" << "\n";
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
		cout << "Введите фамилию" << "\n";
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
		cout << "Введите имя" << "\n";
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
		cout << "Введите позицию" << "\n";
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
		cout << "Введите национальность" << "\n";
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
		cout << "Введите возраст" << "\n";
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
		cout << "Введите футбольный клуб" << "\n";
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
		cout << "Введите цену" << "\n";
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
	FILE* file = fopen("Футболисты.txt","w");
	if (file == NULL) {
		cout<<"Не удалось открыть файл";
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	cout<<"\n"<<"База данных сохранена в Футболисты.txt"<<"\n";
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("Футболисты.txt","r");
	if (file==NULL){
	cout<<"Не удалось открыть файл для чтения"<<"\n";
		return;
	}
	cout<<"Загрузка базы данных из Футболисты.txt приведёт к полной очистке текущей базы данных. Уверены, что хотите продолжить?(1 - да, 0 - нет)"<<"\n";
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	cout<<"\n"<<"База данных успешно сохранена в Футболисты.txt"<<"\n";
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
			cout<<"Вы хотите очистить БД?(1 - да, 0 - нет)" << "\n" << "\n";
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				cout<< "\n" << "База данных готова к выводу." << "\n";
				while (1) {
					AddFootballer(Footballers);
					cout<<"Добавить футболиста? (1 - да, 0 - нет):" << "\n";
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
			cout<<"Выход из программы." << "\n";
			exit(0);
		default:
			if (m == 0) {
				cout << "База данных пуста" << "\n" << "\n";
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
				cout << "Вы ввели значение, не входящее в промежуток от 1-8, попробуйте ещё раз";
			}
		}

	}
}


