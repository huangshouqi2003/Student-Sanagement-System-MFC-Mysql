// are_you_sure.cpp: 实现文件
//

#include "pch.h"
#include "u_5.h"
#include "MFCbookbase.h"
#include "are_you_sure.h"
#include "afxdialogex.h"


// are_you_sure 对话框

IMPLEMENT_DYNAMIC(are_you_sure, CDialogEx)

are_you_sure::are_you_sure(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

are_you_sure::~are_you_sure()
{
}

void are_you_sure::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, back_1);
	DDX_Control(pDX, IDOK, ture_1);
}


BEGIN_MESSAGE_MAP(are_you_sure, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &are_you_sure::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &are_you_sure::OnBnClickedOk)
END_MESSAGE_MAP()


// are_you_sure 消息处理程序


void are_you_sure::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	u_5 yu;
	yu.DoModal();
	CDialogEx::OnCancel();
}


BOOL are_you_sure::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void are_you_sure::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
