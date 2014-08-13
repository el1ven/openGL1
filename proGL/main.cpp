//
//  main.cpp
//  proGL
//
//  Created by el1ven on 6/8/14.
//  Copyright (c) 2014 el1ven. All rights reserved.
//

#include <GLUT/GLUT.h>

static float spin = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.1);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();
    glFlush();
}

void spinDisplay(){
    spin += 2.0;
    if(spin > 360.0){
        spin = 0;
    }
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                glutIdleFunc(spinDisplay);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                glutIdleFunc(nullptr);
            }
            break;
        default:
            break;
    }
    
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

