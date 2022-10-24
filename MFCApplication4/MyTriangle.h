#pragma once

#include "MyShape.h"


class MyTriangle : public MyShape
{

public:

	DECLARE_SERIAL(MyTriangle)

	MyTriangle();

	MyTriangle(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	void draw(CDC* dc) const;

};

