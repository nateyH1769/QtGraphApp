#pragma once
#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QVector>
#include <QGraphicsItem>

class Adjacency;
class GraphNode : public QWidget {
public:
	explicit GraphNode(QWidget* parent = 0);
	GraphNode(const int& xCoord, const int& yCoord, QWidget* parent = 0);
	~GraphNode();

private:
	QGraphicsScene* canvas;
	int nodeID = 0;
	QString text;
	bool nodeSelected;
	QVector<Adjacency*> adjancencyList;


	int isGitHubWorking = 20;
	static int nextNode;
	static int radius;

	static QBrush nodeColor;
	static QBrush selectedColor;
	static QPen nodeBorder;
	static QPen selectedBorder;
	static QPen textColor;
};

#endif