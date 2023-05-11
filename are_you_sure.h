#pragma once


// are_you_sure 对话框

class are_you_sure : public CDialogEx
{
	DECLARE_DYNAMIC(are_you_sure)

public:
	are_you_sure(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~are_you_sure();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton back_1;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CButton ture_1;
	afx_msg void OnBnClickedOk();
};
