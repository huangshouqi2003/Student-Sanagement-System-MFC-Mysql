#pragma once


// xueshengguanli 对话框

class xueshengguanli : public CDialogEx
{
	DECLARE_DYNAMIC(xueshengguanli)

public:
	xueshengguanli(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xueshengguanli();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
