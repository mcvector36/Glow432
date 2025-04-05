#include "floatingbutton.h"
#include <QScreen>  // Înlocuiește QDesktopWidget cu QScreen
#include <QRegion>
#include <QPainter>
#include <QDebug>  // Pentru debug

FloatingButton::FloatingButton(QWidget *parent)
    : QWidget(parent)
{
    // Setează dimensiunile butonului (dimensiune de cerc, să corespundă cu imaginea)
    setFixedSize(123, 123); // Dimensiunea butonului - ajustabilă în funcție de imagine

    // Încarcă imaginea PNG pentru buton (asigură-te că ai calea corectă)
    m_buttonImage = QPixmap(":/sound432-on.png");  // Calea corectă către imagine

    // Verifică dacă imaginea a fost încărcată corect
    if (m_buttonImage.isNull()) {
        qDebug() << "Imaginea nu a fost încărcată corect!";
    }

    // Setează forma widget-ului la cerc
    setMask(QRegion(0, 0, 123, 123, QRegion::Ellipse));  // Folosește dimensiunea cercului corectă

    // Setează fereastra să fie fără margini și fără titlu
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip); // Fereastra fără margini și titlu

    // Setează fundalul transparent
    setAttribute(Qt::WA_OpaquePaintEvent, false);  // Permite transparența
    setAttribute(Qt::WA_NoSystemBackground, true); // Evită să se coloreze fundalul

    // Plasează butonul într-o locație aleatorie pe ecran
    QScreen *screen = QGuiApplication::primaryScreen();  // Obține ecranul principal
    QRect screenGeometry = screen->availableGeometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    int x = rand() % (screenWidth - width());
    int y = rand() % (screenHeight - height());
    move(x, y);
}

FloatingButton::~FloatingButton() {}

void FloatingButton::mousePressEvent(QMouseEvent *event)
{
    // Verifică dacă a fost apăsat butonul
    if (event->button() == Qt::LeftButton)
    {
        // Exemplu: închide aplicația când este apăsat butonul
        qApp->quit();
    }
}

void FloatingButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Desenează imaginea PNG pe widget
    if (!m_buttonImage.isNull()) {
        // Ajustează imaginea să se potrivească cu dimensiunea widget-ului
        painter.drawPixmap(0, 0, width(), height(), m_buttonImage);
    } else {
        qDebug() << "Imaginea nu este încărcată!";
    }
}
