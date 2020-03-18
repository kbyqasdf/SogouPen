#pragma once
#include "stdafx.h"
#include "SogouPen.h"
#include "list.h"
#include <list>


class CTravelDlg : public QWidget
{
	Q_OBJECT

public:
	CTravelDlg(QWidget * parent = Q_NULLPTR);
	~CTravelDlg();

	void AddImportFromDevBtn();
	void AddRecordBtn();

private:
	void initPersonalInfo();
	void initButtonListArea();
	void InitConnect();
	void initBottomButton();

protected:
	void keyPressEvent(QKeyEvent * event);

private slots:
	void slotButtonGroupClick(QAbstractButton * pButton);
	void slotImportFromDevBtnClick();
	void slotSetBtnClick();
	void slotHelpBtnClick();

private:
	QButtonGroup * m_pButtonGroup;
	PushButtonEx * m_pAllButton;
	PushButtonEx * m_pLocalButton;
	PushButtonEx * m_pImportFromDevBtn;
	QWidget  *     m_pImportFromDevWidget;
	QVBoxLayout *  m_pImportFromDevLayout;
	QWidget  *	   m_pRecorderWidget;
	QVBoxLayout *  m_pRecorderVLayout;
	PushButtonEx * m_pImportFromLocalBtn;
	QWidget  *     m_pListWidget;
	QPushButton *  m_pSetBtn;
	QPushButton *  m_pHelpBtn;
	std::list<PushButtonEx *> m_listButtonEx;
	std::list<PushButtonEx *> m_listRecord;
	QScrollArea * m_pScrollArea;
	QVBoxLayout * m_pTravelLayout;
	

private:
	int				m_iButtonId;
	//int             m_iImportButtonCount;
	//int             m_iRecordBtnCount;
	PushButtonEx  * m_pCurrentSelectedButton;
};