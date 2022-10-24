#pragma once

#include "pch.h"
#include "MyShape.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include "MyRectCirc.h"
#include "MyTriangle.h"
#include "MyLine.h"
#include "MyPen.h"
#include "MyMagenDavid.h"


 IMPLEMENT_SERIAL(MyShape, CObject, 1)


MyShape::MyShape() 
{
}

MyShape::MyShape(const CPoint& start,const CPoint& end , COLORREF penColor, int penSize) {
	this->start = start;
	this->end = end;
	this->penColor = penColor;
	this->penSize = penSize;
}


void MyShape::setStart(const CPoint& start)  {
	this->start = start;
}


void MyShape::setEnd(const CPoint& end) {
	this->end = end;
}


void MyShape::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring()) { // SAVE      //בודק אם לשמור או לפתוח את הקובץ
		archive << start;
		archive << end;
		archive << penColor;
		archive << penSize;


	}
	else  // LOAD
	{
		archive >> start;
		archive >> end;
		archive >> penColor;
		archive >> penSize;

	}
}


 bool MyShape::containningGivenPoint(const CPoint& point) const {    // הקונסטים פה כי אנחנו לא משנים את הפוינט וגם לא משהו במחלקה
	 bool contain = false;
	 if ((start.x < end.x && point.x > start.x && point.x < end.x) ||
		 (start.x > end.x && point.x < start.x && point.x > end.x)) {
		 if ((start.y < end.y && point.x > start.y && point.x < end.y) ||
			 (start.y > end.y && point.y < start.y && point.y > end.y)) {
			return true;
		 }
	 }
	 return false;
}// בודק אם הנקודה נמאת בתוך המסגרת של הצורה



 void MyShape::drawAsSelected(CDC* dc) 
 { 
	// מסמן את הצורה ספציפית שאני בוחר

	  CPen pen(PS_DASH, 2, RGB(125, 125, 125));
	 CPen* old = dc->SelectObject(&pen);
	 dc->Rectangle(start.x, start.y, end.x, end.y);
	 dc->SelectObject(old);

}

