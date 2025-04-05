#include "sound432.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Setează icoana aplicației
    a.setWindowIcon(QIcon(":/icon.ico"));  // Calea corectă către icoana din resurse


    Sound432 w;
    w.show();
    return a.exec();
}
