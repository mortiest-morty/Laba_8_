#include "Header.h"

void findAns(int** table, int N, int B, int* c, int& volume, int* d, int** count) {
	using namespace std;

	if (N == 0 || B == 0) return;  

	if (table[N][B] != table[N - 1][B]) {  
		cout << N << ' ';
		volume += d[N];
		findAns(table, N - 1, B - c[N], c, volume, d, count);
	}
	else { 
		findAns(table, N - 1, B, c, volume, d, count);
	}
}

void task1() {
	using namespace std;

	int** table;
	int** count;  
	int N, B, volume = 0;
	int* c;
	int* d;

	fstream f1;
	f1.open("d.txt", ios::in);
	f1 >> N >> B;

	c = new int[N + 1];
	d = new int[N + 1];
	table = new int* [N + 1];
	count = new int* [N + 1];  

	for (int i = 1; i <= N; i++) {
		f1 >> c[i];
	}
	for (int i = 1; i <= N; i++) {
		f1 >> d[i];
	}
	for (int i = 0; i <= N; i++) {
		table[i] = new int[B + 1];
		count[i] = new int[B + 1];  
	}

	
	for (int i = 0; i <= B; i++) {
		table[0][i] = 0;
		count[0][i] = 0;  
	}
	for (int i = 0; i <= N; i++) {
		table[i][0] = 0;
		count[i][0] = 0; 
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= B; s++) {
			if (s >= c[k]) {
				int weight1 = table[k - 1][s];
				int count1 = count[k - 1][s];

				int weight2 = table[k - 1][s - c[k]] + c[k];
				int count2 = count[k - 1][s - c[k]] + 1;

				if (weight2 > weight1) {
					table[k][s] = weight2;
					count[k][s] = count2;
				}
				else if (weight2 < weight1) {
					table[k][s] = weight1;
					count[k][s] = count1;
				}
				else {  
					if (count2 > count1) {
						table[k][s] = weight2;
						count[k][s] = count2;
					}
					else {
						table[k][s] = weight1;
						count[k][s] = count1;
					}
				}
			}
			else {
				table[k][s] = table[k - 1][s];
				count[k][s] = count[k - 1][s];
			}
		}
	}

	cout << "Максимальный вес: " << table[N][B] << endl;
	cout << "Количество предметов: " << count[N][B] << endl;  
	cout << "Номера вещей, которые надо взять: ";
	findAns(table, N, B, c, volume, d, count);
	cout << endl;
	cout << "Суммарный объем: " << volume << endl << endl;
}

void Solve(int n, int** a, int** b) {
	using namespace std;

	int i, j, max = 0;
	b[n-1][n-1] = a[n-1][n-1];
	for (i = n-2; i >= 0; i--) b[i][n - 1] = b[i+1][n-1] + a[i][n - 1];
	for (j = n-2; j >= 0; j--) b[n-1][j] = b[n-1][j + 1] + a[n-1][j];
	for (i = n-2; i >= 0; i--)
		for (j = n-2; j >= 0; j--) {
			if (b[i + 1][j] > b[i][j + 1]) {
				max = b[i + 1][j];
			}
			else {
				max = b[i][j + 1];
			}
			b[i][j] = max + a[i][j];
		}
}

void steps(std::string& motion, int n, int** b) {
	using namespace std;

	int i = n - 1, j = n - 1;

	while (i > 0 || j > 0) {
		if (i == 0) {  
			motion = "L" + motion;
			j--;
		}
		else if (j == 0) {  
			motion = "U" + motion;  
			i--;
		}
		else {
			if (b[i - 1][j] > b[i][j - 1]) {
				motion = "U" + motion;  
				i--;
			}
			else {
				motion = "L" + motion; 
				j--;
			}
		}
	}
}

void task2() {
	using namespace std;

	int n, i, j;
	int** pole1, ** pole2;
	string motion;
	
	fstream f1, f2;
	f1.open("mzlff.txt", ios::in);
	f2.open("dreik.txt", ios::out);

	f1 >> n;
	pole1 = new int* [n];
	pole2 = new int* [n];
	for (i = 0; i < n; i++)
		pole1[i] = new int[n];
	for (i = 0; i < n; i++)
		pole2[i] = new int[n];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			f1 >> pole1[i][j];

	Solve(n, pole1, pole2);
	steps(motion, n, pole2);

	f2 << "\n" << "Максимальная сумма монет: " << pole2[0][0] << "\n" << "Путь = " << motion << "\n";
	
	f1.close();
	f2.close();
}


int input_k(int k) {
	using namespace std;

	cout << "Введите число k = ";
	cin >> k;
	while (k < 2 || k>10) {
		cout << "Введите 2<=k<=10 = ";
		cin >> k;
	}
	return k;
}

int input_n(int n) {
	using namespace std;

	cout << "Введите число n = ";
	cin >> n;
	while (n < 1 || n>20) {
		cout << "Введите 1<n<20 = ";
		cin >> n;
	}
	return n;
}

int checking_usl(int n, int k, int change) {
	using namespace std;

	if (n + k > 26) {
		cout << "Неправильный ввод! Условие (n+k<26) не выполняется" << endl;
		cout << "1 - поменять число k\n 2 - поменять число n\n Введите цифру: ";
		cin >> change;
		while (change < 1 || change > 2) {
			cout << "Введите цифру 1-2: ";
			cin >> change;
		}
	}
	return change;
}

void task3(){
	using namespace std;

	int i, k=0, n=0, nz, _nz, oz, _oz, tz, _tz, change = 0, AllNumbersAmount, answ;

	k = input_k(k);
	n = input_n(n);

	change = checking_usl(n, k, change);

	switch (change) {
	case 1:
		k = input_k(k);
		break;
	case 2:
		n = input_n(n);
		break;
	}

	nz = k - 1;
	oz = 0;
	tz = 0;

	for (i = 2; i <= n; i++)
	{
		_nz = nz;
		_oz = oz;
		_tz = tz;
		nz = _nz * (k - 1) + _oz * (k - 1);
		oz = _nz;
		tz = _tz * k + _oz;
	}

	cout << "Количество чисел, в записи которых содержится >=2 подряд идущих нулей = " << tz << endl;
}
