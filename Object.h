#ifndef GENETICALGORITHM_GRAPHICS_OBJECT_H_
#define GENETICALGORITHM_GRAPHICS_OBJECT_H_
#include "SFML/Graphics.hpp"

#include <ctime>

class Object {
public:
    static const unsigned int window_width;
    static const unsigned int window_height;
public:
    virtual void OnFrame() {
    }
    virtual void OnDraw(sf::RenderWindow& window) {
    }
    virtual void OnEvent(sf::Event& event) {
    }

    long time = clock();
    long delta_time = 0;
    void Timer() {
        delta_time = clock() - time;
        time = clock();
    }

    virtual void SaveParams() {
    }
};

#endif //GENETICALGORITHM_GRAPHICS_OBJECT_H_