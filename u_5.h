#pragma once


// u_5 对话框

class u_5 : public CDialogEx
{
	DECLARE_DYNAMIC(u_5)

public:
	u_5(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic A_1;
	CListCtrl LI5;
	virtual BOOL OnInitDialog();
	CButton B_1;
	afx_msg void OnClickedButton1();
	CStatic A_2;
	CEdit C_1;
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
};
