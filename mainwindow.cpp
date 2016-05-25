#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "easy_mode.h"
#include "medium_mode.h"
#include "jordan_mode.h"
#include "credits.h"
#include "win_screen.h"

/** MainWindow constructor
 * @param parent which is an optional QWidget pointer
 * @return void
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up the normal music
    normal_music = new QMediaPlayer();
    normal_music->setMedia(QUrl("qrc:/sounds/bensound-jazzyfrenchy.mp3"));

    jordan_music = new QMediaPlayer();
    jordan_music->setMedia(QUrl("qrc:/sounds/Space Jam Theme Song.mp3"));
}

/** MainWindow destructor
 *  @return void
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete normal_music;
    delete jordan_music;
}

/** start easy mode function
 *
 * Brief: builds an easy mode object and sets the mainwindow as its parent, also starts up music
 *
 * @param void
 * @return void
 */
void MainWindow::start_easy_mode()
{
    // first let's just get a dude on screen
    easy_mode* e = new easy_mode(this); // set parent to be the main window
    this->setCentralWidget(e);

    // set up the music here!
    normal_music->setPosition(0);
    normal_music->play();
}

/** start medium mode function
 *
 * Brief: builds an medium mode object and sets the mainwindow as its parent, also starts up music
 *
 * @param void
 * @return void
 */
void MainWindow::start_medium_mode()
{
    // let's now create a medium mode
    medium_mode* m = new medium_mode(this);
    this->setCentralWidget(m);

    // set up music here!
    normal_music->setPosition(0);
    normal_music->play();
}

/** start jordan mode function
 *
 * Brief: builds an jordan mode object and sets the mainwindow as its parent, also starts up music
 *
 * @param void
 * @return void
 */
void MainWindow::start_jordan_mode()
{
    // let's create a jordan mode
    jordan_mode* j = new jordan_mode(this);
    this->setCentralWidget(j);

    // set up music here!
    jordan_music->setPosition(15000);
    jordan_music->play();
}

/** start credits function
 *
 * Brief: builds a credits object and sets the mainwindow as its parent
 *
 * @param void
 * @return void
 */
void MainWindow::start_credits()
{
    // opens the credits scene
    credits* c = new credits(this);
    this->setCentralWidget(c);
}

/** start win function
 *
 * Brief: Create a win screen and displays the player's points
 *
 * @param points_scored represents the number of points scored by the player
 * @return void
 */
void MainWindow::start_win_screen()
{
    // if the music is playing by the time a game is over
    if(normal_music->state() == QMediaPlayer::PlayingState){
        normal_music->setPosition(0);
        normal_music->pause();
    }
    else if(jordan_music->state() == QMediaPlayer::PlayingState){
        jordan_music->setPosition(15000);
        jordan_music->pause();
    }

    QWidget* wid = this->centralWidget(); // now our main screen becomes the central widget again
    wid->setParent(NULL); // we want the parent of this main window to be nothing!

    win_screen* ws = new win_screen(this); // we then create a win screen
    this->setCentralWidget(ws); // and make the wins screen our central widget
}

/** game over function
 *
 * Brief: destroys the current ui, then resets the main menu/window as the current ui.
 *
 * @param void
 * @return void
 */
void MainWindow::game_over()
{

    QWidget* wid = this->centralWidget(); // now our main screen becomes the central widget again
    wid->setParent(NULL); // we want the parent of this main window to be nothing!

    ui->setupUi(this); // now everything pops up from the desinger... designer... sorry...
}
