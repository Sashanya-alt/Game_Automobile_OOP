#include<windows.h>
#include <conio.h>
#include "Automobile.h"	//���������� �������

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//���������� ���������� ����� � ���� ������: Point05_03.cpp � Ex05_03_Con.cpp
//������� ��������� ���������� ����������
extern HDC hdc;      // �������  �������� ����������

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*----------------------------------------------------------------*/
/*             � � � � � � � � � �    � � � � � � �               */
/*----------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*        ������ ������ Location          */
/*----------------------------------------*/
//�����������
Location::Location(int InitX, int InitY)
{
	//������������� �������� ���������� ������ ������
	X = InitX;
	Y = InitY;
};//end Location::Location()

  //����������
Location::~Location(void)  //��������� ������ ����
{
};//end Location::~Location()

  //�������� X ���������� �����
int Location::GetX(void)
{
	return X;
};//end Location::GetX()	

  //�������� Y ���������� �����
int Location::GetY(void)
{
	return Y;
}; //end Location::GetY()


/*-----------------------------------------------------------------------*/
/*        ������ ������ Point             */
/*----------------------------------------*/
//�����������
//��� ������������� �������� ����� ���������� ����������� ������
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	//������������� �������� ���������� ������ ������
	Visible = false;
}//end Point::Point()

 //--------------------------------------------------------------
 //����������
Point::~Point(void)   //��������� ������ ����
{
}//end Point::~Point()

 //--------------------------------------------------------------
 //�������� �����
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));			//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));		// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));

}//end Point::Show()

 //--------------------------------------------------------------
 //������ �����
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}//end Point::Hide()

 //--------------------------------------------------------------
 //������ ��� ���������� �����
bool Point::IsVisible(void)
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------
//����������� �����
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};//end Point::MoveTo()

/*-----------------------------------------------------------------------*/
/*        ������ ������ Automobile            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
IAutomobile::IAutomobile()
{
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
IAutomobile::~IAutomobile(void)  //��������� ������ ����
{
};//end Automobile::~Automobile ()

//-------------------------------------------------------------------
//�����������
Automobile::Automobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) : Point(InitX, InitY)
{
	//������������� �������� ���������� ������ ������
	X = InitX;
	Y = InitY;
	A = InitA;
	B = InitB;
	Radius = InitRadius;
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
 //����������
Automobile::~Automobile(void)  //��������� ������ ����
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //�������� ����������
void Automobile::Show(void)
{
	Visible = true;
	
	// ������� ����� � ���� ����� - �����
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);								//������� ����� ��������
	Kuzov();												//�������� ����� ������� ������
	Krisha();												//�������� ����� ������� ������
	// ��������� ���� ��������� ������ 
	DeleteObject(Brush);				

	// ������� ����� � ���� ����� - ������
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//������� ����� ��������
	RightKoleso();											//�������� ������ ������ ������� ������
	SelectObject(hdc, Brush1);								//������� ����� ��������
	LeftKoleso();											//�������� ����� ������ ������� ������
	// ��������� ���� ��������� ������ 
	DeleteObject(Brush1);

	// ������� ����� � ���� ����� - ������
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//������� ����� ��������
	Fara();													//�������� ���� ������� ������
	// ��������� ���� ��������� ������  
	DeleteObject(Brush2);

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush3 = CreateSolidBrush(RGB(0, 255, 255));
	SelectObject(hdc, Brush3);								//������� ����� ��������
	LeftWindow();											//�������� ����� ���� ������� ������
	RightWindow();											//�������� ������ ���� ������� ������
	// ��������� ���� ��������� �������  
	DeleteObject(Brush3);
} // end Automobile::Show()

 //--------------------------------------------------------------
 //���������� �����
void Automobile::Kuzov(void)
{
	// �������� �������
	Rectangle(hdc, X - A, Y - B, X + A, Y + B);
}// end Automobile::Kuzov()

 //--------------------------------------------------------------
 //���������� ����
void Automobile::Fara(void)
{
	// �������� ����
	Ellipse(hdc, X + A - 20, Y  + 9, X + A -2, Y - 9);
}// end Automobile::Fara()

 //--------------------------------------------------------------
 //���������� �����
void Automobile::Krisha(void)
{
	// �������� �������
	Rectangle(hdc, X - A/1.5, Y - 3*B, X + A/1.5, Y - B);
}// end Automobile::Krisha()

 //--------------------------------------------------------------
 //���������� ����� ����
void Automobile::LeftWindow(void)
{
	// �������� �������
	Rectangle(hdc, X - A / 3 - 20, Y - 2 * B-12, X - A / 3 + 20, Y - B-10);
}// end Automobile::LeftWindow()

 //--------------------------------------------------------------
 //���������� ������ ����
void Automobile::RightWindow(void)
{
	// �������� �������
	Rectangle(hdc, X + A / 3 - 20, Y - 2 * B-12, X + A / 3 + 20, Y - B-10);
}// end Automobile::RightWindow()

 //--------------------------------------------------------------
 //���������� ����� ������
void Automobile::LeftKoleso(void)
{
	Visible = true;

	// �������� ���� ������������� ������
	Ellipse(hdc, X - A / 2 - Radius, Y + B + Radius, X - A / 2 + Radius, Y+B - Radius);

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X - A / 2 - Radius/2, Y + B + Radius/2, X - A / 2 + Radius/2, Y + B - Radius/2);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);
}// end Automobile::LeftKoleso()

//--------------------------------------------------------------
//���������� ������ ������
void Automobile::RightKoleso(void)
{
	Visible = true;

	// �������� ���� ������������� ������
	Ellipse(hdc, X + A / 2 - Radius, Y + B + Radius, X + A / 2 + Radius, Y + B - Radius);

	// ������� ����� � ���� ����� - 
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X + A / 2 - Radius/2, Y + B + Radius/2, X + A / 2 + Radius/2, Y + B - Radius/2);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);
}// end Automobile::RightKoleso()

//-------------------------------------------------------------------
//������ ����������
void Automobile::Hide(void)
{
	Visible = false;

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);								//������� ����� ��������
	Kuzov();												//�������� ����� ������� ������
	Krisha();												//�������� ����� ������� ������
	LeftKoleso();											//�������� ����� ������ ������� ������
	RightKoleso();											//�������� ������������ ������� ������
	Fara();													//�������� ���� ������� ������
	// ��������� ���� ��������� �������  
	DeleteObject(Brush1);
}// end Automobile::Hide()

/*-----------------------------------------------------------------------*/
/*        ������ ������ BadAutomobile            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
BadAutomobile::BadAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end BadAutomobile::BadAutomobile ()

//-------------------------------------------------------------------
//����������
BadAutomobile::~BadAutomobile(void)  //��������� ������ ����
{
};//end BadAutomobile::~BadAutomobile ()

 //--------------------------------------------------------------
 //���������� ����� ������
void BadAutomobile::LeftKoleso(void)
{
	// �������� �������
	Rectangle(hdc, X - A / 2 - Radius/2, Y + B + Radius/2, X - A / 2 + Radius/2, Y + B - Radius/2);
}//end BadAutomobile::LeftKoleso()

 //--------------------------------------------------------------
 //���������� ������ ������
void BadAutomobile::RightKoleso(void)
{
	// �������� �������
	Rectangle(hdc, X + A / 2 - Radius/2, Y + B + Radius/2, X + A / 2 + Radius/2, Y + B - Radius/2);
}//end BadAutomobile::RightKoleso()

/*-----------------------------------------------------------------------*/
/*        ������ ������ GoodAutomobile            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
GoodAutomobile::GoodAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end GoodAutomobile::GoodAutomobile ()

//-------------------------------------------------------------------
//����������
GoodAutomobile::~GoodAutomobile(void)  //��������� ������ ����
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //���������� ����� ������
void GoodAutomobile::LeftKoleso(void)
{
	Visible = true;

	// �������� ���� ������������� ������
	Ellipse(hdc, X - A / 2 - Radius-10, Y + B + Radius+10, X - A / 2 + Radius+10, Y + B - Radius-10);

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//������� ����� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X - A / 2 - Radius / 2-10, Y + B + Radius / 2+10, X - A / 2 + Radius / 2+10, Y + B - Radius / 2-10);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush1);
}//end GoodAutomobile::LeftKoleso()

 //--------------------------------------------------------------
 //���������� ������ ������
void GoodAutomobile::RightKoleso(void)
{
	Visible = true;

	// �������� ���� ������������� ������
	Ellipse(hdc, X + A / 2 - Radius-10, Y + B + Radius+10, X + A / 2 + Radius+10, Y + B - Radius-10);

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//������� ����� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X + A / 2 - Radius / 2-10, Y + B + Radius / 2+10, X + A / 2 + Radius / 2+10, Y + B - Radius / 2-10);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush1);
}//end GoodAutomobile::RightKoleso()

/*-----------------------------------------------------------------------*/
/*        ������ ������ FlyAutomobile            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
FlyAutomobile::FlyAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :GoodAutomobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end FlyAutomobile::Automobile ()

//-------------------------------------------------------------------
//����������
FlyAutomobile::~FlyAutomobile(void)  //��������� ������ ����
{
};//end FlyAutomobile::~Automobile ()

 //--------------------------------------------------------------
 //�������� �������� ����������
void FlyAutomobile::Show(void)
{
	Visible = true;
	// ������� ����� � ���� ����� - ������
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//������� ����� ��������
	RightKoleso();											//�������� ������ ������ ������� ������
	SelectObject(hdc, Brush1);								//������� ����� ��������
	LeftKoleso();											//�������� ����� ������ ������� ������
	// ��������� ���� ��������� �������
	DeleteObject(Brush1);

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);								//������� ����� ��������
	Kuzov();												//�������� ����� ������� ������
	Krisha();;												//�������� ����� ������� ������
	// ��������� ���� ��������� �������
	DeleteObject(Brush);

	// ������� ����� � ���� ����� - ������
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//������� ����� ��������
	Fara();													//�������� ���� ������� ������
	// ��������� ���� ��������� �������  
	DeleteObject(Brush2);

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush3 = CreateSolidBrush(RGB(0, 255, 255));
	SelectObject(hdc, Brush3);								//������� ����� ��������
	LeftWindow();											//�������� ����� ���� ������� ������
	RightWindow();											//�������� ������ ���� ������� ������
	// ��������� ���� ��������� �������  
	DeleteObject(Brush3);

} // end FlyAutomobile::Show()

 //--------------------------------------------------------------
 //���������� �����
void FlyAutomobile::Kuzov(void)
{
	Visible = true;

	// �������� ����
	Rectangle(hdc, X - A, Y - B, X + A, Y + B);

	//�����
	POINT dots[4] = { {X + A/2,Y }, {X ,Y + 3 * B }, {X - A / 1.5,Y + 3 * B / 1.5}, {X - A/1.5 ,Y } };

	Polygon(hdc, dots, 4);
} // end FlyAutomobile::Kuzov()

/*-----------------------------------------------------------------------*/
/*        ������ ������ GoodAutomobile            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
FireAutomobile::FireAutomobile(int InitX, int InitY, int InitA, int InitB, int InitRadius) :Automobile(InitX, InitY, InitA, InitB, InitRadius)
{
}//end Automobile::Automobile ()

//-------------------------------------------------------------------
//����������
FireAutomobile::~FireAutomobile(void)  //��������� ������ ����
{
};//end Automobile::~Automobile ()

 //--------------------------------------------------------------
 //�������� �������� ����������
void FireAutomobile::Show()
{
	Visible = true;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, Brush);								//������� ����� ��������
	Kuzov();												//�������� ����� ������� ������
	Krisha();												//�������� ����� ������� ������
	// ��������� ���� ��������� �������
	DeleteObject(Brush);

	// ������� ����� � ���� ����� - ������
	HBRUSH Brush1 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, Brush1);								//������� ����� ��������
	RightKoleso();											//�������� ������ ������ ������� ������
	SelectObject(hdc, Brush1);								//������� ����� ��������
	LeftKoleso();											//�������� ����� ������ ������� ������
	// ��������� ���� ��������� �������
	DeleteObject(Brush1);

	// ������� ����� � ���� ����� - ������
	HBRUSH Brush2 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, Brush2);								//������� ����� ��������
	Fara();													//�������� ���� ������� ������
	// ��������� ���� ��������� �������  
	DeleteObject(Brush2);
}// end FireAutomobile::Show()

 //--------------------------------------------------------------
 //���������� �����
void FireAutomobile::Kuzov(void)
{
	// �������� �������
	Rectangle(hdc, X - A, Y - B/1.5, X + A, Y + B/1.5);
}// end FireAutomobile::Kuzov()

 //--------------------------------------------------------------
 //���������� �����
void FireAutomobile::Krisha(void)
{
	Visible = true;
	//������� ��������� �����, �� ������� �������� �����
	POINT dots[4] = { {X + A,Y - B/1.5}, {X ,Y - 3 * B/1.5}, {X - A / 1.5,Y - 3 * B/1.5}, {X - A ,Y - B/1.5} };

	//�������� ������ �� ������� ������
	Polygon(hdc, dots, 4);
}// end FireAutomobile::Krisha()

 //--------------------------------------------------------------
 //���������� ����� ������
void FireAutomobile::LeftKoleso(void)
{
	Visible = true;

	// �������� ���� 
	Ellipse(hdc, X - A / 2 - Radius - 5, Y + B + Radius + 5-3, X - A / 2 + Radius + 5, Y + B - Radius - 5-3);

	// ������� ����� � ���� ����� - �����
	HBRUSH Brush1 = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush1);	//������� ����� ��������
	// �������� ���� ������������� ������
	Ellipse(hdc, X - A / 2 - Radius / 2 - 5, Y + B + Radius / 2 + 5-3, X - A / 2 + Radius / 2 + 5, Y + B - Radius / 2 - 5-3);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush1);
}// end FireAutomobile::LeftKoleso()

/*-----------------------------------------------------------------------*/
/*        ������ ������ Fuel            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
Fuel::Fuel(int InitX, int InitY, int InitA, int InitB) :Point(InitX, InitY)
{
	//������������� �������� ���������� ������ ������
	X = InitX;
	Y = InitY;
	A = InitA;
	B = InitB;
}//end Fuel::Fuel ()

//-------------------------------------------------------------------
//����������
Fuel::~Fuel(void)  //��������� ������ ����
{
};//end Fuel::~Fuel ()

 //--------------------------------------------------------------
 //�������� �������
void Fuel::Show(void)
{
	Visible = true;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 3*A, Y - 3*B, X + 3*A, Y + 3*B);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);

} // end Fuel::Fuel()

 //--------------------------------------------------------------
 //������ �������
void Fuel::Hide(void)
{
	Visible = false;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);

}// end Fuel::Hide()

/*-----------------------------------------------------------------------*/
/*        ������ ������ BadFuel            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
BadFuel::BadFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
}//end BadFuel::BadFuel ()

//-------------------------------------------------------------------
//����������
BadFuel::~BadFuel(void)  //��������� ������ ����
{
};//end BadFuel::~BadFuel ()

 //--------------------------------------------------------------
 //�������� �������
void BadFuel::Show(void)
{
	Visible = true;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);

} // end BadFuel::Show()

/*-----------------------------------------------------------------------*/
/*        ������ ������ GoodFuel            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
GoodFuel::GoodFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
	//������������� �������� ���������� ������ ������

}//end GoodFuel::GoodFuel ()

//-------------------------------------------------------------------
//����������
GoodFuel::~GoodFuel(void)  //��������� ������ ����
{
};//end GoodFuel::~GoodFuel ()

//--------------------------------------------------------------
 //�������� �������
void GoodFuel::Show(void)
{
	Visible = true;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 3*A, Y - 3*B, X + 3*A, Y + 3*B);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);

} // end GoodFuel::Show()

/*-----------------------------------------------------------------------*/
/*        ������ ������ FireFuel            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
//-------------------------------------------------------------------
//�����������
FireFuel::FireFuel(int InitX, int InitY, int InitA, int InitB) :Fuel(InitX, InitY, InitA, InitB)
{
}//end FireFuel::FireFuel ()

//-------------------------------------------------------------------
//����������
FireFuel::~FireFuel(void)  //��������� ������ ����
{
};//end FireFuel::~FireFuel ()

 //--------------------------------------------------------------
 //�������� �������
void FireFuel::Show(void)
{
	Visible = true;

	// ������� ����� � ���� ����� - �������
	HBRUSH Brush = CreateSolidBrush(RGB(255, 0, 255));
	SelectObject(hdc, Brush);	//������� ����� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 3 * A, Y - 3 * B, X + 3 * A, Y + 3 * B);

	// ��������� ���� ��������� �������  
	DeleteObject(Brush);

} // end FireFuel::Show()