#include <iostream>
#include <cstdlib>
#include <ctime>

//6. ������ ��� ��������� �������.
void my_swap(int n1, int n2);
void p_swap(int* pn1, int* pn2);
void ref_swap(int& ref_n1, int& ref_n2);

//7. ������ ��� ��������� ������ �������.
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
	
	//7. ������ ��� ��������� ������ �������.
	/*
	for (int i = 0; i < 10; i++) {
		std::cout << " ��� �" << i + 1 << ": ";
		std::cin >> mx[i][0];
		func(i) = mx[i][0];
	}

	std::cout << " ��������� ������ --> \n";
	for (int i = 0; i < 10; i++)
		std::cout << mx[i][0] << "\t" << func(i) << '\n';
	*/

	const int size = 5;
	int arr[size]{ 4, 2, 7, 1, 6 };
	std::cout << " ����������� ������ --> ";
	show_arr(arr, size);
	std::cout << " �������� = " << max_arr(arr, size) << '\n';
	std::cout << " �������� ��������...\n �������� ������ --> ";
	max_arr(arr, size) = 0;
	show_arr(arr, size);

	//6. ������ ��� ��������� �������.
	/*
	std::cout << n << ' ' << m << '\n';
	// ������, �� ���������� --> my_swap(n, m);
	// ��������, �� �� ������ --> p_swap(&n, &m);
	ref_swap(n, m);
	std::cout << n << ' ' << m << '\n';
	*/

	//1. ����������� ���������.
	/*
	  // ������ ������. int* pn = 0;	     
	 // ������ ������.int* pn = NULL;   
	// ������ ������.int* pn = nullptr; 
	
	if (pn == nullptr)
		std::cout << " ��������� �����������������\n";
	else
		std::cout << *pn << '\n';
	*/

	int x = 6, y = 7, z = 42;
	//2. ��������� �� ���������. ��������� ������������� ������ �������� �������� ����������, �� ������� ���������.
	/*
	int const* px = &x;
	std::cout << *px << '\n';
	px = &y;
	std::cout << *px << '\n';
	// ������ --> *px = 15;
	*/

	//3. ����������� ���������.
	/*
	const int* py;
	py = &y;
	std::cout << *py << '\n';
	py = &z;
	std::cout << *py << '\n';
	// ������ --> *pb = 35;
	*/

	//4. ����������� ��������� �� ���������. ������ ������ �������� ����������, � ����� ������ �������������� ���������.
	/* 
	const int* const pz = &z;
	std::cout << *pz << '\n';
	// ������ --> pc = &x;
	// ������ --> *pc = 35;
	*/

	//5. ������ �� ����������. ( ���_������ &���_������ = ����������; ) 
	/*
	// ������� ���������� ������: 
	// 1. ������ � ��������� �� ������ ������ ����. 
	// 2. �������� ���������� ������.
	// ������ - �������������� ����� (����������) ��� ������������ ����������.

	int& ref_n = n; // ������� ������, ��������� � ���������� n. 
	std::cout << " n = " << n << '\n';
	std::cout << " ref_n = " << ref_n << '\n';
	ref_n = 15;
	std::cout << " ����� n = " << n << '\n';
	*/
	
	return 0;
}

//6. ������ ��� ��������� �������.
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

//7. ������ ��� ��������� ������ �������.
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