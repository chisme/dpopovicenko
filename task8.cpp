#include <iostream>
#include <ctime>
using namespace std;

int arrayUnique(int* array, int size) // функция, определяющая элементы массива в единственном экземпляре
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (array[i] == array[j]) // если найден одинаковый элемент
			{
				for (int shift = j; shift < size - 1; ++shift)
				{
					// выполнить сдвиг всех остальных элементов массива на -1, начиная со следующего элемента, после найденного дубля
					array[shift] = array[shift + 1];
				}
				size -= 1; // уменьшить размер массива на 1

				if (array[i] == array[j]) // если следующий элемент - дубль
				{
					j--; // выполнить переход на предыдущий элемент     
				}
			}
		}
	}
	return size;
}
void InitArray(int* array, int size) // заполняем массив
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 10;
	}
}
void ShowArray(int* array, int size) // выводим массив на экран
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i];
	}
	cout << endl;
}

int main()
{
	cout << "Task 1" << endl;
	cout << endl;
	// Объявите указатель на массив типа double и предложите пользователю выбрать его размер.
	// Далее напишите четыре блока(можно функции) : 
	// 1. первая должна выделить память для массива
	// 2. вторая  – заполнить ячейки данными
	// 3. третья – показать данные на экран
	// 4. четвертая – освободить занимаемую память
	
	srand(time(0));
	int pSize; // переменная
	cout << "Wich size of Arr you need? " << endl;
	cin >> pSize;

	// создаем динамический массив
	double* pArr = new double[pSize];
	
	// заполняем масив данными 
	for (int i = 0; i < pSize; ++i) 
	{
		pArr[i] = rand() % 10 ;
	}
	
	// выводим массив на экран
	for (int i = 0; i < pSize; ++i)
	{
		cout << pArr[i];
	}
	cout << endl;

	// удаляем динамический массив
	delete pArr;
	cout << endl;
	cout << endl;

	cout << "Task 2" << endl;
	cout << endl;
		// Объявите указатель на массив типа int и выделите память для 12 - ти элементов.
	// Необходимо написать функцию, которая поменяет значения четных и нечетных ячеек массива.
	// Например, есть массив из 4 - х элементов : 1 2 3 4 5 6
	// Результат : 2 1 4 3 6 5
	int size_2 = 12;
	int* pArr2 = new int[size_2];

	InitArray(pArr2, size_2); // заполняем масив данными 
	ShowArray(pArr2, size_2); // выводим массив на экран
	
	// меняем элементы массива местами
	for (int i = 0; i < size_2; ++i)
	{
		int pArr_temp=0;
		if (i % 2 == 0)
		{
			pArr_temp = pArr2[i];
			pArr2[i] = pArr2[i + 1];
			pArr2[i+1] = pArr_temp;
		}
	}

	ShowArray(pArr2, size_2); // выводим массив на экран 2-й раз
	
	delete pArr2;
	cout << endl;
	cout << endl;

	cout << "Task 3" << endl;
	cout << endl;
	// Написать функцию: 
	// int* arrayUnique(int* array, int size), 
	// которая будет удалять из массива дубликаты элементов, и в конце работы вернёт новый массив с новым размером. 
	// (размер массива – глобальная переменная).
	// Для решения этой задачи организовать заполнение массива случайными числами.
	// Результат работы программы показан ниже :
	// 8  2  4  0  6  8  9  3  7  9  7  4  9  9  3  5  1  2  2  9
	// 8  2  4  0  6  9  3  7  5  1
	
	int size_3 = 20;
	int* pArr3 = new int[size_3];

	InitArray(pArr3, size_3); // заполняем масив данными 
	ShowArray(pArr3, size_3); // выводим массив на экран
	// выводим второй массив
	for (int i = 0; i < arrayUnique(pArr3, size_3); ++i)
	{
		cout << pArr3[i]; // печать элементов массива
	}
	delete pArr3;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Task 4" << endl;
	cout << endl;
	// Задан массив с количеством элементов N.
	// Сформировать два массива : в первый включить элементы исходного массива с четными номерами, 
	// а во второй — с нечетными.
	int size_8;
	cout << "Wich size you need? " << endl;
	cin >> size_8;
	int* pArr8 = new int[size_8];

	InitArray(pArr8, size_8); // заполняем масив данными 
	ShowArray(pArr8, size_8); // выводим массив на экран

	for (int i = 0; i < *pArr8; ++i)
	{
		if ((pArr8[i] % 2) != 0) // нечётные числа
			cout << pArr8[i];
	}
	cout << endl;

	for (int i = 0; i < *pArr8; ++i)
	{
		if ((pArr8[i] % 2) == 0) // чётные числа
			cout << pArr8[i];
	}
	delete pArr8;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Task 5" << endl;
	cout << endl;
	// 5. Написать программу, которая создает два массива(размер задает пользователь) и склеивает(объединяет) их в один(третий) массив.
	int size_5, size_6;
	cout << "Wich size of pArr5 you need? " << endl;
	cin >> size_5;
	cout << "Wich size of pArr6 you need? " << endl;
	cin >> size_6;

	int* pArr5 = new int[size_5];
	InitArray(pArr5, size_5); // заполняем масив pArr5 данными 
	ShowArray(pArr5, size_5); // выводим массив pArr5 на экран
	
	int* pArr6 = new int[size_6];
	InitArray(pArr6, size_6); // заполняем масив pArr6 данными 
	ShowArray(pArr6, size_6); // выводим массив pArr6 на экран
	
	int size_7 = size_5 + size_6;
	cout << size_7 << endl;
	// создаем массив pArr7
	int* pArr7 = new int[size_7];
	// заполняем массив // создаем массив pArr7 элементами двух предыдущих
	for (int i = 0; i < size_7; ++i)
	{
		if (i < size_5)
			pArr7[i] = pArr5[i];
		else
			pArr7[i] = pArr6[i-size_5];
	}

	ShowArray(pArr7, size_7); // выводим массив pArr7 на экран
	cout << endl;
	delete pArr5, pArr6, pArr7;

	system("pause");
	return 0;
}
