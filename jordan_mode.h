#ifndef JORDAN_MODE_H
#define JORDAN_MODE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPoint>
#include <QSize>
#include <QTimer>
#include <QPixmap>

namespace Ui {
class jordan_mode;
}

/** Class: jordan_mode
 *
 * Brief: Builds off the QWidget class. Purpose of this class is to display the jordan mode of the game.
 * In jordan mode, the basket and ball move at the same pace as medium mode. Player's receive 90 seconds
 * to score as many points as possible. Like medium mode, a defender that blocks shots is included in the
 * scene.
 *
 */
class jordan_mode : public QWidget
{
    Q_OBJECT

public:
    // easy_mode constructor
    explicit jordan_mode(QWidget *parent = 0);

    // easy_mode destructor
    ~jordan_mode();

    // easy_mode paint event
    void paintEvent(QPaintEvent* e);

    // easy_mode keyPressEvent (inherited from widget)
    void keyPressEvent(QKeyEvent* event);

    // easy_mode showEvent function
    void showEvent(QShowEvent* event);

    // is_ball_in_hoop function
    bool is_ball_in_hoop();

    // displays our points onto the screen
    void display_points();

public slots:
    // animates the hoop left and right (i.e. changes the position, then calls repaint())
    void animate_hoop();

    // ball animation function
    void animate_ball();

    // animates the defender
    void animate_defender();

    // display time remaining
    void display_time_remaining();

private:
    Ui::jordan_mode *ui;

    // general variables
    size_t screen_width;
    size_t screen_height;
    const size_t x_change_per_press = 100;
    QPixmap* background_image;
    size_t time_remaining = 90;
    size_t points = 0;

    // timers
    QTimer* hoop_and_ball_and_defender_timer;
    QTimer* shot_clock;
    QTimer* shot_clock_per_second;

    // baller variables
    QPoint* baller_position;
    QSize* baller_size; //we will grab necessary data in the constructor
    QPixmap* baller_image;

    // defender variables
    QPoint* defender_position;
    QSize* defender_size;
    QPixmap* defender_image;
    int defender_change_per_timeout = 40;

    // hoop variables
    QPoint* hoop_position;
    QSize* hoop_size;
    QPixmap* hoop_image;
    int hoop_change_per_timeout = 20; // want to be able to change this everytime we hit a side wall...


    // ball variabes
    QPoint* ball_position;
    QSize* ball_size;
    QPixmap* ball_image;
    bool ball_in_motion = false;
    size_t ball_default_height;
    const int ball_change_per_timeout = 40;
};

#endif // JORDAN_MODE_H
