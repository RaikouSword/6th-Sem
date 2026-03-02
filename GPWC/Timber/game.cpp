#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Vector2f res;
    res.x = VideoMode::getDesktopMode().width;
    res.y = VideoMode::getDesktopMode().height;

    VideoMode vm(res.x, res.y);

    RenderWindow rm(vm, "Timber", Style::Fullscreen);

    Texture bgTexture;
    bgTexture.loadFromFile("Sprites/Graphics/background.png");
    Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    bgSprite.setPosition(0, 0);
    // std::vector<Texture> backgrounds(3);
    // backgrounds[0].loadFromFile("Sprites/Graphics/background.png");
    // backgrounds[1].loadFromFile("Sprites/Graphics/bg3.jpg");
    // backgrounds[2].loadFromFile("Sprites/Graphics/bg4.jpg");
    // Sprite bgSprite;
    // bgSprite.setTexture(backgrounds[0]);
    // int bgIndex = 0;
    // Clock bgClock;

    Texture treeTexture;
    treeTexture.loadFromFile("Sprites/Graphics/tree.png");
    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(res.x / 2 - 300 / 2, 0);

    Texture playerTexture;
    playerTexture.loadFromFile("Sprites/Graphics/player.png");
    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(1000, res.y - 330);

    Texture beeTexture;
    beeTexture.loadFromFile("Sprites/Graphics/bee.png");
    Sprite beeSprite1;
    beeSprite1.setTexture(beeTexture);
    beeSprite1.setPosition(1000, res.y / 2 - 100);
    Sprite beeSprite2;
    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition(550, res.y / 2 - 40);
    Sprite beeSprite3;
    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition(1100, res.y / 2 - 40);
    Sprite beeSprite4;
    beeSprite4.setTexture(beeTexture);
    beeSprite4.setPosition(450, res.y / 2 - 100);
    bool beeActive1 = false;
    bool beeActive2 = false;
    bool beeActive3 = false;
    bool beeActive4 = false;
    float beeSpeed1 = 0.0f;
    float beeSpeed2 = 0.0f;
    float beeSpeed3 = 0.0f;
    float beeSpeed4 = 0.0f;

    Texture cloudTexture;
    cloudTexture.loadFromFile("Sprites/Graphics/cloud.png");
    Sprite cloudSprite1;
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setPosition(0, 0);
    Sprite cloudSprite2;
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setPosition(res.x - 300, 150);
    Sprite cloudSprite3;
    cloudSprite3.setTexture(cloudTexture);
    cloudSprite3.setPosition(res.x / 2 + 200, 80);
    bool cloudActive1 = false;
    float cloudSpeed1 = 0.0f;
    bool cloudActive2 = false;
    float cloudSpeed2 = 0.0f;
    bool cloudActive3 = false;
    float cloudSpeed3 = 0.0f;

    Clock clock;
    
    bool paused = true;
    
    Text scoreText,messageText;
    Font font;
    font.loadFromFile("Sprites/Font/KOMIKAP_.ttf");
    // myText.setString("Press Enter to start!");
    // myText.setCharacterSize(75);
    // myText.setFillColor(Color::White);
    // myText.setFont(font);
    int score =0;
    messageText.setFont(font);
    scoreText.setFont(font);
    messageText.setString("Press Enter to start!");
    scoreText.setString("Score = 0");
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);


    while (rm.isOpen())
    {
        Event event;
        while (rm.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                rm.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            rm.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
        }
        // if(Keyboard::isKeyPressed(Keyboard::Enter)){
        //     bgIndex = (bgIndex + 1) % backgrounds.size();
        //     bgSprite.setTexture(backgrounds[bgIndex]);
        // }
        // if (bgClock.getElapsedTime().asSeconds() >= 2.0f) {

        //     bgIndex = (bgIndex + 1) % backgrounds.size();
        //     bgSprite.setTexture(backgrounds[bgIndex]);

        //     bgClock.restart();
        // }
        if (!paused)
        {
            Time dt = clock.restart();
            if (!beeActive1)
            {
                beeSpeed1 = (rand() % 200) + 200;
                float height = (rand() % (int)(res.y - 100)) + 50;
                beeSprite1.setPosition(res.x + 200, height);
                beeActive1 = true;
            }
            else
            {
                beeSprite1.setPosition(
                    beeSprite1.getPosition().x - beeSpeed1 * dt.asSeconds(),
                    beeSprite1.getPosition().y);

                if (beeSprite1.getPosition().x < -100)
                    beeActive1 = false;
            }

            if (!beeActive2)
            {
                beeSpeed2 = (rand() % 200) + 200;
                float height = (rand() % (int)(res.y - 100)) + 50;
                beeSprite2.setPosition(res.x + 200, height);
                beeActive2 = true;
            }
            else
            {
                beeSprite2.move(-beeSpeed2 * dt.asSeconds(), 0);

                if (beeSprite2.getPosition().x < -100)
                    beeActive2 = false;
            }

            if (!beeActive3)
            {
                beeSpeed3 = (rand() % 200) + 200;
                float height = (rand() % (int)(res.y - 100)) + 50;
                beeSprite3.setPosition(res.x + 200, height);
                beeActive3 = true;
            }
            else
            {
                beeSprite3.move(-beeSpeed3 * dt.asSeconds(), 0);

                if (beeSprite3.getPosition().x < -100)
                    beeActive3 = false;
            }

            if (!beeActive4)
            {
                beeSpeed4 = (rand() % 200) + 200;
                float height = (rand() % (int)(res.y - 100)) + 50;
                beeSprite4.setPosition(res.x + 200, height);
                beeActive4 = true;
            }
            else
            {
                beeSprite4.move(-beeSpeed4 * dt.asSeconds(), 0);

                if (beeSprite4.getPosition().x < -100)
                    beeActive4 = false;
            }
            if (!cloudActive1)
            {
                srand((int)time(0) * 10);
                cloudSpeed1 = (rand() % 200);
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                cloudSprite1.setPosition(-200, height);
                cloudActive1 = true;
            }
            else
            {
                cloudSprite1.setPosition(
                    cloudSprite1.getPosition().x + (cloudSpeed1 * dt.asSeconds()), cloudSprite1.getPosition().y);
                if (cloudSprite1.getPosition().x > res.x)
                {
                    cloudActive1 = false;
                }
            }
            if (!cloudActive2)
            {
                srand((int)time(0) * 20);
                cloudSpeed2 = (rand() % 200);
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                cloudSprite2.setPosition(-200, height);
                cloudActive2 = true;
            }
            else
            {
                cloudSprite2.setPosition(
                    cloudSprite2.getPosition().x + (cloudSpeed2 * dt.asSeconds()), cloudSprite2.getPosition().y);
                if (cloudSprite2.getPosition().x > res.x)
                {
                    cloudActive2 = false;
                }
            }
            if (!cloudActive3)
            {
                srand((int)time(0) * 20);
                cloudSpeed3 = (rand() % 200);
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                cloudSprite3.setPosition(-200, height);
                cloudActive3 = true;
            }
            else
            {
                cloudSprite3.setPosition(
                    cloudSprite3.getPosition().x + (cloudSpeed3 * dt.asSeconds()), cloudSprite3.getPosition().y);
                if (cloudSprite3.getPosition().x > res.x)
                {
                    cloudActive3 = false;
                }
            }
        }
        rm.clear();
        rm.draw(bgSprite);
        rm.draw(beeSprite1);
        rm.draw(beeSprite2);
        rm.draw(beeSprite3);
        rm.draw(beeSprite4);
        rm.draw(cloudSprite1);
        rm.draw(cloudSprite2);
        rm.draw(cloudSprite3);
        rm.draw(playerSprite);
        rm.draw(treeSprite);
        rm.display();
    }
}