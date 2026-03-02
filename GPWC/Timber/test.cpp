#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

int main() {

    Vector2f res;
    res.x = VideoMode::getDesktopMode().width;
    res.y = VideoMode::getDesktopMode().height;

    VideoMode vm(res.x, res.y);
    RenderWindow rm(vm, "Timber", Style::Fullscreen);

    // ================= BACKGROUNDS =================
    std::vector<Texture> backgrounds(3);

    backgrounds[0].loadFromFile("Sprites/Graphics/background.png");
    backgrounds[1].loadFromFile("Sprites/Graphics/bg3.jpg");
    backgrounds[2].loadFromFile("Sprites/Graphics/bg4.jpg");

    Sprite bgSprite;
    bgSprite.setTexture(backgrounds[0]);

    int bgIndex = 0;
    Clock bgClock;

    // ================= TREE =================
    Texture treeTexture;
    treeTexture.loadFromFile("Sprites/Graphics/tree.png");

    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);

    // Tree grows from ground
    treeSprite.setPosition(
        res.x / 2 - treeTexture.getSize().x / 2,
        res.y - treeTexture.getSize().y
    );

    // ================= PLAYER =================
    Texture playerTexture;
    playerTexture.loadFromFile("Sprites/Graphics/player.png");

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(1000, res.y - 330);

    // ================= GAME LOOP =================
    while (rm.isOpen()) {

        Event event;
        while (rm.pollEvent(event)) {
            if (event.type == Event::Closed)
                rm.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            rm.close();

        // ===== Change Background Every 5 Seconds =====
        if (bgClock.getElapsedTime().asSeconds() >= 2.0f) {

            bgIndex = (bgIndex + 1) % backgrounds.size();
            bgSprite.setTexture(backgrounds[bgIndex]);

            bgClock.restart();
        }

        rm.clear();

        rm.draw(bgSprite);
        rm.draw(treeSprite);
        rm.draw(playerSprite);

        rm.display();
    }

    return 0;
}