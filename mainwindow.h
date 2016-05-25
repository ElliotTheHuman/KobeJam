#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}


/** Class: Main Window
 *
 * Brief: In short, this acts as our main window/main menu, with buttons that create each of the three different
 * mode types as well as a button to display the credits. Music is also initialized here.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    // starts up easy mode
    void start_easy_mode();

    // starts up medium mode
    void start_medium_mode();

    // starts up jordan mode (WITH SPECIAL GRAPHICS)
    void start_jordan_mode();

    // starts the credits screen
    void start_credits();

    // starts the win screen
    void start_win_screen();

    // Game over function
    void game_over();

public:
    //Main Window Constructor (with optional parent QWidget)
    explicit MainWindow(QWidget *parent = 0);

    //Main Window Destructor
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* normal_music;
    QMediaPlayer* jordan_music;
};

#endif // MAINWINDOW_H
