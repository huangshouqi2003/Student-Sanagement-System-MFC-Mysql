
// MFCbookbaseDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCbookbase.h"
#include "MFCbookbaseDlg.h"
#include "u_1.h"
#include "u_2.h"
#include "u_3.h"
#include "afxdialogex.h"
#include<string>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置

#pragma comment(lib,"mysqlclient.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCbookbaseDlg 对话框



CMFCbookbaseDlg::CMFCbookbaseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBOOKBASE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCbookbaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST1, A_1);
	DDX_Control(pDX, IDOK, guanyu);
	DDX_Control(pDX, IDCANCEL, tuicu);
	DDX_Control(pDX, IDC_ST2, A_2);
	DDX_Control(pDX, IDC_ST3, A_3);
	DDX_Control(pDX, IDC_EDIT1, B_1);
	DDX_Control(pDX, IDC_EDIT2, B_2);
	DDX_Control(pDX, IDC_BUTTON1, C_1);
	DDX_Control(pDX, IDC_BUTTON2, C_2);
}

BEGIN_MESSAGE_MAP(CMFCbookbaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCbookbaseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCbookbaseDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCbookbaseDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCbookbaseDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCbookbaseDlg::OnClickedButton1)
END_MESSAGE_MAP()


// CMFCbookbaseDlg 消息处理程序

BOOL CMFCbookbaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。
	A_1.SetWindowTextA("登录界面");
	A_2.SetWindowTextA("账号");
	A_3.SetWindowTextA("密码");
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCbookbaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCbookbaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCbookbaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCbookbaseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox("versions 1.23\n版权所有，仿冒必究\n反馈地址：1770960700@qq.com");
}


void CMFCbookbaseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox("感谢使用");
	CDialogEx::OnCancel();
}


void CMFCbookbaseDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCbookbaseDlg::OnClickedButton2()
{
	u_1 zhuche;
	zhuche.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCbookbaseDlg::OnClickedButton1()
{
	char u1[256];
	char u2[256];
	B_1.GetWindowTextA(u1, 256);
	B_2.GetWindowTextA(u2, 256);
	int len1 = strlen(u1);
	int len2 = strlen(u2);
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
		if (u1[0]=='1'&&u2[0]=='1'&&len1==1&&len2==1)
		{
			u_3 guanliyuan;
			guanliyuan.DoModal();
		}
		else
		{
			int flag = 0;
			mysql_query(&mysql, "SET NAMES 'GB2312'");
			mysql_query(&mysql, "select * from users;");
			UpdateData(true);
			res = mysql_store_result(&mysql);
			while (row = mysql_fetch_row(res))
			{
				if (!strcmp(row[0], u1) && !strcmp(row[1], u2))
				{
					CString ggh = u1;
					UpdateData(TRUE);
					u_2* dlg = new u_2;
					dlg->Create(IDD_DIALOG2, this);
					dlg->EDO_1.SetWindowTextA(ggh);
					dlg->UpdateData(FALSE);
					dlg->ShowWindow(SW_SHOW);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				AfxMessageBox("无此用户或账号密码错误");
			}
			flag = 0;
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}
