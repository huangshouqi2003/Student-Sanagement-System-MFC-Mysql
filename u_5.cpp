// u_5.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_5.h"
#include"are_you_sure.h"
#include "afxdialogex.h"
#include "u_4.h"
#include "afxdialogex.h"
#include "u_3.h"
#include "u_6.h"
#include "u_7.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// u_5 对话框

IMPLEMENT_DYNAMIC(u_5, CDialogEx)

u_5::u_5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

u_5::~u_5()
{
}

void u_5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDC_LIST2, LI5);
	DDX_Control(pDX, IDC_BUTTON1, B_1);
	DDX_Control(pDX, IDC_ST2, A_2);
	DDX_Control(pDX, IDC_EDIT1, C_1);
}


BEGIN_MESSAGE_MAP(u_5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &u_5::OnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &u_5::OnDblclkList2)
END_MESSAGE_MAP()


// u_5 消息处理程序


BOOL u_5::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	A_1.SetWindowTextA("删除书籍界面");
	A_2.SetWindowTextA("请输入你要删除书籍的ID:");
	// TODO:  在此添加额外的初始化
	LI5.InsertItem(0, "学生管理", 0);
	LI5.InsertItem(1, "增加书籍", 0);
	LI5.InsertItem(2, "删除书籍", 0);
	LI5.InsertItem(3, "修改书籍", 0);
	LI5.InsertItem(4, "查找书籍", 0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_5::OnClickedButton1()
{
	CString text1;
	C_1.GetWindowTextA(text1);
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
		mysql_query(&mysql, "select * from book;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[0] == text1)
			{
				mysql_query(&mysql, "SET NAMES 'GB2312'");
				char kp[256];
				snprintf(kp, 256, "delete from book where id='%s'", text1);
				if (!mysql_query(&mysql, kp))
				{
					AfxMessageBox("删除成功");
					return;
				}
				else
				{
					AfxMessageBox(_T("删除失败"));
					return;
				}
			}
		}
		AfxMessageBox(_T("没有此书"));
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}


void u_5::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
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
		u_5 kk6;
		kk6.DoModal();
	}
	else if (i == 4)
	{
		u_7 kk2;
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
}
