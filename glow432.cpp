#include "glow432.h"
#include "ui_glow432.h"
#include "floatingbutton.h"
#include <QIcon>  // Asigură-te că ai importat QIcon

Glow432::Glow432(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Glow432)
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

Glow432::~Glow432()
{
    delete ui;
}
