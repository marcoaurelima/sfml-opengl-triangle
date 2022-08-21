#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>


int main(int argc, char **argv){

    sf::Window window(sf::VideoMode(600,600), "teste");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);


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
        

        window.display();
    }

    return 0;
}