#pragma once
#pragma execution_character_set("utf-8")

#include <cstring>
#include <QString>
#include "nlohmann/json.hpp"

class Clue
{
	using json = nlohmann::json;
public:
	int clueId;
	enum ClueType
	{
		CLUE_NAIVE,
		CLUE_ABS,
		CLUE_ITEM,
		CLUE_PERSON,
		CLUE_INTERACT,
		CLUE_UNDEFINED
	} clueType;

	json clueData;

	Clue(int id, json j);
	QString getClueName();
	QString getClueText();
	int numOfAsks();
	QString getAskName(int i);
	QString getAskText(int i);



};