#pragma once      

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;        // Пространство имен std

#include "Automobile.h"
#include "GetConWin.h"		//указатель на консольное окно

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*************************************************************************
 *                  П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
 ************************************************************************/
int Drag(Automobile& MyAuto, int Step, int FigX, int FigY, Fuel** MyFuel);

HDC hdc;

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
void main()
{
	//объявление и инициализация переменных
	int xStart = 450, yStart = 175;							//стартовые координаты автомобиля
	int a = 100, b = 20;									//ширина и высота атомобиля
	int Radius = 25;									    //начальное значение радиуса колес
	int X, Y;												//Координаты машинки в данный момент
	int x0 = 200, y0 = 500;									//начальные координаты топлива
	int a0 = 20, b0 = 20;									//размер топлива
	int x1 = 700, y1 = 600;									//начальные координаты плохого топлива
	int x2 = 1000, y2 = 400;								//начальные координаты хорошего топлива
	int x3 = 1600, y3 = 300;								//начальные координаты огненного топлива
	int Step = 15;											//начальный шаг
	int index = 0;											//индекс для машин и топлив
	int D;													//результат работы функции Drag

	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();
	
	//если дескриптор существует
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{

			//объявление автомобилей
			Automobile MyAutomobile(xStart, yStart, a, b, Radius);
			BadAutomobile BadAutomobile(xStart, yStart, a, b, Radius);
			GoodAutomobile GoodAutomobile(xStart, yStart, a, b, Radius);
			FireAutomobile FireAutomobile(xStart, yStart, a, b, Radius);
			FlyAutomobile FlyAutomobile(xStart, yStart, a, b, Radius);

			//абстрактный класс для автомобиля
			Automobile* Automobile[5];
			Automobile[0] = &MyAutomobile;
			Automobile[1] = &BadAutomobile;
			Automobile[2] = &GoodAutomobile;
			Automobile[3] = &FireAutomobile;
			Automobile[4] = &FlyAutomobile;

			//объявление топлив
			Fuel MyFuel(x0, y0, a0, b0);
			BadFuel BadFuel(x1, y1, a0, b0);
			GoodFuel GoodFuel(x2, y2, a0, b0);
			FireFuel FireFuel(x3, y3, a0, b0);

			//абстрактный класс для топлива
			Fuel* Fuels[4];
			Fuels[0] = &MyFuel;
			Fuels[1] = &BadFuel;
			Fuels[2] = &GoodFuel;
			Fuels[3] = &FireFuel;

			//вывести на экран все топлива
			for (int i = 0; i < 4; i++) 
			{
				Fuels[i]->Show();
			}//end for

			//вывести на экран машинку
			Automobile[0]->Show();

			//считываем текущие координаты автомобиля
			X = Automobile[0]->GetX();
			Y = Automobile[0]->GetY();
			
			//бесконечный цикл
			while (1)
			{
				D = Drag(*Automobile[index], Step, X, Y, Fuels);	//вызвать функцию для буксировки автомобиля

				if (D == -1)								//если функция вернула -1
				{
					//считываем текущие координаты текущего автомобиля
					X = Automobile[index]->GetX();
					Y = Automobile[index]->GetY();

					Automobile[index]->Hide();				//скрыть текущий автомобиль

					index = 0;								//присвоить новое значние индексу
					Fuels[index]->Hide();					//скрыть текущее топливо
					Fuels[index]->MoveTo(rand() % (1001), rand() % (1001));//переместить текущее топливо в рандомное место
					Automobile[index]->MoveTo(X, Y);		//переместить машину в текущее место
					Automobile[index]->Show();				//вывести на экран машинку
					Step = 15;								//присвоить новое значние шагу
				
				}//end if

				if (D == 1)									//если функция вернула 1
				{	
					//считываем текущие координаты текущего автомобиля
					X = Automobile[index]->GetX();
					Y = Automobile[index]->GetY();

					Automobile[index]->Hide();				//скрыть текущий автомобиль

					index = 1;								//присвоить новое значние индексу	
					Fuels[index]->Hide();					//скрыть текущее топливо
					Fuels[index]->MoveTo(rand() % (1001), rand() % (1001));//переместить текущее топливо в рандомное место
					Automobile[index]->MoveTo(X, Y);		//переместить плохую машину в текущее место
					Automobile[index]->Show();				//вывести на экран плохую машинку
					Step = 5;								//присвоить новое значние шагу
				
				}//end if

				if (D == 2)									//если функция вернула 2
				{
					//считываем текущие координаты текущего автомобиля
					X = Automobile[index]->GetX();
					Y = Automobile[index]->GetY();

					Automobile[index]->Hide();				//скрыть текущий автомобиль

					if (index == 2)							//если текущая машина хорошая
					{		
						index = 4;							//присвоить новое значние индексу
						Automobile[index]->MoveTo(X, Y);	//переместить крылатую машину в текущее место
						Automobile[index]->Show();			//вывести на экран крылатую машинку
						Step = 35;							//присвоить новое значние шагу
					}//end if

					else if (index != 2)					//если текущая машина не является хорошей
					{		
						index = 2;							//присвоить новое значние индексу
						Automobile[index]->MoveTo(X, Y);	//переместить хорошую машину в текущее место
						Automobile[index]->Show();			//вывести на экран хорошую машинку
						Step = 25;							//присвоить новое значние шагу		
					}//end else if

					Fuels[2]->Hide();						//скрыть хорошее топливо
					Fuels[2]->MoveTo(rand() % (1001), rand() % (1001));//переместить хорошее топливо в рандомное место
				
				}//end if

				if (D == 3)									//если функция вернула 3
				{
					//считываем текущие координаты текущего автомобиля
					X = Automobile[index]->GetX();
					Y = Automobile[index]->GetY();

					Automobile[index]->Hide();				//скрыть текущий автомобиль

					index = 3;								//присвоить новое значние индексу
					Fuels[index]->Hide();					//скрыть текущее топливо
					Fuels[index]->MoveTo(rand() % (1001), rand() % (1001));//переместить текущее топливо в рандомное место
					Automobile[index]->MoveTo(X, Y);		//переместить огненную машину в текущее место
					Automobile[index]->Show();				//вывести на экран огненную машинку
					Step = 50;								//присвоить новое значние шагу
				
				}//end if
			}//end while
		}//end if
	}//end if
}//end main

/*************************************************************************
 *                 Р Е А Л И З А Ц И Я    Ф У Н К Ц И Й                  *
 ************************************************************************/

 /*=======================================================================/
 / Буксировка фигуры	                                                  /
 /=======================================================================*/
int Drag(Automobile& MyAuto, int Step, int FigX, int FigY, Fuel** MyFuel)
{
	int Xfb, Yfb, Xfg, Yfg, Xff, Yff, Xfn, Yfn;				//координаты топлив
		
	//считываем текущии координаты топлив
	Xfn = MyFuel[0]->GetX();
	Yfn = MyFuel[0]->GetY();
	Xfb = MyFuel[1]->GetX();
	Yfb = MyFuel[1]->GetY();
	Xfg = MyFuel[2]->GetX();
	Yfg = MyFuel[2]->GetY();
	Xff = MyFuel[3]->GetX();
	Yff = MyFuel[3]->GetY();

	while (1)	//бесконечный цикл буксировки фигуры
	{

		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
			break;

		//направление движения объекта

		while (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX -= Step;
			MyAuto.MoveTo(FigX, FigY);
			Sleep(50);

			//Врезаемся в плохое топливо
			if (((Xfn - 60 <= FigX) && (Xfn + 60 >= FigX)) && ((Yfn - 60 <= FigY) && (Yfn + 60 >= FigY)))
			{
				return -1;
			}

			//Врезаемся в плохое топливо
			if (((Xfb - 60 <= FigX) && (Xfb + 60 >= FigX)) && ((Yfb - 60 <= FigY) && (Yfb + 60 >= FigY)))
			{
				return 1;
			}

			//Врезаемся в хорошое топливо
			if (((Xfg - 60 <= FigX) && (Xfg + 60 >= FigX)) && ((Yfg - 60 <= FigY) && (Yfg + 60 >= FigY)))
			{
				return 2;
			}

			//Врезаемся в огненное топливо
			if (((Xff - 60 <= FigX) && (Xff + 60 >= FigX)) && ((Yff - 60 <= FigY) && (Yff + 60 >= FigY)))
			{
				return 3;
			}
		}//end while
		
		while (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX += Step;
			MyAuto.MoveTo(FigX, FigY);
			Sleep(50);

			//Врезаемся в плохое топливо
			if (((Xfn - 60 <= FigX) && (Xfn + 60 >= FigX)) && ((Yfn - 60 <= FigY) && (Yfn + 60 >= FigY)))
			{
				return -1;
			}

			//Врезаемся в плохое топливо
			if (((Xfb - 60 <= FigX) && (Xfb + 60 >= FigX)) && ((Yfb - 60 <= FigY) && (Yfb + 60 >= FigY)))
			{
				return 1;
			}//end if

			//Врезаемся в хорошое топливо
			if (((Xfg - 60 <= FigX) && (Xfg + 60 >= FigX)) && ((Yfg - 60 <= FigY) && (Yfg + 60 >= FigY)))
			{
				return 2;
			}//end if

			//Врезаемся в огненное топливо
			if (((Xff - 60 <= FigX) && (Xff + 60 >= FigX)) && ((Yff - 60 <= FigY) && (Yff + 60 >= FigY)))
			{
				//MyAuto.Hide();
				return 3;
			}//end if
		}//end while

		while (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY += Step;
			MyAuto.MoveTo(FigX, FigY);
			Sleep(50);	

			//Врезаемся в плохое топливо
			if (((Xfn - 60 <= FigX) && (Xfn + 60 >= FigX)) && ((Yfn - 60 <= FigY) && (Yfn + 60 >= FigY)))
			{
				return -1;
			}

			//Врезаемся в плохое топливо
			if (((Xfb - 60 <= FigX) && (Xfb + 60 >= FigX)) && ((Yfb - 60 <= FigY) && (Yfb + 60 >= FigY)))
			{
				return 1;
			}//end if

			//Врезаемся в хорошое топливо
			if (((Xfg - 60 <= FigX) && (Xfg + 60 >= FigX)) && ((Yfg - 60 <= FigY) && (Yfg + 60 >= FigY)))
			{
				return 2;
			}//end if

			//Врезаемся в огненное топливо
			if (((Xff - 60 <= FigX) && (Xff + 60 >= FigX)) && ((Yff - 60 <= FigY) && (Yff + 60 >= FigY)))
			{
				return 3;
			}//end if
		}//end while

		while (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY -= Step;
			MyAuto.MoveTo(FigX, FigY);
			Sleep(50);	

			//Врезаемся в плохое топливо
			if (((Xfn - 60 <= FigX) && (Xfn + 60 >= FigX)) && ((Yfn - 60 <= FigY) && (Yfn + 60 >= FigY)))
			{
				return -1;
			}//end if

			//Врезаемся в плохое топливо
			if (((Xfb - 60 <= FigX) && (Xfb + 60 >= FigX)) && ((Yfb - 60 <= FigY) && (Yfb + 60 >= FigY)))
			{
				//MyAuto.Hide();
				return 1;
			}//end if

			//Врезаемся в хорошое топливо
			if (((Xfg - 60 <= FigX) && (Xfg + 60 >= FigX)) && ((Yfg - 60 <= FigY) && (Yfg + 60 >= FigY)))
			{
				//MyAuto.Hide();
				return 2;
			}//end if

			//Врезаемся в огненное топливо
			if (((Xff - 60 <= FigX) && (Xff + 60 >= FigX)) && ((Yff - 60 <= FigY) && (Yff + 60 >= FigY)))
			{
				//MyAuto.Hide();
				return 3;
			}//end if
		}//end while
	}//end while
	return 0;
}//end Drag
