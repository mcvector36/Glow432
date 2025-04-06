#ifndef GLOW432_H
#define GLOW432_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class Glow432;
}
QT_END_NAMESPACE

class Glow432 : public QWidget
{
    Q_OBJECT

public:
    Glow432(QWidget *parent = nullptr);
    ~Glow432();

private:
    Ui::Glow432 *ui;

    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
};
#endif // GLOW432_H
