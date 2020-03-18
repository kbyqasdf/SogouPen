#include "stdafx.h"
#include "TravelDlg.h"

#pragma execution_character_set("utf-8")

#define    ALL_BTN      0
#define    LOCAL_BTN	1001

#define BTN_ALL_QSS					"PushButtonEx{font-family:Microsoft YaHei; font-size:14px; color:#ff000000;border:none;}" 

#define BTN_DEV_BTN_QSS				"PushButtonEx{font-family:Microsoft YaHei; font-size:12px; color:#ff000000;border:none;}" 
								 
#define BTN_ALL_SELECTED_QSS		"PushButtonEx{font-family:Microsoft YaHei; font-size:14px; color:#ffffffff; border:none;}" 

#define BTN_DEV_SELECTED_QSS		"PushButtonEx{font-family:Microsoft YaHei; font-size:12px; color:#ffffffff; border:none;}" 

#define BTN_IMPORT_FROM_DEV_QSS		"PushButtonEx{font-family:Microsoft YaHei; font-size:14px; color:#ff000000; border:none;}"

#define BTN_IMPORT_LOCAL_AUDIO_QSS  "PushButtonEx{font-family:Microsoft YaHei; font-size:12px; color:#ff000000; border:none; background:#ffdfe1e6}" \
									"PushButtonEx:hover{background-color:#ffffd6c7;}"\
									"PushButtonEx:pressed{background-color:#ffffbba2;}"

#define BTN_SET_QSS					"QPushButton{font-family:Microsoft YaHei; font-size:12px; border:none;}" \
									"QPushButton:hover{color:#ffff7846}" \
									"QPushButton:pressed{color:#FFec4703}"

CTravelDlg::CTravelDlg(QWidget * parent)
	: QWidget(parent)
	, m_pButtonGroup(NULL)
	, m_iButtonId(-1)
	, m_pCurrentSelectedButton(NULL)
{
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(0xef, 0xf2, 0xf6, 0xff));
	this->setPalette(palette);
	m_pTravelLayout = new QVBoxLayout(this);
	m_pTravelLayout->setContentsMargins(0, 0, 0, 0);
	m_pTravelLayout->setSpacing(0);
	this->setFixedWidth(190);
	this->setMinimumHeight(688);
	setAutoFillBackground(true);

	initPersonalInfo();
	initButtonListArea();
	initBottomButton();

	InitConnect();
}

void CTravelDlg::initPersonalInfo()
{
	QLabel * pTitleLabel = new QLabel();
	pTitleLabel->setPixmap(QPixmap("./Resources/pic/SogouLogo.png"));
	pTitleLabel->setFixedSize(144, 32);
	QHBoxLayout * pTitleHLayout = new QHBoxLayout;
	pTitleHLayout->addWidget(pTitleLabel, Qt::AlignCenter);

	QLabel * pIconLabel = new QLabel();
	pIconLabel->setPixmap(QPixmap("./Resources/pic/imgDefaultAvatar.png"));
	pIconLabel->setFixedSize(55, 55);
	QHBoxLayout * pIconHLayout = new QHBoxLayout;
	pIconHLayout->addWidget(pIconLabel, Qt::AlignCenter);
	pIconHLayout->setSpacing(0);

	QLabel * pUserNameLabel = new QLabel();
	pUserNameLabel->setText(tr("kbyq"));
	pUserNameLabel->setFixedHeight(26);
	pUserNameLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	QFont font;
	font.setFamily("MicrosoftYahei");
	font.setPointSize(18);
	pUserNameLabel->setFont(font);
	QHBoxLayout * pUserNameHLayout = new QHBoxLayout;
	pUserNameHLayout->addWidget(pUserNameLabel, Qt::AlignHCenter);

	QHBoxLayout * pVipHLayout = new QHBoxLayout;
	QLabel * pVipLabel1 = new QLabel;
	pVipLabel1->setFixedSize(20, 20);
	pVipLabel1->setPixmap(QPixmap("./Resources/pic/icHomeMember1.png"));
	QLabel * pVipLabel2 = new QLabel;
	pVipLabel2->setFixedSize(20, 20);
	pVipLabel2->setPixmap(QPixmap("./Resources/pic/icHomeMember2.png"));
	QLabel * pVipLabel3 = new QLabel;
	pVipLabel3->setFixedSize(20, 20);
	pVipLabel3->setPixmap(QPixmap("./Resources/pic/icHomeMember3.png"));
	QLabel * pVipLabel4 = new QLabel;
	pVipLabel4->setFixedSize(20, 20);
	pVipLabel4->setPixmap(QPixmap("./Resources/pic/icHomeMember4.png"));
	pVipHLayout->addStretch();
	pVipHLayout->setSpacing(4);
	pVipHLayout->addWidget(pVipLabel1);
	pVipHLayout->addWidget(pVipLabel2);
	pVipHLayout->addWidget(pVipLabel3);
	pVipHLayout->addWidget(pVipLabel4);
	pVipHLayout->addStretch();

	QLabel * pLabel = new QLabel;
	pLabel->setFixedSize(190, 1);
	pLabel->setStyleSheet("background-color:#33bec3c9");

	m_pTravelLayout->addSpacing(22);
	m_pTravelLayout->addLayout(pTitleHLayout);
	m_pTravelLayout->addSpacing(18);
	m_pTravelLayout->addLayout(pIconHLayout);
	m_pTravelLayout->addSpacing(9);
	m_pTravelLayout->addLayout(pUserNameHLayout, Qt::AlignTop);
	m_pTravelLayout->addSpacing(3);
	m_pTravelLayout->addLayout(pVipHLayout);
	m_pTravelLayout->addSpacing(20);
	m_pTravelLayout->addWidget(pLabel);
}

void CTravelDlg::initButtonListArea()
{
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(0xef, 0xf2, 0xf6, 0xff));

	m_pListWidget = new QWidget;
	m_pListWidget->setFixedWidth(190);
	m_pListWidget->setMinimumHeight(444);
	m_pListWidget->setPalette(palette);
	QVBoxLayout * pListVLayout = new QVBoxLayout(m_pListWidget);
	m_pListWidget->setContentsMargins(0, 0, 0, 0);
	pListVLayout->setSpacing(0);
	pListVLayout->setContentsMargins(0, 0, 0, 0);

	m_pScrollArea = new QScrollArea;
	m_pScrollArea->setBackgroundRole(QPalette::Dark);
	m_pScrollArea->setWidget(m_pListWidget);
	m_pScrollArea;

	QLabel * pMyAudioLabel = new QLabel;
	pMyAudioLabel->setText(tr("我的音频库"));
	pMyAudioLabel->setFixedSize(60, 14);
	pMyAudioLabel->setStyleSheet("font-family:Microsoft YaHei; font-size:12px; color:#ff969696");
	QHBoxLayout * pMyAudioHLayout = new QHBoxLayout;
	pMyAudioHLayout->addSpacing(28);
	pMyAudioHLayout->addWidget(pMyAudioLabel, Qt::AlignLeft);
	pMyAudioHLayout->addStretch();

	m_pButtonGroup = new QButtonGroup(this);
	m_pAllButton = new PushButtonEx;
	m_pButtonGroup->addButton(m_pAllButton, ALL_BTN);
	m_pAllButton->setFixedSize(190, 40);
	m_pAllButton->setBtnName("全部音频");
	m_pAllButton->setBtnIcon("./Resources/pic/quanbu.png");
	m_pAllButton->setSelectedBtnIcon("./Resources/pic/quanbu-white.png");
	m_pAllButton->setStyleSheet(BTN_ALL_QSS);
	m_pAllButton->setFocusPolicy(Qt::ClickFocus);
	m_pAllButton->setAutoFillBackground(true);
	m_pAllButton->setHotBkColor(QColor(0xff, 0x78, 0x46, 0x4d));
	m_pAllButton->setPressedBkColor(QColor(0xff, 0x78, 0x46, 0x80));
	m_pAllButton->setSelectedBkColor(QColor(0xff, 0x78, 0x46, 0xff));
	m_pAllButton->setCursor(QCursor(Qt::PointingHandCursor));

	m_pLocalButton = new PushButtonEx;
	m_pButtonGroup->addButton(m_pLocalButton, LOCAL_BTN);
	m_pLocalButton->setFixedSize(190, 40);
	m_pLocalButton->setBtnName("从本地导入");
	m_pLocalButton->setBtnIcon("./Resources/pic/bendi.png");
	m_pLocalButton->setSelectedBtnIcon("./Resources/pic/bendi-white.png");
	m_pLocalButton->setStyleSheet(BTN_ALL_QSS);
	m_pLocalButton->setFocusPolicy(Qt::ClickFocus);
	m_pLocalButton->setAutoFillBackground(true);
	m_pLocalButton->setHotBkColor(QColor(0xff, 0x78, 0x46, 0x4d));
	m_pLocalButton->setPressedBkColor(QColor(0xff, 0x78, 0x46, 0x80));
	m_pLocalButton->setSelectedBkColor(QColor(0xff, 0x78, 0x46, 0xff));
	m_pLocalButton->setCursor(QCursor(Qt::PointingHandCursor));
	//m_pLocalButton->setVisible(false);

	m_pImportFromDevBtn = new PushButtonEx;
	m_pImportFromDevBtn->setFixedSize(190, 40);
	m_pImportFromDevBtn->setBtnIcon("./Resources/pic/shebei.png");
	m_pImportFromDevBtn->setBtnName("从设备导入");
	m_pImportFromDevBtn->setExpandIcon("./Resources/pic/expand.png");
	m_pImportFromDevBtn->setCollapseIcon("./Resources/pic/collapse.png");
	m_pImportFromDevBtn->setStyleSheet(BTN_IMPORT_FROM_DEV_QSS);
	m_pImportFromDevBtn->setVisible(false);
	m_pImportFromDevBtn->setCursor(QCursor(Qt::PointingHandCursor));

	m_pImportFromDevWidget = new QWidget;
	m_pImportFromDevWidget->setFixedWidth(190);
	m_pImportFromDevWidget->setHidden(true);
	m_pImportFromDevWidget->setContentsMargins(0, 0, 0, 0);
	m_pImportFromDevWidget->setPalette(palette);
	m_pImportFromDevWidget->setVisible(false);
	m_pImportFromDevLayout = new QVBoxLayout(m_pImportFromDevWidget);
	m_pImportFromDevLayout->setSpacing(0);
	m_pImportFromDevLayout->setContentsMargins(0, 0, 0, 0);

	QLabel * pDeviceLabel = new QLabel;
	pDeviceLabel->setFixedHeight(24);
	pDeviceLabel->setText("设备：未接入");
	pDeviceLabel->setStyleSheet("QLabel{ font-family:Microsoft YaHei; font-size:12px; color:#ff969696; border:none; }");
	pDeviceLabel->setContentsMargins(24, 0, 0, 0);

	m_pRecorderWidget = new QWidget;
	m_pRecorderWidget->setFixedWidth(190);
	m_pRecorderWidget->setContentsMargins(0, 0, 0, 0);
	m_pRecorderWidget->setPalette(palette);
	m_pRecorderVLayout = new QVBoxLayout(m_pRecorderWidget);
	m_pRecorderVLayout->setSpacing(0);
	m_pRecorderVLayout->setContentsMargins(0, 0, 0, 0);
	m_pRecorderVLayout->addStretch();

	pListVLayout->addSpacing(10);
	pListVLayout->addLayout(pMyAudioHLayout);
	pListVLayout->addSpacing(10);
	pListVLayout->addWidget(m_pAllButton);
	pListVLayout->addWidget(m_pImportFromDevBtn);
	pListVLayout->addWidget(m_pImportFromDevWidget);
	pListVLayout->addWidget(m_pLocalButton);
	pListVLayout->addSpacing(20);
	pListVLayout->addWidget(pDeviceLabel);
	pListVLayout->addWidget(m_pRecorderWidget);
	m_pTravelLayout->addWidget(m_pListWidget);
}

void CTravelDlg::initBottomButton()
{
	m_pImportFromLocalBtn = new PushButtonEx;
	m_pImportFromLocalBtn->setFixedSize(150, 36);
	m_pImportFromLocalBtn->setBtnName("导入本地音频");
	m_pImportFromLocalBtn->setBtnIcon("./Resources/pic/import.png");
	m_pImportFromLocalBtn->setFrontIconPosition(31, 13);
	m_pImportFromLocalBtn->setFrontIconSiz(10, 10);
	m_pImportFromLocalBtn->setTextPosition(47, 24);
	m_pImportFromLocalBtn->setStyleSheet(BTN_IMPORT_LOCAL_AUDIO_QSS);
	m_pImportFromLocalBtn->setBkColor(QColor(0xdf, 0xe1, 0xe6, 0xff));
	m_pImportFromLocalBtn->setHotBkColor(QColor(0xff, 0xd6, 0xc7, 0xff));
	m_pImportFromLocalBtn->setPressedBkColor(QColor(0xff, 0xbb, 0xa2, 0xff));
	m_pImportFromLocalBtn->setCursor(QCursor(Qt::PointingHandCursor));
	QHBoxLayout * pImportFromLocalLayout = new QHBoxLayout;
	pImportFromLocalLayout->addWidget(m_pImportFromLocalBtn);
	pImportFromLocalLayout->setContentsMargins(20, 0, 20, 0);
	m_pTravelLayout->addLayout(pImportFromLocalLayout);
	m_pTravelLayout->addSpacing(10);

	m_pSetBtn = new QPushButton;
	m_pSetBtn->setText("高级设置");
	m_pSetBtn->setFixedSize(48, 24);
	m_pSetBtn->setStyleSheet(BTN_SET_QSS);
	m_pSetBtn->setCursor(QCursor(Qt::PointingHandCursor));

	m_pHelpBtn = new QPushButton;
	m_pHelpBtn->setText("帮助中心");
	m_pHelpBtn->setFixedSize(48, 24);
	m_pHelpBtn->setStyleSheet(BTN_SET_QSS);
	m_pHelpBtn->setCursor(QCursor(Qt::PointingHandCursor));

	QLabel * pSplitLabel = new QLabel;
	pSplitLabel->setFixedSize(1, 9);
	pSplitLabel->setPixmap(QPixmap("./Resources/pic/split-line.png"));

	QHBoxLayout * pSetHLayout = new QHBoxLayout;
	pSetHLayout->setSpacing(0);
	pSetHLayout->setContentsMargins(0, 0, 0, 0);
	pSetHLayout->addStretch();
	pSetHLayout->addWidget(m_pSetBtn);
	pSetHLayout->addSpacing(15);
	pSetHLayout->addWidget(pSplitLabel);
	pSetHLayout->addSpacing(15);
	pSetHLayout->addWidget(m_pHelpBtn);
	pSetHLayout->addStretch();

	m_pTravelLayout->addLayout(pSetHLayout);
	m_pTravelLayout->addSpacing(24);
}

CTravelDlg::~CTravelDlg()
{
	
}

void CTravelDlg::InitConnect()
{
	connect(m_pButtonGroup, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(slotButtonGroupClick(QAbstractButton *)));
	connect(m_pImportFromDevBtn, SIGNAL(clicked()), this, SLOT(slotImportFromDevBtnClick()));
	connect(m_pSetBtn, SIGNAL(clicked()), this, SLOT(slotSetBtnClick()));
	connect(m_pHelpBtn, SIGNAL(clicked()), this, SLOT(slotHelpBtnClick()));
}

void CTravelDlg::slotButtonGroupClick(QAbstractButton * pButton)
{
	if (m_pCurrentSelectedButton)
	{
		emit m_pCurrentSelectedButton->unselected();
		if (m_pCurrentSelectedButton == m_pAllButton || m_pCurrentSelectedButton == m_pLocalButton)
		{
			m_pCurrentSelectedButton->setStyleSheet(BTN_ALL_QSS);
		}
		else
		{
			m_pCurrentSelectedButton->setStyleSheet(BTN_DEV_BTN_QSS);
		}
	}

	PushButtonEx * pButtonEx = (PushButtonEx *)pButton;
	emit pButtonEx->selected();
	if (pButtonEx == m_pAllButton || m_pLocalButton == pButtonEx)
	{
		pButtonEx->setStyleSheet(BTN_ALL_SELECTED_QSS);
	}
	else
	{
		pButtonEx->setStyleSheet(BTN_DEV_SELECTED_QSS);
	}

	m_pCurrentSelectedButton = pButtonEx;
}

void CTravelDlg::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Down:
		break;
	case Qt::Key_Up:
		break;
	default:
		QWidget::keyPressEvent(event);
		break;
	}
}

void CTravelDlg::AddImportFromDevBtn()
{
	PushButtonEx * pButton = new PushButtonEx;
	pButton->setFixedSize(190, 40);
	pButton->setBtnName("搜狗C1录音笔");
	pButton->setStyleSheet(BTN_DEV_BTN_QSS);
	pButton->setFocusPolicy(Qt::ClickFocus);
	pButton->setAutoFillBackground(true);
	pButton->setHotBkColor(QColor(0xff, 0x78, 0x46, 0x4d));
	pButton->setPressedBkColor(QColor(0xff, 0x78, 0x46, 0x80));
	pButton->setSelectedBkColor(QColor(0xff, 0x78, 0x46, 0xff));
	pButton->setCursor(QCursor(Qt::PointingHandCursor));
	m_pButtonGroup->addButton(pButton);
	m_listButtonEx.push_back(pButton);
	m_pImportFromDevLayout->addWidget(pButton);
	
	m_pImportFromDevWidget->setFixedHeight(40 * m_listButtonEx.size());
	m_pImportFromDevBtn->setVisible(true);
	m_pImportFromDevWidget->setVisible(true);
	m_pImportFromDevWidget->setHidden(!m_pImportFromDevBtn->isExpand());
}

void CTravelDlg::slotImportFromDevBtnClick()
{
	m_pImportFromDevWidget->setHidden(!m_pImportFromDevBtn->isExpand());
}

void CTravelDlg::AddRecordBtn()
{
	PushButtonEx * pButton = new PushButtonEx;
	pButton->setFixedSize(190, 40);
	pButton->setBtnName("搜狗C1录音笔");
	pButton->setBtnIcon("./Resources/pic/recorder.png");
	pButton->setSelectedBtnIcon("./Resources/pic/recorder-hover.png");
	pButton->setFrontIconPosition(28, 13);
	pButton->setFrontIconSiz(10, 14);
	pButton->setStyleSheet(BTN_ALL_QSS);
	pButton->setFocusPolicy(Qt::ClickFocus);
	pButton->setAutoFillBackground(true);
	pButton->setHotBkColor(QColor(0xff, 0x78, 0x46, 0x4d));
	pButton->setPressedBkColor(QColor(0xff, 0x78, 0x46, 0x80));
	pButton->setSelectedBkColor(QColor(0xff, 0x78, 0x46, 0xff));
	pButton->setCursor(QCursor(Qt::PointingHandCursor));
	m_listRecord.push_back(pButton);
	m_pButtonGroup->addButton(pButton);
	m_pRecorderVLayout->insertWidget(m_listRecord.size() - 1, pButton);
}

void CTravelDlg::slotSetBtnClick()
{
	AddImportFromDevBtn();
}

void CTravelDlg::slotHelpBtnClick()
{
	AddRecordBtn();
}