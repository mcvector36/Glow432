#include "floatingbutton.h"
#include <QScreen>
#include <QRegion>
#include <QPainter>
#include <QMouseEvent>
#include <QGuiApplication>

// Constructor
FloatingButton::FloatingButton(QWidget *parent)
    : QWidget(parent),
    m_isOn(false),
    m_dragging(false)
{
    setFixedSize(123, 123);
    m_buttonImage = QPixmap(":/glow432-off.png");

    setMask(QRegion(0, 0, 123, 123, QRegion::Ellipse));
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip);
    setAttribute(Qt::WA_OpaquePaintEvent, false);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setMouseTracking(true); // Nu e strict necesar, dar ajută la interactivitate

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

FloatingButton::~FloatingButton() {}

void FloatingButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void FloatingButton::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void FloatingButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();

        // Acționează ca buton normal când este doar click, nu drag
        if (!m_isOn) {
            m_buttonImage = QPixmap(":/glow432-on.png");
        } else {
            m_buttonImage = QPixmap(":/glow432-off.png");
        }
        m_isOn = !m_isOn;
        update();
    }
}

void FloatingButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (!m_buttonImage.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), m_buttonImage);
    }
}
