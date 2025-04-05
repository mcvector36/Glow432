#include "sound432.h"
#include "ui_sound432.h"
#include "floatingbutton.h"  // Adaugă header-ul pentru FloatingButton

Sound432::Sound432(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sound432)
{
    ui->setupUi(this);

    // Ascunde fereastra principală
    this->hide();

    // Creează și afișează doar un singur buton plutitor
    FloatingButton *floatingButton = new FloatingButton(this);
    floatingButton->show();
}

Sound432::~Sound432()
{
    delete ui;
}
