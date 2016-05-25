#include "win_screen.h"
#include "ui_win_screen.h"
#include <QString>
#include <string>
#include <sstream>

/** win_screen constructor
 *
 * Brief: sets up the ui and the message onscreen
 *
 * @param parent: If a QWidget pointer is included as parameter, then that pointer acts as a parent
 * to the win_screen object.
 */
win_screen::win_screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win_screen)
{
    /*
    std::string points_in_string;
    std::stringstream converter;

    converter << points_scored;
    points_in_string = converter.str();
*/
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), parent, SLOT(game_over()));

    //ui->label_2->setText(QString::fromStdString("You scored " + points_in_string + "!"));
}

win_screen::~win_screen()
{
    delete ui;
}
