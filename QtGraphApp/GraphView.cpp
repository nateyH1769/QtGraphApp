#include "GraphView.h"


/*

The default constructor for a custom QWidget.

*/
GraphView::GraphView(QWidget* parent): QGraphicsView(parent) {
	//Enables mouse drag events for drawing graph connections(NYI)
	this->setMouseTracking(true);
	
	//Creates a new QGraphicsScene which displays the graph
	scene = new QGraphicsScene(this);

	//setScene function places the new scene in the graphics view
	setScene(scene);
}

/*

Default destructor for a GraphView

*/
GraphView::~GraphView() {
	//The 'nodes' list and the scene are cleared
	clearNodes();
}

/*

Calculates the distance  between two sets of coordinates. Passing by constant
reference allows the function to run faster since the ints are not copied. However,
the points do need to be turned into doubles which is a waste of memory in my opinion.
At the moment, this function is only used to ensure two nodes do not overlap.

*/
double GraphView::dist(const int& x1, const int& x2, const int& y1, const int& y2) {
	//Initializes doubles for each coordinate to allow the std::pow function to be
	//called on the coordinates.
	double dX1 = double(x1);
	double dX2 = double(x2);
	double dY1 = double(y1);
	double dY2 = double(y2);

	//Calculates (x1-x2)^2
	double temp1 = std::pow(x1 - x2, 2.0);
	
	//Calculates (y1-y2)^2
	double temp2 = std::pow(y1 - y2, 2.0);
	
	//Gets the distance: Sqrt[(x1-x2)^2 + (y1-y2)^2]
	double d = std::pow(temp1 + temp2, .5);
	
	//Returns the distance
	return d;
}

/*

Checks the coordinates of a node-creating click to make sure that a 
new node will not overlap an old node. The use of a constant reference
will ideally speed up the function but I'm still unclear on the actual
workings of passing by const reference in c++. Currently, this is used
by the mouseReleaseEvent function, but will eventually be used to figure
out which node a connection is being drawn to. That feature is NYI. 

*/
bool GraphView::checkOverlap(const int& x, const int& y) {
	//Defaults to true(no overlap)
	bool place = true;

	//Loops for each node in the 'nodes' list
	for (auto& n : nodes) {

		//Checks to see if the click is within the radius of another node.
		//Changes to false if true.
		if (dist(x, n->x(), y, n->y()) < rad + 10) { place = false; break; }
	}
	//Returns true if no overlap, false if there is an overlap.
	return place;
}


/*

Handles mouse release event(Mouse event triggered from a button release
after a click). Currently this is used to draw a new node, but later it
will be used when drawing connections between nodes.

*/
void GraphView::mouseReleaseEvent(QMouseEvent* event) {
	//Checks if left mouse click
	if (event->button() == Qt::LeftButton && createNode == true) {

		//Gets the original coordinates of mouse event
		QPointF orig = QPointF(event->x(), event->y());
		
		//Transposes the original coordinates to scene coordinates
		QPointF fixed = mapToScene(orig.x() - rad / 2, orig.y() - rad / 2);
		
		//Creates a QRectangle with the coordinates of the click and the radius
		//of the circle.
		QRectF fRect = QRectF(fixed.x(), fixed.y(), qreal(rad), qreal(rad));
		
		//Checks if the new circle will overlap an old circle
		if (checkOverlap(fixed.x(), fixed.y())) {
		
			//Checks to make sure the whole circle will be within the screne
			if (sceneRect().contains(fRect)) {
			
				//Adds the new circle to the nodes list.
				nodes.append(scene->addEllipse(0, 0, qreal(rad), qreal(rad),
											   outlinePen, blueBrush));
				
				//Sets the coordinates of the circle to the fixed click-coordinates.
				nodes.last()->setPos(fixed.x(), fixed.y());
			}
		}
	}
}

void GraphView::toggleMode(int mode) {
	if (mode == 0) {
		if (createConnection == false && createNode == false) {
			createNode = true;
		}

		else if (createConnection == true && createNode == false) {
			createConnection = false;
			createNode = true;
		}

		else {
			createNode = false;
		}
	}

	else if (mode == 1) {
		if (createConnection == false && createNode == false) {
			createConnection= true;
		}

		else if (createConnection == false && createNode == true) {
			createConnection = true;
			createNode = false;
		}

		else {
			createConnection = false;
		}
	}

	else {
		qDebug << "ERROR: UNEXPECTED CODE (Function: 'GraphView::toggleMode')";
	}
}

/*

Let's the function 'QtGraphApp::toggleColors()' which button colors to change. Does this
by sending integers as codes:
Code 0: No current selections
Code 1: New node selected
Code 2: New connection selected
Code -1: An unexpected state was returned. 
		 Unlikely to occur, but most likely
		 would be caused by a true, true or
		 a null, null.

*/
int GraphView::getMode() {
	//Return code: 0 for no current selections
	if (createConnection == false && createNode == false) {
		return 0;
	}
	//Returns code: 1 if createNode is selected
	else if (createNode == true && createConnection == false) {
		return 1;
	}
	//Returns code: 2 if createConnection is selected
	else if (createNode == false && createConnection == true) {
		return 2;
	}
	//Returns code -1 if there is an error;
	else {
		//Prints error to console
		qDebug() << "ERROR: UNEXPECTED BOOLEAN (Function: 'GraphView::getMode()')";
		return -1;
	}
}

/*

This provides functionallity to the clear button. Removes all
nodes from the screen.

*/
void GraphView::clearNodes() {
	
	//Removes all items in the node list from the scene
	for (auto& node : nodes) {
		scene->removeItem(node);
	}

	//Clears the 'nodes' list
	nodes.clear();
}

/*

Fixes the sceneSize property of the scene so it fits the entire
GraphView.

*/
void GraphView::fixSceneSize() {
	//Fixes the scene size so that the program can properly determine
	//if a new circle will be created outside of the scene. The new
	//scene size is the size of the entire graph view shrunk by 10 
	//in each dimension.
	scene->setSceneRect((this->geometry()).adjusted(10,10,-10,-10));
}