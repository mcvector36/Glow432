#include "floatingbutton.h"
#include "sound432.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sound432 w;

    // Ascunde fereastra principală
    w.hide();

    return a.exec();
}
