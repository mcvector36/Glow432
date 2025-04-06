#include "glow432.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icon.ico"));

    Glow432 w;
    // w.setWindowOpacity(0); ← mutat deja în constructor
    // w.show(); ← deja apelat în constructor
    return a.exec();
}
