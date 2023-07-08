#include "policeask.h"
#include "clue.h"
#include<QFont>
#include <QTextBrowser>

PoliceAsk::PoliceAsk(QWidget* parent, Clue* clue) : QTabWidget(parent)
{
	corresClue = clue;
	setGeometry(10, 10, 750, 360);
	setDocumentMode(true);
	for (int i = 0; i < clue->numOfAsks(); ++i)
	{
		QTextBrowser* ask = new QTextBrowser();
		ask->setText(clue->getAskText(i));
		ask->setStyleSheet(
			"QTextBrowser{"
			"color:#b1d2da;"
			"background-color:#043049;"
			"border-radius:15px;"
			"border-width:0px;"
			"padding:30px;"
			"}"
		);
		ask->setFont(QFont("微软雅黑", 12));
		addTab(ask , clue->getAskName(i));
		setTabVisible(i, false);
	}
	setStyleSheet(
		"QTabWidget{"
		"background-color:#2a545e;"
		"border-radius:15px;"
		"border-width:20px;"
		"}"
		"QTabBar::tab		"
		"{"
		"	color:#b1d2da;"
		"	background:transparent;"
		"	"
		"	font-family:\"微软雅黑\";"
		"	font-size:14px;"
		"	"
		"	padding-left:-9px;"
		"	padding-right:-9px;"
		"	width:105px;"
		"	height:30px;"
		"	margin-left:0px;"
		"	margin-right:40px;"
		"}"
		" "
		"QTabBar::tab:selected"
		"{"
		"	color:#618BE5;"
		"	background:transparent;"
		"	"
		"	font-family:\"微软雅黑\";"
		"	font-size:14px;"
		"	"
		"	border-bottom:2px solid #618BE5;"
		"}"
		" "
		"QTabWidget::tab-bar {  	"
		"    alignment: left;  "
		"	top:10px;"
		"	left:30px;"
		"	"
		"} "
		" "
		" "
		"#detailWgt, #appealReasonWgt	"
		"{"
		"	border:none;"
		"}"
	);
}

void PoliceAsk::update(Clue* clue)
{
	for (int i = 0; i < corresClue->numOfAsks(); ++i)
	{
		if(corresClue->getAskName(i)==clue->getClueName())
		setTabVisible(i, true);
	}
}