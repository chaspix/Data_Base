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
	std::cout << "\n" << "\n" << "Нажмите Enter для продолжения....";
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
} // нахождение свободного места для ввода
void AddFootballer(struct Footballer Footballers[]) {
	int n = FindSlot(Footballers);
	if (n == -1) {
		std::cout<<"База данных заполнена."<<"\n";
		return;
	}
	
	Footballer fb;
	int c = 0;
	std::cout<<"\n"<<"Введите номер футболиста : ";
	std::cin>>fb.Number;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	std::cout<<"\n"<<"Введите фамилию : ";
	fgets(fb.Surname,70,stdin);
	char* newsurnameline = strrchr(fb.Surname,'\n'); //поиск последнего \n
	if (newsurnameline) {
		*newsurnameline = '\0';
	}
	std::cout<<"\n"<<"Введите имя : ";
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	std::cout<<"\n"<<"Введите позицию футболиста : ";
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	std::cout<<"\n"<<"Введите национальность : ";
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	std::cout<<"\n"<<"Введите возраст : ";
	std::cin>>fb.Age;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	std::cout<<"\n"<<"Введите футбольный клуб, в котором играет футболист : ";
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	std::cout<<"\n"<<"Введите стоимость футболиста на трансферном рынке : ";
	std::cin>>fb.Price;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	std::cout << "\n" << "Футболист добавлен" << "\n" << "\n";
}
void PrintDB(struct Footballer Footballers[]){
	std::cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	std::cout<<" Номер | Фамилия              | Имя                  | Позиция                                  | Национальность       | Возраст | Клуб                           | Цена      |"<<"\n";
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
	std::cout<<"Введите номер действия, которое хотите использовать:"<<"\n"<<"\n";
	std::cout<<"1. Ввод данных в пустую БД."<<"\n";
	std::cout<<"2. Вывод БД."<<"\n";
	std::cout<<"3. Добавление 1-ой строки."<<"\n";
	std::cout<<"4. Поиск по любому столбцу."<<"\n";
	std::cout<<"5. Удаление строки."<<"\n";
	std::cout<<"6. Сохранение БД в файл (.txt)."<<"\n";
	std::cout<<"7. Выгрузка из файла."<<"\n";
	std::cout<<"8. Выход."<<"\n";
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	std::cout<<"Введите номер футболиста для удаления: ";
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
			printf("Футболист под %d номером удалён",del);
			return;
		}
	}
	printf("Футболист под %d номером не найдем",del);
}
void ColumnMenu(void) {
	std::cout << "Выберите по какому столбцу будет производиться поиск" << "\n";
	std::cout << "1. Номер" << "\n";
	std::cout << "2. Фамилия" << "\n";
	std::cout << "3. Имя" << "\n";
	std::cout << "4. Позиция" << "\n";
	std::cout << "5. Национальность" << "\n";
	std::cout << "6. Возраст" << "\n";
	std::cout << "7. Футбольный клуб" << "\n";
	std::cout << "8. Цена" << "\n";
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
		std::cout << "Введите номер от 1 до 99" << "\n";
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
		std::cout << "Введите фамилию" << "\n";
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
		std::cout << "Введите имя" << "\n";
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
		std::cout << "Введите позицию" << "\n";
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
		std::cout << "Введите национальность" << "\n";
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
		std::cout << "Введите возраст" << "\n";
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
		std::cout << "Введите футбольный клуб" << "\n";
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
		std::cout << "Введите цену" << "\n";
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
		std::cout<<"Не удалось открыть файл";
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	std::cout<<"\n"<<"База данных сохранена в Футболисты.txt"<<"\n";
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("Футболисты.txt","r");
	if (file==NULL){
	std::cout<<"Не удалось открыть файл для чтения"<<"\n";
		return;
	}
	std::cout<<"Загрузка базы данных из Футболисты.txt приведёт к полной очистке текущей базы данных. Уверены, что хотите продолжить?(1 - да, 0 - нет)"<<"\n";
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	std::cout<<"\n"<<"База данных успешно сохранена в Футболисты.txt"<<"\n";
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
			std::cout<<"Вы хотите очистить БД?(1 - да, 0 - нет)" << "\n" << "\n";
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				std::cout<< "\n" << "База данных готова к выводу." << "\n";
				while (1) {
					AddFootballer(Footballers);
					std::cout<<"Добавить футболиста? (1 - да, 0 - нет):" << "\n";
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
			std::cout<<"Выход из программы." << "\n";
			exit(0);
		default:
			std::cout<<"Вы ввели значение, не входящее в промежуток от 1-8, попробуйте ещё раз";
		}

	}
}
