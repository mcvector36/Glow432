#ifndef FLOATINGBUTTON_H
#define FLOATINGBUTTON_H

#include <QWidget>
#include <QPixmap>

class FloatingButton : public QWidget
{
    Q_OBJECT

public:
    explicit FloatingButton(QWidget *parent = nullptr);
    ~FloatingButton();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_buttonImage;
    bool m_isOn;  // Adăugăm variabila care va ține evidența stării butonului
};

#endif // FLOATINGBUTTON_H
