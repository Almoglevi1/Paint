#pragma once

#include "MyRectangle.h"


class MyRectCirc : public MyRectangle
{

public:
	DECLARE_SERIAL(MyRectCirc)

	MyRectCirc();

	MyRectCirc(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	virtual void draw(CDC* dc) const;

};

