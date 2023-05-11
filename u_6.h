#pragma once


// u_6 对话框

class u_6 : public CDialogEx
{
	DECLARE_DYNAMIC(u_6)

public:
	u_6(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic A_1;
	CListCtrl JK_1;
	CStatic A_2;
	CEdit EDG1;
	CButton kkij;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit D_1;
	CEdit D_2;
	CEdit D_3;
	CEdit D_4;
	CEdit D_5;
	CEdit D_6;
	CEdit D_7;
	CEdit D_8;
	afx_msg void OnChangeEdit1();
	afx_msg void OnClickedButton1();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
};
