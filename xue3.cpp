// xue3.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "xue3.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// xue3 对话框

IMPLEMENT_DYNAMIC(xue3, CDialogEx)

xue3::xue3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIxue3, pParent)
{

}

xue3::~xue3()
{
}

void xue3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON3, chazao);
	DDX_Control(pDX, IDC_EDIT1, ED_1);
	DDX_Control(pDX, IDC_EDIT2, ED_2);
	DDX_Control(pDX, IDC_EDIT3, ED_3);
	DDX_Control(pDX, IDC_EDIT4, ED_4);
	DDX_Control(pDX, IDC_EDIT5, ED_5);
	DDX_Control(pDX, IDC_BUTTON5, chazao1);
	DDX_Control(pDX, IDC_EDIT6, ED_6);
	DDX_Control(pDX, IDC_COMBO2, yyy);
}


BEGIN_MESSAGE_MAP(xue3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &xue3::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &xue3::OnClickedButton5)
END_MESSAGE_MAP()


// xue3 消息处理程序


void xue3::OnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	ED_1.GetWindowTextA(text1);
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


void xue3::OnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	ED_6.GetWindowTextA(text1);
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
				ED_2.SetWindowTextA(row[0]);
				ED_3.SetWindowTextA(row[1]);
				ED_4.SetWindowTextA(row[2]);
				ED_5.SetWindowTextA(row[3]);
				return;
			}
		}
		AfxMessageBox(_T("无此书"));
		return;
	}
}


BOOL xue3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
		CDialogEx::OnCancel();
	}
	else
	{
		string text;
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		mysql_query(&mysql, "select * from book;");
		UpdateData(true);
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			text = "ID:";
			text.append(row[0]);
			text.append("  书名");
			text.append(row[1]);
			text.append("  作者");
			text.append(row[2]);
			text.append("  数量");
			text.append(row[3]);
			yyy.AddString(text.c_str());
		}

	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
