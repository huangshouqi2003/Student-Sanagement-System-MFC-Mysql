
// MFCbookbaseDlg.h: 头文件
//

#pragma once


// CMFCbookbaseDlg 对话框
class CMFCbookbaseDlg : public CDialogEx
{
// 构造
public:
	CMFCbookbaseDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBOOKBASE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic A_1;
	CButton guanyu;
	afx_msg void OnBnClickedOk();
	CButton tuicu;
	afx_msg void OnBnClickedCancel();
	CStatic A_2;
	CStatic A_3;
	afx_msg void OnEnChangeEdit2();
	CEdit B_1;
	CEdit B_2;
	CButton C_1;
	CButton C_2;
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton1();
};
