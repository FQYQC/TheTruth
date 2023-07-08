#include "mainareas.h"
#include "cluelist.h"
#include "clue.h"
#include "clueitem.h"
#include "policeask.h"
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <vector>

QLineEdit* clueSearch;
ClueList* clueList;
QLabel* searchState;

ClueArea::ClueArea(QWidget* parent) : QFrame(parent)
{
	// clue list
	clueSearch = new QLineEdit(this);
	clueSearch->setGeometry(35, 35, 280, 35);
	clueSearch->setPlaceholderText("在此输入检索线索");
	clueSearch->setFont(QFont("微软雅黑",16,-1));
	clueSearch->setMaxLength(6);
	//clueSearch->settextco

	searchState = new QLabel(this);
	searchState->setGeometry(35, 70, 280, 40);
	//searchState->setText(QString("调试中。。"));
	searchState-> setFont(QFont("微软雅黑", 14));
	searchState->setAlignment(Qt::AlignCenter);
	searchState->setStyleSheet("color:#e09c2f");
	
	clueList = new ClueList(this);
	clueList->setGeometry(20, 110, 310, 640);
	clueList->setStyleSheet("QScrollArea{"
		"background-color:rgba(0,0,0,0);"
		"}");
	
	ptr_clueList = clueList;
	connect(clueSearch, &QLineEdit::returnPressed, this, &ClueArea::searchNewClue);
}

void ClueArea::searchNewClue()
{
	//qDebug() << "searchNewClue...";
	QString userText = clueSearch->text();
	for (int i = 0; i < clueList->ptr_allClues->size(); ++i)
	{
		if (clueList->ptr_allClues->at(i)->getClueName() == userText)
		{
			if (clueList->ptr_allClueItems->at(i)->state == ClueItem::CS_HIDDEN) {
				clueList->clueFound(i);
				searchState->setText(QString("已找到线索 ") + userText);
				return;
			}
			else
			{
				searchState->setText(QString("线索 ") + userText+QString(" 已存在"));
				return;
			}
		}
	}
	searchState->setText(QString("未找到线索 " + userText));
}


BasicInvestArea::BasicInvestArea(QWidget* parent) :QFrame(parent)
{
	label = new QLabel(this);
	label->setGeometry(45, 5, 200, 40);
	label->setText("警方调查");
	label->setStyleSheet("color:#639dbc");
	label->setFont(QFont("微软雅黑", 12));
	BIAcontext = new QTextBrowser(this);
	BIAcontext->setGeometry(20, 50, 760, 230);
	BIAcontext->setFont(QFont("微软雅黑", 10));
	BIAcontext->setStyleSheet("QTextBrowser{"
		"color:#bbdce4;"
		"background-color:#2c6c80;"
		"border-radius:15px;"
		"border-width:0px;"
		"padding:8px;"
		"}");
	//BIAcontext->setText("");
}

void BasicInvestArea::show(Clue* clue)
{
	BIAcontext->setText(clue->getClueText());
}

AskInvestArea::AskInvestArea(QWidget* parent) :QStackedWidget(parent)
{
	std::vector<Clue*>* clues = clueList->ptr_allClues;
	for (int i = 0; i < clues->size(); ++i)
	{
		QWidget* tmp;
		if (clues->at(i)->numOfAsks() == 0)
			 tmp = new QWidget(this);
		else tmp = new PoliceAsk(this, clues->at(i));
		addWidget(tmp);
		connect(clueList->ptr_allClueItems->at(i), &ClueItem::clicked, this, [=]() {setCurrentIndex(i); });
	}	
	connect(clueList, &ClueList::clueFoundSig, this, &AskInvestArea::clueFound);
}

void AskInvestArea::clueFound(int id)
{
	std::vector<Clue*>* clues = clueList->ptr_allClues;
	for (int i = 0; i < clues->size(); ++i)
	{
		if (clues->at(i)->numOfAsks() > 0)
		{
			((PoliceAsk*)widget(i))->update(clues->at(id));
		}
	}

}

InfoArea::InfoArea(QWidget* parent) :QFrame(parent)
{
	
}

InvestArea::InvestArea(QWidget* parent) :QFrame(parent)
{
	basicInvestArea = new BasicInvestArea(this);
	basicInvestArea->setGeometry(20, 20, 800, 300);
	basicInvestArea->setStyleSheet("QFrame{"
		"background-color:#043049;"
		"border-radius:15px;"
		"border-width:0px;"
		"}");

	askInvestArea = new AskInvestArea(this);
	askInvestArea->setGeometry(20, 340, 800, 380);
	askInvestArea->setStyleSheet("QStackedWidget{"
		"background-color:#043049;"
		"border-radius:15px;"
		"border-width:0px;"
		"}");
	
	infoArea = new InfoArea(this);
	infoArea->setGeometry(840, 20, 280, 700);
	infoArea->setStyleSheet("QFrame{"
		"background-color:#043049;"
		"border-radius:15px;"
		"border-width:0px;"
		"}");
	
}

void InvestArea::show(Clue* clue)
{
	basicInvestArea->show(clue);
}
