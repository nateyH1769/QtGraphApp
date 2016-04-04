#include "GraphNode.h"

//oye
GraphNode::GraphNode(QWidget* parent) :
	QWidget(parent) {

	nodeID = ++nextNode;
	text = "N" + QString::number(nodeID);
	

}

GraphNode::GraphNode(const int& xCoord, const int& yCoord,
					 QWidget* parent) : QWidget(parent) {
	nodeID = ++nextNode;
	text = "N" + QString::number(nodeID);
	canvas->setSceneRect(QRectF(xCoord, yCoord, radius, radius));
	canvas->addEllipse(qreal(0), qreal(0), qreal(radius), qreal(radius),
										 nodeBorder, nodeColor);


}



GraphNode::~GraphNode() {}



int GraphNode::radius = 45;
int GraphNode::nextNode = 0;

QBrush GraphNode::nodeColor = QBrush(Qt::blue);
QBrush GraphNode::selectedColor = QBrush(Qt::blue);

QPen GraphNode::nodeBorder = QPen(Qt::black);
QPen GraphNode::selectedBorder = QPen(Qt::yellow);