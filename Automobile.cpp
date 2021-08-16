#include<windows.h>
#include <conio.h>
#include "Automobile.h"	//объявление классов

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//глобальная переменная видна в двух файлах: Point05_03.cpp и Ex05_03_Con.cpp
//внешнее обявление глобальной переменной
extern HDC hdc;      // объявим  контекст устройства

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*----------------------------------------------------------------*/
/*             Р Е А Л И З А Ц И Я    М Е Т О Д О В               */
/*----------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/
//конструктор
Location::Location(int InitX, int InitY)
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
};//end Location::Location()

  //деструктор
Location::~Location(void)  //формально пустое тело
{
};//end Location::~Location()

  //получить X координату точки
int Location::GetX(void)
{
	return X;
};//end Location::GetX()	

  //получить Y координату точки
int Location::GetY(void)
{
	return Y;
}; //end Location::GetY()


/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Point             */
/*----------------------------------------*/
//конструктор
//для инициализации закрытых полей используем конструктор предка
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	//инициализация закрытых переменных своего класса
	Visible = false;
}//end Point::Point()

 //--------------------------------------------------------------
 //деструктор
Point::~Point(void)   //формально пустое тело
{
}//end Point::~Point()

 //--------------------------------------------------------------
 //показать ТОЧКУ
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));			//рисуем красным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));		// 4 точки для удобства
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));

}//end Point::Show()

 //--------------------------------------------------------------
 //скрыть ТОЧКУ
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}//end Point::Hide()

 //--------------------------------------------------------------
 //узнать про светимость ТОЧКИ
bool Point::IsVisible(void)
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------
//переместить ТОЧКУ
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};//end Point::MoveTo()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Automobile            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
IAutomobile::IAutomobile()
{
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
IAutomobile::~IAutomobile(void)  //формально пустое тело
{
};//end Automobile::~Automobile ()

//-------------------------------------------------------------------
//конструктор
Automobile::Automobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) : Point(InitX, InitY)
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
	A = InitA;
	B = InitB;
	Radius = InitRadius;
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
 //деструктор
Automobile::~Automobile(void)  //формально пустое тело
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //показать АВТОМОБИЛЬ
void Automobile::Show(void)
{
	Visible = true;
	
	// Зададим кисть и цвет кисти - синий
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);								//сделаем кисть активной
	Kuzov();												//нарисуем кузов заданым цветом
	Krisha();												//нарисуем крышу заданым цветом
	// Уничтожим нами созданный объект 
	DeleteObject(Brush);				

	// Зададим кисть и цвет кисти - черный
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	RightKoleso();											//нарисуем правое колесо заданым цветом
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	LeftKoleso();											//нарисуем левое колесо заданым цветом
	// Уничтожим нами созданный объект 
	DeleteObject(Brush1);

	// Зададим кисть и цвет кисти - желтый
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//сделаем кисть активной
	Fara();													//нарисуем фару заданым цветом
	// Уничтожим нами созданный объект  
	DeleteObject(Brush2);

	// Зададим кисть и цвет кисти - голубой
	HBRUSH Brush3 = CreateSolidBrush(RGB(0, 255, 255));
	SelectObject(hdc, Brush3);								//сделаем кисть активной
	LeftWindow();											//нарисуем левое окно заданым цветом
	RightWindow();											//нарисуем правое окно заданым цветом
	// Уничтожим нами созданные объекты  
	DeleteObject(Brush3);
} // end Automobile::Show()

 //--------------------------------------------------------------
 //нарисовать кузов
void Automobile::Kuzov(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X - A, Y - B, X + A, Y + B);
}// end Automobile::Kuzov()

 //--------------------------------------------------------------
 //нарисовать фару
void Automobile::Fara(void)
{
	// Нарисуем круг
	Ellipse(hdc, X + A - 20, Y  + 9, X + A -2, Y - 9);
}// end Automobile::Fara()

 //--------------------------------------------------------------
 //нарисовать крышу
void Automobile::Krisha(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X - A/1.5, Y - 3*B, X + A/1.5, Y - B);
}// end Automobile::Krisha()

 //--------------------------------------------------------------
 //нарисовать левое окно
void Automobile::LeftWindow(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X - A / 3 - 20, Y - 2 * B-12, X - A / 3 + 20, Y - B-10);
}// end Automobile::LeftWindow()

 //--------------------------------------------------------------
 //нарисовать правое окно
void Automobile::RightWindow(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X + A / 3 - 20, Y - 2 * B-12, X + A / 3 + 20, Y - B-10);
}// end Automobile::RightWindow()

 //--------------------------------------------------------------
 //нарисовать левое колесо
void Automobile::LeftKoleso(void)
{
	Visible = true;

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - A / 2 - Radius, Y + B + Radius, X - A / 2 + Radius, Y+B - Radius);

	// Зададим кисть и цвет кисти - белый
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - A / 2 - Radius/2, Y + B + Radius/2, X - A / 2 + Radius/2, Y + B - Radius/2);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);
}// end Automobile::LeftKoleso()

//--------------------------------------------------------------
//нарисовать правое колесо
void Automobile::RightKoleso(void)
{
	Visible = true;

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X + A / 2 - Radius, Y + B + Radius, X + A / 2 + Radius, Y + B - Radius);

	// Зададим кисть и цвет кисти - 
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X + A / 2 - Radius/2, Y + B + Radius/2, X + A / 2 + Radius/2, Y + B - Radius/2);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);
}// end Automobile::RightKoleso()

//-------------------------------------------------------------------
//скрыть автомобиль
void Automobile::Hide(void)
{
	Visible = false;

	// Зададим кисть и цвет кисти - белый
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	Kuzov();												//нарисуем кузов заданым цветом
	Krisha();												//нарисуем крышу заданым цветом
	LeftKoleso();											//нарисуем левок колесо заданым цветом
	RightKoleso();											//нарисуем правоеколесо заданым цветом
	Fara();													//нарисуем фару заданым цветом
	// Уничтожим нами созданные объекты  
	DeleteObject(Brush1);
}// end Automobile::Hide()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА BadAutomobile            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
BadAutomobile::BadAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end BadAutomobile::BadAutomobile ()

//-------------------------------------------------------------------
//дестректор
BadAutomobile::~BadAutomobile(void)  //формально пустое тело
{
};//end BadAutomobile::~BadAutomobile ()

 //--------------------------------------------------------------
 //нарисовать левое колесо
void BadAutomobile::LeftKoleso(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X - A / 2 - Radius/2, Y + B + Radius/2, X - A / 2 + Radius/2, Y + B - Radius/2);
}//end BadAutomobile::LeftKoleso()

 //--------------------------------------------------------------
 //нарисовать правое колесо
void BadAutomobile::RightKoleso(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X + A / 2 - Radius/2, Y + B + Radius/2, X + A / 2 + Radius/2, Y + B - Radius/2);
}//end BadAutomobile::RightKoleso()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА GoodAutomobile            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
GoodAutomobile::GoodAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end GoodAutomobile::GoodAutomobile ()

//-------------------------------------------------------------------
//деструктор
GoodAutomobile::~GoodAutomobile(void)  //формально пустое тело
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //нарисовать левое колесо
void GoodAutomobile::LeftKoleso(void)
{
	Visible = true;

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - A / 2 - Radius-10, Y + B + Radius+10, X - A / 2 + Radius+10, Y + B - Radius-10);

	// Зададим кисть и цвет кисти - белый
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - A / 2 - Radius / 2-10, Y + B + Radius / 2+10, X - A / 2 + Radius / 2+10, Y + B - Radius / 2-10);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush1);
}//end GoodAutomobile::LeftKoleso()

 //--------------------------------------------------------------
 //нарисовать правое колесо
void GoodAutomobile::RightKoleso(void)
{
	Visible = true;

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X + A / 2 - Radius-10, Y + B + Radius+10, X + A / 2 + Radius+10, Y + B - Radius-10);

	// Зададим кисть и цвет кисти - белый
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X + A / 2 - Radius / 2-10, Y + B + Radius / 2+10, X + A / 2 + Radius / 2+10, Y + B - Radius / 2-10);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush1);
}//end GoodAutomobile::RightKoleso()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА FlyAutomobile            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
FlyAutomobile::FlyAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :GoodAutomobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end FlyAutomobile::Automobile ()

//-------------------------------------------------------------------
//деструктор
FlyAutomobile::~FlyAutomobile(void)  //формально пустое тело
{
};//end FlyAutomobile::~Automobile ()

 //--------------------------------------------------------------
 //показать летающий АВТОМОБИЛЬ
void FlyAutomobile::Show(void)
{
	Visible = true;
	// Зададим кисть и цвет кисти - черный
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	RightKoleso();											//нарисуем правое колесо заданым цветом
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	LeftKoleso();											//нарисуем левое колесо заданым цветом
	// Уничтожим нами созданные объекты
	DeleteObject(Brush1);

	// Зададим кисть и цвет кисти - синий
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);								//сделаем кисть активной
	Kuzov();												//нарисуем кузов заданым цветом
	Krisha();;												//нарисуем крышу заданым цветом
	// Уничтожим нами созданные объекты
	DeleteObject(Brush);

	// Зададим кисть и цвет кисти - желтый
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//сделаем кисть активной
	Fara();													//нарисуем фару заданым цветом
	// Уничтожим нами созданные объекты  
	DeleteObject(Brush2);

	// Зададим кисть и цвет кисти - голубой
	HBRUSH Brush3 = CreateSolidBrush(RGB(0, 255, 255));
	SelectObject(hdc, Brush3);								//сделаем кисть активной
	LeftWindow();											//нарисуем левое окно заданым цветом
	RightWindow();											//нарисуем правое окно заданым цветом
	// Уничтожим нами созданные объекты  
	DeleteObject(Brush3);

} // end FlyAutomobile::Show()

 //--------------------------------------------------------------
 //нарисовать кузов
void FlyAutomobile::Kuzov(void)
{
	Visible = true;

	// Нарисуем круг
	Rectangle(hdc, X - A, Y - B, X + A, Y + B);

	//крыло
	POINT dots[4] = { {X + A/2,Y }, {X ,Y + 3 * B }, {X - A / 1.5,Y + 3 * B / 1.5}, {X - A/1.5 ,Y } };

	Polygon(hdc, dots, 4);
} // end FlyAutomobile::Kuzov()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА GoodAutomobile            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
FireAutomobile::FireAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
//деструктор
FireAutomobile::~FireAutomobile(void)  //формально пустое тело
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //показать огненный АВТОМОБИЛЬ
void FireAutomobile::Show()
{
	Visible = true;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, Brush);								//сделаем кисть активной
	Kuzov();												//нарисуем кузов заданым цветом
	Krisha();												//нарисуем крышу заданым цветом
	// Уничтожим нами созданные объекты
	DeleteObject(Brush);

	// Зададим кисть и цвет кисти - черный
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	RightKoleso();											//нарисуем правое колесо заданым цветом
	SelectObject(hdc, Brush1);								//сделаем кисть активной
	LeftKoleso();											//нарисуем левое колесо заданым цветом
	// Уничтожим нами созданные объекты
	DeleteObject(Brush1);

	// Зададим кисть и цвет кисти - желтый
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//сделаем кисть активной
	Fara();													//нарисуем фару заданым цветом
	// Уничтожим нами созданные объекты  
	DeleteObject(Brush2);
}// end FireAutomobile::Show()

 //--------------------------------------------------------------
 //нарисовать кузов
void FireAutomobile::Kuzov(void)
{
	// Нарисуем квадрат
	Rectangle(hdc, X - A, Y - B/1.5, X + A, Y + B/1.5);
}// end FireAutomobile::Kuzov()

 //--------------------------------------------------------------
 //нарисовать крышу
void FireAutomobile::Krisha(void)
{
	Visible = true;
	//зададим координты точек, по который нарисуем крышу
	POINT dots[4] = { {X + A,Y - B/1.5}, {X ,Y - 3 * B/1.5}, {X - A / 1.5,Y - 3 * B/1.5}, {X - A ,Y - B/1.5} };

	//нарисуем фигуру по заданым точкам
	Polygon(hdc, dots, 4);
}// end FireAutomobile::Krisha()

 //--------------------------------------------------------------
 //нарисовать левое колесо
void FireAutomobile::LeftKoleso(void)
{
	Visible = true;

	// Нарисуем круг 
	Ellipse(hdc, X - A / 2 - Radius - 5, Y + B + Radius + 5-3, X - A / 2 + Radius + 5, Y + B - Radius - 5-3);

	// Зададим кисть и цвет кисти - белый
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//сделаем кисть активной
	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - A / 2 - Radius / 2 - 5, Y + B + Radius / 2 + 5-3, X - A / 2 + Radius / 2 + 5, Y + B - Radius / 2 - 5-3);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush1);
}// end FireAutomobile::LeftKoleso()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Fuel            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
Fuel::Fuel(int InitX, int InitY, int InitA, int InitB) :Point(InitX, InitY)
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
	A = InitA;
	B = InitB;
}//end Fuel::Fuel ()

//-------------------------------------------------------------------
//деструктор
Fuel::~Fuel(void)  //формально пустое тело
{
};//end Fuel::~Fuel ()

 //--------------------------------------------------------------
 //показать ТОПЛИВО
void Fuel::Show(void)
{
	Visible = true;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 3*A, Y - 3*B, X + 3*A, Y + 3*B);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);

} // end Fuel::Fuel()

 //--------------------------------------------------------------
 //скрыть ТОПЛИВО
void Fuel::Hide(void)
{
	Visible = false;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);

}// end Fuel::Hide()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА BadFuel            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
BadFuel::BadFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
}//end BadFuel::BadFuel ()

//-------------------------------------------------------------------
//деструктор
BadFuel::~BadFuel(void)  //формально пустое тело
{
};//end BadFuel::~BadFuel ()

 //--------------------------------------------------------------
 //показать ТОПЛИВО
void BadFuel::Show(void)
{
	Visible = true;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);

} // end BadFuel::Show()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА GoodFuel            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
GoodFuel::GoodFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
	//инициализация закрытых переменных своего класса

}//end GoodFuel::GoodFuel ()

//-------------------------------------------------------------------
//деструктор
GoodFuel::~GoodFuel(void)  //формально пустое тело
{
};//end GoodFuel::~GoodFuel ()

//--------------------------------------------------------------
 //показать ТОПЛИВО
void GoodFuel::Show(void)
{
	Visible = true;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 3*A, Y - 3*B, X + 3*A, Y + 3*B);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);

} // end GoodFuel::Show()

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА FireFuel            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
//-------------------------------------------------------------------
//конструктор
FireFuel::FireFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
}//end FireFuel::FireFuel ()

//-------------------------------------------------------------------
//деструктор
FireFuel::~FireFuel(void)  //формально пустое тело
{
};//end FireFuel::~FireFuel ()

 //--------------------------------------------------------------
 //показать ТОПЛИВО
void FireFuel::Show(void)
{
	Visible = true;

	// Зададим кисть и цвет кисти - красный
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 255));
	SelectObject(hdc, Brush);	//сделаем кисть активной

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// Уничтожим нами созданные объекты  
	DeleteObject(Brush);

} // end FireFuel::Show()