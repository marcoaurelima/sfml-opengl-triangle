#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>


int main(int argc, char **argv){

    // Para uso exclusivamente com OpenGL, basta `sf::Window`
    // para uso de OpenGL juntamente com objetos SFML, usar `sf::RenderWindow`
    // sf::Window window(sf::VideoMode(600,600), "teste");
    sf::RenderWindow window(sf::VideoMode(600,600), "teste");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(50,50));
    shape.setFillColor(sf::Color::Red);


    bool running = true;
    while (running) 
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed){
                running = false;
            }
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        {
            glVertex3f(0.0, 2.0, -5.0);
            glVertex3f(-2.0, -2.0, -5.0);
            glVertex3f(2.0, -2.0, -5.0);
        }
        glEnd();

        // Se estiver usando `sf::RenderWindow`, estas duas funções delimitam
        // onde chamar a função `draw` para desenhos do SFML.
        window.pushGLStates();
        window.draw(shape);
        window.popGLStates();

        window.display();
    }

    return 0;
}