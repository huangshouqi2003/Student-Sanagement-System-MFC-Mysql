// u_3.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_3.h"
#include "u_4.h"
#include "u_5.h"
#include "u_6.h"
#include "u_7.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;

// u_3 对话框

IMPLEMENT_DYNAMIC(u_3, CDialogEx)

u_3::u_3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

u_3::~u_3()
{
}

void u_3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	A_1.SetWindowTextA("管理员界面");
	//  DDX_Control(pDX, IDC_LIST1, Q_1);
	DDX_Control(pDX, IDC_LIST2, HH_1);
	DDX_Control(pDX, IDCANCEL, jj);
	DDX_Control(pDX, IDC_COMBO1, cb_1);
	DDX_Control(pDX, IDC_ST2, A_2);
	DDX_Control(pDX, IDC_ST3, A_3);
	DDX_Control(pDX, IDC_EDIT1, B_1);
	DDX_Control(pDX, IDC_EDIT2, B_2);
	DDX_Control(pDX, IDC_ST4, A_4);
	DDX_Control(pDX, IDC_BUTTON1, xiugai);
}


BEGIN_MESSAGE_MAP(u_3, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &u_3::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &u_3::OnSelchangeCombo1)
	ON_STN_CLICKED(IDC_ST1, &u_3::OnStnClickedSt1)
	ON_BN_CLICKED(IDC_BUTTON1, &u_3::OnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &u_3::OnChangeEdit2)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &u_3::OnColumnclickList2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &u_3::OnDblclkList2)
END_MESSAGE_MAP()


// u_3 消息处理程序


void u_3::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL u_3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HH_1.InsertItem(0, "学生管理", 0);
	HH_1.InsertItem(1, "增加书籍", 0);
	HH_1.InsertItem(2, "删除书籍", 0);
	HH_1.InsertItem(3, "修改书籍", 0);
	HH_1.InsertItem(4, "查找书籍", 0);
	cb_1.SetWindowTextA("ID:");
	A_2.SetWindowTextA("ID:");
	A_3.SetWindowTextA("密码:");
	A_4.SetWindowTextA("ID:");
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
		mysql_query(&mysql, "select * from users;");
		UpdateData(true);
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			text.append(row[0]);
			cb_1.AddString(text.c_str());
			text = "";
		}

	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_3::OnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	CString text2;
	cb_1.GetLBText(cb_1.GetCurSel(), text1);
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
		mysql_query(&mysql, "select * from users;");
		UpdateData(true);
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[0] == text1)
			{
				text2 = row[1];
				break;
			}
		}
	}
	B_1.SetWindowTextA(text1);
	B_2.SetWindowTextA(text2);
}


void u_3::OnStnClickedSt1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void u_3::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	CString text2;
	B_1.GetWindowTextA(text1);
	B_2.GetWindowTextA(text2);
	int aa_1 = text2.GetLength();
	if (aa_1 > 10)
	{
		AfxMessageBox(_T("修改的密码不能超过10位"));
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
		char koo[265];
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		snprintf(koo, 256, "update users set pwd='%s' where id='%s'",text2,text1);
		if (!mysql_query(&mysql, koo))
		{
			AfxMessageBox(_T("修改成功"));
		}
		else
		{
			AfxMessageBox(_T("修改失败"));
		}
	}
}


void u_3::OnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void u_3::OnColumnclickList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
}


void u_3::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	CDialogEx::OnCancel();
	int i=pNMItemActivate->iItem;
	if (i == 1)
	{
		u_4 kkl;
		kkl.DoModal();
		return;
	}
	else if (i==0)
	{
		u_3 kk45;
		kk45.DoModal();
	}
	else if (i == 2)
	{
		u_5 kk2;
		kk2.DoModal();
		return;
	}
	else if (i == 3)
	{
		u_6 kk3;
		kk3.DoModal();
		return;
	}
	else if (i == 4)
	{
		u_7 kk4;
		kk4.DoModal();
		return;
	}
}
