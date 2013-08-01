
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/

#ifndef LIGHT_H
#define LIGHT_H

#include <QVector4D>

class Light
{

public slots:


public:


    double r1,g1,b1;

    Light();
    QVector4D position;
    QVector4D ambient;
    QVector4D diffuse;
    QVector4D specular;
};

#endif // LIGHT_H
