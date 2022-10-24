
// MFCApplication4Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include "MyRectCirc.h"
#include "MyTriangle.h"
#include "MyLine.h"
#include "MyPen.h"
#include "MyMagenDavid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication4Dlg dialog


CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, myCheckBtn(FALSE) ,currentShape(NULL) ,currentSize(5), currentColor(RGB(0, 0, 0)), isSelected(FALSE), lButtonDown(FALSE),selectedShape(NULL), shape(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	lButtonDown = FALSE;
	isSelected = FALSE;
	shape = NULL;
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colorBox);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_FILE_LOAD, &CMFCApplication4Dlg::OnMenuFileLoad)
	ON_COMMAND(ID_MENU_FILE_SAVE, &CMFCApplication4Dlg::OnMenuFileSave)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_RADIO1_RECTANGLE, &CMFCApplication4Dlg::OnBnClickedRadio1Rectangle)
	ON_BN_CLICKED(IDC_RADIO2_CIRCLE, &CMFCApplication4Dlg::OnBnClickedRadio2Circle)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication4Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)


	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication4Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5_LINE, &CMFCApplication4Dlg::OnBnClickedRadio5Line)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication4Dlg::OnBnClickedRadio3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCApplication4Dlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCApplication4Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDOK, &CMFCApplication4Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication4Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFCApplication4Dlg message handlers

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CPoint screenStart;
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen* old = dc.SelectObject(&pen);
		screenEnd.x = 650 + 200 + 50;
		screenEnd.y = 345 + 200 + 82;
		screenStart.x = 8;
		screenStart.y = 5;

		dc.Rectangle(screenStart.x, screenStart.y, screenEnd.x, screenEnd.y);
		dc.SelectObject(old);
		
		drawAllShapes(&dc);

		if (isSelected)
		{
			shape->drawAsSelected(&dc);
		}
		if (shape != NULL)
		{  
			shape->draw(&dc);
			delete shape;
		}

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication4Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{

	CClientDC dc(this);
	if (point.x <= screenEnd.x && point.y <= screenEnd.y)
	{
		lButtonDown = true;
		startSrc = point;
		

		if (selectedShape == ShapeBank::Pen) 
		{
			COLORREF color = colorBox.GetColor();
			shapes.Add(new MyPen(point, color, sizeOfPen));
		}
	}
	
CDialogEx::OnLButtonDown(nFlags, point);
}
	

void CMFCApplication4Dlg::OnMouseMove(UINT nFlags, CPoint point)
{

	if (lButtonDown)
	{
		COLORREF color = colorBox.GetColor();

		CClientDC dc(this);

		if (selectedShape == ShapeBank::Triangle)
		{
			shape = new MyTriangle(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Rectangle)
		{
			shape = new MyRectangle(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Line)
		{
			shape = new MyLine(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Circle)
		{
			shape = new MyCircle(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::RectCirc)
		{
			shape = new MyRectCirc(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::MagenDavid)
		{
			shape = new MyMagenDavid(startSrc, point, RGB(0,0,255), sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Pen)
		{
			MyPen* pen = dynamic_cast<MyPen*>(shapes[shapes.GetSize() - 1]);
			// if the object is not 'MyPen' so the dynamic_cast fails and return null

			if (pen != NULL) 
			{
				pen->build(point);
				Invalidate();
			}

		}

		if (shape != NULL)
		{
			
			Invalidate();
			
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCApplication4Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{

	if (lButtonDown)
	{

		COLORREF color = colorBox.GetColor();

		CClientDC dc(this);
		if (selectedShape == ShapeBank::Triangle)
		{
			shape = new MyTriangle(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Rectangle)
		{
			shape = new MyRectangle(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Circle)
		{
			shape = new MyCircle(startSrc, point, color, sizeOfPen);
			
		}
		else if (selectedShape == ShapeBank::RectCirc)
		{
			shape = new MyRectCirc(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::Line)
		{
			shape = new MyLine(startSrc, point, color, sizeOfPen);
		}
		else if (selectedShape == ShapeBank::MagenDavid)
		{
			shape = new MyMagenDavid(startSrc, point, RGB(0,0,255), sizeOfPen);
		}
		else 	if (selectedShape == ShapeBank::Pen)
		{
			MyPen* pen = dynamic_cast<MyPen*>(shapes[shapes.GetSize() - 1]);
			// if the object is not 'MyPen' so the dynamic_cast fails and return null


			if (pen != NULL)
			{
				pen->build(point);
				Invalidate();
			}
		}


		if (shape != NULL)
		{
			shapes.Add(shape); // הוספת אובייקטים למערך המצביעים הטמפלייטי
			Invalidate();
		}
		
	}

	shape = NULL;
	lButtonDown = FALSE;

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CMFCApplication4Dlg::drawAllShapes(CDC* dc)
{
	int max = (int)shapes.GetSize();
	for (int i = 0; i < max; i++)
	{
		shapes[i]->draw(dc); // הפונקציה מציירת כל צורה במערך הצורות בדרך הרלוונטית לאותה צורה - שימוש בפולימורפיזם
	}
}

//שיופיע בתפריט

void CMFCApplication4Dlg::OnMenuFileLoad()
{
	const TCHAR szFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (fDialog.DoModal() == IDOK)
	{
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();     //מוחק את המסך ומצייר אותו מחדש
	}
}


void CMFCApplication4Dlg::OnMenuFileSave()
{
	const TCHAR szFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if (fDialog.DoModal() == IDOK)
	{
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}



void CMFCApplication4Dlg::OnBnClickedRadio1Rectangle()
{
	selectedShape = ShapeBank::Rectangle;
}


void CMFCApplication4Dlg::OnBnClickedRadio2Circle()
{
	selectedShape = ShapeBank::Circle;
}


void CMFCApplication4Dlg::OnBnClickedRadio1()
{
	selectedShape = ShapeBank::Triangle;

}


void CMFCApplication4Dlg::OnBnClickedButton1() // clear
{
	int length = shapes.GetCount();
	for (int i = 0; i < length; i++)
	{
		delete shapes[i];
	}

	shapes.RemoveAll();
	Invalidate();
}


void CMFCApplication4Dlg::OnBnClickedButton2() // undo
{
	int lastIndex = shapes.GetCount() - 1;
	if (lastIndex >= 0) {

		delete shapes[lastIndex];


		shapes.RemoveAt(lastIndex);
		Invalidate();

	}
}


void CMFCApplication4Dlg::OnBnClickedRadio4()
{
	selectedShape = ShapeBank::RectCirc;
}


void CMFCApplication4Dlg::OnBnClickedRadio5Line()
{
	selectedShape = ShapeBank::Line;
}


void CMFCApplication4Dlg::OnBnClickedRadio3()
{

	selectedShape = ShapeBank::Pen;
}


void CMFCApplication4Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	*pResult = 0;

	CSliderCtrl * slider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);

	int numberPercent = slider->GetPos();

	sizeOfPen =( numberPercent * maxSizePen  )/ 100;
}


void CMFCApplication4Dlg::OnBnClickedRadio6()
{
	
	selectedShape = ShapeBank::MagenDavid;
}


void CMFCApplication4Dlg::OnBnClickedOk()
{
	OnBnClickedButton1();
	CDialogEx::OnOK();
}


void CMFCApplication4Dlg::OnBnClickedCancel()
{
	OnBnClickedButton1();
	CDialogEx::OnCancel();
}
