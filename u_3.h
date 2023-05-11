#pragma once


// u_3 对话框

class u_3 : public CDialogEx
{
	DECLARE_DYNAMIC(u_3)

public:
	u_3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic A_1;
//	CListCtrl Q_1;
	CListCtrl HH_1;
	CButton jj;
	afx_msg void OnBnClickedCancel();
	CComboBox cb_1;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	CStatic A_2;
	CStatic A_3;
	CEdit B_1;
	CEdit B_2;
	afx_msg void OnStnClickedSt1();
	CStatic A_4;
	CButton xiugai;
	afx_msg void OnClickedButton1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnColumnclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
};
