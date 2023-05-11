// xue2.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "xue2.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// xue2 对话框

IMPLEMENT_DYNAMIC(xue2, CDialogEx)

xue2::xue2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIxue2, pParent)
{

}

xue2::~xue2()
{
}

void xue2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EW1);
	DDX_Control(pDX, IDC_EDIT2, EW2);
	DDX_Control(pDX, IDC_EDIT3, EW3);
	DDX_Control(pDX, IDC_EDIT4, EW4);
	DDX_Control(pDX, IDC_EDIT5, EW5);
	DDX_Control(pDX, IDC_EDIT6, EW6);
	DDX_Control(pDX, IDC_BUTTON3, huan);
	DDX_Control(pDX, IDC_EDIT7, youid);
	DDX_Control(pDX, IDC_BUTTON5, gghg);
}


BEGIN_MESSAGE_MAP(xue2, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &xue2::OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &xue2::OnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &xue2::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &xue2::OnClickedButton5)
END_MESSAGE_MAP()


// xue2 消息处理程序


void xue2::OnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	EW2.SetWindowTextA("");
	EW3.SetWindowTextA("");
	EW4.SetWindowTextA("");
	EW5.SetWindowTextA("");
	CString text1;
	EW1.GetWindowTextA(text1);
	CString shei;
	youid.GetWindowTextA(shei);
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
		int oopp;
		char koo[265];
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		mysql_query(&mysql, "select * from history;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			oopp = _ttoi(row[4]);
			if (row[1] == text1&&row[5]==shei&&oopp!=0)
			{
				EW2.SetWindowTextA(row[1]);
				EW3.SetWindowTextA(row[2]);
				EW4.SetWindowTextA(row[3]);
				EW5.SetWindowTextA(row[4]);
				return;
			}
		}
	}
}


void xue2::OnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ttu;
	EW2.GetWindowTextA(ttu);
	if (ttu == "")
	{
		AfxMessageBox(_T("无此书"));
		return;
	}
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

		CString num;
		EW6.GetWindowTextA(num);
		CString ID;
		EW1.GetWindowTextA(ID);
		CString shei;
		youid.GetWindowTextA(shei);
		if (ID == "" || num == "")
		{
			AfxMessageBox(_T("不能有选项为空"));
			return;
		}
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		mysql_query(&mysql, "select * from history;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[5]==shei&&row[1]==ID)
			{
				int folg = 0;
				CString n1 = row[4];
				CString n2 = num;
				CString tatal;
				int j1, j2, j3;
				j1 = _ttoi(n1);
				j2= _ttoi(n2);
				j3 = j1 - j2;
				if (j3 < 0)
				{
					folg = 1;
					AfxMessageBox(_T("书没有那么多"));
					return;
				}
				else if (j2<=0)
				{
					AfxMessageBox(_T("数量不能为0或负数"));
					return;
				}
				if (folg == 0)
				{
					tatal.Format(_T("%d"), j3);
					char temp[256];
					snprintf(temp, 256, "update history set number='%s' where ci='%s'", tatal, row[0]);
					mysql_query(&mysql, temp);
					AfxMessageBox(_T("还书成功"));
					folg = 0;
					break;
				}
			}
		}
		mysql_query(&mysql,"quit");
		mysql_query(&mysql, "select * from book;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[0]==ID )
			{
				CString n1 = row[3];
				CString n2 = num;
				CString tatal;
				int j1, j2, j3;
				j1 = _ttoi(n1);
				j2 = _ttoi(n2);
				j3 = j1 +j2;
				tatal.Format(_T("%d"), j3);
				char temp1[256];
				snprintf(temp1, 256, "update book set number='%s' where id='%s'",tatal, row[0]);
				mysql_query(&mysql, temp1);
				break;
			}
		}

	}
}


void xue2::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void xue2::OnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString shei;
	int aapp;
	youid.GetWindowTextA(shei);
	CString aa="你借的书ID有：";
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
		char koo[265];
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		mysql_query(&mysql, "select * from history;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			aapp = _ttoi(row[4]);
			if (row[5] == shei&&aapp!=0)
			{
				aa.Append(row[1]);
			}
		}
		if (aa == "你借的书ID有：")
		{
			AfxMessageBox("你还没借书呢");
			return;
		}
		AfxMessageBox(aa);
	}
}
