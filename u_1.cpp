// u_1.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_1.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// u_1 对话框

IMPLEMENT_DYNAMIC(u_1, CDialogEx)

u_1::u_1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

u_1::~u_1()
{
}

void u_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_ST1, A_1);

	//  DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDC_ST1, A_2);
	DDX_Control(pDX, IDC_ST1, A_2);
	DDX_Control(pDX, IDC_ST2, A_3);
	DDX_Control(pDX, IDC_ST3, A_4);
	DDX_Control(pDX, IDC_ST4, A_5);
	A_2.SetWindowTextA("注册界面");
	A_3.SetWindowTextA("账号");
	A_4.SetWindowTextA("密码");
	A_5.SetWindowTextA("确认密码");
	DDX_Control(pDX, IDC_EDIT1, B_1);
	DDX_Control(pDX, IDC_EDIT2, B_2);
	DDX_Control(pDX, IDC_EDIT3, B_3);
	DDX_Control(pDX, IDCANCEL, tuichu);
	DDX_Control(pDX, IDOK, zhuche);
}


BEGIN_MESSAGE_MAP(u_1, CDialogEx)
	ON_STN_CLICKED(IDC_ST4, &u_1::OnStnClickedSt4)
	ON_STN_CLICKED(IDC_ST2, &u_1::OnStnClickedSt2)
	ON_EN_CHANGE(IDC_EDIT2, &u_1::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &u_1::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &u_1::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &u_1::OnBnClickedCancel)
END_MESSAGE_MAP()


// u_1 消息处理程序


void u_1::OnStnClickedSt4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void u_1::OnStnClickedSt2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void u_1::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void u_1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void u_1::OnBnClickedOk()//
{
	// TODO: 在此添加控件通知处理程序代码
	char text1[256];
	char text2[256];
	char text3[256];
	B_1.GetWindowTextA(text1,256);
	B_2.GetWindowTextA(text2,256);
	B_3.GetWindowTextA(text3,256);
	int a = strlen(text1);
	int b = strlen(text2);
	int c = strlen(text3);
	if (a > 10||b>10||c>10)
	{
		AfxMessageBox(_T("账号密码不能超过10位"));
		CDialogEx::OnCancel();
		return;
	}
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	//初始化数据库对象
	mysql_init(&mysql);
	CString kl;
	if (!mysql_real_connect(&mysql, "localhost", "root",
		"", "library", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败!"));
		return;
	}
	else
	{
		if (strcmp(text2,text3))
		{
			AfxMessageBox(_T("两次密码不一致！"));
		}
		else
		{
			mysql_query(&mysql, "SET NAMES 'GB2312'");
			char kp[256];
			snprintf(kp, 256, "insert into users values('%s', '%s')", text1, text2);
			if (!mysql_query(&mysql, kp))
			{
				AfxMessageBox(_T("注册成功"));
				CDialogEx::OnCancel();
			}
			else
			{
				AfxMessageBox(_T("注册失败，账号已被占用"));
			}
			UpdateData(true);
		}
	}
}


void u_1::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
