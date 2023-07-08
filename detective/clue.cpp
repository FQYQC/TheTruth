#include "clue.h"
#include <fstream>
#include <string>
using json = nlohmann::json;

Clue::Clue(int id, json j)
{
	clueId = id;
	clueData = j;
	std::string type = j["clue_type"].template get<std::string>();
	if (type == "abs")
		clueType = CLUE_ABS;
	else if (type == "naive")
		clueType = CLUE_NAIVE;
	else if (type == "item")
		clueType = CLUE_ITEM;
	else if (type == "person")
		clueType = CLUE_PERSON;
	else if (type=="interact")
		clueType = CLUE_INTERACT;
	else
		clueType = CLUE_UNDEFINED;
}

QString Clue::getClueName()
{
	return QString::fromStdString(clueData["clue_name"].template get<std::string>()); 	
}

QString Clue::getClueText()
{
	return QString::fromStdString(clueData["clue_text"].template get<std::string>());
}

int Clue::numOfAsks()
{
	return clueData["clue_ask"].size();
}

QString Clue::getAskName(int i)
{
	return QString::fromStdString(clueData["clue_ask"][i]["name"].template get<std::string>());
}
QString Clue::getAskText(int i)
{
	return QString::fromStdString(clueData["clue_ask"][i]["text"].template get<std::string>());
}