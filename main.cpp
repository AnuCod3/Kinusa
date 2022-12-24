#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fake Mario by Anusan and Kilian");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}