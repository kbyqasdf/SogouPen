#pragma once
#include "stdafx.h"
#include "SogouPen.h"

class CTabPanel : public QWidget
{
	Q_OBJECT

public:
	CTabPanel(QWidget * parent = Q_NULLPTR);
	~CTabPanel();

private:

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

private:
	bool		   m_bMax;
};