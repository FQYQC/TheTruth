#pragma once
#pragma execution_character_set("utf-8")

#include <QListWidget>
#include <QScrollArea>
#include <QVector>
#include <vector>
class Clue;
class ClueItem;

class ClueList : public QScrollArea
{
	Q_OBJECT
public:
	ClueList(QWidget* parent);
	std::vector<Clue*>* ptr_allClues;
	std::vector<ClueItem*>* ptr_allClueItems;
	void clueFound(int id);
signals:
	void clueFoundSig(int id);
};