// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <iomanip>
//---------------------------------------------------------------------------

int main()
{
  TMatrix<int> a(2000), b(2000);
  TMatrix<int>a1(4000), b1(4000);
  TMatrix<int>a2(8000), b2(8000);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Замер реальной времени работы операций"
    << endl;
  time_t s1, s2, s3, e1, e2, e3;
  for (i = 0; i < 2000; i++)
    for (j = i; j < 2000; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  for (i = 0; i < 4000; i++)
	  for (j = i; j < 4000; j++)
	  {
		  a1[i][j] = i * 10 + j;
		  b1[i][j] = (i * 10 + j) * 100;
	  }
  for (i = 0; i < 8000; i++)
	  for (j = i; j < 8000; j++)
	  {
		  a2[i][j] = i * 10 + j;
		  b2[i][j] = (i * 10 + j) * 100;
	  }
  s1 = clock();
  a + b;
  e1 = clock();
  s2 = clock();
  a1 + b1;
  e2 = clock();
  s3 = clock();
  a2 + b2;
  e3 = clock();
  cout << (double)(e1 - s1) / CLOCKS_PER_SEC << 
	  endl <<(double)(e2 - s2) / CLOCKS_PER_SEC << endl << (double)(e3 - s3) / CLOCKS_PER_SEC << endl;
  time_t s4, e4, s5, e5, s6, e6;
  TVector<int>A1(1000000), B1(1000000),A2(2000000),B2(2000000),A3(3000000),B3(3000000);
  for (int i = 0; i < 1000000; i++)
  {
	  A1[i] = i;
	  B1[i] = i;
  }
  for (int i = 0; i < 2000000; i++)
  {
	  A2[i] = i;
	  B2[i] = i;
  }
  for (int i = 0; i < 3000000; i++)
  {
	  A3[i] = i;
	  B3[i] = i;
  }
  s4 = clock();
  A1*B1;
  e4 = clock();
  s5 = clock();
  A2*B2;
  e5 = clock();
  s6 = clock();
  A3*B3;
  e6 = clock();

  cout << (double)(e4 - s4) / CLOCKS_PER_SEC << endl << (double)(e5 - s5) / CLOCKS_PER_SEC <<
	  endl << (double)(e6 - s6) / CLOCKS_PER_SEC << endl;
	return 0;
}
//---------------------------------------------------------------------------
