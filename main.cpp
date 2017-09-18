#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <clocale>
#include <fstream>

#include "./headers/json.hpp"


using namespace std;
using json = nlohmann::json;

void main() {
	setlocale(LC_CTYPE, "rus");

	int n = 10;

	double *y = new double[n];
	double *x = new double[n];

	json j; // json массив для вывода данных в графике, туда запишутся два массива x и y

	x[0] = -3; //начальное значение
	y[0] = x[0] * x[0]; // для примера функция y(x) = x*x

	for (int i = 1; i < n; i++) 
	{ //цикл для вычисления значений
		x[i] = x[i-1] + 0.2;
		y[i] = x[i]*x[i];
	}

	for (int i = 0; i < n; i++)
	{ //запись массивов в json-файл для вывода в график
		j["x"][i] = x[i];
		j["y"][i] = y[i];
	}

	ofstream fout("data.json"); // создаём объект класса ofstream для записи
	fout << "data = '" << j << "';"; // запись строки в файл
	fout.close(); // закрываем файл

	cout << "x = " << j["x"] << endl << "y = " << j["y"] << endl;
}