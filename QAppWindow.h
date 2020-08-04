#ifndef QAPPWINDOW_H
#define QAPPWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTimer>

class QDefaultImageCanvas;
class QPushButton;

class QAppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QAppWindow(QWidget *parent = 0);
    ~QAppWindow();

    void init(const QString& szDir, int iInvervalMs = 30);

private slots:
    void onRunTest();

private:
    QDefaultImageCanvas* m_pImageCanvas;

	QTimer m_timer;

	int m_iCurrentStep;
	QStringList m_listFiles;

};

#endif // QAPPWINDOW_H
