#ifndef GENETICALGORITHM_GRAPHICS_SPACE_H_
#define GENETICALGORITHM_GRAPHICS_SPACE_H_
#include "Object.h"

#include <vector>

class Space {
    std::vector<Object*> objects;
    bool running = true;
    const unsigned int window_height = sf::VideoMode::getDesktopMode().height;
    const unsigned int window_width = sf::VideoMode::getDesktopMode().width;
public:
    Space() = default;
    ~Space() {
        for (Object* object : objects)
            delete object;
    }

    Space& operator<<(Object* object) {
        objects.push_back(object);
        return *this;
    }
    void Start() {
        sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                                "", sf::Style::Fullscreen);
        while (window.isOpen() && running) {
            sf::Event event{};
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            window.pollEvent(event);
            window.clear();

            OnEvent(event);
            OnFrame();
            OnDraw(window);
            window.display();
        }
    }
    void Stop() {
        running = false;
    }
    void Clear() {
        for (Object* object : objects)
            delete object;
        objects.clear();
    }
    void SaveParams() {
        for (Object* object : objects)
            object->SaveParams();
    }
private:

    void OnFrame() {
        for (Object* object : objects) {
            object->Timer();
            object->OnFrame();
        }
    }
    void OnDraw(sf::RenderWindow& window) {
        for (Object* object : objects)
            object->OnDraw(window);
    }
    void OnEvent(sf::Event& event) {
        for (Object* object : objects)
            object->OnEvent(event);
    }
};

#endif //GENETICALGORITHM_GRAPHICS_SPACE_H_