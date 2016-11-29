#ifndef MESOPOINTERUPDATER_H
#define MESOPOINTERUPDATER_H

#include <QtGui/QMainWindow>
#include "ui_mesopointerupdater.h"
#include <Windows.h>
#include <QMessageBox>
#include <QClipboard>
#include <QFileDialog>
#include <QTextStream>
#include <qevent.h>

class MesoPointerUpdater : public QMainWindow
{
	Q_OBJECT

public:
	MesoPointerUpdater(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MesoPointerUpdater();

private slots:
	void ActionTriggered();

private:
	Ui::MesoPointerUpdaterClass ui;

	void AddItem(bool bColor, QString qstrName, char* caPattern, int iNumber, int iInc, int iLength);
	bool UpdatePointer();
	void SaveText();

protected:
	void closeEvent(QCloseEvent *event);

};

#endif // MESOPOINTERUPDATER_H
