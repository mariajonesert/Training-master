// pop3_imap4_simple.vcNativeDlg.h : header file
//

#pragma once

#include <atlbase.h>
#include <atlcom.h>
#include "afxwin.h"
#include "afxcmn.h"



static _ATL_FUNC_INFO OnIdle = {CC_STDCALL, VT_EMPTY, 2, {VT_DISPATCH, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnConnected = {CC_STDCALL, VT_EMPTY, 2, {VT_DISPATCH, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnQuit = {CC_STDCALL, VT_EMPTY, 2, {VT_DISPATCH, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnSendCommand = {CC_STDCALL, VT_EMPTY, 4, {VT_DISPATCH, VT_VARIANT, VT_BOOL, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnReceiveResponse = {CC_STDCALL, VT_EMPTY, 4, {VT_DISPATCH, VT_VARIANT, VT_BOOL, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnSecuring = {CC_STDCALL, VT_EMPTY, 2, {VT_DISPATCH, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnAuthorized = {CC_STDCALL, VT_EMPTY, 2, {VT_DISPATCH, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnSendingDataStream = {CC_STDCALL, VT_EMPTY, 4, {VT_DISPATCH, VT_I4, VT_I4, VT_BOOL|VT_BYREF }};
static _ATL_FUNC_INFO OnReceivingDataStream  = {CC_STDCALL, VT_EMPTY, 5, {VT_DISPATCH, VT_DISPATCH, VT_I4, VT_I4, VT_BOOL|VT_BYREF }};

// Cpop3_imap4_simplevcNativeDlg dialog
class Cpop3_imap4_simplevcNativeDlg : public CDialog, 
	public IDispEventSimpleImpl<IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, 
	Cpop3_imap4_simplevcNativeDlg, &__uuidof(_IMailClientEvents)> 
{
// Construction
public:
	Cpop3_imap4_simplevcNativeDlg(CWnd* pParent = NULL);	// standard constructor

BEGIN_SINK_MAP(Cpop3_imap4_simplevcNativeDlg)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 1, OnIdleHandler, &OnIdle)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 2, OnConnectedHandler, &OnConnected)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 3, OnQuitHandler, &OnQuit)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 4, OnSendCommandHandler, &OnSendCommand)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 5, OnReceiveResponseHandler, &OnReceiveResponse)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 6, OnSecuringHandler, &OnSecuring)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 7, OnAuthorizedHandler, &OnAuthorized)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 8, OnSendingDataStreamHandler, &OnSendingDataStream)
	SINK_ENTRY_INFO(IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG, __uuidof(_IMailClientEvents), 9, OnReceivingDataStreamHandler, &OnReceivingDataStream)

END_SINK_MAP()
// Dialog Data
	enum { IDD = IDD_POP3_IMAP4_SIMPLEVCNATIVE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HRESULT __stdcall OnIdleHandler(
		IDispatch * oSender,
        VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnConnectedHandler(
		IDispatch * oSender,
        VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnQuitHandler(
		IDispatch * oSender,
        VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnSendCommandHandler(
		IDispatch * oSender,
        VARIANT data,
        VARIANT_BOOL IsDataStream,
        VARIANT_BOOL * Cancel);

    HRESULT __stdcall OnReceiveResponseHandler (
        IDispatch * oSender,
        VARIANT data,
        VARIANT_BOOL IsDataStream,
        VARIANT_BOOL * Cancel );

    HRESULT __stdcall OnSecuringHandler (
        IDispatch * oSender,
        VARIANT_BOOL * Cancel );

    HRESULT __stdcall OnAuthorizedHandler (
        IDispatch * oSender,
        VARIANT_BOOL * Cancel );

    HRESULT __stdcall OnSendingDataStreamHandler (
        IDispatch * oSender,
        long Sent,
        long Total,
        VARIANT_BOOL * Cancel );

    HRESULT __stdcall OnReceivingDataStreamHandler (
        IDispatch * oSender,
        IDispatch * oInfo,
        long Received,
        long Total,
        VARIANT_BOOL * Cancel );

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	VARIANT_BOOL	m_bCancel;
	void	DoEvents();

	void LoadMails();
	void ShowReport( LPCTSTR lpszFile );
	CString m_uidlfile;
	CString m_curpath;

	static int CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, 
			LPARAM lParamSort);


public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonCancel();
	CString textServer;
	CString textUser;
	CString textPassword;
	BOOL chkSSL;
	CComboBox lstAuthType;
	CComboBox lstProtocol;
	BOOL chkLeaveCopy;
	CProgressCtrl pgBar;
	CListCtrl lstMail;

	afx_msg void OnNMClickListMail(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnCbnSelchangeComboProtocol();
	CEdit m_textReport;
};
