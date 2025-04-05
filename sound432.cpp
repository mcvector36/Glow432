#include "sound432.h"
#include "ui_sound432.h"
#include "floatingbutton.h"

Sound432::Sound432(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sound432)
{
    ui->setupUi(this);

    // Ascunde fereastra principală
    this->hide();

    // Creează și afișează butonul plutitor
    FloatingButton *floatingButton = new FloatingButton(this);
    floatingButton->show();
}

Sound432::~Sound432()
{
    delete ui;
}
