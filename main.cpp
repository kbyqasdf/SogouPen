#include "stdafx.h"
#include <QApplication>
#include "SogouPen.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SogouPen * ab = new SogouPen();

	ab->show();

	return a.exec();
}
