#ifndef HORIZONTALRULER_H
#define HORIZONTALRULER_H

#include <QGraphicsView>

class HorizontalRuler : public QGraphicsView
{
	Q_OBJECT
public:
	explicit HorizontalRuler(QWidget *parent = 0);

private:
	void addLabel(int n);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *);

	void wheelEvent(QWheelEvent *);

	int m_value;
	bool m_scrolling;

signals:
	void scrolled(int);
};

#endif // HORIZONTALRULER_H
