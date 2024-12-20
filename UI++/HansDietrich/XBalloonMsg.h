// XBalloonMsg.h  Version 1.3+
//
// Author:  Hans Dietrich
//          hdietrich@gmail.com
//
// License:
//     This file is Copyright � 2009 Hans Dietrich. All Rights Reserved.
//
//     This source file is the property of Hans Dietrich and is not to be
//     re-distributed by any means whatsoever without the expressed written
//     consent of Hans Dietrich.
//
//     This source code can only be used under the Terms of Use set forth
//     on the Hans Dietrich Software web site. Hans Dietrich Software grants 
//     to you (one software developer) the limited right to use this software.
//
//     This software is provided "as is" with no expressed or implied warranty.
//     Hans Dietrich accepts no liability for any damage or loss of business 
//     that this software may cause.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XBALLOONMSG_H
#define XBALLOONMSG_H

#include <windows.h>
#include "commctrl.h"

//=============================================================================
// special symbol for title string - replaced with module name
#define LPCTSTR_DEFAULT_TITLE	((LPCTSTR)-1L)

namespace HansDietrich {

	//=============================================================================
	class CXBalloonMsg
		//=============================================================================
	{
		// Construction
	public:
		CXBalloonMsg();
		virtual ~CXBalloonMsg();

		// Attributes
	public:
		static HWND m_hWndBalloon;

		// Operations
	public:
		static void Show(LPCTSTR lpszTitle,
			LPCTSTR lpszMsg,
			HWND hCtrl,
			HWND hParent,
			HINSTANCE hInstance,
			UINT nIcon = TTI_INFO,
			BOOL bUseBalloonTips = TRUE,
			UINT nTimeOutSeconds = 0,
			LPRECT pRect = NULL,
			BOOL bSubclassParent = TRUE);
		static void Destroy();

		// Implementation
	protected:
		static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
		static LRESULT __stdcall DefWindowProcX(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);
		static void CALLBACK TimerProcX(HWND hwnd,
			UINT message,
			UINT_PTR nIdEvent,
			DWORD dwTime);
		static BOOL GetEnableBalloonTips();
		static void GetStrings(LPCTSTR lpszTitle, LPCTSTR lpszMsg, HINSTANCE hInstance);
		static TCHAR * GetModuleName(HINSTANCE hInstance);
		static void PositionBalloon(LPRECT pRect, LPRECT pNewRect, BOOL bBalloon);

		static BOOL			m_bInit;			// TRUE = initialization finished
		static BOOL			m_bUseBalloonTips;	// TRUE = use balloon tips if possible
		static BOOL			m_bBalloon;			// TRUE = balloon tips not disallowed in 
												// registry
		static BOOL			m_bSubclassParent;	// TRUE = subclass parent
		static HINSTANCE	m_hInstance;		// app instance
		static UINT			m_nIcon;			// icon to use
		static UINT			m_nLastMessage;		// last message received
		static UINT			m_nTimeOutSeconds;	// message timeout in seconds;
												// 0 = no timeout
		static UINT_PTR		m_nTimerId;			// timer id returned by SetTimer()
		static LPRECT		m_pRect;			// NULL = use control rect
		static HWND			m_hWnd;				// hwnd of CXBalloonMsg
		static HWND			m_hParent;			// parent hwnd
		static HWND			m_hCtrl;			// control hwnd
		static WNDPROC		m_wndProc;			// window proc for parent subclassing
		static HHOOK		m_hKeyboardHook;	// keyboard hook
		static HHOOK		m_hMouseHook;		// mouse hook
		static TCHAR		m_szTitle[500];		// title string
		static TCHAR		m_szMsg[4000];		// message string
	};
}
#endif // XBALLOONMSG_H
