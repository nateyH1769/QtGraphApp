#ifndef QTGRAPHAPP_H
#define QTGRAPHAPP_H
#include <QApplication>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWidget>
#include <QMainWindow>
#include <QVector>
#include <QMouseEvent>
#include<QColor>
#include <Qt>
#include <iostream>
#include <cmath>
#include <QDebug>
#include <QPointF>
#include <QRectF>
#include "ui_qtgraphapp.h"
namespace Ui { class QtGraphApp; }

class QtGraphApp : public QMainWindow, private Ui::QtGraphAppClass {
	Q_OBJECT

public:

	explicit QtGraphApp(QWidget *parent = 0);
	~QtGraphApp();
	void toggleNodeMode();
	void toggleConnectMode();
	void toggleColors();



private:

};

#endif  QTGRAPHAPP_H
