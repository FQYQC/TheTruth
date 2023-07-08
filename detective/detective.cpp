#include "detective.h"
#include "mainareas.h"
#include "clue.h"
#include "cluelist.h"
#include <QLineEdit>
#include <QRect>
#include <QFont>

ClueArea* clueArea;
InvestArea* investArea;
QLabel* gameName;

void InvestPressClueItem(int id)
{
	Clue* currClue = clueArea->ptr_clueList->ptr_allClues->at(id);
	investArea->show(currClue);
	
}


detective::detective(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	setGeometry(0, 0, 1600, 900);
	setFixedSize(1600, 900);
	setStyleSheet("QMainWindow{"
		"background-color:#2e393b;"
		"}");
	

	clueArea = new ClueArea(this);
	clueArea->setGeometry(40, 110, 350, 770);
	clueArea->setStyleSheet("QFrame{"
		"background-color:#2a4a51;"
		"border-radius:15px;"
	"}");
	
	investArea = new InvestArea(this);
	investArea->setGeometry(420, 140, 1140, 740);
	investArea->setStyleSheet("QFrame"// + objectName() +
		"{"
		"background-color:#1b1f21;"
		"border-style:solid;"
		"border-color:#2c6c80;"
		"border-width:4px;"
		"border-radius:15px;"
		"}");
	
	gameName = new QLabel(QString("THE TRUTH"), this);
	gameName->setGeometry(400, 40, 900, 100);
	gameName->setAlignment(Qt::AlignCenter);
	gameName->setFont(QFont("Bradley Hand ITC",70,800));
	gameName->setStyleSheet("QLabel{"
		"color:#adadad;"
		"}");
	
}

detective::~detective()
{
	delete clueArea;
	delete investArea;
}
