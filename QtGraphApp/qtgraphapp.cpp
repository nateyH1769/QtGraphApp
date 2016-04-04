#include "qtgraphapp.h"
#include "ui_qtgraphapp.h"
QtGraphApp::QtGraphApp(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);
	graphScreen->fixSceneSize();
	toggleColors();


	connect(this->clearButton, &QPushButton::clicked,
			this->graphScreen, &GraphView::clearNodes);
	
	connect(this->buttonNewNode, &QPushButton::clicked,
			this, &QtGraphApp::toggleNodeMode);
	
	connect(this->buttonConnection, &QPushButton::clicked,
			this,&QtGraphApp::toggleConnectMode);



}

QtGraphApp::~QtGraphApp()
{
	
}

void QtGraphApp::toggleNodeMode() {
	buttonNewNode->setChecked(!((*buttonNewNode).isChecked()));
	buttonConnection->setChecked(false);
	graphScreen->toggleMode(0);
	toggleColors();
}

void QtGraphApp::toggleConnectMode() {
	buttonConnection->setChecked(!((*buttonConnection).isChecked()));
	buttonNewNode->setChecked(false);
	graphScreen->toggleMode(1);
	toggleColors();
}

void QtGraphApp::toggleColors() {
	switch (graphScreen->getMode()) {
		case 1:
		{
			buttonNewNode->setStyleSheet("QPushButton {background-color: #d9d9d9}");
			buttonConnection->setStyleSheet("QPushButton {background-color: #f0f0f0}");
			buttonConnection->update();
			buttonNewNode->update();
			break;
		}

		case 2:
		{
			buttonConnection->setStyleSheet("QPushButton {background-color: #d9d9d9}");
			buttonNewNode->setStyleSheet("QPushButton {background-color: #f0f0f0}");
			buttonConnection->update();
			buttonNewNode->update();
			break;
		}
		
		case -1:
		{
			break;
		}

		default :
		{
			buttonConnection->setStyleSheet("QPushButton {background-color: #f0f0f0}");
			buttonNewNode->setStyleSheet("QPushButton {background-color: #f0f0f0}");
			buttonConnection->update();
			buttonNewNode->update();
			break;
		}
	}
}