#pragma once

#include "MyShape.h"

class MyRectangle: public MyShape
{

public:
	DECLARE_SERIAL(MyRectangle)

	MyRectangle();

	MyRectangle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	virtual void draw(CDC* dc) const;

};

