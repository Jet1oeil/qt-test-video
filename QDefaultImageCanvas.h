/*
 * QDefaultImageCanvas.h
 *
 *  Created on: 30 avr. 2018
 *      Author: alavier
 */

#ifndef SRC_GUI_QDEFAULTIMAGECANVAS_H_
#define SRC_GUI_QDEFAULTIMAGECANVAS_H_

#include <QFrame>
#include <QSharedPointer>
#include <QPaintEvent>
#include <QSize>

#include <QImage>
#include <QSharedPointer>
#include <QMutex>

class QDefaultImageCanvas : public QFrame {
	Q_OBJECT

public:
	QDefaultImageCanvas(QWidget* parent = NULL, Qt::GlobalColor bgColor = Qt::black);
	virtual ~QDefaultImageCanvas();

	void updateImage(const QSharedPointer<QImage>& pImage);


signals:
	// Internal use
	void imageChanged();

protected:
	virtual void paintEvent(QPaintEvent* event);

private:
    QColor m_bgColor;

    QSharedPointer<QImage> m_img;

    bool m_bLastImgPainted;
};

#endif /* SRC_GUI_QDEFAULTIMAGECANVAS_H_ */
