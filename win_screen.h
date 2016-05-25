#ifndef WIN_SCREEN_H
#define WIN_SCREEN_H

#include <QWidget>

namespace Ui {
class win_screen;
}

/** Class: win_screen
 *
 * Brief: The sole purpose of the win screen class is to display a screen with both
 * the player's score and a congratulatory message after each played game.
 *
 */
class win_screen : public QWidget
{
    Q_OBJECT

public:
    explicit win_screen(QWidget *parent = 0);
    ~win_screen();

private:
    Ui::win_screen *ui;
};

#endif // WIN_SCREEN_H
