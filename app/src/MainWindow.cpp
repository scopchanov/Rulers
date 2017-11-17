#include "MainWindow.h"
#include "HorizontalRuler.h"
#include "VerticalRuler.h"
#include <QVBoxLayout>
#include <QScrollBar>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	auto *widget = new QWidget(this);
	auto *layoutMain = new QVBoxLayout(widget);
	auto *layoutBody = new QHBoxLayout();
	auto *gridLayout = new QGridLayout();
	auto *hruler = new HorizontalRuler(this);
	auto *vruler = new VerticalRuler(this);
	auto *view = new QGraphicsView(this);

	hruler->setMaximumSize(QSize(1263, 20));
	vruler->setMaximumSize(QSize(20, 813));

	view->setFrameStyle(QFrame::StyledPanel);
	view->setMaximumSize(QSize(1263, 813));
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	gridLayout->addWidget(new QLabel(this), 0, 0, 1, 1);
	gridLayout->addWidget(hruler, 0, 1, 1, 1);
	gridLayout->addWidget(vruler, 1, 0, 1, 1);
	gridLayout->addWidget(view, 1, 1, 1, 1);
	gridLayout->setSpacing(0);

	layoutBody->addStretch();
	layoutBody->addLayout(gridLayout);
	layoutBody->addStretch();
	layoutBody->setContentsMargins(0, 0, 0, 0);
	layoutBody->setSpacing(0);

	layoutMain->addStretch();
	layoutMain->addLayout(layoutBody);
	layoutMain->addStretch();
	layoutMain->setContentsMargins(0, 0, 0, 0);
	layoutMain->setSpacing(0);


	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	view->setBackgroundBrush(QPixmap(":/pix/images/bckg/grid.png"));
	view->setScene(new QGraphicsScene(this));
	view->setSceneRect(-10, -10, 1261, 811);

	setCentralWidget(widget);
	resize(1126, 695);

	connect(hruler, &HorizontalRuler::scrolled, view->horizontalScrollBar(), &QScrollBar::setValue);
	connect(vruler, &VerticalRuler::scrolled, view->verticalScrollBar(), &QScrollBar::setValue);
	connect(view->horizontalScrollBar(), &QScrollBar::valueChanged, hruler->horizontalScrollBar(), &QScrollBar::setValue);
	connect(view->verticalScrollBar(), &QScrollBar::valueChanged, vruler->verticalScrollBar(), &QScrollBar::setValue);
}
