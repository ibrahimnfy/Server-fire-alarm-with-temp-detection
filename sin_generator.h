
#pragma once
#include <QtMath>   // qSin
#include <QElapsedTimer>

inline qint64 sinValue(const QElapsedTimer& timer,
                       double freq=0.11, double amp=100.0, double phase=3.0)
{
    const double t = timer.elapsed() / 1000.0;           // saniye
    const double angle = 2 * M_PI * freq * t + phase;    // rad
    return static_cast<qint64>(amp * qSin(angle));
}
