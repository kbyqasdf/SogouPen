#include "stdafx.h"
#include "TabPanel.h"

#pragma execution_character_set("utf-8")

CTabPanel::CTabPanel(QWidget * parent)
	: QWidget(parent)
	, m_pMinBtn(NULL)
	, m_pMaxBtn(NULL)
	, m_pCloseBtn(NULL)
	, m_bMax(false)
	, m_pPlayerSlider(NULL)
	, m_pVoiceSlider(NULL)
{
	setObjectName("TabPanel");
	this->setStyleSheet("#TabPanel{background-color:#ffffffff;}");
	this->setFixedSize(810, 688);
	setAutoFillBackground(true);

	QVBoxLayout * pMainLayout = new QVBoxLayout(this);
	pMainLayout->setSpacing(0);
	pMainLayout->setContentsMargins(0, 0, 0, 0);

	QWidget * pTopWidget = new QWidget;
	pTopWidget->setFixedSize(810, 70);
	pTopWidget->setContentsMargins(0, -8, 0, 0);

	QHBoxLayout * pTopLayout = new QHBoxLayout(pTopWidget);
	pTopLayout->setSpacing(0);
	pTopLayout->setContentsMargins(0, 0, 0, 20);

	m_pBtnPrevious = new QPushButton;
	m_pBtnPrevious->setFixedSize(14, 22);
	m_pBtnPrevious->setStyleSheet("QPushButton{image: url(./Resources/pic/shangyishou.png); border: none; background-color:#ffffffff;}" \
							   "QPushButton:hover{image: url(./Resources/pic/shangyishou-hover.png);}" \
							   "QPushButton:pressed{image: url(./Resources/pic/shangyishou.png)}" \
							   "QPushButton:disabled{image: url(./Resources/pic/shangyishou-disable.png)}");
	QVBoxLayout * pPreviousVLayout = new QVBoxLayout;
	pPreviousVLayout->setSpacing(0);
	pPreviousVLayout->addSpacing(24);
	pPreviousVLayout->addWidget(m_pBtnPrevious);

	m_pBtnPlay = new QPushButton;
	m_pBtnPlay->setFixedSize(18, 22);
	m_pBtnPlay->setStyleSheet("QPushButton{image: url(./Resources/pic/bofang.png); border:none; background-color:#ffffffff}" \
	                          "QPushButton:hover{image: url(./Resources/pic/bofang-hover.png);}" \
							  "QPushButton:pressed{image: url(./Resources/pic/bofang.png);}" \
							  "QPushButton:disabled{image: url(./Resources/pic/bofang-disable.png)}");
	QVBoxLayout * pPlayLayout = new QVBoxLayout;
	pPlayLayout->setSpacing(0);
	pPlayLayout->addSpacing(24);
	pPlayLayout->addWidget(m_pBtnPlay);

	m_pBtnNext = new QPushButton;
	m_pBtnNext->setFixedSize(18, 22);
	m_pBtnNext->setStyleSheet("QPushButton{image: url(./Resources/pic/xiayishou.png); border:none; background-color:#ffffffff}" \
		"QPushButton:hover{image: url(./Resources/pic/xiayishou-hover.png);}" \
		"QPushButton:pressed{image: url(./Resources/pic/xiayishou.png);}" \
		"QPushButton:disabled{image: url(./Resources/pic/xiayishou-disable.png)}");
	QVBoxLayout * pNextLayout = new QVBoxLayout;
	pNextLayout->setSpacing(0);
	pNextLayout->addSpacing(24);
	pNextLayout->addWidget(m_pBtnNext);

	m_pStartTimeLabel = new QLabel;
	m_pStartTimeLabel->setFixedSize(40, 10);
	m_pStartTimeLabel->setText("00:00:00");
	m_pStartTimeLabel->setStyleSheet("QLabel{font-family:Microsoft YaHei; font-size:10px;}");
	QVBoxLayout * pStartTimeLayout = new QVBoxLayout;
	pStartTimeLayout->setSpacing(0);
	pStartTimeLayout->addSpacing(24);
	pStartTimeLayout->addWidget(m_pStartTimeLabel);

	m_pAudioLabel = new QLabel;
	m_pAudioLabel->setText("ÎÞ²¥·ÅÒôÆµ");
	m_pAudioLabel->setMinimumWidth(180);
	m_pAudioLabel->setFixedHeight(16);
	m_pAudioLabel->setStyleSheet("QLabel{font-family:Microsoft YaHei; font:bold; font-size:12px; color:#ff070708; \
								  border:none; text-align:left;}");
	QVBoxLayout * pPlayerLayout = new QVBoxLayout;
	pPlayerLayout->setSpacing(0);
	pPlayerLayout->addSpacing(10);
	pPlayerLayout->addWidget(m_pAudioLabel);

	m_pPlayerSlider = new QSlider;
	m_pPlayerSlider->setFixedSize(180, 20);
	m_pPlayerSlider->setOrientation(Qt::Horizontal);
	m_pPlayerSlider->setMinimum(0);
	m_pPlayerSlider->setStyleSheet("QSlider::groove:horizontal{\
									border-image: url(./Resources/pic/jindutiao-beijing.png);} \
									QSlider::handle:horizontal{width:16px; height:24px; border-image: url(./Resources/pic/slide-icon1.png);} \
									QSlider::sub-page:horizontal{border-image: url(./Resources/pic/jindutiao1.png)}");
	pPlayerLayout->addSpacing(0);
	pPlayerLayout->addWidget(m_pPlayerSlider);

	m_pAudioLenthLabel = new QLabel;
	m_pAudioLenthLabel->setFixedSize(40, 10);
	m_pAudioLenthLabel->setText("00:00:00");
	m_pAudioLenthLabel->setStyleSheet("QLabel{font-family:Microsoft YaHei; font-size:10px;}");
	QVBoxLayout * pEndTimeLayout = new QVBoxLayout;
	pEndTimeLayout->setSpacing(0);
	pEndTimeLayout->addSpacing(24);
	pEndTimeLayout->addWidget(m_pAudioLenthLabel);

	QLabel *pVoiceLabel = new QLabel;
	pVoiceLabel->setFixedSize(14, 14);
	pVoiceLabel->setStyleSheet("QLabel{image: url(./Resources/pic/shengyin.png); }");
	QVBoxLayout * pVoiceLayout = new QVBoxLayout;
	pVoiceLayout->setSpacing(0);
	pVoiceLayout->addSpacing(28);
	pVoiceLayout->addWidget(pVoiceLabel);

	QVBoxLayout * pVoiceSliderLayout = new QVBoxLayout;
	pVoiceSliderLayout->setSpacing(0);
	pVoiceSliderLayout->addSpacing(26);
	m_pVoiceSlider = new QSlider;
	pVoiceSliderLayout->addWidget(m_pVoiceSlider);
	m_pVoiceSlider->setFixedSize(80, 20);
	m_pVoiceSlider->setOrientation(Qt::Horizontal);
	m_pVoiceSlider->setMinimum(0);
	m_pVoiceSlider->setStyleSheet("QSlider::groove:horizontal{\
									border-image: url(./Resources/pic/jindutiao-beijing.png);} \
									QSlider::handle:horizontal{width:16px; height:24px; border-image: url(./Resources/pic/slide-icon1.png);} \
									QSlider::sub-page:horizontal{border-image: url(./Resources/pic/jindutiao1.png)}");

	m_pMinBtn = new QPushButton;
	m_pMinBtn->setFixedSize(40, 40);
	m_pMinBtn->setStyleSheet("QPushButton{image: url(./Resources/pic/zuixiao-normal.png); border:none; }" \
							 "QPushButton:hover{image: url(./Resources/pic/zuixiao-hover.png); background-color:#ffff7846;}" \
							 "QPushButton:pressed{background-color:#ffc2c8d3}");

	m_pMaxBtn = new QPushButton;
	m_pMaxBtn->setFixedSize(40, 40);
	m_pMaxBtn->setStyleSheet("QPushButton{image: url(./Resources/pic/zuida-normal.png); border:none;}" \
							 "QPushButton:hover{image: url(./Resources/pic/zuida-hover.png); background-color:#ffff7846;}" \
							 "QPushButton:pressed{background-color:#ffc2c8d3}");

	m_pCloseBtn = new QPushButton;
	m_pCloseBtn->setFixedSize(40, 40);
	m_pCloseBtn->setStyleSheet("QPushButton{image: url(./Resources/pic/close-normal.png); border:none;}" \
							   "QPushButton:hover{image: url(./Resources/pic/close-hover.png); background-color:#ffff7846;}" \
							   "QPushButton:pressed{background-color:#ffe45926}");

	pTopLayout->addSpacing(20);
	pTopLayout->addLayout(pPreviousVLayout);
	pTopLayout->addSpacing(28);
	pTopLayout->addLayout(pPlayLayout);
	pTopLayout->addSpacing(28);
	pTopLayout->addLayout(pNextLayout);
	pTopLayout->addSpacing(32);
	pTopLayout->addLayout(pStartTimeLayout);
	pTopLayout->addSpacing(6);
	pTopLayout->addLayout(pPlayerLayout);
	pTopLayout->addSpacing(6);
	pTopLayout->addLayout(pEndTimeLayout);
	pTopLayout->addSpacing(25);
	pTopLayout->addLayout(pVoiceLayout);
	pTopLayout->addSpacing(8);
	pTopLayout->addLayout(pVoiceSliderLayout);
	pTopLayout->addStretch();
	pTopLayout->addWidget(m_pMinBtn);
	pTopLayout->addWidget(m_pMaxBtn);
	pTopLayout->addWidget(m_pCloseBtn);

	pMainLayout->addWidget(pTopWidget);
	pMainLayout->addStretch();
}

CTabPanel::~CTabPanel()
{
	
}