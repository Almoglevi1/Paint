#pragma once

#include "MyShape.h"

class MyLine : public MyShape
{

public:
	 DECLARE_SERIAL(MyLine)

	 MyLine();

	MyLine(const CPoint& start, const CPoint& end, COLORREF penColor, int penSize);


	MyLine(COLORREF penColor, int penSize);

	virtual void draw(CDC* dc) const;


	bool isSelected(CPoint& point) const;
	
};