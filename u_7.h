#pragma once


// u_7 对话框

class u_7 : public CDialogEx
{
	DECLARE_DYNAMIC(u_7)

public:
	u_7(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic A_1;
	CListCtrl LI1;
	CStatic A_2;
	CEdit ED1;
	CStatic A_3;
	CStatic A_4;
	CStatic A_5;
	CStatic A_6;
	afx_msg void OnStnClickedSt6();
	CButton B_1;
	CEdit ED2;
	CEdit ED3;
	CEdit ED4;
	CEdit ED5;
	afx_msg void OnClickedButton1();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit9();
	CButton ui;
	afx_msg void OnClickedButton3();
	CEdit ED6;
};
