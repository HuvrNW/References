#include <iostream>
#include <cstdlib>
#include <ctime>

//6. Ссылки как параметры функции.
void my_swap(int n1, int n2);
void p_swap(int* pn1, int* pn2);
void ref_swap(int& ref_n1, int& ref_n2);

//7. Ссылки как результат работы функции.
int mx[10][2];

int& func(int index);
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
T& max_arr(T arr[], const int length);

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10, m = 20;
	
	//7. Ссылки как результат работы функции.
	/*
	for (int i = 0; i < 10; i++) {
		std::cout << " Ряд №" << i + 1 << ": ";
		std::cin >> mx[i][0];
		func(i) = mx[i][0];
	}

	std::cout << " Итоговвый массив --> \n";
	for (int i = 0; i < 10; i++)
		std::cout << mx[i][0] << "\t" << func(i) << '\n';
	*/

	const int size = 5;
	int arr[size]{ 4, 2, 7, 1, 6 };
	std::cout << " Изначальный массив --> ";
	show_arr(arr, size);
	std::cout << " Максимум = " << max_arr(arr, size) << '\n';
	std::cout << " Обнуляем максимум...\n Итоговый массив --> ";
	max_arr(arr, size) = 0;
	show_arr(arr, size);

	//6. Ссылки как параметры функции.
	/*
	std::cout << n << ' ' << m << '\n';
	// Удобно, но неработает --> my_swap(n, m);
	// Работает, но не удобно --> p_swap(&n, &m);
	ref_swap(n, m);
	std::cout << n << ' ' << m << '\n';
	*/

	//1. Нейтральный указатель.
	/*
	  // Первый способ. int* pn = 0;	     
	 // Второй способ.int* pn = NULL;   
	// Третий способ.int* pn = nullptr; 
	
	if (pn == nullptr)
		std::cout << " Указатель неинициализирован\n";
	else
		std::cout << *pn << '\n';
	*/

	int x = 6, y = 7, z = 42;
	//2. Указатель на константу. Используя разыменование нельзя поменять значение переменной, на которую указывает.
	/*
	int const* px = &x;
	std::cout << *px << '\n';
	px = &y;
	std::cout << *px << '\n';
	// Ошибка --> *px = 15;
	*/

	//3. Константный указатель.
	/*
	const int* py;
	py = &y;
	std::cout << *py << '\n';
	py = &z;
	std::cout << *py << '\n';
	// Ошибка --> *pb = 35;
	*/

	//4. Константный указатель на константу. Нельзя менять значение переменной, а также нельзя перенаправлять указатель.
	/* 
	const int* const pz = &z;
	std::cout << *pz << '\n';
	// Ошибка --> pc = &x;
	// Ошибка --> *pc = 35;
	*/

	//5. Ссылки на переменную. ( тип_данных &имя_ссылки = переменная; ) 
	/*
	// Области применения ссылок: 
	// 1. Работа с объектами из разных частей кода. 
	// 2. Экономия выделяемой памяти.
	// Ссылки - альтернативные имена (псевдонимы) уже существующих переменных.

	int& ref_n = n; // создаем ссылку, связанную с переменной n. 
	std::cout << " n = " << n << '\n';
	std::cout << " ref_n = " << ref_n << '\n';
	ref_n = 15;
	std::cout << " Новая n = " << n << '\n';
	*/
	
	return 0;
}

//6. Ссылки как параметры функции.
void my_swap(int n1, int n2) {
	int x = n1;
	n1 = n2;
	n2 = x;
}
void p_swap(int* pn1, int* pn2) {
	int x = *pn1;
	*pn1 = *pn2;
	*pn2 = x;
}
void ref_swap(int& ref_n1, int& ref_n2) {
	int x = ref_n1;
	ref_n1 = ref_n2;
	ref_n2 = x;
}

//7. Ссылки как результат работы функции.
int& func(int index) {
	return mx[index][1];
}
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
T& max_arr(T arr[], const int length) {
	int i_max = 0;
	for (int i = 1; i < length; i++)
		i_max = arr[i] > arr[i_max] ? i : i_max;
	return arr[i_max];
}