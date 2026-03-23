#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
using namespace std;
void updateBranches(int);
const int NUM_BRANCHES = 6;
enum class side{LEFT,RIGHT,NONE};
side sidePlayer = side::LEFT;
side branchPositions[NUM_BRANCHES];
Sprite Branches[NUM_BRANCHES];
int main()
{

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);

    RenderWindow window(vm, "Timber!!!");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Sprites/Graphics/background.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Tree
    Texture treeTexture;
    treeTexture.loadFromFile("Sprites/Graphics/tree.png");

    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition((resolution.x / 2.0 - 300 / 2.0), 0);

    // Branches
    Texture branchTexture;
    branchTexture.loadFromFile("Sprites/Graphics/branch.png");


    for(int i = 0; i < NUM_BRANCHES; i++){
        Branches[i].setTexture(branchTexture);
        Branches[i].setOrigin(220,20);
        Branches[i].setPosition(-2000,-2000);
    }
    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);


    // Cloud1
    Texture cloudTexture;
    cloudTexture.loadFromFile("Sprites/Graphics/cloud.png");

    Sprite cloud1Sprite;
    cloud1Sprite.setTexture(cloudTexture);
    cloud1Sprite.setPosition(0, 0);

    float cloud1Speed = 0.0f;
    float cloud1Height = 0.0f;
    bool cloud1Active = false;

    // Cloud2

    Sprite cloud2Sprite;
    cloud2Sprite.setTexture(cloudTexture);
    cloud2Sprite.setPosition(0, 0);

    float cloud2Speed = 0.0f;
    float cloud2Height = 0.0f;
    bool cloud2Active = false;

    // Cloud3

    Sprite cloud3Sprite;
    cloud3Sprite.setTexture(cloudTexture);
    cloud3Sprite.setPosition(0, 0);

    float cloud3Speed = 0.0f;
    float cloud3Height = 0.0f;
    bool cloud3Active = false;

    // Bee1
    Texture beeTexture;
    beeTexture.loadFromFile("Sprites/Graphics/bee.png");

    Sprite bee1Sprite;
    bee1Sprite.setTexture(beeTexture);
    bee1Sprite.setPosition(1700, (resolution.y / 2.0 + 150));

    float bee1Speed = 0.0f;
    float bee1Height = 0.0f;
    bool bee1Active = false;

    // Clock and time
    Clock clock;

    // Timebar

    RectangleShape timeBar;
    float timeBarStartWidth = 400.0f;
    float timeBarHeight = 80.0f;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(resolution.x / 2.0 - timeBarStartWidth / 2.0, resolution.y - 100);
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
    bool paused = true;

    // Message text

    Font font;
    font.loadFromFile("Sprites/Font/KOMIKAP_.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setFillColor(Color::White);
    messageText.setCharacterSize(100);
    messageText.setString("Press Enter key to Start");
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin((textRect.left + textRect.width) / 2.0, (textRect.top + textRect.height) / 2.0);
    messageText.setPosition(resolution.x / 2.0, resolution.y / 2.0);

    // Score

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setFillColor(Color::Red);
    scoreText.setCharacterSize(75);
    scoreText.setString("Score = 0");
    scoreText.setPosition(20, 20);
    int score = 0;

    // Player

    Texture playerTexture;
    playerTexture.loadFromFile("Sprites/Graphics/player.png");

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(380,640);

    // Grave Stone

    Texture ripTexture;
    ripTexture.loadFromFile("Sprites/Graphics/rip.png");

    Sprite ripSprite;
    ripSprite.setTexture(ripTexture);
    ripSprite.setPosition(380,640);

    // Axe

    Texture axeTexture;
    axeTexture.loadFromFile("Sprites/Graphics/axe.png");

    Sprite axeSprite;
    axeSprite.setTexture(axeTexture);
    axeSprite.setPosition(700,830);

    // Line up the Axe with the Tree

    const int AXE_POSITION_LEFT = 700;
    const int AXE_POSITION_RIGHT = 1075;

    // Log

    Texture logTexture;
    logTexture.loadFromFile("Sprites/Graphics/log.png");

    Sprite logSprite;
    logSprite.setTexture(logTexture);
    logSprite.setPosition(380,640);

    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    // Control player input
    bool acceptInput = false;

    // Prepare the sound chopping, out of time, death sound

    // game loop

    while (window.isOpen())
    {
        // Handle user input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            /*if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                paused = false;
                timeRemaining = 6.0f;
                
                // Reset score
                score = 0;

                // Make all branches disappear
                for(int i=0;i<NUM_BRANCHES;i++)
                {
                    branchPositions[i] = side::NONE;
                }

                // Make Gravestone hidden
                ripSprite.setPosition(2000,2000);

                // MOve player into the position
                playerSprite.setPosition(580,720);

                // Make acceptinput true
                acceptInput = true;
            }*/

            
            /*if (event.type == Event::KeyPressed && !paused)
            {
                acceptInput = true;
                axeSprite.setPosition(2000,axeSprite.getPosition().y);
            }*/


        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = !paused;
            timeRemaining = 5.0f;
            // Reset score
            score = 0;

            // Make all branches disappear
            for(int i=0;i<NUM_BRANCHES;i++)
            {
                branchPositions[i] = side::NONE;
            }

            // Make Gravestone hidden
            ripSprite.setPosition(2000,2000);

            // Move player into the position
            playerSprite.setPosition(580,720);

            // Make accept input true
            acceptInput = true;
        }
        Time dt = clock.restart();
        if(acceptInput){
            // Handle Right Cursor Key
            if(Keyboard::isKeyPressed(Keyboard::Right)){
                // update score
                score++;

                // update time remaining
                timeRemaining -= dt.asSeconds();

                // set the playerr side to right
                sidePlayer = side::RIGHT;

                //set the player position
                playerSprite.setPosition(1200,640);

                //set the axe position
                axeSprite.setPosition(AXE_POSITION_RIGHT,axeSprite.getPosition().y);

                // set the log position, log-speed on X to fly on the left,logAcive enabled
                logSprite.setPosition(810,720);
                logSpeedX = 5000;
                logActive = true;

                // update branches

                updateBranches(score);

                // acceptInput to false
                //acceptInput = false;

                // play a chop sound

            } // End Right key

            // Handle Left Cursor Key
            if(Keyboard::isKeyPressed(Keyboard::Left)){
                // update score
                score++;

                // update time remaining
                timeRemaining -= dt.asSeconds();

                // set the playerr side to left
                sidePlayer = side::LEFT;

                //set the player position
                playerSprite.setPosition(580,720);

                //set the axe position
                axeSprite.setPosition(AXE_POSITION_LEFT,axeSprite.getPosition().y);

                // set the log position, log-speed on X to fly on the right,logAcive enabled
                logSprite.setPosition(810,720);
                logSpeedX = -5000;
                logActive = true;

                // update branches

                updateBranches(score);

                // acceptInput to false
                //acceptInput = false;

                // play a chop sound

            } // End Left key
        } // End of if(acceptInput)

        if (!paused)
        {
            // scene updates if game is running
            //Time dt = clock.restart();
            timeRemaining -= dt.asSeconds();

            if (timeRemaining <= 0.0f)
            {
                paused = true;
                messageText.setString("Time Out!!!");
                textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
                messageText.setPosition(resolution.x / 2.0, resolution.y / 2.0);
            }
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

            // Bee1 movement
            if (!bee1Active)
            {
                srand(time(0) * 10);
                bee1Speed = rand() % 200 + 200;
                srand(time(0) * 20);
                bee1Height = rand() % 450 + 450;
                bee1Sprite.setPosition(1700, bee1Height);
                bee1Active = true;
            }
            else
            {
                bee1Sprite.setPosition(bee1Sprite.getPosition().x - bee1Speed * dt.asSeconds(), bee1Sprite.getPosition().y);

                if (bee1Sprite.getPosition().x < -100)
                    bee1Active = false;
            }
            // Cloud1 movement
            if (!cloud1Active)
            {
                srand(time(0) * 10);
                cloud1Speed = rand() % 90;
                srand(time(0) * 20);
                cloud1Height = rand() % 150;
                cloud1Sprite.setPosition(-150, cloud1Height);
                cloud1Active = true;
            }
            else
            {
                cloud1Sprite.setPosition(cloud1Sprite.getPosition().x + cloud1Speed * dt.asSeconds(), cloud1Sprite.getPosition().y);

                if (cloud1Sprite.getPosition().x > 1700)
                    cloud1Active = false;
            }

            // Cloud2 movement
            if (!cloud2Active)
            {
                srand(time(0) * 10);
                cloud2Speed = rand() % 75;
                srand(time(0) * 20);
                cloud2Height = rand() % 300;
                cloud2Sprite.setPosition(-150, cloud2Height);
                cloud2Active = true;
            }
            else
            {
                cloud2Sprite.setPosition(cloud2Sprite.getPosition().x + cloud2Speed * dt.asSeconds(), cloud2Sprite.getPosition().y);

                if (cloud2Sprite.getPosition().x > 1700)
                    cloud2Active = false;
            }

            // Cloud3 movement
            if (!cloud3Active)
            {
                srand(time(0) * 10);
                cloud3Speed = rand() % 60;
                srand(time(0) * 20);
                cloud3Height = rand() % 450;
                cloud3Sprite.setPosition(-150, cloud3Height);
                cloud3Active = true;
            }
            else
            {
                 cloud3Sprite.setPosition(cloud3Sprite.getPosition().x + cloud3Speed * dt.asSeconds(), cloud3Sprite.getPosition().y);

                if (cloud3Sprite.getPosition().x > 1700)
                     cloud3Active = false;
            }
            // Test updation of score with left and right arrow key
            /*if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::Right))
                 score++;*/


            std::stringstream ss;
            ss<<"Score = "<<score;
            scoreText.setString(ss.str());
            
            // Update positions of branches

            for(int i = 0; i < NUM_BRANCHES; i++){
                float branchHeight = i*150;
                if(branchPositions[i]==side::LEFT)
                {
                    Branches[i].setPosition(460,branchHeight);
                    Branches[i].setRotation(180); //flip
                }
                else if(branchPositions[i]==side::RIGHT)
                {
                    Branches[i].setPosition(1170,branchHeight);
                    Branches[i].setRotation(0); //flip
                }
                else
                {
                    Branches[i].setPosition(3000,branchHeight);
                }
            }
        /*
        updateBranches(1);
        updateBranches(2);
        updateBranches(3);
        updateBranches(4);
        updateBranches(5);
        */

        // Handle a flying log

        if(logActive)
        {
            logSprite.setPosition(logSprite.getPosition().x + logSpeedX*dt.asSeconds(),logSprite.getPosition().y + logSpeedY*dt.asSeconds());
            if(logSprite.getPosition().x <- 100 || logSprite.getPosition().y > 1800);
            logSprite.setPosition(810,720);
            logActive = false;

        }
        // Has the player been squished by a branch ?
        if(branchPositions[5]==sidePlayer){
            // Pause the game
            paused = true;
            // Accepting no input
            acceptInput = false;
            // Hide the player
            playerSprite.setPosition(2000,2000);
            // Show the grave stone
            ripSprite.setPosition(600,830);
            // Show "Game Over !!!" message
            messageText.setString("Game Over!!!");
            textRect = messageText.getLocalBounds();
            messageText.setOrigin((textRect.left + textRect.width )/ 2.0, (textRect.top + textRect.height) / 2.0);
            messageText.setPosition(resolution.x / 2.0, resolution.y / 2.0);
            // Play sound of death
        }
 
        } //End of if(!paused)

        // window.clear(Color::Yellow);
        window.clear();

        // draw objects

        window.draw(backgroundSprite);
        window.draw(cloud1Sprite);
        window.draw(cloud2Sprite);
        window.draw(cloud3Sprite);
        for (int i = 0; i < NUM_BRANCHES; i++){
            window.draw(Branches[i]);
        }
        window.draw(treeSprite);
        window.draw(playerSprite);
        window.draw(axeSprite);
        window.draw(logSprite);
        window.draw(ripSprite);
        window.draw(bee1Sprite);
        window.draw(timeBar);
        if (paused)
            window.draw(messageText);
        window.draw(scoreText);
        
        window.display();
    }
    return 0;
}

void updateBranches(int seed)
{
 // Shift each position one place to right
 for(int i = NUM_BRANCHES-1; i > 0; i--)
 {
    branchPositions[i] = branchPositions[i-1];
 }
 // Update 0th position
 srand(time(0)+seed);
 int r = rand()%3;
 switch(r)
 {
    case 0: branchPositions[0] = side::LEFT;
    break;
    case 1: branchPositions[0] = side::RIGHT;
    break;
    default: branchPositions[0] = side::NONE;
 }
}