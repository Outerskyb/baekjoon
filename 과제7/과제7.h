#ifndef ___7_H
#define ___7_H

#include <QtWidgets/QMainWindow>
#include "ui_과제7.h"
#define toKor(str) QString::fromLocal8Bit(str)

class 과제7 : public QMainWindow
{
	Q_OBJECT

public:
	과제7(QWidget *parent = 0);
	~과제7();

private:
	Ui::과제7Class ui;
};

#endif // ___7_H
