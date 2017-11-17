#include "VerticalRuler.h"
#include <QGraphicsProxyWidget>
#include <QScrollBar>
#include <QLabel>

VerticalRuler::VerticalRuler(QWidget *parent) :
	QGraphicsView(parent),
	m_value(0),
	m_scrolling(false)
{
	setScene(new QGraphicsScene(this));
	setBackgroundBrush(QBrush(QPixmap(":/pix/images/bckg/vrule.png")));
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-open.png")));
	setAlignment(Qt::AlignLeft | Qt::AlignTop);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFocusPolicy(Qt::NoFocus);
	setAcceptDrops(false);
	setSceneRect(0, -10, 15, 811);

	for (int n = 0; n < 16; n++)
		addLabel(n);
}

void VerticalRuler::addLabel(int n)
{
	auto *label = new QLabel();
	QPalette p(label->palette());

	p.setColor(QPalette::Window, QColor(Qt::white));
	p.setColor(QPalette::WindowText, QColor(69, 67, 67));

	label->setPalette(p);
	label->setMinimumWidth(1);
	label->setText(QString::number(50*n));
	label->adjustSize();

	QGraphicsProxyWidget *gtext = new QGraphicsProxyWidget();
	gtext->setWidget(label);
	scene()->addItem(gtext);
	gtext->setRotation(-90);
	gtext->setPos(0, 50*n+label->rect().width()/2.0+20);
}

void VerticalRuler::mousePressEvent(QMouseEvent *event)
{
	m_value = event->pos().y();
	m_scrolling = true;
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-closed.png")));
}

void VerticalRuler::mouseMoveEvent(QMouseEvent *event)
{
	if (m_scrolling) {
		verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->pos().y() - m_value));
		m_value = event->pos().y();

		scrolled(verticalScrollBar()->value());
	}
}

void VerticalRuler::mouseReleaseEvent(QMouseEvent *)
{
	m_scrolling = false;
	setCursor(QCursor(QPixmap(":/pix/images/icons/hand-open.png")));
}

void VerticalRuler::wheelEvent(QWheelEvent *)
{

}
