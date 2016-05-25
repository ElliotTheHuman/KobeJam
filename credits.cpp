#include "credits.h"
#include "ui_credits.h"

/** credits constructor
 *
 * Brief: constructs a credits object/pops it up on the screen
 *
 */
credits::credits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::credits)
{
    ui->setupUi(this);

    // this will connect our return to main menu button with game_over function
    connect(ui->pushButton, SIGNAL(clicked()), parent, SLOT(game_over()));
}

/** credits destructor
 *
 * Brief: deletes the ui for the credits object
 *
 */
credits::~credits()
{
    delete ui;
}


/** back to main menu
 *
 * Brief: gets us back to the main menu
 *
 * @param void
 * @return void
 */
void credits::back_to_main_menu()
{
    // do I do anything here?
}
