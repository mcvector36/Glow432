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
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_buttonImage;
    bool m_isOn;

    // Pentru mutare
    bool m_dragging;
    QPoint m_dragPosition;
};

#endif // FLOATINGBUTTON_H
