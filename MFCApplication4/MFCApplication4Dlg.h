
// MFCApplication4Dlg.h : header file
//

#pragma once

#include "MyShape.h"

// CMFCApplication4Dlg dialog
class CMFCApplication4Dlg : public CDialogEx
{
// Construction
	bool lButtonDown;

	CTypedPtrArray<CObArray, MyShape* > shapes;
	MyShape* currentShape = NULL;
	
	bool isSelected;  // indicate that a shape was selected using right click
	enum ShapeBank { Pen, Line, Rectangle, Circle, Triangle, RectCirc , MagenDavid };//enum of all shapes
	int selectedShape;
	int currentSize;
	void drawAllShapes(CDC* dc);

	MyShape* shape = NULL;

	CPoint startSrc, EndDest;

	CPoint screenEnd;

	COLORREF currentColor;

	int sizeOfPen = 3;

	int maxSizePen = 10;
	int minSizePen = 1;
	

public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
	BOOL myCheckBtn;
	afx_msg void OnMenuFileLoad();
	afx_msg void OnMenuFileSave();
	afx_msg void OnBnClickedRadio1Rectangle();
	afx_msg void OnBnClickedRadio2Circle();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5Line();
	afx_msg void OnBnClickedRadio3();
	CMFCColorButton colorBox;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
