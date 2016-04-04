#pragma once
#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <QWidget>
#include <QGraphicsScene>

class GraphNode;
class Adjacency: public QWidget  {
public:
	bool directed;
	bool valued;
	GraphNode* first;
	GraphNode* second;
	double value;
	Adjacency(QWidget* parent = 0);

	Adjacency(bool temp_dir, bool temp_valued, GraphNode* temp_first,
			  GraphNode* temp_second, double temp_value, QWidget* parent = 0);

	~Adjacency();

private:
	QGraphicsScene* canvas;
	QString text;
	bool adjSelected;

	static QBrush arrowColor;
	static QPen textColor;
};

#endif