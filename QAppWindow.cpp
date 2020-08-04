#include <QDir>

#include "QDefaultImageCanvas.h"

#include "QAppWindow.h"

QAppWindow::QAppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_pImageCanvas = new QDefaultImageCanvas(this);
    setCentralWidget(m_pImageCanvas);

	m_iCurrentStep = 0;
}

QAppWindow::~QAppWindow()
{

}

void QAppWindow::init(const QString& szDir, int iInvervalMs)
{
	QDir dir(szDir);

	QStringList listEntry = dir.entryList();
	QStringList::const_iterator iter;
	for(iter = listEntry.constBegin(); iter != listEntry.constEnd(); ++iter)
	{
		QString szFilePath = dir.filePath(*iter);
		qDebug("Loading: %s", qPrintable(szFilePath));
		m_listFiles.append(szFilePath);
	}

	m_timer.setInterval(iInvervalMs);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onRunTest()));

	m_timer.start();
}

void QAppWindow::onRunTest()
{
    bool bRes = true;

    if(m_iCurrentStep >= m_listFiles.count()){
		m_iCurrentStep = 0;
    }

    QString szFilePath = m_listFiles.at(m_iCurrentStep);

	QSharedPointer<QImage> pImage = QSharedPointer<QImage>(new QImage());
	bRes = pImage->load(szFilePath);
	if(bRes){
		m_pImageCanvas->updateImage(pImage);
	}

	m_iCurrentStep++;
}
