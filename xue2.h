#pragma once


// xue2 对话框

class xue2 : public CDialogEx
{
	DECLARE_DYNAMIC(xue2)

public:
	xue2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xue2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIxue2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EW1;
	CEdit EW2;
	CEdit EW3;
	CEdit EW4;
	CEdit EW5;
	CEdit EW6;
	CButton huan;
	afx_msg void OnChangeEdit1();
	afx_msg void OnClickedButton3();
	CEdit youid;
	afx_msg void OnEnChangeEdit2();
	CButton gghg;
	afx_msg void OnClickedButton5();
};
