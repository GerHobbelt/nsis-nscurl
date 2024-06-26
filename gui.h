
//? Marius Negrutiu (mailto:marius.negrutiu@protonmail.com) :: 2019/12/08
//? User Interface

#pragma once
#include "queue.h"

//+ struct GUI_REQUEST
typedef struct {
	QUEUE_SELECTION qsel;				/// HTTP requests that we're waiting for
	LPTSTR pszReturn;					/// Can be NULL. Custom return string (e.g. "@ERRORCODE@")
	BOOLEAN bBackground   : 1;			/// Background transfer, no waiting
	BOOLEAN bSilent       : 1;			/// Wait in Silent-mode
	BOOLEAN bPopup        : 1;			/// Wait in Popup-mode
	BOOLEAN bCancel       : 1;			/// Enable Cancel button in Page-mode and Popup-mode
	HWND hTitle, hText, hProgress;		/// Optional window handles. Can be NULL
	HWND hCancel;						/// Optional button handle. Can be NULL
	LPTSTR pszTitle;
	LPTSTR pszTitleNoSize;
	LPTSTR pszTitleMulti;
	LPTSTR pszText;
	LPTSTR pszTextNoSize;
	LPTSTR pszTextMulti;
	struct {
		ULONG iVisibleId;				/// May be 0
		ULONG iAnimIndex;				/// Auto increment
		HWND hTitle, hText, hProgress;	/// Runtime controls
		HWND hCancel;					/// RUntime controls
		LPTSTR pszTitle0, pszText0;
	} Runtime;
} GUI_REQUEST, *PGUI_REQUEST;

//+ GuiRequestInit
static void GuiRequestInit( _Inout_ PGUI_REQUEST pGui ) {
	if (!pGui) return;
	ZeroMemory( pGui, sizeof( *pGui ) );
}

//+ GuiRequestDestroy
static void GuiRequestDestroy( _In_opt_ PGUI_REQUEST pGui ) {
	if (!pGui) return;
	MyFree( pGui->qsel.pszTag );
	MyFree( pGui->pszReturn );
	MyFree( pGui->pszTitle );
	MyFree( pGui->pszTitleNoSize );
	MyFree( pGui->pszTitleMulti );
	MyFree( pGui->pszText );
	MyFree( pGui->pszTextNoSize );
	MyFree( pGui->pszTextMulti );
	MyFree( pGui->Runtime.pszTitle0 );
	MyFree( pGui->Runtime.pszText0 );
	ZeroMemory( pGui, sizeof( *pGui ) );
}

// ____________________________________________________________________________________________________________________________________ //
//                                                                                                                                      //

//+ Initialization
void GuiInitialize(void);
void GuiDestroy(void);

//+ GuiParseRequestParam
// Returns Win32 error code (ERROR_NOT_SUPPORTED for unknown parameters)
ULONG GuiParseRequestParam(
	_In_ LPTSTR pszParam,		/// Working buffer with the current parameter
	_In_ int iParamMaxLen,
	_Out_ PGUI_REQUEST pGui
);


//+ GuiWait
void GuiWait(
	_Inout_ PGUI_REQUEST pGui,
	_Out_ LPTSTR pszResult,
	_In_ int iResultMaxLen
);


//+ GuiRefresh
void GuiRefresh(
	_Inout_ PGUI_REQUEST pGui
);