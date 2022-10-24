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


	//virtual void draw(CDC* dc) const = 0; // רצינו שהקלאס יהיה אבסטרקטי , כלומר שהפונקציה תהיה פיור וירטואל, אבל הסיריאליזציה מנעה מאיתנו, אז מימשנו באופן ריק 
	virtual void draw(CDC* dc) const {} // זו הפונקציה הוירטואלית שעושה לנו פולימורפיזם בכך שכל צורה תמומש בדרך שונה

	// virtual void clear(CDC* dc) const = 0;


	virtual ~MyShape() {}

	virtual void Serialize(CArchive& archive);  //בודק אם לשמור או לפתוח את הקובץ

	virtual bool containningGivenPoint(const CPoint& point) const;    // הקונסטים פה כי אנחנו לא משנים את הפוינט וגם לא משהו במחלקה
                                                                      // בודק אם הנקודה נמאת בתוך המסגרת של הצורה

	virtual void drawAsSelected(CDC* dc) ;  // מסמן את הצורה ספציפית שאני בוחר		
};