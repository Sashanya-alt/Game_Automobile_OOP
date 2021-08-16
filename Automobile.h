#pragma once
/*-----------------------------------------------------------------------*/
/*                         Т И П Ы    Д А Н Н Ы Х                        */
/*-----------------------------------------------------------------------*/

/*-----------------------  Класс МЕСТОПОЛОЖЕНИЕ -------------------------*/
class Location
{
protected:		//предоставляет возможность потомкам (производному 
				//классу) иметь доступ к частным данным
	int X;		//координата X
	int Y;		//координата Y

public:   //эти методы доступны извне всем в программе

	Location(int InitX, int InitY); //конструктор
	~Location();                    //деструктор
	int GetX();						//получить X координату точки
	int GetY();						//получить Y координату точки
};//end class Location

  /*-----------------------  Класс ТОЧКА ----------------------------------*/
class Point : public Location
{
	// Point - производный класс от Location
	// атрибут public в объявлении производного класса означает
	// возможность вызова любого из полей и методов, унаследованных
	// от Location

protected:							//классам, производным от Point, потребуется доступ public
	bool Visible;					//светится точка или нет

public:
	Point(int InitX, int InitY);	//конструктор класса
	~Point();						//деструктор
	virtual void  Show();					//показать фигуру ТОЧКА
	virtual void  Hide();					//скрыть фигуру ТОЧКА
	bool IsVisible();				//узнать про светимость точки
	void MoveTo(int NewX, int NewY);//переместить фигуру
};//end class Point

//************************ новый класс **********************************/
/*-----------------------  Интерфейс Автомобиль  ---------------------------*/
class IAutomobile
{
public:
	IAutomobile();
	~IAutomobile();
	virtual void Kuzov() = 0;
	virtual void Krisha() = 0;
	virtual void LeftKoleso() = 0;
	virtual void RightKoleso() = 0;
	virtual void Fara() = 0;
	virtual void LeftWindow() = 0;
	virtual void RightWindow() = 0;
};//end class IAutomobile

/*---------------------  Базовый класс Автомобиль  -------------------------*/
class Automobile : public Point, public IAutomobile
{
protected:								//необязательно , т.к. по умолчанию
	int A;								//половина ширины автомобиля
	int B;								//половина высоты автомобиля
	int Radius;							//радиус круга
public:
	//конструктор с параметрами по умолчанию
	Automobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~Automobile();						//деструктор
	virtual void Show();				//показать фигуру АВТОМОБИЛЬ
	virtual void Kuzov();				//нарисовать кузов
	virtual void Krisha();				//нарисовать крышу
	virtual void LeftKoleso();			//нарисовать левое колесо
	virtual void RightKoleso();			//нарисовать правое колесо
	virtual void Fara();				//нарисовать фару
	virtual void LeftWindow();			//нарисовать левое окно
	virtual void RightWindow();			//нарисовать правое окно
	virtual void Hide();				//скрыть фигуру АВТОМОБИЛЬ
};//end class Automobile

/*-----------------------  Класс плохой Автомобиль  ---------------------------*/
class BadAutomobile : public Automobile	//наследник класса АВТОМОБИЛЬ
{
public:
	//конструктор с параметрами по умолчанию
	BadAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~BadAutomobile();					//деструктор
	void LeftKoleso();					//нарисовать левое окно
	void RightKoleso();					//нарисовать правое окно
};//end class BadAutomobile

/*-----------------------  Класс огненный Автомобиль  ---------------------------*/
class FireAutomobile : public Automobile//наследник класса АВТОМОБИЛЬ
{
public:
	//конструктор с параметрами по умолчанию
	FireAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~FireAutomobile();					//деструктор
	void Show();						//показать фигуру огненный АВТОМОБИЛЬ
	void Kuzov();						//нарисовать кузов
	void Krisha();						//нарисовать крышу
	void LeftKoleso();					//нарисовать левое окно
};

/*-----------------------  Класс хороший Автомобиль  ---------------------------*/
class GoodAutomobile : public Automobile//наследник класса АВТОМОБИЛЬ
{
public:
	//конструктор с параметрами по умолчанию
	GoodAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~GoodAutomobile();					//деструктор
	void LeftKoleso();					//нарисовать левое окно
	void RightKoleso();					//нарисовать правое окно
};//end class GoodAutomobile

class FlyAutomobile : public GoodAutomobile
{
public:
	//конструктор с параметрами по умолчанию
	FlyAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~FlyAutomobile();					//деструктор
	void Show();
	void Kuzov();
};

//************************ новый класс **********************************/
/*-----------------------  Класс Топливо  ---------------------------*/
class Fuel : public Point
{
protected:								//необязательно , т.к. по умолчанию
	int A;								//половина ширины топлива
	int B;								//половина длины топлива
public:
	//конструктор с параметрами по умолчанию
	Fuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~Fuel();							//деструктор
	void Show();						//показать фигуру ТОПЛИВО
	void Hide();						//скрыть фигуру ТОПЛИВО
};//end class Fuel

/*-----------------------  Класс плохое Топливо  ---------------------------*/
class BadFuel : public Fuel
{
public:
	//конструктор с параметрами по умолчанию
	BadFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~BadFuel();					//деструктор
	void Show();				//показать фигуру ТОПЛИВО
};//end class BadFuel

/*-----------------------  Класс хорошее Топливо  ---------------------------*/
class GoodFuel : public Fuel
{
public:
	//конструктор с параметрами по умолчанию
	GoodFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~GoodFuel();					//деструктор
	void Show();					//показать фигуру ТОПЛИВО
};//end class GoodFuel

/*-----------------------  Класс огненное Топливо  ---------------------------*/
class FireFuel : public Fuel
{
public:
	//конструктор с параметрами по умолчанию
	FireFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~FireFuel();					//деструктор
	void Show();					//показать фигуру ТОПЛИВО
};//end class FireFuel

/******************   End of File Automobile.h *****************/