#include "sound432.h"
#include "ui_sound432.h"
#include "floatingbutton.h"
#include <QIcon>  // Asigură-te că ai importat QIcon

Sound432::Sound432(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sound432)
{
    ui->setupUi(this);

    // Setează icoana aplicației
    QIcon appIcon(":/icon.ico");  // Calea către icoana din fișierul .qrc
    setWindowIcon(appIcon);  // Setează icoana ferestrei aplicației

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
