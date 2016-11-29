#include "mesopointerupdater.h"
#include "Function.h"
#include "Pattern.h"

Function::PFSEARCH pf;
LPVOID lpvBase;
DWORD dwSize;

MesoPointerUpdater::MesoPointerUpdater(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Tool | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
	setWindowTitle(windowTitle() + " - " + QString::number(GetCurrentProcessId()));

	ui.Tree_Widget->addAction(ui.actionCopy);
	ui.Tree_Widget->setColumnWidth(0, 140);

	pFunction = new Function();
}

MesoPointerUpdater::~MesoPointerUpdater()
{
}

void MesoPointerUpdater::ActionTriggered()
{
	QObject* pSender = sender();

	if (pSender == ui.actionAbout)
	{
		QMessageBox::information(this, "About", "Created by meso615134.\n\nmesopl0x92864.blogspot.com");
	}
	else if (pSender == ui.actionSave)
	{
		ui.Tree_Widget->topLevelItemCount() ? SaveText() : QMessageBox::critical(this, "Error", "Please Update Pointers !");
	}
	else if (pSender == ui.actionUpdate)
	{
		ui.Tree_Widget->clear();
		UpdatePointer() ? QMessageBox::information(this, "Succeed", "Updating succeed.") : QMessageBox::critical(this, "Failed", "Updating failed !");
	}
	else if (pSender == ui.actionCopy)
	{
		QTreeWidgetItem* pItem = ui.Tree_Widget->currentItem();
		
		if (!pItem == NULL)
		{
			QClipboard* pClipboard = QApplication::clipboard();
			pClipboard->setText(pItem->text(1));
		}
	}
}

void MesoPointerUpdater::AddItem(bool bColor, QString qstrName, char* caPattern, int iNumber, int iInc, int iLength)
{
	if (!pFunction->FindPattern(caPattern, &pf, lpvBase, dwSize) == PF_NONE) return;

	QTreeWidgetItem* pItem = new QTreeWidgetItem;
	QString qstrData = QString().sprintf("%08X", *(DWORD*)((DWORD)pf.lpvResult + iNumber) + iInc);

	bColor ? pItem->setTextColor(0, Qt::red), pItem->setTextColor(1, Qt::red) : NULL;
	iLength ? qstrData = qstrData.right(iLength) : NULL;

	switch (iLength)
	{
	case 1:
		qstrData.prepend("0000000");
		break;
	case 2:
		qstrData.prepend("000000");
		break;
	case 3:
		qstrData.prepend("00000");
		break;
	case 4:
		qstrData.prepend("0000");
		break;
	}

	pItem->setText(0, qstrName);
	pItem->setText(1, qstrData);
	ui.Tree_Widget->addTopLevelItem(pItem);
}

bool MesoPointerUpdater::UpdatePointer()
{
	pFunction->GetModuleSize(GetModuleHandle(NULL), &lpvBase, &dwSize);

	AddItem(true, "Character Base", Patterns::caCharacterBase, 2, 0, 0);
	AddItem(false, "pID", Patterns::caCharacterPID, 2, 0, 0);
	AddItem(false, "X", Patterns::caCharacterX, 2, 0, 0);
	AddItem(false, "Y", Patterns::caCharacterX, 2, 4, 0);
	AddItem(false, "Teleport", Patterns::caTeleport, 2, 0, 0);
	AddItem(false, "Teleport X", Patterns::caTeleportX, 2, 0, 0);
	AddItem(false, "Teleport Y", Patterns::caTeleportX, 2, - 0xC, 0);
	AddItem(false, "Attack Count", Patterns::caCharacterAttacks, 2, 0, 0);
	AddItem(false, "Combo Count", Patterns::caCharacterCombos, 2, 0, 0);
	AddItem(false, "Skill ID", Patterns::caCharacterSkillID, 2, 0, 0);
	AddItem(false, "Breath", Patterns::caCharacterBreath, 2, 0, 0);
	AddItem(false, "Emotion", Patterns::caCharacterBreath, 2, - 0x84, 0);
	AddItem(false, "Item ID", Patterns::caItemID, 2, 0, 0);

	AddItem(true, "Mob Base", Patterns::caMobBase, 2, 0, 0);
	AddItem(false, "Count", Patterns::caMobs, 2, 0, 2);
	AddItem(false, "Mob 1", Patterns::caMob1, 2, 0, 2);
	AddItem(false, "Mob 2", Patterns::caMob2, 2, 0, 2);
	AddItem(false, "Mob 3", Patterns::caMob3, 2, 0, 0);
	AddItem(false, "Mob 4", Patterns::caMob4, 2, 0, 2);
	AddItem(false, "X", Patterns::caMobX, 2, 0, 2);
	AddItem(false, "Y", Patterns::caMobX, 2, 4, 2);
	AddItem(false, "Death", Patterns::caMobDeath, 2, 0, 0);

	AddItem(true, "Mouse Base", Patterns::caMouseBase, 2, 0, 0);
	AddItem(false, "Animation", Patterns::caMouseAnimation, 2, 0, 0);
	AddItem(false, "Location", Patterns::caMouseLocation, 2, 0, 0);
	AddItem(false, "X", Patterns::caMouseX, 2, 0, 0);
	AddItem(false, "Y", Patterns::caMouseX, 2, 4, 0);

	AddItem(true, "Server Base", Patterns::caServerBase, 1, 0, 0);
	AddItem(false, "Tubi", Patterns::caTubi, 2, 0, 0);
	AddItem(false, "World", Patterns::caWorld, 2, 0, 0);
	AddItem(false, "Channel", Patterns::caWorld, 2, 8, 0);

	AddItem(true, "Map Base", Patterns::caMapBase, 2, 0, 0);
	AddItem(false, "Map ID", Patterns::caMapID, 2, 0, 0);

	AddItem(true, "People Base", Patterns::caPeopleBase, 2, 0, 0);
	AddItem(false, "Count", Patterns::caPeople, 2, 0, 2);

	AddItem(true, "Item Base", Patterns::caItemBase, 2, 0, 0);
	AddItem(false, "Count", Patterns::caItems, 3, 0, 2);

	AddItem(true, "Portal Base", Patterns::caPortalBase, 2, 0, 0);
	AddItem(false, "Count", "18", 0, 0, 2);

	return true;
}

void MesoPointerUpdater::SaveText()
{
	QFileDialog* pDlg = new QFileDialog(this);
	QTreeWidget* pTree = ui.Tree_Widget;
	QString qstrTemp;

	pDlg->setAcceptMode(QFileDialog::AcceptSave);
	pDlg->setWindowTitle("Save File...");
	pDlg->setFilter("*.txt");
	pDlg->exec();

	qstrTemp = pDlg->selectedFiles()[0].remove(".txt") + ".txt";
	QFile file(qstrTemp);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	if (file.exists(qstrTemp))
		file.remove(qstrTemp);

	QTextStream Stream(&file);
	qstrTemp.clear();

	for (int i = 0; i <= pTree->topLevelItemCount() - 1; i++)
	{
		if (pTree->topLevelItem(i)->textColor(0).isValid() && i)
			qstrTemp.append("\n##########################################################################\n\n");
		qstrTemp.append(pTree->topLevelItem(i)->text(0) + " = " + pTree->topLevelItem(i)->text(1) + "\n");
	}

	Stream << qstrTemp;
	file.close();
}

void MesoPointerUpdater::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::question(this, "Exit", "Exit ?", QMessageBox::Ok | QMessageBox::Cancel))
	{
	case QMessageBox::Ok:
		TerminateProcess(GetCurrentProcess(), NULL);
		break;
	case QMessageBox::Cancel:
		event->ignore();
		break;
	}
}