#pragma once


// xue1 对话框

class xue1 : public CDialogEx
{
	DECLARE_DYNAMIC(xue1)

public:
	xue1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xue1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIxue1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EGO_1;
	CEdit EDP1;
	CEdit EDP2;
	CEdit EDP3;
	CEdit EDP4;
	CEdit EDP5;
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit2();
	CButton B_1;
	CEdit num;
	afx_msg void OnClickedButton3_1();
};
