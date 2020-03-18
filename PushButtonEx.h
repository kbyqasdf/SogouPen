#pragma once
#include "stdafx.h"


typedef enum
{
	BT_NORMAL,
	BT_MOUSE_MOVE,
	BT_PRESSED,
	BT_RELEASED,
	BT_SELECTED
}BTN_TYPE;

class PushButtonEx : public QPushButton
{
	Q_OBJECT

public:
	PushButtonEx(QWidget *parent = Q_NULLPTR);
	~PushButtonEx();

public:
	void setBtnIcon(const QString &strBtnIcon);
	void setSelectedBtnIcon(const QString &strBtnIcon);
	void setBtnName(const QString &strName);
	void setExpandIcon(const QString &strExpandIcon);
	void setCollapseIcon(const QString &strCollapseIcon);
	void setExpand(bool bIsTrue);
	bool isExpand();
	void setBehindIconPosition(int iX, int iY);
	void setBehindIconSiz(int iWidth, int iHeight);
	void setFrontIconPosition(int iX, int iY);
	void setFrontIconSiz(int iWidth, int iHeight);
	void setTextPosition(int iX, int iY);
	void setTextSize(int iWidth, int iHeight);
	void setBkColor(const QColor & color);
	void setHotBkColor(const QColor & color);
	void setPressedBkColor(const QColor & color);
	void setSelectedBkColor(const QColor & color);


public slots:
	void clicked();
	void pressed();
	void selected();
	void unselected();
	void mousemove();
	void mouseleave();

protected:
	void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
	virtual void mousePressEvent(QMouseEvent *event)Q_DECL_OVERRIDE;
	virtual void mouseReleaseEvent(QMouseEvent *event)Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent *event)Q_DECL_OVERRIDE;
	virtual bool eventFilter(QObject *target, QEvent *event);

private:
	QString m_strBtnIcon;
	QString m_strSelectedBtnIcon;
	QString m_strName;
	QString m_strExpandIcon;
	QString m_strCollapseIcon;

	bool    m_bIsExpand;

	QPoint m_pBehindIcon;
	QSize  m_sizeBehindIcon;

	QPoint m_pFrontIcon;
	QSize  m_sizeFrontIcon;

	QPoint m_pointText;
	QSize  m_sizeText;

	BTN_TYPE m_enumBtnType;
	QColor m_colorNormal;
	QColor m_colorHover;
	QColor m_colorPressed;
	QColor m_colorSelected;
};