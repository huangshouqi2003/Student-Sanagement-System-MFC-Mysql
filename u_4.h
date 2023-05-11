#pragma once


// u_4 对话框

class u_4 : public CDialogEx
{
	DECLARE_DYNAMIC(u_4)

public:
	u_4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic A_1;
	CListCtrl LI1;
	CStatic A_2;
	CStatic A_3;
	CStatic A_4;
	CStatic A_5;
	CEdit EDI1;
	CEdit EDI2;
	CEdit EDI3;
	CEdit EDI4;
	CButton btt_1;
	afx_msg void OnClickedButton3();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
};
