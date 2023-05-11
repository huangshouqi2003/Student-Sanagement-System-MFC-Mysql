#pragma once


// xue3 对话框

class xue3 : public CDialogEx
{
	DECLARE_DYNAMIC(xue3)

public:
	xue3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xue3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIxue3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton chazao;
	afx_msg void OnClickedButton3();
	CEdit ED_1;
	CEdit ED_2;
	CEdit ED_3;
	CEdit ED_4;
	CEdit ED_5;
	CButton chazao1;
	CEdit ED_6;
	afx_msg void OnClickedButton5();
	CComboBox yyy;
	virtual BOOL OnInitDialog();
};
