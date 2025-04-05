#ifndef SOUND432_H
#define SOUND432_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Sound432;
}
QT_END_NAMESPACE

class Sound432 : public QWidget
{
    Q_OBJECT

public:
    Sound432(QWidget *parent = nullptr);
    ~Sound432();

private:
    Ui::Sound432 *ui;
};
#endif // SOUND432_H
