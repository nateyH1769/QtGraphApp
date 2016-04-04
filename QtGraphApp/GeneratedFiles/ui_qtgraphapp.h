/********************************************************************************
** Form generated from reading UI file 'qtgraphapp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGRAPHAPP_H
#define UI_QTGRAPHAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "graphview.h"

QT_BEGIN_NAMESPACE

class Ui_QtGraphAppClass
{
public:
    QWidget *centralWidget;
    GraphView *graphScreen;
    QPushButton *clearButton;
    QLabel *xPos;
    QLabel *yPos;
    QPushButton *buttonNewNode;
    QPushButton *buttonConnection;
    QMenuBar *menuBar;
    QMenu *menuHi;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGraphAppClass)
    {
        if (QtGraphAppClass->objectName().isEmpty())
            QtGraphAppClass->setObjectName(QStringLiteral("QtGraphAppClass"));
        QtGraphAppClass->resize(1091, 716);
        centralWidget = new QWidget(QtGraphAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphScreen = new GraphView(centralWidget);
        graphScreen->setObjectName(QStringLiteral("graphScreen"));
        graphScreen->setGeometry(QRect(30, 20, 1021, 561));
        graphScreen->setMouseTracking(true);
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(30, 610, 93, 31));
        xPos = new QLabel(centralWidget);
        xPos->setObjectName(QStringLiteral("xPos"));
        xPos->setGeometry(QRect(220, 620, 171, 16));
        yPos = new QLabel(centralWidget);
        yPos->setObjectName(QStringLiteral("yPos"));
        yPos->setGeometry(QRect(570, 610, 181, 16));
        buttonNewNode = new QPushButton(centralWidget);
        buttonNewNode->setObjectName(QStringLiteral("buttonNewNode"));
        buttonNewNode->setGeometry(QRect(130, 610, 31, 31));
        buttonNewNode->setStyleSheet(QStringLiteral("selection-background-color: rgb(90, 90, 90);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtGraphApp/Resources/NewNodeIconTransparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNewNode->setIcon(icon);
        buttonNewNode->setCheckable(true);
        buttonNewNode->setChecked(false);
        buttonConnection = new QPushButton(centralWidget);
        buttonConnection->setObjectName(QStringLiteral("buttonConnection"));
        buttonConnection->setGeometry(QRect(160, 610, 31, 31));
        buttonConnection->setStyleSheet(QStringLiteral("selection-background-color: rgb(90, 90, 90);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QtGraphApp/Resources/NewConnectionIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonConnection->setIcon(icon1);
        buttonConnection->setCheckable(true);
        QtGraphAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGraphAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1091, 26));
        menuHi = new QMenu(menuBar);
        menuHi->setObjectName(QStringLiteral("menuHi"));
        QtGraphAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGraphAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGraphAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGraphAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGraphAppClass->setStatusBar(statusBar);

        menuBar->addAction(menuHi->menuAction());

        retranslateUi(QtGraphAppClass);

        QMetaObject::connectSlotsByName(QtGraphAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGraphAppClass)
    {
        QtGraphAppClass->setWindowTitle(QApplication::translate("QtGraphAppClass", "QtGraphApp", 0));
        clearButton->setText(QApplication::translate("QtGraphAppClass", "Clear", 0));
        xPos->setText(QString());
        yPos->setText(QString());
        buttonNewNode->setText(QString());
        buttonConnection->setText(QString());
        menuHi->setTitle(QApplication::translate("QtGraphAppClass", "Hi", 0));
    } // retranslateUi

};

namespace Ui {
    class QtGraphAppClass: public Ui_QtGraphAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGRAPHAPP_H
