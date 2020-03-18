#pragma once
#include "stdafx.h"
#include "TabPanel.h"
#include "TravelDlg.h"

class CTravelDlg;
class CTabPanel;

class SogouPen : public QWidget
{
	Q_OBJECT

public:
	SogouPen(QWidget *parent = Q_NULLPTR);
	~SogouPen();

private:
	void InitRight(QHBoxLayout * pLayout);

private slots:
	void min_slot_click();
	void max_slot_click();
	void close_slot_click();

private:
	bool m_bMax;
	CTabPanel * m_pTabPanel;
	CTravelDlg * m_pTravel;

private:
	QPushButton*   m_pMinBtn;
	QPushButton*   m_pMaxBtn;
	QPushButton*   m_pCloseBtn;
	QPushButton*   m_pBtnPlay;

	QPushButton*   m_pBtnPause;
	QPushButton*   m_pBtnNext;
	QPushButton*   m_pBtnPrevious;
	QLabel*        m_pAudioLabel;
	QLabel*        m_pStartTimeLabel;
	QLabel*        m_pAudioLenthLabel;
	QSlider*       m_pPlayerSlider;
	QSlider*       m_pVoiceSlider;
	QWidget*	   m_pRightWidget;
};