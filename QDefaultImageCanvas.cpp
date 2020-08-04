/*
 * QDefaultImageCanvas.cpp
 *
 *  Created on: 30 avr. 2018
 *      Author: alavier
 */

#include <QApplication>
#include <QPainter>

#include "QDefaultImageCanvas.h"

QDefaultImageCanvas::QDefaultImageCanvas(QWidget* parent, Qt::GlobalColor bgColor)
	: QFrame(parent), m_bgColor(bgColor)
{
    setFixedSize(1280, 544);
	m_bLastImgPainted = true;

	connect(this, SIGNAL(imageChanged()), this, SLOT(update()));
}

QDefaultImageCanvas::~QDefaultImageCanvas()
{

}

void QDefaultImageCanvas::updateImage(const QSharedPointer<QImage>& pImage)
{
	m_img = pImage;

	if(m_bLastImgPainted){
		m_bLastImgPainted = false;
		emit imageChanged();
	}
}

void QDefaultImageCanvas::paintEvent(QPaintEvent* event)
{
	QSharedPointer<QImage> pImage;
	pImage = m_img;

	if(!pImage.isNull()){

		// Compute the padding of the image inside the view
		QRect imageRect(0, 0, pImage->width(), pImage->height());
		QRect targetRect = imageRect;

		QPainter p(this);
		p.drawImage(targetRect, *pImage, imageRect);

		m_bLastImgPainted = true;
	}else{
		QPainter p(this);
		p.fillRect(rect(), m_bgColor);
		m_bLastImgPainted = true;
	}
}
