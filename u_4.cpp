// u_4.cpp: 实现文件
//

#include "pch.h"
#include "MFCbookbase.h"
#include "u_4.h"
#include "afxdialogex.h"
#include "u_3.h"
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


// u_4 对话框

IMPLEMENT_DYNAMIC(u_4, CDialogEx)

u_4::u_4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

u_4::~u_4()
{
}

void u_4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDC_LIST2, LI1);
	DDX_Control(pDX, IDC_STA1, A_2);
	DDX_Control(pDX, IDC_STA2, A_3);
	DDX_Control(pDX, IDC_STA3, A_4);
	DDX_Control(pDX, IDC_STA4, A_5);
	DDX_Control(pDX, IDC_EDIT1, EDI1);
	DDX_Control(pDX, IDC_EDIT2, EDI2);
	DDX_Control(pDX, IDC_EDIT3, EDI3);
	DDX_Control(pDX, IDC_EDIT4, EDI4);
	DDX_Control(pDX, IDC_BUTTON3, btt_1);
}


BEGIN_MESSAGE_MAP(u_4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &u_4::OnClickedButton3)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &u_4::OnDblclkList2)
END_MESSAGE_MAP()


// u_4 消息处理程序


BOOL u_4::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	A_1.SetWindowTextA("增加书籍界面");
	A_2.SetWindowTextA("ID");
	A_3.SetWindowTextA("书名");
	A_4.SetWindowTextA("作者");
	A_5.SetWindowTextA("数量");
	LI1.InsertItem(0, "学生管理", 0);
	LI1.InsertItem(1, "增加书籍", 0);
	LI1.InsertItem(2, "删除书籍", 0);
	LI1.InsertItem(3, "修改书籍", 0);
	LI1.InsertItem(4, "查找书籍", 0);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void u_4::OnClickedButton3()
{
	CString text1;
	CString text2;
	CString text3;
	CString text4;
	EDI1.GetWindowTextA(text1);
	EDI2.GetWindowTextA(text2);
	EDI3.GetWindowTextA(text3);
	EDI4.GetWindowTextA(text4);
	int aa_1 = strlen(text4);
	int aa_2 = strlen(text1);
	int aa_3 = _ttoi(text4);
	if (text1 == "" || text2 == "" || text3 == "" || text4 == "")
	{
		AfxMessageBox(_T("不能有空选项"));
		return;
	}
	else if (aa_1 <= 0)
	{
		AfxMessageBox(_T("数量有误"));
		return;
	}
	else if (aa_3 > 500)
	{
		AfxMessageBox(_T("超过500本"));
		return;
	}
	else if (aa_3 <= 0)
	{
		AfxMessageBox(_T("不能为负数和0"));
		return;
	}
	else if (aa_2 >8)
	{
		AfxMessageBox(_T("ID太长"));
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
		snprintf(koo, 256, "insert into book values('%s', '%s','%s','%s')", text1, text2,text3,text4);
		if (!mysql_query(&mysql, koo))
		{
			AfxMessageBox(_T("添加成功"));
			return;
		}
		else
		{
			AfxMessageBox(_T("添加失败,数量类型错误或ID已被占用"));
			return;
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void u_4::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CDialogEx::OnCancel();
	int i = pNMItemActivate->iItem;
	if (i == 4)
	{
		u_7 kkl;
		kkl.DoModal();
	}
	else if (i == 1)
	{
		u_4 kk6;
		kk6.DoModal();
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
}
