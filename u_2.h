#pragma once


// u_2 对话框

class u_2 : public CDialogEx
{
	DECLARE_DYNAMIC(u_2)

public:
	u_2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EDO_1;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButton2();
	CButton jie;
	CButton huan;
	CButton cha;
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton4();
};
