#pragma once
#include<QTabWidget>
class Clue;

class PoliceAsk :public QTabWidget
{
	Q_OBJECT
public:
	Clue* corresClue;
	PoliceAsk(QWidget* parent = nullptr, Clue* clue = nullptr);
	void update(Clue* clue);
};