// u_2.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_2.h"
#include"xue1.h"
#include"xue2.h"
#include"xue3.h"
#include "afxdialogex.h"


// u_2 对话框

IMPLEMENT_DYNAMIC(u_2, CDialogEx)

u_2::u_2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

u_2::~u_2()
{
}

void u_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EDO_1);
	DDX_Control(pDX, IDC_BUTTON1, jie);
	DDX_Control(pDX, IDC_BUTTON2, huan);
	DDX_Control(pDX, IDC_BUTTON4, cha);
}


BEGIN_MESSAGE_MAP(u_2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &u_2::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &u_2::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &u_2::OnClickedButton4)
END_MESSAGE_MAP()


// u_2 消息处理程序


BOOL u_2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_2::OnClickedButton2()
{
	CString ggh;
	EDO_1.GetWindowTextA(ggh);
	UpdateData(TRUE);
	xue2* dlg = new xue2;
	dlg->Create(IDD_DIxue2, this);
	dlg->youid.SetWindowTextA(ggh);
	dlg->UpdateData(FALSE);
	dlg->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void u_2::OnClickedButton1()
{
	CString ggh;
	EDO_1.GetWindowTextA(ggh);
	UpdateData(TRUE);
	xue1* dlg = new xue1;
	dlg->Create(IDD_DIxue1, this);
	dlg->EGO_1.SetWindowTextA(ggh);
	dlg->UpdateData(FALSE);
	dlg->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void u_2::OnClickedButton4()
{
	xue3 kk3;
	kk3.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
