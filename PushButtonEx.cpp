#include "stdafx.h"
#include "PushButtonEx.h"

PushButtonEx::PushButtonEx(QWidget * parent) :
	  m_bIsExpand(false)
	, m_enumBtnType(BT_NORMAL)
	, m_pBehindIcon(156, 17)
	, m_sizeBehindIcon(10, 6)
	, m_pFrontIcon(24, 14)
	, m_sizeFrontIcon(14, 13)
	, m_pointText(51, 26)
	, m_colorNormal(QColor(0xef, 0xf2, 0xf6, 0xff))
	, m_colorHover(QColor(0xef, 0xf2, 0xf6, 0xff))
	, m_colorPressed(QColor(0xef, 0xf2, 0xf6, 0xff))
	, m_colorSelected(QColor(0xef, 0xf2, 0xf6, 0xff))
{
	connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
	setObjectName("PushButtonEx");
	setMouseTracking(true);

	PushButtonEx::installEventFilter(this);
}

PushButtonEx::~PushButtonEx()
{
	
}

void PushButtonEx::setExpand(bool bIsTrue)
{
	m_bIsExpand = bIsTrue;
	update();
}

bool PushButtonEx::isExpand()
{
	return m_bIsExpand;
}

void PushButtonEx::setBtnIcon(const QString &strBtnIcon)
{
	m_strBtnIcon = strBtnIcon;
}

void PushButtonEx::setSelectedBtnIcon(const QString &strBtnIcon)
{
	m_strSelectedBtnIcon = strBtnIcon;
}

void PushButtonEx::setBtnName(const QString &strName)
{
	m_strName = strName;
}

void PushButtonEx::setExpandIcon(const QString &strExpandIcon)
{
	m_strExpandIcon = strExpandIcon;
}

void PushButtonEx::setCollapseIcon(const QString &strCollapseIcon)
{
	m_strCollapseIcon = strCollapseIcon;
}

void PushButtonEx::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	//	{
	//	QStyleOption opt;
	//	opt.init(this);
	//	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	//}

	switch (m_enumBtnType)
	{
	case BT_MOUSE_MOVE:
		painter.setBrush(m_colorHover);
		painter.setPen(QColor(0xef, 0xf2, 0xf6, 0xff));
		painter.drawRect(this->rect());
		painter.setPen(QColor(0xff000000));
		painter.drawPixmap(m_pFrontIcon.x(), m_pFrontIcon.y(), m_sizeFrontIcon.width(), m_sizeFrontIcon.height(), m_strBtnIcon);
		painter.drawText(m_pointText.x(), m_pointText.y(), m_strName);
		m_enumBtnType = BT_NORMAL;
		break;
	case BT_PRESSED:
		painter.setBrush(m_colorPressed);
		painter.setPen(QColor(0xef, 0xf2, 0xf6, 0xff));
		painter.drawRect(this->rect());
		painter.setPen(QColor(0xff000000));
		painter.drawPixmap(m_pFrontIcon.x(), m_pFrontIcon.y(), m_sizeFrontIcon.width(), m_sizeFrontIcon.height(), m_strBtnIcon);
		painter.drawText(m_pointText.x(), m_pointText.y(), m_strName);
		break;
	case BT_SELECTED:
		painter.setBrush(m_colorSelected);
		painter.setPen(QColor(0xef, 0xf2, 0xf6, 0xff));
		painter.drawRect(this->rect());
		painter.drawPixmap(m_pFrontIcon.x(), m_pFrontIcon.y(), m_sizeFrontIcon.width(), m_sizeFrontIcon.height(), m_strSelectedBtnIcon);
		painter.drawText(m_pointText.x(), m_pointText.y(), m_strName);
		break;
	case BT_NORMAL:
		painter.setBrush(m_colorNormal);
		painter.setPen(QColor(0xef, 0xf2, 0xf6, 0xff));
		painter.drawRect(this->rect());
		painter.setPen(QColor(0xff000000));
		painter.drawPixmap(m_pFrontIcon.x(), m_pFrontIcon.y(), m_sizeFrontIcon.width(), m_sizeFrontIcon.height(), m_strBtnIcon);
		painter.drawText(m_pointText.x(), m_pointText.y(), m_strName);
		break;
	default:
		break;
	}
	
	//»æÖÆºó±ßÍ¼±ê
	if (m_strExpandIcon.size())
	{
		if (!m_bIsExpand)
		{
			painter.drawPixmap(m_pBehindIcon.x(), m_pBehindIcon.y(), m_sizeBehindIcon.width(), m_sizeBehindIcon.height(), m_strExpandIcon);
		}
		else
		{
			painter.drawPixmap(m_pBehindIcon.x(), m_pBehindIcon.y(), m_sizeBehindIcon.width(), m_sizeBehindIcon.height(), m_strCollapseIcon);
		}
	}
}

void PushButtonEx::clicked()
{
	m_bIsExpand = !m_bIsExpand;
	m_enumBtnType = BT_NORMAL;
	update();
}

void PushButtonEx::selected()
{
	m_enumBtnType = BT_SELECTED;
	update();
}

void PushButtonEx::unselected()
{
	m_enumBtnType = BT_NORMAL;
	update();
}

void PushButtonEx::mousemove()
{
	m_enumBtnType = BT_MOUSE_MOVE;
	update();
}

void PushButtonEx::pressed()
{
	m_enumBtnType = BT_PRESSED;
	update();
}

void PushButtonEx::mouseleave()
{
	m_enumBtnType = BT_NORMAL;
	update();
}

void PushButtonEx::setBehindIconPosition(int iX, int iY)
{
	m_pBehindIcon.setX(iX);
	m_pBehindIcon.setY(iY);
}

void PushButtonEx::setBehindIconSiz(int iWidth, int iHeight)
{
	m_sizeBehindIcon.setWidth(iWidth);
	m_sizeBehindIcon.setHeight(iHeight);
}

void PushButtonEx::setFrontIconPosition(int iX, int iY)
{
	m_pFrontIcon.setX(iX);
	m_pFrontIcon.setY(iY);
}

void PushButtonEx::setFrontIconSiz(int iWidth, int iHeight)
{
	m_sizeFrontIcon.setWidth(iWidth);
	m_sizeFrontIcon.setHeight(iHeight);
}

void PushButtonEx::setTextPosition(int iX, int iY)
{
	m_pointText.setX(iX);
	m_pointText.setY(iY);
}

void PushButtonEx::setTextSize(int iWidth, int iHeight)
{
	m_sizeText.setWidth(iWidth);
	m_sizeText.setHeight(iHeight);
}

void PushButtonEx::mousePressEvent(QMouseEvent *event)
{
	if (m_enumBtnType != BT_SELECTED)
	{
		emit pressed();
		QPushButton::mousePressEvent(event);
	}
}


void PushButtonEx::mouseReleaseEvent(QMouseEvent *event)
{
	QPushButton::mouseReleaseEvent(event);
}

void PushButtonEx::mouseMoveEvent(QMouseEvent *event)
{
	if (m_enumBtnType == BT_NORMAL)
	{
		emit mousemove();
		QPushButton::mouseMoveEvent(event);
	}
}

void PushButtonEx::setBkColor(const QColor & color)
{
	m_colorNormal = color;
}

void PushButtonEx::setHotBkColor(const QColor & color)
{
	m_colorHover = color;
}

void PushButtonEx::setPressedBkColor(const QColor & color)
{
	m_colorPressed = color;
}

void PushButtonEx::setSelectedBkColor(const QColor & color)
{
	m_colorSelected = color;
}

bool PushButtonEx::eventFilter(QObject *target, QEvent *event)
{
	if (event->type() == QEvent::Leave)
	{
		if (m_enumBtnType == BT_NORMAL || BT_PRESSED == m_enumBtnType)
		{
			emit mouseleave();
		}
	}

	return QPushButton::eventFilter(target, event);
}