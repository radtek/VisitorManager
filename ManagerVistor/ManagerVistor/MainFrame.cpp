#include "StdAfx.h"
#include "MainFrame.h"
#include <string.h>
#include "VisitorRecordUI.h"
#include "ConectToMySql.h"
#include "ConstDataDef.h"
using namespace std;

CMainFrame::CMainFrame(LPCTSTR pszXMLName) : m_strXMLName(pszXMLName)
	, m_pCloseBtn(NULL)
	, m_pMaxBtn(NULL)
	, m_pMinBtn(NULL)
	, m_pRestoreBtn(NULL)
{
}

CMainFrame::~CMainFrame(void)
{
}

void CMainFrame::InitWindow()
{
	CenterWindow();
	m_pCloseBtn = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("closebtn")));
	m_pMaxBtn = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("maxbtn")));
	m_pMinBtn = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("minbtn")));
	m_pRestoreBtn = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("restorebtn")));
	PostMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	InitSearchCtrl();
	AddCertitypeMsg();
}

CControlUI* CMainFrame::CreateControl( LPCTSTR pstrClassName )
{
	if(_tcscmp(pstrClassName,_T("VistorRecord"))==0)
		return new CVisitorRecordUI(&m_PaintManager);
	return NULL;
}

LRESULT CMainFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = __super::HandleMessage(uMsg, wParam, lParam);
	return lRes;
}

void CMainFrame::Notify( TNotifyUI& msg )
{
	if(msg.sType == DUI_MSGTYPE_SELECTCHANGED){
		CDuiString name = msg.pSender->GetName();
		CTabLayoutUI* pTabLayoutModule = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabModule")));
		if(pTabLayoutModule){
			if(name==_T("record"))
				pTabLayoutModule->SelectItem(0);
			else if(name==_T("datamanage"))
				pTabLayoutModule->SelectItem(1);
			else if(name==_T("check"))
				pTabLayoutModule->SelectItem(2);
			else if(name==_T("appointment"))
				pTabLayoutModule->SelectItem(3);
			else if(name==_T("user"))
				pTabLayoutModule->SelectItem(4);
			else if(name==_T("email"))
				pTabLayoutModule->SelectItem(5);
		}
		CTabLayoutUI* pTabLayoutRecord = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabRecord")));
		if(pTabLayoutRecord){
			if(name==_T("NoRecord"))
				pTabLayoutRecord->SelectItem(0);
			else if(name==_T("LeaveRecord"))
				pTabLayoutRecord->SelectItem(1);
		}
	}
	else if( msg.sType == _T("click") ) {
		if( msg.pSender == m_pCloseBtn ) {
			PostQuitMessage(0);
			return; 
		}
		else if( msg.pSender == m_pMinBtn ) { 
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0); return; }
		else if( msg.pSender == m_pMaxBtn ) { 
			SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0); return; }
		else if( msg.pSender == m_pRestoreBtn ) { 
			SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0); return; 
		}
	}
}

void CMainFrame::InitSearchCtrl()
{
	m_pCertiTypeCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("CertiTypeCombo")));
	m_pCertiNumEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("CertiNumEdit")));
	m_pVistorNameEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("VistorNameEdit")));
	m_pSexCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("SexCombo")));
	m_pCardNumEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("CardNumEdit")));
	m_pAddressEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("AddressEdit")));
	m_pCarNumCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("CarNumCombo")));
	m_pCarNumEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("CarNumEdit")));
	m_pCarTypeCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("CarTypeCombo")));
	m_pAddCarTypeBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("AddCarTypeBtn")));
	m_pVistorUnitEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("VistorUnitEdit")));
	m_pVistorPhoneNumEdit = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("VistorPhoneNumEdit")));
	m_pVistorNumCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("VistorNumCombo")));
	m_pAddVistorBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("AddVistorBtn")));
	m_pLeaveDate = static_cast<CDateTimeUI*>(m_PaintManager.FindControl(_T("LeaveDate")));
	m_pLeaveTime = static_cast<CDateTimeUI*>(m_PaintManager.FindControl(_T("LeaveTime")));
	m_pBatchCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("BatchCombo")));
	m_pAddBatchBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("AddBatchBtn")));
}

void CMainFrame::AddCertitypeMsg()
{
	CListLabelElementUI* pListItem1 = new CListLabelElementUI;
	pListItem1->SetOwner(m_pCertiTypeCombo);
	pListItem1->SetText(CERTITYPE_SECOND_GENIDCARD);
// 	TListInfoUI* pListInfoUI = pListItem1->GetOwner()->GetListInfo();
// 	pListInfoUI->nFont = 2;
	m_pCertiTypeCombo->Add(pListItem1);

	CListLabelElementUI* pListItem2 = new CListLabelElementUI;
	pListItem2->SetText(CERTITYPE_FIRST_GENIDCARD);
	pListItem2->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem2);

	CListLabelElementUI* pListItem3 = new CListLabelElementUI;
	pListItem3->SetText(CERTITYPE_HONGKANG_PERMIT);
	pListItem3->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem3);
	
	CListLabelElementUI* pListItem4 = new CListLabelElementUI;
	pListItem4->SetText(CERTITYPE_INTERNA_PASSPORT);
	pListItem4->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem4);

	CListLabelElementUI* pListItem5 = new CListLabelElementUI;
	pListItem5->SetText(CERTITYPE_HVPS);
	pListItem5->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem5);

	CListLabelElementUI* pListItem6 = new CListLabelElementUI;
	pListItem6->SetText(CERTITYPE_DRIVER_LICENSE);
	pListItem6->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem6);

	CListLabelElementUI* pListItem7 = new CListLabelElementUI;
	pListItem7->SetText(CERTITYPE_MILIT_OFFICER);
	pListItem7->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem7);

	CListLabelElementUI* pListItem8 = new CListLabelElementUI;
	pListItem8->SetText(CERTITYPE_SOLDIERS_CARD);
	pListItem8->SetOwner(m_pCertiTypeCombo);
	m_pCertiTypeCombo->Add(pListItem8);
}