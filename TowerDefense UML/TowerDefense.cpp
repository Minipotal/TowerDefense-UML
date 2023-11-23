#include <iostream>
#include <thread>  
#include <SFML/Graphics.hpp>
#include "Towers.h"
#include "GameManager.h"
#include "FileReader.h"
#include "Window.h"
#include "GameManager.h"
#include "EventManager.h"

void Game()
{
    FileReader* oFile = new FileReader();

    oFile->readFileTxt("Files/test.txt");

    MWindow* oWindow = new MWindow(Vect2(1000, 800), "Tower Defence");

    sf::Texture tBackground;
    if (!tBackground.loadFromFile("src/road.jpg"))
        return -1;
    
    sf::Sprite backgroundImage(tBackground);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    GameManager* oGameManager = new GameManager();
    Towers* oTower = new Towers(Vect2(20, 20), Vect2(30, 30), sf::Color(255, 0, 0));

    float fDeltaTime = 0;

    sf::RenderWindow* pWindowRenderer = oWindow->getWindow();

    while (oWindow->getWindow()->isOpen())
    {
        sf::Clock oClock;
        //EVENT
        sf::Event oEvent;
        while (pWindowRenderer->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                pWindowRenderer->close();
            else if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i vMousePos = sf::Mouse::getPosition(*pWindowRenderer);
                }
            }
        }

        //UPDATE
        oTower->ChooseTarget(oGameManager->EnemiesList);
        for (int i = 0; i < oTower->GetBulletsList().size(); i++)
        {
            oTower->GetBulletsList()[i]->Movement(fDeltaTime, pWindowRenderer);
        }

        //DRAW
        pWindowRenderer->clear();

        pWindowRenderer->draw(backgroundImage);

        for (int i = 0; i < oTower->GetBulletsList().size(); i++)
        {
            oTower->GetBulletsList()[i]->Draw(pWindowRenderer);
        }
        oTower->Draw(pWindowRenderer);

        pWindowRenderer->display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;

// 	GameManager::Get()->game();
}

int main()
{
// 	EventManager::Create();
// 	GameManager::Create();
	Game();
}

