#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_detective.h"

class detective : public QMainWindow
{
    Q_OBJECT

public:
    detective(QWidget *parent = nullptr);
    ~detective();

private:
    Ui::detectiveClass ui;
};

void InvestPressClueItem(int id);