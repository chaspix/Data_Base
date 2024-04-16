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
	printf("\n\nНажмите Enter для продолжения....");
	int c=0;
	while ((c = getchar()) != '\n' && c != EOF) { 
	} //очистка ввода
	getchar(); //запрос символа
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
		printf("База данных заполнена.\n");
		return;
	}
	
	Footballer fb;
	int c = 0;
	printf("Введите номер футболиста: ");
	scanf("%d",&fb.Number);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	printf("\nВведите фамилию: ");
	fgets(fb.Surname,70,stdin);
	char* newsurnameline = strrchr(fb.Surname,'\n'); //поиск последнего \n
	if (newsurnameline) {
		*newsurnameline = '\0';
	}
	printf("\nВведите имя: ");
	fgets(fb.Name,70,stdin);
	char* newnameline = strrchr(fb.Name,'\n');
	if (newnameline) {
		*newnameline = '\0';
	}
	printf("\nВведите позицию футболиста: ");
	fgets(fb.Role,70,stdin);
	char* newroleline = strrchr(fb.Role, '\n');
	if (newroleline) {
		*newroleline = '\0';
	}
	printf("\nВведите национальность: ");
	fgets(fb.Nation,70,stdin);
	char* newnationline = strrchr(fb.Nation, '\n');
	if (newnationline) {
		*newnationline = '\0';
	}
	printf("\nВведите возраст: ");
	scanf("%d",&fb.Age);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	printf("\nВведите футбольный клуб, в котором играет футболист: ");
	fgets(fb.Club,70,stdin);
	char* newclubline = strrchr(fb.Club, '\n');
	if (newclubline) {
		*newclubline = '\0';
	}
	printf("\nВведите стоимость футболиста на трансферном рынке: ");
	scanf("%d",&fb.Price);
	while ((c = getchar()) != '\n' && c != EOF) {
	}
	Footballers[n] = fb;
	printf("Футболист добавлен\n\n");
}
void PrintDB(struct Footballer Footballers[]){
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" Номер | Фамилия              | Имя                  | Позиция                                  | Национальность       | Возраст | Клуб                           | Цена      |\n");
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
	printf("Введите номер действия, которое хотите использовать:\n\n");
	printf("1. Ввод данных в пустую БД.\n");
	printf("2. Вывод БД.\n");
	printf("3. Добавление 1-ой строки.\n");
	printf("4. Поиск по любому столбцу.\n");
	printf("5. Удаление строки.\n");
	printf("6. Сохранение БД в файл (.txt).\n");
	printf("7. Выгрузка из файла.\n");
	printf("8. Выход.\n");
}
void DeleteRow(struct Footballer Footballers[]) {
	int del;
	printf("Введите номер футболиста для удаления: ");
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
			printf("Футболист под %d номером удалён.\n", del);
			return;
		}
	}
	printf("Футболист под %d номером не найден.\n",del);
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
	FILE* file = fopen("Футболисты.txt","w");
	if (file == NULL) {
		printf("Не удалось открыть файл");
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (Footballers[i].Number != 0) {
			fwrite(&Footballers[i],sizeof(Footballer),1,file);
		}
	}
	fclose(file);
	printf("База данных сохранена в Футболисты.txt");
}
void LoadDB(struct Footballer Footballers[]) {
	FILE* file = fopen("Футболисты.txt","r");
	if (file==NULL){
		printf("Не удалось открыть файл для чтения\n");
		return;
	}
	printf("Загрузка базы данных из Футболисты.txt приведёт к полной очистке текущей базы данных. Уверены, что хотите продолжить?(1 - да, 0 - нет)");
	if (GetVibor()!=1) {
		fclose(file);
		return;
	}
	int i = 0;
	while (fread(&Footballers[i], sizeof(Footballer), 1, file) == 1 && i < MAX) {
		i++;
	}
	fclose(file);
	printf("База данных успешно сохранена в Футболисты.txt");
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
			printf("Вы хотите очистить БД?(1 - да, 0 - нет)\n)");
			if (GetVibor() != 1) {
				ContinueProgramm();
				continue;
			}
			else {
				InitDB(Footballers);
				printf("База данных готова к выводу.\n");
				while (1) {
					AddFootballer(Footballers);
					printf("Добавить футболиста? (1 - да, 0 - нет):\n");
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
			printf("Выход из программы.\n");
			exit(0);
		default:
			printf("Вы ввели значение, не входящее в промежуток от 1-8, попробуйте ещё раз");
		}

	}
}
