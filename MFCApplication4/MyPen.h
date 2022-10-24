#pragma once

#include "MyLine.h"
#include <vector>

using namespace std;

class MyPen : public MyLine
{
private:
	vector<CPoint> pointArray; //  ���� �������� �� �������� ������ ����� � STL  

public:
	 DECLARE_SERIAL(MyPen)

	MyPen();
	MyPen(CPoint, COLORREF penColor, int penSize);

	virtual void Serialize(CArchive& archive);  //���� �� ����� �� ����� �� �����


	CPoint lastPoint();
	void build(CPoint currentPoint) ;
	void draw(CDC* dc) const override;

};