#include "clueitem.h"
#include "clue.h"
#include<QFont>

ClueItem::ClueItem(QWidget* parent, QRect _position, Clue* _clue = NULL) : QPushButton(parent), position(_position), corresClue(_clue)
{
	if (corresClue->clueId == 0)
	{
		state = CS_NEW;
		setStyleSheet(styleNewClue);
		setText(corresClue->getClueName());
	}
	else
	{
		state = CS_HIDDEN;
		setEnabled(false);
		setStyleSheet(styleHiddenClue);
	}
	setGeometry(position);
	setFont(QFont("微软雅黑", 12, QFont::Bold));

}