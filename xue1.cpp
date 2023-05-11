// xue1.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "xue1.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
using namespace std;


// xue1 对话框

IMPLEMENT_DYNAMIC(xue1, CDialogEx)

xue1::xue1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIxue1, pParent)
{

}

xue1::~xue1()
{
}

void xue1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EGO_1);
	DDX_Control(pDX, IDC_EDIT2, EDP1);
	DDX_Control(pDX, IDC_EDIT3, EDP2);
	DDX_Control(pDX, IDC_EDIT4, EDP3);
	DDX_Control(pDX, IDC_EDIT5, EDP4);
	DDX_Control(pDX, IDC_EDIT11, EDP5);
	DDX_Control(pDX, IDC_BUTTON3, B_1);
	DDX_Control(pDX, IDC_EDIT6, num);
}


BEGIN_MESSAGE_MAP(xue1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &xue1::OnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &xue1::OnClickedButton3_1)
END_MESSAGE_MAP()


// xue1 消息处理程序


BOOL xue1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void xue1::OnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	CString text1;
	EDP1.GetWindowTextA(text1);
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
				EDP2.SetWindowTextA(row[0]);
				EDP3.SetWindowTextA(row[1]);
				EDP4.SetWindowTextA(row[2]);
				EDP5.SetWindowTextA(row[3]);
				break;
			}
		}
	}

}


void xue1::OnClickedButton3_1()
{
	CString yuanLnum;
	EDP5.GetWindowTextA(yuanLnum);
	CString jienum;
	num.GetWindowTextA(jienum);
	int k1, k2, k3;
	k1 =_ttoi(yuanLnum);
	k2= _ttoi(jienum);
	k3 = k1 - k2;
	CString nownum;
	nownum.Format(_T("%d"), k3);
	// TODO: 在此添加控件通知处理程序代码
	CString text1;
	int flog = 0;
	EDP1.GetWindowTextA(text1);
	if (jienum==""|| text1 == "")
	{
		AfxMessageBox(_T("不能有选项为空"));
		flog = 1;
		return;
	}
	else if (k2 <= 0)
	{
		AfxMessageBox(_T("借书数量不能为0或负数"));
		return;
	}
	else if (k3 < 0)
	{
		AfxMessageBox(_T("书没那么多"));
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
		EndDialog(0);
	}
	else
	{
		char koo[265];
		mysql_query(&mysql, "SET NAMES 'GB2312'");
		UpdateData(true);
		snprintf(koo, 256, "update book set number='%s' where id='%s'",nownum,text1);
		if (!mysql_query(&mysql, koo)&&flog==0)
		{
			AfxMessageBox(_T("借书成功"));
		}
		int pp = 0;
		CString ER,AR;
		EGO_1.GetWindowTextA(ER);
		EDP2.GetWindowTextA(AR);
		mysql_query(&mysql, "quit");
		mysql_query(&mysql, "select * from history;");
		res = mysql_store_result(&mysql);
		char nb[265];
		while (row = mysql_fetch_row(res))
		{
			if (row[5] == ER && row[1] == AR)
			{
				pp = 1;
				CString yuanLnum1=row[4];
				CString jienum1;
				num.GetWindowTextA(jienum1);
				int t1, t2, t3;
				t1 = _ttoi(yuanLnum1);
				t2 = _ttoi(jienum1);
				t3 = t1+t2;
				CString hhhh;
				hhhh.Format(_T("%d"), t3);
				snprintf(nb, 256, "update history set number='%s' where ci='%s'",hhhh ,row[0]);
				mysql_query(&mysql, nb);
				break;
			}
		}
		mysql_query(&mysql, "quit");
		if (pp == 0)
		{
			char krp[256];
			CString e1, e2, e3, e4, e5;
			EGO_1.GetWindowTextA(e1);
			EDP3.GetWindowTextA(e2);
			EDP4.GetWindowTextA(e3);
			EDP2.GetWindowTextA(e5);
			num.GetWindowTextA(e4);
			snprintf(krp, 256, "insert into history values(0,'%s','%s','%s','%s','%s')", e5, e2, e3, e4, e1);
			mysql_query(&mysql, krp);
		}
		pp = 0;
	}
}
