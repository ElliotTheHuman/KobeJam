#ifndef EASY_MODE_H
#define EASY_MODE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPoint>
#include <QSize>
#include <QTimer>
#include <QPixmap>

namespace Ui {
class easy_mode;
}


/** Class: easy_mode
 *
 * Brief: Builds off the QWidget class. Purpose of this class is to display the easy mode of the game.
 * In easy mode, the basket and ball move at a slow pace. The player has 60 seconds to score as many
 * points as possible into the basket. When time expires, the player will be shipped back to the starting screen.
 *
 */
class easy_mode : public QWidget
{
    Q_OBJECT

public:
    // easy_mode constructor
    explicit easy_mode(QWidget *parent = 0);

    // easy_mode destructor
    ~easy_mode();

    // easy_mode paint event
    void paintEvent(QPaintEvent* e);

    // easy_mode keyPressEvent (inherited from widget)
    void keyPressEvent(QKeyEvent* event);

    // easy_mode showEvent function
    void showEvent(QShowEvent* event);

    // is_ball_in_hoop function
    bool is_ball_in_hoop();

    void display_points();

public slots:
    // animates the hoop left and right (i.e. changes the position, then calls repaint())
    void animate_hoop();

    // ball animation function
    void animate_ball();

    // display time remaining
    void display_time_remaining();

private:
    Ui::easy_mode *ui;

    // general variables
    size_t screen_width;
    size_t screen_height;
    const size_t x_change_per_press = 100;
    QPixmap* background_image;
    size_t time_remaining = 60;
    size_t points = 0;

    // timers
    QTimer* hoop_and_ball_timer;
    QTimer* shot_clock;
    QTimer* shot_clock_per_second;

    // baller variables
    QPoint* baller_position;
    QSize* baller_size; //we will grab necessary data in the constructor
    QPixmap* baller_image;

    // hoop variables
    QPoint* hoop_position;
    QSize* hoop_size;
    QPixmap* hoop_image;
    int hoop_change_per_timeout = 10; // want to be able to change this everytime we hit a side wall...

    // ball variabes
    QPoint* ball_position;
    QSize* ball_size;
    QPixmap* ball_image;
    bool ball_in_motion = false;
    size_t ball_default_height;
    int ball_change_per_timeout = 20;
};

#endif // EASY_MODE_H
