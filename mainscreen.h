#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "gameview.h"

class MainScreen : public QDialog
{
    Q_OBJECT

    MainScreen(QWidget *parent = 0);
    MainScreen(const MainScreen &);
    MainScreen &operator=(MainScreen &);

    enum : unsigned int {Width = 650, Height = 700};

public:
    ~MainScreen();
     static MainScreen *instance();

private:
        void initScreen();
};

#endif // MAINSCREEN_H
