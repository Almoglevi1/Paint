#pragma once

#include "framework.h"

class MyShape : public CObject
{
protected:
	CPoint start;
	CPoint end;

	COLORREF penColor;
	int penSize;
	
public:

	 DECLARE_SERIAL(MyShape)

	MyShape();
	
	MyShape(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	void setStart(const CPoint& start) ;

	void setEnd(const CPoint& end) ;


	//virtual void draw(CDC* dc) const = 0; // ����� ������ ���� �������� , ����� ��������� ���� ���� �������, ��� ������������ ���� ������, �� ������ ����� ��� 
	virtual void draw(CDC* dc) const {} // �� �������� ���������� ����� ��� ����������� ��� ��� ���� ����� ���� ����

	// virtual void clear(CDC* dc) const = 0;


	virtual ~MyShape() {}

	virtual void Serialize(CArchive& archive);  //���� �� ����� �� ����� �� �����

	virtual bool containningGivenPoint(const CPoint& point) const;    // �������� �� �� ����� �� ����� �� ������ ��� �� ���� ������
                                                                      // ���� �� ������ ���� ���� ������ �� �����

	virtual void drawAsSelected(CDC* dc) ;  // ���� �� ����� ������� ���� ����		
};