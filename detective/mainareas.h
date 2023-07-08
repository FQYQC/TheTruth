#pragma once
#pragma execution_character_set("utf-8")

#include<QWidget>
#include<QFrame>
#include<QPainter>
#include<QPainterPath>
#include<QLabel>
#include<QTextBrowser>
#include<QTabWidget>
#include<QStackedWidget>
#include<ui_detective.h>

class Clue;
class ClueList;

class ClueArea : public QFrame
{
	Q_OBJECT
public:
	QLineEdit* ptr_clueSearch;
	ClueList* ptr_clueList;
	QLabel* ptr_searchState;
	ClueArea(QWidget* parent);
	
	//~CaseArea();

public slots:
	void searchNewClue();
};


class BasicInvestArea :public QFrame
{
	Q_OBJECT
public:
	QLabel* label;
	QTextBrowser* BIAcontext;

	BasicInvestArea(QWidget* parent);
	void show(Clue* clue);
};

class AskInvestArea : public QStackedWidget
{
	Q_OBJECT
public:
	QLabel* label;
	QTextBrowser* context;
	AskInvestArea(QWidget* parent);
	void clueFound(int i);
	
};

class InfoArea :public QFrame
{
	Q_OBJECT
public:
	QLabel* label[10];
	InfoArea(QWidget* parent);
};


class InvestArea : public QFrame
{
	Q_OBJECT
public:
	ClueList* clueList;
	QLabel* searchState;
	BasicInvestArea* basicInvestArea;
	AskInvestArea* askInvestArea;
	InfoArea* infoArea;
	InvestArea(QWidget* parent);
	void show(Clue* clue);
public slots:
	

};
