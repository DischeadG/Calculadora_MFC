
// CalculadoraDlg.h : header file
//

#pragma once


// CCalculadoraDlg dialog
class CCalculadoraDlg : public CDialogEx
{
// Construction
public:
	CCalculadoraDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULADORA_DIALOG };
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
	CString resultado;
	float num1, num2, num3;
	CString str1, str2;
	bool flag;
	int operacion;
	afx_msg void OnBnClickedcero();
	afx_msg void OnBnClickeduno();
	afx_msg void OnBnClickeddos();
	afx_msg void OnBnClickedtres();
	afx_msg void OnBnClickedcuatro();
	afx_msg void OnBnClickedcinco();
	afx_msg void OnBnClickedseis();
	afx_msg void OnBnClickedsiete();
	afx_msg void OnBnClickedocho();
	afx_msg void OnBnClickednueve();
	afx_msg void OnBnClickedmas();
	afx_msg void OnBnClickedigual();
	afx_msg void OnBnClickedmenos();
	afx_msg void OnBnClickedmultiplicacion();
	afx_msg void OnBnClickeddivision();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedpunto();
	afx_msg void OnBnClickedmasmenos();
	afx_msg void OnBnClickedraiz();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedpotencia();
	afx_msg void OnBnClickedunosobrex();
	afx_msg void OnBnClickeddeleterealnofake();
	afx_msg void OnBnClickedclearone();
	afx_msg void OnBnClickedresiduo();
};
