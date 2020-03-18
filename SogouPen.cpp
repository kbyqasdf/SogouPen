#include "stdafx.h"
#include "SogouPen.h"
#include "TravelDlg.h"
#include "TabPanel.h"

#pragma execution_character_set("utf-8")

#define BTN_PLAYER_PREVIOUS_QSS		"QPushButton{image: url(./Resources/pic/shangyishou.png); border: none; background-color:#ffffffff;}" \
		"QPushButton:hover{image: url(./Resources/pic/shangyishou-hover.png);}" \
		"QPushButton:pressed{image: url(./Resources/pic/shangyishou.png)}" \
		"QPushButton:disabled{image: url(./Resources/pic/shangyishou-disable.png)}"

#define BTN_PLAYER_PLAY_QSS			"QPushButton{image: url(./Resources/pic/bofang.png); border:none; background-color:#ffffffff}" \
		"QPushButton:hover{image: url(./Resources/pic/bofang-hover.png);}" \
		"QPushButton:pressed{image: url(./Resources/pic/bofang.png);}" \
		"QPushButton:disabled{image: url(./Resources/pic/bofang-disable.png)}"

#define BTN_PLAYER_NEXT_QSS			"QPushButton{image: url(./Resources/pic/xiayishou.png); border:none; background-color:#ffffffff}" \
		"QPushButton:hover{image: url(./Resources/pic/xiayishou-hover.png);}" \
		"QPushButton:pressed{image: url(./Resources/pic/xiayishou.png);}" \
		"QPushButton:disabled{image: url(./Resources/pic/xiayishou-disable.png)}"

#define BTN_PLAYER_SLIDER_QSS		"QSlider::groove:horizontal{\
		border-image: url(./Resources/pic/jindutiao-beijing.png);} \
		QSlider::handle:horizontal{width:16px; height:24px; border-image: url(./Resources/pic/slide-icon1.png);} \
		QSlider::sub-page:horizontal{border-image: url(./Resources/pic/jindutiao1.png)}"

#define BTN_PLAYER_VOICE_QSS		"QSlider::groove:horizontal{\
		border-image: url(./Resources/pic/jindutiao-beijing.png);} \
		QSlider::handle:horizontal{width:16px; height:24px; border-image: url(./Resources/pic/slide-icon1.png);} \
		QSlider::sub-page:horizontal{border-image: url(./Resources/pic/jindutiao1.png)}"

#define BTN_MIN_QSS					"QPushButton{image: url(./Resources/pic/zuixiao-normal.png); border:none; }" \
		"QPushButton:hover{image: url(./Resources/pic/zuixiao-hover.png); background-color:#ffff7846;}" \
		"QPushButton:pressed{background-color:#ffc2c8d3}"


#define	BTN_MAX_QSS		"QPushButton{image: url(./Resources/pic/zuida-normal.png); border:none;}" \
		"QPushButton:hover{image: url(./Resources/pic/zuida-hover.png); background-color:#ffff7846;}" \
		"QPushButton:pressed{background-color:#ffc2c8d3}"

#define BTN_CLOSE_QSS		"QPushButton{image: url(./Resources/pic/close-normal.png); border:none;}" \
		"QPushButton:hover{image: url(./Resources/pic/close-hover.png); background-color:#ffff7846;}" \
		"QPushButton:pressed{background-color:#ffe45926}"

#define LABEL_PLAYER_NAME_QSS	"QLabel{font-family:Microsoft YaHei; font:bold; font-size:12px; color:#ff070708; \
								border:none; text-align:left;}"


SogouPen::SogouPen(QWidget *parent)
	: QWidget(parent)
	, m_bMax(false)
{
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
		Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint |
		Qt::WindowMaximizeButtonHint);//去掉标题栏，且点击任务栏图标最小化窗口
	this->setFixedSize(1000, 690);
	setObjectName("SogouPen");
	this->setStyleSheet("#SogouPen{background-color:#ffffffff;}");

	QHBoxLayout * pMainLayout = new QHBoxLayout(this);
	pMainLayout->setContentsMargins(0, 0, 0, 0);
	pMainLayout->setMargin(0);
	pMainLayout->setSpacing(0);

	m_pTravel = new CTravelDlg(this);
	pMainLayout->addWidget(m_pTravel, 19);

	InitRight(pMainLayout);
}

SogouPen::~SogouPen()
{
	
}

void SogouPen::min_slot_click()
{
	this->showMinimized();
}

void SogouPen::max_slot_click()
{
	if (!m_bMax) {
		this->showMaximized();
		m_bMax = true;
	}
	else {
		this->showNormal();
		m_bMax = false;
	}
}


void SogouPen::close_slot_click()
{
	this->close();
}

void SogouPen::InitRight(QHBoxLayout * pLayout)
{
	m_pRightWidget = new QWidget;
	pLayout->addWidget(m_pRightWidget, 81);
	m_pRightWidget->setMinimumSize(810, 688);
	m_pRightWidget->setObjectName("TabPanel");
	m_pRightWidget->setStyleSheet("#TabPanel{background-color:#ffffffff;}");
	m_pRightWidget->setAutoFillBackground(true);
	m_pRightWidget->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout * pRightLayout = new QVBoxLayout(m_pRightWidget);
	pRightLayout->setSpacing(0);
	pRightLayout->setContentsMargins(0, 0, 0, 0);

	QWidget * pTopWidget = new QWidget;
	pTopWidget->setMinimumSize(810, 70);
	pTopWidget->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout * pTopLayout = new QHBoxLayout(pTopWidget);
	pTopLayout->setSpacing(0);
	pTopLayout->setContentsMargins(0, 0, 0, 20);

	m_pBtnPrevious = new QPushButton;
	m_pBtnPrevious->setFixedSize(14, 22);
	m_pBtnPrevious->setStyleSheet(BTN_PLAYER_PREVIOUS_QSS);
	QVBoxLayout * pPreviousVLayout = new QVBoxLayout;
	pPreviousVLayout->setSpacing(0);
	pPreviousVLayout->addSpacing(24);
	pPreviousVLayout->addWidget(m_pBtnPrevious);

	m_pBtnPlay = new QPushButton;
	m_pBtnPlay->setFixedSize(18, 22);
	m_pBtnPlay->setStyleSheet(BTN_PLAYER_PLAY_QSS);
	QVBoxLayout * pPlayLayout = new QVBoxLayout;
	pPlayLayout->setSpacing(0);
	pPlayLayout->addSpacing(24);
	pPlayLayout->addWidget(m_pBtnPlay);

	m_pBtnNext = new QPushButton;
	m_pBtnNext->setFixedSize(18, 22);
	m_pBtnNext->setStyleSheet(BTN_PLAYER_NEXT_QSS);
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
	m_pAudioLabel->setText("无播放音频");
	m_pAudioLabel->setMinimumWidth(180);
	m_pAudioLabel->setFixedHeight(16);
	m_pAudioLabel->setStyleSheet(LABEL_PLAYER_NAME_QSS);
	QVBoxLayout * pPlayerLayout = new QVBoxLayout;
	pPlayerLayout->setSpacing(0);
	pPlayerLayout->addSpacing(10);
	pPlayerLayout->addWidget(m_pAudioLabel);

	m_pPlayerSlider = new QSlider;
	m_pPlayerSlider->setFixedSize(180, 20);
	m_pPlayerSlider->setOrientation(Qt::Horizontal);
	m_pPlayerSlider->setMinimum(0);
	m_pPlayerSlider->setStyleSheet(BTN_PLAYER_SLIDER_QSS);
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
	m_pVoiceSlider->setStyleSheet(BTN_PLAYER_VOICE_QSS);

	m_pMinBtn = new QPushButton;
	m_pMinBtn->setFixedSize(40, 40);
	m_pMinBtn->setStyleSheet(BTN_MIN_QSS);

	m_pMaxBtn = new QPushButton;
	m_pMaxBtn->setFixedSize(40, 40);
	m_pMaxBtn->setStyleSheet(BTN_MAX_QSS);

	m_pCloseBtn = new QPushButton;
	m_pCloseBtn->setFixedSize(40, 40);
	m_pCloseBtn->setStyleSheet(BTN_CLOSE_QSS);

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

	pRightLayout->addWidget(pTopWidget);
	pRightLayout->addStretch();

	connect(m_pMinBtn, SIGNAL(clicked()), this, SLOT(min_slot_click()));
	connect(m_pMaxBtn, SIGNAL(clicked()), this, SLOT(max_slot_click()));
	connect(m_pCloseBtn, SIGNAL(clicked()), this, SLOT(close_slot_click()));
}