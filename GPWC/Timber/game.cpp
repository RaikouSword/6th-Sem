#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    Vector2f res;
    res.x = VideoMode::getDesktopMode().width;
    res.y = VideoMode::getDesktopMode().height;

    VideoMode vm(res.x,res.y);
    
    RenderWindow rm(vm,"Timber");

    Texture bgTexture;
    bgTexture.loadFromFile("Sprites/Graphics/background.png");
    Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    bgSprite.setPosition(0,0);

    Texture treeTexture;
    treeTexture.loadFromFile("Sprites/Graphics/tree.png");
    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(res.x/2-300/2,0);

    Texture playerTexture;
    playerTexture.loadFromFile("Sprites/Graphics/player.png");
    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(1000,res.y-330);

    Texture beeTexture;
    beeTexture.loadFromFile("Sprites/Graphics/bee.png");
    Sprite beeSprite1;
    beeSprite1.setTexture(beeTexture);
    beeSprite1.setPosition(1000,res.y/2-100);
    Sprite beeSprite2;
    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition(550,res.y/2-40);
    Sprite beeSprite3;
    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition(1100,res.y/2-40);
    Sprite beeSprite4;
    beeSprite4.setTexture(beeTexture);
    beeSprite4.setPosition(450,res.y/2-100);

    Texture cloudTexture;
    cloudTexture.loadFromFile("Sprites/Graphics/cloud.png");
    Sprite cloudSprite1;
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setPosition(0,0);
    Sprite cloudSprite2;
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setPosition(res.x-300,150);
    
    while(rm.isOpen()){
        Event event;
        while(rm.pollEvent(event)){
            if(event.type==Event::Closed){
                rm.close();
            }
        }
        
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            rm.close();
        }
        
        rm.clear();
        rm.draw(bgSprite);
        rm.draw(treeSprite);
        rm.draw(playerSprite);
        rm.draw(beeSprite1);
        rm.draw(beeSprite2);
        rm.draw(beeSprite3);
        rm.draw(beeSprite4);
        rm.draw(cloudSprite1);
        rm.draw(cloudSprite2);
        rm.display();
    }
}