// u_6.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_6.h"
#include "afxdialogex.h"
#include "u_7.h"
#include "afxdialogex.h"
#include "u_3.h"
#include "u_4.h"
#include "u_5.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// u_6 对话框

IMPLEMENT_DYNAMIC(u_6, CDialogEx)

u_6::u_6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

u_6::~u_6()
{
}

void u_6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDC_LIST2, JK_1);
	DDX_Control(pDX, IDC_ST6, A_2);
	DDX_Control(pDX, IDC_EDIT1, EDG1);
	DDX_Control(pDX, IDC_BUTTON1, kkij);
	DDX_Control(pDX, IDC_EDIT2, D_1);
	DDX_Control(pDX, IDC_EDIT4, D_2);
	DDX_Control(pDX, IDC_EDIT5, D_3);
	DDX_Control(pDX, IDC_EDIT6, D_4);
	DDX_Control(pDX, IDC_EDIT7, D_5);
	DDX_Control(pDX, IDC_EDIT8, D_6);
	DDX_Control(pDX, IDC_EDIT9, D_7);
	DDX_Control(pDX, IDC_EDIT10, D_8);
}


BEGIN_MESSAGE_MAP(u_6, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &u_6::OnLvnItemchangedList2)
	ON_EN_CHANGE(IDC_EDIT1, &u_6::OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &u_6::OnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &u_6::OnDblclkList2)
END_MESSAGE_MAP()


// u_6 消息处理程序


BOOL u_6::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	A_1.SetWindowTextA("修改界面");
	A_2.SetWindowTextA("请输入你要修改的ID");
	JK_1.InsertItem(0, "学生管理", 0);
	JK_1.InsertItem(1, "增加书籍", 0);
	JK_1.InsertItem(2, "删除书籍", 0);
	JK_1.InsertItem(3, "修改书籍", 0);
	JK_1.InsertItem(4, "查找书籍", 0);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_6::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void u_6::OnChangeEdit1()
{

	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	D_1.SetWindowTextA("");
	D_2.SetWindowTextA("");
	D_3.SetWindowTextA("");
	D_4.SetWindowTextA("");
	CString text1;
	EDG1.GetWindowTextA(text1);
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
		mysql_query(&mysql, "select * from book;");
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res))
		{
			if (row[0] == text1)
			{
				D_1.SetWindowTextA(row[0]);
				D_2.SetWindowTextA(row[1]);
				D_3.SetWindowTextA(row[2]);
				D_4.SetWindowTextA(row[3]);
				return; 
			}
		}
	}
}


void u_6::OnClickedButton1()
{
	CString k1;
	CString k2;
	CString k3;
	CString k4;
	CString k5;
	CString k6;
	D_1.GetWindowTextA(k6);
	EDG1.GetWindowTextA(k5);
	D_5.GetWindowTextA(k1);
	D_6.GetWindowTextA(k2);
	D_7.GetWindowTextA(k3);
	D_8.GetWindowTextA(k4);
	int aa_1 = _ttoi(k4);
	if (k1 == "" || k2 == "" || k3 == "" || k4 == "")
	{
		AfxMessageBox(_T("不能有修改项为空"));
		return;
	}
	if (aa_1<=0)
	{
		AfxMessageBox(_T("数量不能为0或负数"));
		return;
	}
	else if (k6 == "")
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
		char koo[265];
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		snprintf(koo, 256, "update book set id='%s',bookname='%s',author='%s',number='%s' where id='%s'",k1,k2,k3,k4,k5);
		if (!mysql_query(&mysql, koo))
		{
			AfxMessageBox(_T("修改成功"));
			return;
		}
		else
		{
			AfxMessageBox(_T("修改失败,数量类型错误或ID已被占用"));
			return;
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void u_6::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
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
	else if (i == 3)
	{
		u_6 kk7;
		kk7.DoModal();
	}
	else if (i == 2)
	{
		u_5 kk2;
		kk2.DoModal();
	}
	else if (i == 0)
	{
		u_3 kk3;
		kk3.DoModal();
	}
	else if (i == 4)
	{
		u_7 kk4;
		kk4.DoModal();
	}
}
