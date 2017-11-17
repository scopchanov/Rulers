#include "HorizontalRuler.h"
#include <QGraphicsProxyWidget>
#include <QScrollBar>
#include <QLabel>

HorizontalRuler::HorizontalRuler(QWidget *parent) :
	QGraphicsView(parent),
	m_value(0),
	m_scrolling(false)
{
	setScene(new QGraphicsScene(this));
	setBackgroundBrush(QBrush(QPixmap(":/pix/images/bckg/hrule.png")));
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-open.png")));
	setAlignment(Qt::AlignLeft | Qt::AlignTop);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFocusPolicy(Qt::NoFocus);
	setAcceptDrops(false);
	setSceneRect(-10, 0, 1261, 15);

	for (int n = 0; n < 25; n++)
		addLabel(n);
}

void HorizontalRuler::addLabel(int n)
{
	auto *label = new QLabel();
	QPalette pal(label->palette());

	pal.setColor(QPalette::Window, QColor(Qt::white));
	pal.setColor(QPalette::WindowText, QColor(69, 67, 67));

	label->setPalette(pal);
	label->setMinimumWidth(1);
	label->setText(QString::number(50*n));
	label->adjustSize();

	QGraphicsProxyWidget *gtext = new QGraphicsProxyWidget();
	gtext->setWidget(label);
	scene()->addItem(gtext);
	gtext->setPos(50*n+21-label->rect().width()/2.0, 0);
}

void HorizontalRuler::mousePressEvent(QMouseEvent *event)
{
	m_value = event->pos().x();
	m_scrolling = true;
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-closed.png")));
}

void HorizontalRuler::mouseMoveEvent(QMouseEvent *event)
{
	if (m_scrolling) {
		horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->pos().x() - m_value));
		m_value = event->pos().x();

		scrolled(horizontalScrollBar()->value());
	}
}

void HorizontalRuler::mouseReleaseEvent(QMouseEvent *)
{
	m_scrolling = false;
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-open.png")));
}

void HorizontalRuler::wheelEvent(QWheelEvent *)
{

}
