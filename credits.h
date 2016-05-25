#ifndef CREDITS_H
#define CREDITS_H

#include <QWidget>

namespace Ui {
class credits;
}

/** Class: credits
 *
 * Brief: The purpose of this class was mostly for the ui form, which displayed
 * the game's credits as well as a button that returns the user to the main menu.
 *
 */
class credits : public QWidget
{
    Q_OBJECT

public:
    explicit credits(QWidget *parent = 0);
    ~credits();

public slots:
    void back_to_main_menu();

private:
    Ui::credits *ui;
};

#endif // CREDITS_H
