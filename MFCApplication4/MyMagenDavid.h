#pragma once

#include "MyTriangle.h"


class MyMagenDavid : public MyTriangle
{

public:
	DECLARE_SERIAL(MyMagenDavid)

	MyMagenDavid();

	MyMagenDavid(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);

	void draw(CDC* dc) const;

};



