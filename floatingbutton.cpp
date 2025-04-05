#include "floatingbutton.h"
#include <QScreen>
#include <QRegion>
#include <QPainter>
#include <QMouseEvent>  // Pentru a captura evenimentul de click

FloatingButton::FloatingButton(QWidget *parent)
    : QWidget(parent),
    m_isOn(false)  // Inițial butonul va fi "off"
{
    // Setează dimensiunile butonului
    setFixedSize(123, 123);  // Dimensiunea butonului - ajustabilă

    // Încarcă imaginea inițială (butonul va fi "off" la început)
    m_buttonImage = QPixmap(":/sound432-off.png");

    // Setează forma widget-ului la cerc
    setMask(QRegion(0, 0, 123, 123, QRegion::Ellipse));

    // Setează fereastra să fie fără margini și fără titlu
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip); // Fereastra fără margini și titlu

    // Setează fundalul transparent
    setAttribute(Qt::WA_OpaquePaintEvent, false);  // Permite transparența
    setAttribute(Qt::WA_NoSystemBackground, true); // Evită să se coloreze fundalul

    // Plasează butonul în centrul ecranului
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

FloatingButton::~FloatingButton() {}

void FloatingButton::mousePressEvent(QMouseEvent *event)
{
    // Verifică dacă a fost apăsat butonul
    if (event->button() == Qt::LeftButton) {
        // Schimbă imaginea
        m_isOn = !m_isOn;  // Inversează starea (dacă e "on", devine "off" și invers)

        if (m_isOn) {
            m_buttonImage = QPixmap(":/sound432-on.png");
        } else {
            m_buttonImage = QPixmap(":/sound432-off.png");
        }

        // Reactualizează imaginea pe widget
        update();
    }
}

void FloatingButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Desenează imaginea PNG pe widget
    if (!m_buttonImage.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), m_buttonImage);  // Ajustează imaginea să se potrivească
    }
}
