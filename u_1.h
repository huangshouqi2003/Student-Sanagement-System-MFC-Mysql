#pragma once


// u_1 对话框

class u_1 : public CDialogEx
{
	DECLARE_DYNAMIC(u_1)

public:
	u_1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~u_1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CButton tuicu;
//	CStatic A_1;
//	CStatic A_1;
//	CStatic A_2;
	CStatic A_2;
	afx_msg void OnStnClickedSt4();
	afx_msg void OnStnClickedSt2();
	CStatic A_3;
	CStatic A_4;
	CStatic A_5;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CEdit B_1;
	CEdit B_2;
	CEdit B_3;
	CButton tuichu;
	CButton zhuche;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
