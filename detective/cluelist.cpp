#include "cluelist.h"
#include "clueitem.h"
#include "clue.h"
#include "nlohmann/json.hpp"
#include "mainareas.h"
#include <QRect>
#include <string>
#include <fstream>
#include <vector>
#include "detective.h"
using json = nlohmann::json;

std::vector<Clue*> allClues;
std::vector<ClueItem*> allClueItems;

void pressClueItem(int id)
{
	allClueItems[id]->state = ClueItem::CS_READING;
	allClueItems[id]->setStyleSheet(styleReadingClue);
	for (int i = 0; i < allClueItems.size(); i++)
	{
		if (i == id)continue;
		if (allClueItems[i]->state==ClueItem::CS_READING)
		{
			allClueItems[i]->state = ClueItem::CS_READ;
			allClueItems[i]->setStyleSheet(styleReadClue);
		}
	}
	InvestPressClueItem(id);
}


json initClue(std::string file)
{
	std::ifstream fin(file);
	json j = json::parse(fin);
	fin.close();
	return j;
}

ClueList::ClueList(QWidget* parent) :QScrollArea(parent)
{
	ptr_allClues = &allClues;
	ptr_allClueItems = &allClueItems;

	json clues = initClue("sources/datas/clues/CC200729.json");
	for (int i = 0; i < clues.size(); i++)
	{
		Clue *clue = new Clue(clues[i]["clue_index"].template get<int>(), clues[i]);
		allClues.push_back(clue);
		ClueItem *clueItem = new ClueItem(this,QRect(10+(i%2)*160, 20+(i/2)*75, 130, 60), clue);
		allClueItems.push_back(clueItem);
		connect(clueItem, &ClueItem::clicked, this, [=]() {pressClueItem(i); });
	}

}

void ClueList::clueFound(int id)
{
	allClueItems[id]->state = ClueItem::CS_NEW;
	allClueItems[id]->setStyleSheet(styleNewClue);
	allClueItems[id]->setEnabled(true);
	allClueItems[id]->setText(allClues[id]->getClueName());
	if (allClues[id]->clueType==Clue::CLUE_PERSON)
		emit clueFoundSig(id);
}