#pragma once
/*-----------------------------------------------------------------------*/
/*                         � � � �    � � � � � �                        */
/*-----------------------------------------------------------------------*/

/*-----------------------  ����� �������������� -------------------------*/
class Location
{
protected:		//������������� ����������� �������� (������������ 
				//������) ����� ������ � ������� ������
	int X;		//���������� X
	int Y;		//���������� Y

public:   //��� ������ �������� ����� ���� � ���������

	Location(int InitX, int InitY); //�����������
	~Location();                    //����������
	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
};//end class Location

  /*-----------------------  ����� ����� ----------------------------------*/
class Point : public Location
{
	// Point - ����������� ����� �� Location
	// ������� public � ���������� ������������ ������ ��������
	// ����������� ������ ������ �� ����� � �������, ��������������
	// �� Location

protected:							//�������, ����������� �� Point, ����������� ������ public
	bool Visible;					//�������� ����� ��� ���

public:
	Point(int InitX, int InitY);	//����������� ������
	~Point();						//����������
	virtual void  Show();					//�������� ������ �����
	virtual void  Hide();					//������ ������ �����
	bool IsVisible();				//������ ��� ���������� �����
	void MoveTo(int NewX, int NewY);//����������� ������
};//end class Point

//************************ ����� ����� **********************************/
/*-----------------------  ��������� ����������  ---------------------------*/
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

/*---------------------  ������� ����� ����������  -------------------------*/
class Automobile : public Point, public IAutomobile
{
protected:								//������������� , �.�. �� ���������
	int A;								//�������� ������ ����������
	int B;								//�������� ������ ����������
	int Radius;							//������ �����
public:
	//����������� � ����������� �� ���������
	Automobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~Automobile();						//����������
	virtual void Show();				//�������� ������ ����������
	virtual void Kuzov();				//���������� �����
	virtual void Krisha();				//���������� �����
	virtual void LeftKoleso();			//���������� ����� ������
	virtual void RightKoleso();			//���������� ������ ������
	virtual void Fara();				//���������� ����
	virtual void LeftWindow();			//���������� ����� ����
	virtual void RightWindow();			//���������� ������ ����
	virtual void Hide();				//������ ������ ����������
};//end class Automobile

/*-----------------------  ����� ������ ����������  ---------------------------*/
class BadAutomobile : public Automobile	//��������� ������ ����������
{
public:
	//����������� � ����������� �� ���������
	BadAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~BadAutomobile();					//����������
	void LeftKoleso();					//���������� ����� ����
	void RightKoleso();					//���������� ������ ����
};//end class BadAutomobile

/*-----------------------  ����� �������� ����������  ---------------------------*/
class FireAutomobile : public Automobile//��������� ������ ����������
{
public:
	//����������� � ����������� �� ���������
	FireAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~FireAutomobile();					//����������
	void Show();						//�������� ������ �������� ����������
	void Kuzov();						//���������� �����
	void Krisha();						//���������� �����
	void LeftKoleso();					//���������� ����� ����
};

/*-----------------------  ����� ������� ����������  ---------------------------*/
class GoodAutomobile : public Automobile//��������� ������ ����������
{
public:
	//����������� � ����������� �� ���������
	GoodAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~GoodAutomobile();					//����������
	void LeftKoleso();					//���������� ����� ����
	void RightKoleso();					//���������� ������ ����
};//end class GoodAutomobile

class FlyAutomobile : public GoodAutomobile
{
public:
	//����������� � ����������� �� ���������
	FlyAutomobile(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10, int InitRdius = 10);
	~FlyAutomobile();					//����������
	void Show();
	void Kuzov();
};

//************************ ����� ����� **********************************/
/*-----------------------  ����� �������  ---------------------------*/
class Fuel : public Point
{
protected:								//������������� , �.�. �� ���������
	int A;								//�������� ������ �������
	int B;								//�������� ����� �������
public:
	//����������� � ����������� �� ���������
	Fuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~Fuel();							//����������
	void Show();						//�������� ������ �������
	void Hide();						//������ ������ �������
};//end class Fuel

/*-----------------------  ����� ������ �������  ---------------------------*/
class BadFuel : public Fuel
{
public:
	//����������� � ����������� �� ���������
	BadFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~BadFuel();					//����������
	void Show();				//�������� ������ �������
};//end class BadFuel

/*-----------------------  ����� ������� �������  ---------------------------*/
class GoodFuel : public Fuel
{
public:
	//����������� � ����������� �� ���������
	GoodFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~GoodFuel();					//����������
	void Show();					//�������� ������ �������
};//end class GoodFuel

/*-----------------------  ����� �������� �������  ---------------------------*/
class FireFuel : public Fuel
{
public:
	//����������� � ����������� �� ���������
	FireFuel(int InitX = 10, int InitY = 10, int InitA = 10, int InitB = 10);
	~FireFuel();					//����������
	void Show();					//�������� ������ �������
};//end class FireFuel

/******************   End of File Automobile.h *****************/