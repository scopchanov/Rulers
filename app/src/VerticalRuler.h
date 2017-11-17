#ifndef VERTICALRULER_H
#define VERTICALRULER_H

#include <QGraphicsView>

class VerticalRuler : public QGraphicsView
{
	Q_OBJECT
public:
	explicit VerticalRuler(QWidget *parent = 0);

private:
	void addLabel(int n);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *);

	void wheelEvent(QWheelEvent *);

	int m_value;
	bool m_scrolling ;

signals:
	void scrolled(int);
};

#endif // VERTICALRULER_H
