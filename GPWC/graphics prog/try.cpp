#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>   // for time()

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Random Spawner");
    srand(static_cast<unsigned>(time(NULL))); // Seed the randomizer

    // A list to hold all our spawned circles
    std::vector<sf::CircleShape> shapes;

    sf::Clock spawnClock; // Tracks time for spawning
    float spawnInterval = 1.0f; // 1 second

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // 1. Check if 1 second has passed
        if (spawnClock.getElapsedTime().asSeconds() >= spawnInterval) {
            // Create a new shape
            sf::CircleShape newShape(rand() % 50 + 20); // Random radius 20-70
            newShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            newShape.setPosition(rand() % 1800, rand() % 1000); // Random screen pos
            
            shapes.push_back(newShape); // Add to our list
            spawnClock.restart();       // Reset timer for next second
        }

        // 2. Rendering
        window.clear();
        for (const auto& s : shapes) {
            window.draw(s); // Draw every shape in our list
        }
        window.display();
    }
    return 0;
}
