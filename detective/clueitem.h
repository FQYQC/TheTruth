#pragma once
#pragma execution_character_set("utf-8")


#include<QListWidgetItem>
#include<QPushButton>
#include<QRect>
#include<QString>

class Clue;

const QString styleNewClue = QString(
	"QPushButton{"
	"background-color:#997336;"
	"border-style:solid;"
	"border-width:2px;"
	"border-color:#233942;"
	"color:#b7d8e2;"
	"padding:6px;"
	"}"
);

const QString styleReadClue = QString(
	"QPushButton{"
	"background-color:#0d5471;"
	"border-style:solid;"
	"border-width:2px;"
	"border-color:#233942;"
	"color:#b7d8e2;"
	"padding:6px;"
	"}"
);

const QString styleReadingClue = QString(
	"QPushButton{"
	"background-color:#0a384b;"
	"border-style:solid;"
	"border-width:2px;"
	"border-color:#233942;"
	"color:#b7d8e2;"
	"padding:6px;"
	"}"
);

const QString styleHiddenClue = QString(
	"QPushButton{"
	"background-color:#233842;"
	"border-style:solid;"
	"border-width:0px;"
	"border-color:#233942;"
	"color:#b7d8e2;"
	"padding:6px;"
	"}"
);



class ClueItem :public QPushButton
{
	Q_OBJECT
public:
	enum ClueState
	{
		CS_HIDDEN,
		CS_NEW,
		CS_READ,
		CS_READING,
		CS_NEWCT
	} state;
	Clue* corresClue;
	QRect position;
	QString text;
	ClueItem(QWidget* parent, QRect position, Clue* _clue);
};