#pragma once
#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H
#include <QApplication>
#include <QDialog>
#include <QGraphicsScene>
#include "qgraphicsview.h"
#include <QGraphicsItem>
#include <QWidget>
#include <QMainWindow>
#include <QVector>
#include <QMouseEvent>
#include <QColor>
#include <Qt>
#include <iostream>
#include <cmath>
#include <QDebug>
#include <QPointF>
#include <QRectF>
#include <GraphNode.h>

class GraphView : public QGraphicsView {
public:
	explicit GraphView(QWidget* parent);
	~GraphView();


	double dist(const int& x1, const int& x2, const int& y1, const int& y2);
	bool checkOverlap(const int & x, const int & y);
	void mouseReleaseEvent(QMouseEvent* event);
	void toggleMode(int mode);
	int getMode();
	void fixSceneSize();
	void clearNodes();


private:


	QBrush blueBrush = QBrush(Qt::blue);
	QPen outlinePen = QPen(Qt::black);
	const int rad = 25;
	QGraphicsScene *scene;
	QVector<QGraphicsEllipseItem*> nodes;
	QVector<Adjacency*> adjacencies;
	bool createNode = false;
	bool createConnection = false;


};

#endif