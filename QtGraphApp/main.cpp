#include "qtgraphapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGraphApp w;
	w.show();
	return a.exec();
}
