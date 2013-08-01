
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#include "camera.h"

Camera::Camera()
{
     eye = QVector3D(0.0, 0.0, 2);    // posicao do "olho" do observador. Neste caso a Camera
     at  = QVector3D(0.0, 0.0, 0.0);  // posicao para onde a camera aponta
     up  = QVector3D(0.0, 1.0, 0.0);  // posicao q indica o topo do objeto apontado pela camera
}
