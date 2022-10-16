#include "../include/Space.h"

Space::~Space() {
    for (Object* object : objects)
        delete object;
}

Space& Space::operator<<(Object* object) {
    objects.push_back(object);
    return *this;
}

void Space::Start() {
    sf::VideoMode video_mode;
    for (auto vm : sf::VideoMode::getFullscreenModes()) {
        if (vm.isValid()) {
            video_mode = vm;
            break;
        }
    }
    sf::RenderWindow window(video_mode,
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

void Space::Stop() {
    running = false;
}

void Space::Clear() {
    for (Object* object : objects)
        delete object;
    objects.clear();
}

void Space::SaveParams() {
    for (Object* object : objects)
        object->SaveParams();
}

void Space::OnFrame() {
    for (Object* object : objects) {
        object->Timer();
        object->OnFrame();
    }
}

void Space::OnDraw(sf::RenderWindow& window) {
    for (Object* object : objects)
        object->OnDraw(window);
}

void Space::OnEvent(sf::Event& event) {
    for (Object* object : objects)
        object->OnEvent(event);
}