// u_7.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_7.h"
#include "afxdialogex.h"
#include "u_3.h"
#include "u_4.h"
#include "u_5.h"
#include "u_6.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// u_7 对话框

IMPLEMENT_DYNAMIC(u_7, CDialogEx)

u_7::u_7(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

u_7::~u_7()
{
}

void u_7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDC_LIST2, LI1);
	DDX_Control(pDX, IDC_ST2, A_2);
	DDX_Control(pDX, IDC_EDIT1, ED1);
	DDX_Control(pDX, IDC_ST3, A_3);
	DDX_Control(pDX, IDC_ST5, A_4);
	DDX_Control(pDX, IDC_ST6, A_5);
	DDX_Control(pDX, IDC_ST7, A_6);
	DDX_Control(pDX, IDC_BUTTON1, B_1);
	DDX_Control(pDX, IDC_EDIT2, ED2);
	DDX_Control(pDX, IDC_EDIT4, ED3);
	DDX_Control(pDX, IDC_EDIT5, ED4);
	DDX_Control(pDX, IDC_EDIT6, ED5);
	DDX_Control(pDX, IDC_BUTTON3, ui);
	DDX_Control(pDX, IDC_EDIT9, ED6);
}


BEGIN_MESSAGE_MAP(u_7, CDialogEx)
	ON_STN_CLICKED(IDC_ST6, &u_7::OnStnClickedSt6)
	ON_BN_CLICKED(IDC_BUTTON1, &u_7::OnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &u_7::OnDblclkList2)
	ON_EN_CHANGE(IDC_EDIT9, &u_7::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_BUTTON3, &u_7::OnClickedButton3)
END_MESSAGE_MAP()


// u_7 消息处理程序


BOOL u_7::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	A_1.SetWindowTextA("查找书籍");
	LI1.InsertItem(0, "学生管理", 0);
	LI1.InsertItem(1, "增加书籍", 0);
	LI1.InsertItem(2, "删除书籍", 0);
	LI1.InsertItem(3, "修改书籍", 0);
	LI1.InsertItem(4, "查找书籍", 0);
	A_2.SetWindowTextA("请输入查找的书名");
	A_3.SetWindowTextA("ID：");
	A_4.SetWindowTextA("书名：");
	A_5.SetWindowTextA("作者：");
	A_6.SetWindowTextA("数量：");
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_7::OnStnClickedSt6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void u_7::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	ED1.GetWindowTextA(text1);
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int flag = 0;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root",
		"", "library", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败!"));
		CDialogEx::OnCancel();
	}
	else
	{
		CString aa = "书名相同的书ID有：";
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		mysql_query(&mysql, "select * from book;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[1] == text1)
			{
				aa.Append(row[0]);
				aa.Append("");
			}
		}
		if (aa == "书名相同的书ID有：")
		{
			AfxMessageBox(_T("无此书"));
			return;
		}
		AfxMessageBox(aa);
	}
}


void u_7::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CDialogEx::OnCancel();
	int i = pNMItemActivate->iItem;
	if (i == 1)
	{
		u_4 kkl;
		kkl.DoModal();
	}
	else if (i == 2)
	{
		u_5 kk2;
		kk2.DoModal();
	}
	else if (i == 3)
	{
		u_6 kk3;
		kk3.DoModal();
	}
	else if (i == 0)
	{
		u_3 kk4;
		kk4.DoModal();
	}
	else if (i == 4)
	{
		u_7 kk7;
		kk7.DoModal();
	}
}


void u_7::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void u_7::OnClickedButton3()
{
	CString text1;
	ED6.GetWindowTextA(text1);
	// TODO: 在此添加控件通知处理程序代码
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root",
		"", "library", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败!"));
		CDialogEx::OnCancel();
	}
	else
	{
	mysql_query(&mysql, "SET NAMES 'GB2312'");
	UpdateData(true);
	mysql_query(&mysql, "select * from book;");
	res = mysql_store_result(&mysql);
	while (row = mysql_fetch_row(res))
	{
		if (row[0] == text1)
		{
			ED2.SetWindowTextA(row[0]);
			ED3.SetWindowTextA(row[1]);
			ED4.SetWindowTextA(row[2]);
			ED5.SetWindowTextA(row[3]);
			return;
		}
	}
	AfxMessageBox(_T("无此书"));
	return;
	}
}
