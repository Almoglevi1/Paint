#pragma once

#include "MyShape.h"

class MyCircle : public MyShape
{
protected:
	CPoint center;
	double radius;

public:

	DECLARE_SERIAL(MyCircle)

	MyCircle();

	MyCircle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	void draw(CDC* dc) const;
};