﻿

#include <iostream>
#include <fstream>
#define N 3000
#define SYMBS 33

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fin("text.txt");

    char buff[100];

    for (int i = 0; i < 100; i++)
        buff[i] = 0;

    char words[N][100];
    int k = 0;

    while (!fin.eof())      // read
    {
        fin >> buff;

        for (int i = 0; i < 100; i++)
        {
            words[k][i] = buff[i];
            k++;
        }

        for (int i = 0; i < 100; i++)
        {
            buff[i] = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (words[i][j] >= 'а' && words[i][j] <= 'я')     // меняем регистр на строчные буквы
                words[i][j] -= 'а' - 'А';
        }
    }

    int kol = 0;   // количество букв в слове
    bool flag = false;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; words[i][j]!=0; j++)
        {
            // найти первое нулевое значение, пройтись по всей строке
            
            kol++;     

        }

        int m = 0;    //счетчик
        int n = kol;    //изменяемое количество букв
        

        while (n > 0)   
        {
            for (int j = 0; j < kol; j++)
            {
                if (words[i][j] == words[i][n - 1])   // сравнение первой и последней буквы
                    m++;     // счетчик +1
                n--;     // последнюю букву убираем. первая убирается самим циклом
            }
        }

        if (m == (kol /= 2))   // если счетчик = половине количества бувк
        {
            flag = true;
        }
        
        if (flag)
            break;

    }

    int count = 0;

    int stock[100];    //счетчик согласных
    for (int i = 0; i < 100; i++)
    {
        stock[i] = 0;
    }

    if (flag == false)  // если нет палиндрома
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; words[i][j] != 0; j++)   // количество букв в слове
            {
                count++;
            }

            for (int j = 0; j < count; j++)     // количество согласных в слове
            {
                if ((words[i][j] != 'а') ||
                    (words[i][j] != 'е') ||
                    (words[i][j] != 'ё') ||
                    (words[i][j] != 'и') ||
                    (words[i][j] != 'о') ||
                    (words[i][j] != 'у') ||
                    (words[i][j] != 'ы') ||
                    (words[i][j] != 'э') ||
                    (words[i][j] != 'ю') ||
                    (words[i][j] != 'я'))
                {
                    stock[i]++;
                }
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k-1; j++)
            {
                if (stock[i] < stock[j])
                {
                    int tmp = stock[i];
                    stock[i] = stock[j];
                    stock[j] = tmp;

                    for (int h = 0; h < 100; h++)
                    {
                        int tmpp = words[i][h];
                        words[i][h] = words[j][h];
                        words[j][h] = tmpp;
                    }
                }
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                std::cout << words[i][j];
            }
            std::cout << std::endl;
        }
    }



}
