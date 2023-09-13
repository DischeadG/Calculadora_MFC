
// CalculadoraDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculadora.h"
#include "CalculadoraDlg.h"
#include "afxdialogex.h"

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


// CCalculadoraDlg dialog



CCalculadoraDlg::CCalculadoraDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULADORA_DIALOG, pParent)
	, resultado(_T(""))
{
	num1 = num2 = num3 = 0;
	str1 = _T("");
	str2 = _T("");
	flag = true;
	operacion = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, resultado);
}

BEGIN_MESSAGE_MAP(CCalculadoraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(cero, &CCalculadoraDlg::OnBnClickedcero)
	ON_BN_CLICKED(uno, &CCalculadoraDlg::OnBnClickeduno)
	ON_BN_CLICKED(dos, &CCalculadoraDlg::OnBnClickeddos)
	ON_BN_CLICKED(tres, &CCalculadoraDlg::OnBnClickedtres)
	ON_BN_CLICKED(cuatro, &CCalculadoraDlg::OnBnClickedcuatro)
	ON_BN_CLICKED(cinco, &CCalculadoraDlg::OnBnClickedcinco)
	ON_BN_CLICKED(seis, &CCalculadoraDlg::OnBnClickedseis)
	ON_BN_CLICKED(siete, &CCalculadoraDlg::OnBnClickedsiete)
	ON_BN_CLICKED(ocho, &CCalculadoraDlg::OnBnClickedocho)
	ON_BN_CLICKED(nueve, &CCalculadoraDlg::OnBnClickednueve)
	ON_BN_CLICKED(mas, &CCalculadoraDlg::OnBnClickedmas)
	ON_BN_CLICKED(igual, &CCalculadoraDlg::OnBnClickedigual)
	ON_BN_CLICKED(menos, &CCalculadoraDlg::OnBnClickedmenos)
	ON_BN_CLICKED(multiplicacion, &CCalculadoraDlg::OnBnClickedmultiplicacion)
	ON_BN_CLICKED(division, &CCalculadoraDlg::OnBnClickeddivision)
	ON_BN_CLICKED(punto, &CCalculadoraDlg::OnBnClickedpunto)
	ON_BN_CLICKED(masmenos, &CCalculadoraDlg::OnBnClickedmasmenos)
	ON_BN_CLICKED(raiz, &CCalculadoraDlg::OnBnClickedraiz)
	ON_BN_CLICKED(clear, &CCalculadoraDlg::OnBnClickedclear)
	ON_BN_CLICKED(potencia, &CCalculadoraDlg::OnBnClickedpotencia)
	ON_BN_CLICKED(unosobrex, &CCalculadoraDlg::OnBnClickedunosobrex)
	ON_BN_CLICKED(deleterealnofake, &CCalculadoraDlg::OnBnClickeddeleterealnofake)
	ON_BN_CLICKED(clearone, &CCalculadoraDlg::OnBnClickedclearone)
	ON_BN_CLICKED(residuo, &CCalculadoraDlg::OnBnClickedresiduo)
END_MESSAGE_MAP()


// CCalculadoraDlg message handlers

BOOL CCalculadoraDlg::OnInitDialog()
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

void CCalculadoraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculadoraDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculadoraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculadoraDlg::OnBnClickedcero()
{
	if (flag == true) {
		str1 += _T("0");
		resultado = str1;
	}
	else {
		str2 += _T("0");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickeduno()
{
	if (flag == true) {
		str1 += _T("1");
		resultado = str1;
	}
	else {
		str2 += _T("1");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickeddos()
{
	if (flag == true) {
		str1 += _T("2");
		resultado = str1;
	}
	else {
		str2 += _T("2");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedtres()
{
	if (flag == true) {
		str1 += _T("3");
		resultado = str1;
	}
	else {
		str2 += _T("3");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedcuatro()
{
	if (flag == true) {
		str1 += _T("4");
		resultado = str1;
	}
	else {
		str2 += _T("4");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedcinco()
{
	if (flag == true) {
		str1 += _T("5");
		resultado = str1;
	}
	else {
		str2 += _T("5");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedseis()
{
	if (flag == true) {
		str1 += _T("6");
		resultado = str1;
	}
	else {
		str2 += _T("6");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedsiete()
{
	if (flag == true) {
		str1 += _T("7");
		resultado = str1;
	}
	else {
		str2 += _T("7");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedocho()
{
	if (flag == true) {
		str1 += _T("8");
		resultado = str1;
	}
	else {
		str2 += _T("8");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickednueve()
{
	if (flag == true) {
		str1 += _T("9");
		resultado = str1;
	}
	else {
		str2 += _T("9");
		resultado = str2;
	}
	UpdateData(false);
}

void CCalculadoraDlg::OnBnClickedpunto()
{
	if (flag == true) {
		str1 += _T(".");
		resultado = str1;
	}
	else {
		str2 += _T(".");
		resultado = str2;
	}
	UpdateData(false);
}


void CCalculadoraDlg::OnBnClickedmasmenos()
{
	if (resultado != _T("")) {
		double numero = _ttof(resultado);
		numero *= -1; 
		resultado.Format(_T("%.2f"), numero);
		UpdateData(false);
	}
}

void CCalculadoraDlg::OnBnClickedraiz()
{
	if (resultado != _T("")) {
		double numero = _ttof(resultado);
		if (numero >= 0) {
			numero = sqrt(numero);
			resultado.Format(_T("%.2f"), numero);
		}
		else {
			resultado = _T("Invalid Input");
		}
		UpdateData(false);
	}
}

void CCalculadoraDlg::OnBnClickedpotencia()
{
	if (resultado != _T("")) {
		double numero = _ttof(resultado);
		numero = numero * numero;
		resultado.Format(_T("%.2f"), numero);
		UpdateData(false);
	}
}

void CCalculadoraDlg::OnBnClickedunosobrex()
{
	if (resultado != _T("")) {
		double numero = _ttof(resultado);
		if (numero != 0) {
			numero = 1 / numero;
			resultado.Format(_T("%.2f"), numero);
		}
		else {
			resultado = _T("Cannot divide by zero");
		}
	}
	UpdateData(false);
}

void CCalculadoraDlg::OnBnClickeddeleterealnofake()
{
	if (!resultado.IsEmpty()) {
		resultado = resultado.Left(resultado.GetLength() - 1);
		UpdateData(false);
	}
}

void CCalculadoraDlg::OnBnClickedclearone()
{
	if (flag == true) {
		str1.Empty();
	}
	else {
		str2.Empty();
	}
	resultado.Empty();
	UpdateData(false);
}

void CCalculadoraDlg::OnBnClickedclear()
{
	num1 = num2 = num3 = 0;
	str1 = _T("");
	str2 = _T("");
	operacion = 0;
	resultado = _T("");
	UpdateData(false);
}

void CCalculadoraDlg::OnBnClickedresiduo()
{
	if (resultado != _T("")) {
		num1 = _ttof(resultado);
		flag = !flag;
		resultado = _T("");
		operacion = 5;
	}
}

void CCalculadoraDlg::OnBnClickedmas()
{
	if (resultado != _T("")) {
		float total = _ttof(resultado);
		num1 += total;
		resultado.Format(_T("%.2f"), num1);
		UpdateData(false);
		str1 = _T("");
		str2 = _T("");
		flag = true;
		operacion = 1;
	}
}

void CCalculadoraDlg::OnBnClickedmenos()
{
	if (resultado != _T("")) {
		float total = _ttof(resultado);
		if (operacion == 1) {
			num1 += total;
		}
		else {
			num1 = total;
		}
		resultado.Format(_T("%.2f"), num1);
		UpdateData(false);
		str1 = _T("");
		str2 = _T("");
		flag = true;
		operacion = 2;
	}
}

void CCalculadoraDlg::OnBnClickedmultiplicacion()
{
	if (operacion != 3) {
		num1 = _ttof(resultado);
		flag = !flag;
		resultado = _T("");
		operacion = 3;
	}
	else {
		float total = _ttof(resultado);
		num1 *= total;
		resultado.Format(_T("%.2f"), num1);
		UpdateData(false);
		str1 = _T("");
		str2 = _T("");
		flag = true;
		operacion = 3;
	}
}

void CCalculadoraDlg::OnBnClickeddivision()
{
	if (operacion != 4) {
		num1 = _ttof(resultado);
		flag = !flag;
		resultado = _T("");
		operacion = 4;
	}
	else {
		float total = _ttof(resultado);
		num1 /= total;
		resultado.Format(_T("%.2f"), num1);
		UpdateData(false);
		str1 = _T("");
		str2 = _T("");
		flag = true;
		operacion = 4;
	}
}

void CCalculadoraDlg::OnBnClickedigual()
{
	if (resultado != _T("")) {
		num2 = _ttof(resultado);
		flag = !flag;
		resultado = _T("");
	}
	switch (operacion)
	{
	case 1:
		num3 = num1 + num2;
		break;
	case 2:
		num3 = num1 - num2;
		break;
	case 3:
		num3 = num1 * num2;
		break;
	case 4:
		if (num2 > 0) {
			num3 = num1 / num2;
		}
		else {
			resultado = _T("cannot divide by zero");
		}
		break;
	case 5:
		num3 = (num1 / 100) * num2;
		break;
	default:
		num3 = num2;
		break;
	}
	resultado.Format(_T("%.2f"), num3);
	UpdateData(false);
	str1 = _T("");
	str2 = _T("");
	operacion = 0;
}
