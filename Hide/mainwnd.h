
// mainwnd.h : header file
//

#pragma once
#include <tlhelp32.h>
#include <locale.h> 
#include <atlstr.h>  
#include "afxwin.h"
#include "../VolumeCtrl/VolumeCtrl.h"
#pragma comment(lib,"../debug/VolumeCtrl.lib")


BOOL CALLBACK EnumWindowCallBack(HWND hWnd, LPARAM lParam);


// mainwnd dialog
class mainwnd : public CDialogEx
{
	// Construction
public:
	mainwnd(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_HIDE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;

	CVolumeCtrl volCtrl;
	int tgtPID[32];//Ŀ�����
	int countTgt;
	HWND hiddenHWND[100];//�����ش��ھ��
	int countHidden;//�����ش�����
	int hideState;//״̬ 1=���� 0=δ����

	CListCtrl *m_list1, *m_list2;
	//NOTIFYICONDATA m_nid;

	BOOL PreTranslateMessage(MSG* pMsg);//���λس���ESC  
	
	BOOL GetProcessList();
	void RefreshPID();
	afx_msg LRESULT OnFindWindow(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnUmTraymsg(WPARAM wParam, LPARAM lParam);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();//��ʾ����������
	afx_msg void OnBnClickedButton2();	//���ش���
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnAddProcess();
	afx_msg void OnRemoveProcess();
	afx_msg void OnRefresh();
	afx_msg void OnClose();
};
