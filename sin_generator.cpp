#include "sin_generator.h"


sin_generator::sin_generator(QElapsedTimer m_elapsedtimer) {
    double elapsedMs = m_elapsedtimer.elapsed();
    double frequency = 0.11; // Hz → 10 saniyede bir döngü
    double amplitude = 100.0;
    double phase = 3.0;

    double t = elapsedMs / 1000.0; // geçen süre saniye olarak
    double angle = 2 * M_PI * frequency * t + phase;
    double m_value = amplitude * qSin(angle);
}
