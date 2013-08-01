

/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#include "glwidget.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <light.h>
#include "Point3d.h"
#include "Point2d.h"
#include "IDList.h"
#include "PointTool.h"
#include "PolarList.h"
#include "IDSet.h"
#include "PCBCGSolver.h"
#include "Polyhedron.h"

GLWidget::GLWidget(QWidget *parent) :  //metodo construtor da classe GLWidget
    QGLWidget(parent)
{
    m_shaderProgram = NULL;     m_vertexShader = NULL;     m_fragmentShader = NULL;
    m_vboVertices = NULL;       m_vboNormals = NULL;       m_vboColors = NULL;        m_vboIndices = NULL;
    verticesphere = NULL;       verticesphere_aux = NULL;  indicessphere = NULL;     indicessphere_aux = NULL;    normalsphere = NULL;
    exemplo = 0;
    iscullface = true;
    rotatey = 0;                texture_index = 0;         coordinate_texture_index = 0;   texture_mode=0;
    tangents = NULL;
    texcoords = NULL;
    r=255;     g=255;     b=255;
    isfile=false;
    left=-2;     right=2;      bottom=-2;     top=2;      zNearOrtho=5;     zFarOrtho=-10;     zNearPerspec=3;     zFarPerspec=-10;    fovy=45;
    eye = QVector3D(0,0,2);      at = QVector3D(0,0,0);     up = QVector3D(0,1,0);
    dz=1;
    lx = 3;     ly = 3;      lz = 3;     lw = 0;

    max_y = -1e10, min_y = 1e10; // PRA OBTER MAX e MIN (Y)

    cube_img[0] = QImage(":/cubemap/negx.jpg","JPG");
    cube_img[1] = QImage(":/cubemap/negy.jpg","JPG");
    cube_img[2] = QImage(":/cubemap/negz.jpg","JPG");
    cube_img[3] = QImage(":/cubemap/posx.jpg","JPG");
    cube_img[4] = QImage(":/cubemap/posy.jpg","JPG");
    cube_img[5] = QImage(":/cubemap/posz.jpg","JPG");


    tx_id[0] = -1; tx_id[1] = -1;tx_id[2] = -1;
    tx_id[3] = -1; tx_id[4] = -1; tx_id[5] = -1;
    tx_id[6] = -1;

}

GLWidget::~GLWidget() // metodo destrutor  da classe GLWidget
{
    if(m_vertexShader)   delete m_vertexShader;
    if(m_fragmentShader) delete m_fragmentShader;
    if(m_shaderProgram)   delete m_shaderProgram;
    if(m_vboVertices)    delete m_vboVertices;
    if(m_vboIndices)     delete m_vboIndices;
}

void GLWidget::initializeGL()   // metodo de inicializacao
{
    glEnable(GL_DEPTH_TEST);
    ModelView.setToIdentity();     //setando a Matriz ModelView para Identidade
    ModelView.lookAt(eye,at,up);    //
    NormalMatrix = ModelView.normalMatrix();
    Projection.setToIdentity();      //setando a Matriz de projecao para Identidade
    projectiontype = 0;                  //projecao inicializa em Ortogonal
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(0);
    this->initialize_example1();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glClearColor(r,g,b,1);

    ModelView.setToIdentity();
    ModelView.lookAt(eye,at,up);
    ModelView.rotate(dx,0,1,0);
    ModelView.rotate(dy,1,0,0);
    ModelView.scale(dz);
    NormalMatrix = ModelView.normalMatrix();

    //Projection.setToIdentity();

    if(projectiontype == 0 ){
         Projection.setToIdentity();
         Projection.ortho(left,right,bottom,top,zNearOrtho,zFarOrtho);
    }
    if (projectiontype == 1){
           Projection.setToIdentity();
           Projection.perspective(fovy, aspect, zNearPerspec, zFarPerspec);

    }
    if (projectiontype == 2){
          Projection.setToIdentity();
          Projection.frustum(left, right, bottom, top, zNearPerspec, zFarPerspec);
        }

    m_shaderProgram->setUniformValue("Projection", Projection);
    m_shaderProgram->setUniformValue("ModelView", ModelView);
    m_shaderProgram->setUniformValue("NormalMatrix", NormalMatrix);
    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));


    if(isfile){
        switch(exemplo){
        case 0:
            execute_example_1();
            break;
        case 1:
            execute_example_1();
            break;
        case 2:           
            execute_flat();
            break;
        case 3:
            execute_phong();
            break;
        case 4:
            execute_phong_modificado();
            break;
        case 5:
            execute_Gouraud();
            break;
        case 6:
            execute_toon();
            break;
        case 7:
            execute_toon2();
            break;
        case 8:
            execute_shadingY();
            break;
        case 9:
            execute_tex1();
            break;
        case 10:
            execute_tex2();
            break;
        case 11:
            execute_tex3();
            break;
        }

}
}



void GLWidget::initialize_example1()
{
  //  this->sphere();
   // reloadMatriz();
    this->setshaders(":/shaders/vshader1.glsl",":/shaders/fshader1.glsl");
    // create VBO for vertices
    if(m_vboVertices) delete m_vboVertices;
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));
   // delete []verticesphere;
   // verticesphere=NULL;
    if(m_vboIndices) delete m_vboIndices;
    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
    //delete []this->indicessphere;
    //indicessphere=NULL;
}
void GLWidget::execute_example_1()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboIndices->bind();
    if(iscullface)
        glEnable(GL_CULL_FACE);
    else
       glDisable(GL_CULL_FACE);
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    m_vboVertices->release();
    m_vboIndices->release();
}


void GLWidget::initialize_example2()
{
   // this->sphere();
    reloadMatriz();
    this->build_normal_faces_sphere();
    this->setshaders(":/shaders/vshader2.glsl",":/shaders/fshader2.glsl");
    QVector4D *flatvertices = new QVector4D[this->n_faces*3];
    QVector4D *flatcolors   = new QVector4D[this->n_faces*3];
    QVector4D ambient_color    = light.ambient*material.ambient;
    //QVector4D ambient_color    = QVector4D(ambR,ambG,ambB,1.0)*material.ambient;
    QVector4D diffuse_product  = light.diffuse*material.diffuse;
    //QVector4D diffuse_product  = QVector4D(difR,difG,difB,1.0)*material.diffuse;
    QVector4D specular_product = light.specular*material.specular;
    // QVector4D specular_product = QVector4D(specR,specG,specB,1.0)*material.specular;

    for(unsigned int i = 0; i < this->n_faces; i++)
    {
        QVector3D N(this->normalsphere[i].normalized());
        //QVector3D L = light.position.toVector3D().normalized();
        QVector3D L = QVector4D(lx,ly,lz,lw).toVector3D().normalized();
        QVector3D E = camera.eye.normalized();
        QVector3D H = (L+E).normalized();
        float LdN = QVector3D::dotProduct(L,N);
        float kd = (LdN > 0 ? LdN:0);
        QVector4D   diffuse = kd*diffuse_product;
        float NdH = QVector3D::dotProduct(N,H);
        float ks = pow(  (NdH > 0 ? NdH:0), material.shininess );
        QVector4D specular = ks*specular_product;
        if(QVector4D::dotProduct(L,N)  < 0.0)
            specular = QVector4D(0,0,0,1);
        QVector4D color = ambient_color + diffuse + specular;
        color.setW(1.0);
        flatvertices[3*i]   = this->verticesphere[this->indicessphere[3*i]];
        flatvertices[3*i+1] = this->verticesphere[this->indicessphere[3*i+1]];
        flatvertices[3*i+2] = this->verticesphere[this->indicessphere[3*i+2]];
        flatcolors[3*i]     = color;
        flatcolors[3*i+1]   = color;
        flatcolors[3*i+2]   = color;
    }
    if(m_vboVertices) delete m_vboVertices;
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(flatvertices, this->n_faces*3*sizeof(QVector4D));
   // delete []flatvertices;
    if(m_vboColors) delete m_vboColors;
    m_vboColors = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboColors->create();
    m_vboColors->bind();
    m_vboColors->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboColors->allocate(flatcolors, this->n_faces*3*sizeof(QVector4D));
   // delete []flatcolors;
}
void GLWidget::execute_example_2()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboColors->bind();
    m_shaderProgram->enableAttributeArray("vColor");
    m_shaderProgram->setAttributeBuffer("vColor",GL_FLOAT,0,4,0);
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glDrawArrays( GL_TRIANGLES, 0, this->n_faces*3 );
    this->m_vboColors->release();
    this->m_vboVertices->release();
}


//Flat Shading
void GLWidget::initialize_flat()
{
    this->setshaders(":/shaders/vshader3.glsl",":/shaders/fshader3.glsl");
   // this->sphere();
    reloadMatriz();
    this->build_normal_faces_sphere();
    QVector4D *flatvertices = new QVector4D[this->n_faces*3];
    QVector3D *flatnormals = new QVector3D[this->n_faces*3];
    for(unsigned int i = 0; i < this->n_faces; i++)
    {
        flatvertices[3*i] = this->verticesphere[this->indicessphere[3*i]];
        flatvertices[3*i+1] = this->verticesphere[this->indicessphere[3*i+1]];
        flatvertices[3*i+2] = this->verticesphere[this->indicessphere[3*i+2]];
        flatnormals[3*i] = this->normalsphere[i];
        flatnormals[3*i+1] = this->normalsphere[i];
        flatnormals[3*i+2] = this->normalsphere[i];
    }
    // create VBO for vertices
    if(m_vboVertices) delete m_vboVertices;
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(flatvertices, this->n_faces*3*sizeof(QVector4D));
   // delete []flatvertices;
  //  flatvertices = NULL;
    if(m_vboNormals) delete m_vboNormals;
    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(flatnormals, this->n_faces*3*sizeof(QVector3D));
 //   delete []flatnormals;
//    flatnormals = NULL;
 //   delete []normalsphere;
  //  normalsphere = NULL;
    QVector4D ambient_product  = light.ambient*material.ambient;
    QVector4D diffuse_product  = light.diffuse*material.diffuse;
    QVector4D specular_product = light.specular*material.specular;
    m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
    m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
    m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
//    m_shaderProgram->setUniformValue("LightPosition",light.position);
    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
}
void GLWidget::execute_flat()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    glDrawArrays( GL_TRIANGLES, 0, this->n_faces*3 );
    this->m_vboNormals->release();
    this->m_vboVertices->release();
}


//Phong Shading
void GLWidget::initialize_phong(){

        reloadMatriz();
        this->build_normal_vertices_sphere();
        this->setshaders(":/shaders/vshader4.glsl",":/shaders/fshader4.glsl");

        if(m_vboVertices){
            delete m_vboVertices;
            m_vboVertices =  NULL;
        }
        m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
        m_vboVertices->create();
        m_vboVertices->bind();
        m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
        m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));

        if(m_vboNormals) {
            delete m_vboNormals;
            m_vboNormals = NULL;
        }
        m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
        m_vboNormals->create();
        m_vboNormals->bind();
        m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
        m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
        //delete []normals;
        //normals=NULL;

        if(m_vboIndices) {
            delete m_vboIndices;
            m_vboIndices= NULL;
        }
        m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
        m_vboIndices->create();
        m_vboIndices->bind();
        m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
        m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));

        QVector4D ambient_product = light.ambient*material.ambient;
        QVector4D diffuse_product = light.diffuse * material.diffuse;
        QVector4D specular_product = light.specular * material.specular;

        m_shaderProgram->setUniformValue("LightPosition",light.position);
        m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
        m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
        m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
        m_shaderProgram->setUniformValue("Shininess",material.shininess);
    /*// this->sphere();
    reloadMatriz();
    this->build_normal_vertices_sphere();
    this->setshaders(":/shaders/vshader4.glsl",":/shaders/fshader4.glsl");
    // create VBO for vertices
    if(m_vboVertices) delete m_vboVertices;
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));
  //  delete []verticesphere;
   // verticesphere=NULL;
    if(m_vboNormals) delete m_vboNormals;
    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
 //   delete []normalsphere;
 //   normalsphere=NULL;
    if(m_vboIndices) delete m_vboIndices;
    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
//    delete []this->indicessphere;
//    indicessphere=NULL;
    QVector4D ambient_product = light.ambient*material.ambient;
    QVector4D diffuse_product = light.diffuse * material.diffuse;
    QVector4D specular_product = light.specular * material.specular;
//    m_shaderProgram->setUniformValue("LightPosition",light.position);
    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
    m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
    m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
*/
}
void GLWidget::execute_phong()
{


   //     glEnable(GL_CULL_FACE);
  //      glPolygonMode( GL_FRONT_AND_BACK, GL_LINE);

        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);

    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);

    m_vboIndices->bind();

    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);

    m_vboVertices->release();
    m_vboIndices->release();

    /*
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess*100);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    m_vboVertices->release();
    m_vboIndices->release();*/
}


//Phong Modificado
void GLWidget::initialize_phong_modificado(){
    reloadMatriz();
    this->build_normal_vertices_sphere();
    this->setshaders(":/shaders/vshader9.glsl",":/shaders/fshader9.glsl");
    if(m_vboVertices){        delete m_vboVertices;        m_vboVertices = NULL;    }
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));
//    delete []verticesphere;
//    verticesphere=NULL;
    if(m_vboNormals){        delete m_vboNormals;        m_vboNormals = NULL;    }
    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
//    delete []normalsphere;
//    normalsphere=NULL;
    if(m_vboIndices){        delete m_vboIndices;        m_vboIndices = NULL;    }
    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
//    delete []this->indicessphere;
//    indicessphere=NULL;
    QVector4D ambient_product = light.ambient * material.ambient;
    QVector4D diffuse_product = light.diffuse * material.diffuse;
    QVector4D specular_product = light.specular * material.specular;
    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
    m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
    m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
}

//desenha o objeto na tela com a iluminacao Phong Modificada
void GLWidget::execute_phong_modificado()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    m_vboVertices->release();
    m_vboNormals->release();
    m_vboIndices->release();
}



//Gouraud Shading
void GLWidget::initialize_Gouraud()
{
    this->reloadMatriz();
    this->build_normal_vertices_sphere();  // calcula as normais dos vetores
    this->setshaders(":/shaders/vshader2.glsl",":/shaders/fshader2.glsl");

//faz calculo geral das caracteristicas de luz e material para calcular a iluminacao
    QVector4D ambient_product    = light.ambient*material.ambient;
    QVector4D diffuse_product  = light.diffuse*material.diffuse;
    QVector4D specular_product = light.specular*material.specular;



//"linka" as variaveis necessarias para iluminacao em seus respectivos vetores usados no shader
    m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
    m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
    m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("Shininess",material.shininess);

//manda vertices e normais para o Buffer
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));

    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(normalsphere, this->n_points_sphere*sizeof(QVector3D));

    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
}
void GLWidget::execute_Gouraud()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_vboIndices->bind();

    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glDrawElements(GL_TRIANGLES, this->n_faces*3, GL_UNSIGNED_INT, 0);


     m_vboVertices->release();
     m_vboIndices->release();
     m_vboNormals->release();
}



//Cartoon Shading
void GLWidget::initialize_toon()
{
    // this->sphere();
     this->reloadMatriz();
     this->build_normal_vertices_sphere();
     this->setshaders(":/shaders/vshader5.glsl",":/shaders/fshader5.glsl");
     // create VBO for vertices
     if(m_vboVertices) delete m_vboVertices;
     m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
     m_vboVertices->create();
     m_vboVertices->bind();
     m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));
   //  delete []verticesphere;
    // verticesphere=NULL;
     if(m_vboNormals) delete m_vboNormals;
     m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
     m_vboNormals->create();
     m_vboNormals->bind();
     m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
  //   delete []normalsphere;
  //   normalsphere=NULL;
     if(m_vboIndices) delete m_vboIndices;
     m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
     m_vboIndices->create();
     m_vboIndices->bind();
     m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
 //    delete []this->indicessphere;
 //    indicessphere=NULL;
     QVector4D ambient_product = light.ambient*material.ambient;
     QVector4D diffuse_product = light.diffuse * material.diffuse;
     QVector4D specular_product = light.specular * material.specular;
     //m_shaderProgram->setUniformValue("LightPosition",light.position);
     m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
     m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
     m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
     m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
     m_shaderProgram->setUniformValue("Shininess",material.shininess);

}
void GLWidget::execute_toon()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    m_vboVertices->release();
    m_vboIndices->release();

}





//Cartoon Shading
void GLWidget::initialize_toon2()
{
    // this->sphere();
     this->reloadMatriz();
     this->build_normal_vertices_sphere();
     this->setshaders(":/shaders/vshader10.glsl",":/shaders/fshader10.glsl");
     // create VBO for vertices
     if(m_vboVertices) delete m_vboVertices;
     m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
     m_vboVertices->create();
     m_vboVertices->bind();
     m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));
   //  delete []verticesphere;
    // verticesphere=NULL;
     if(m_vboNormals) delete m_vboNormals;
     m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
     m_vboNormals->create();
     m_vboNormals->bind();
     m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
  //   delete []normalsphere;
  //   normalsphere=NULL;
     if(m_vboIndices) delete m_vboIndices;
     m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
     m_vboIndices->create();
     m_vboIndices->bind();
     m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
     m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));
 //    delete []this->indicessphere;
 //    indicessphere=NULL;
     QVector4D ambient_product = light.ambient*material.ambient;
     QVector4D diffuse_product = light.diffuse * material.diffuse;
     QVector4D specular_product = light.specular * material.specular;
     m_shaderProgram->setUniformValue("LightPosition",-light.position);

     m_shaderProgram->setUniformValue("AmbientProduct",light.ambient*material.ambient);
     m_shaderProgram->setUniformValue("DiffuseProduct",light.diffuse*QVector4D(0.0,0.0,1.0,1.0));
     m_shaderProgram->setUniformValue("SpecularProduct",light.specular*material.specular);
     m_shaderProgram->setUniformValue("Shininess",material.shininess);

}
void GLWidget::execute_toon2()
{



    //glClearColor(0.5019608,0.5019608,0.5019608,1);
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    m_vboVertices->release();
    m_vboIndices->release();

}



void GLWidget::initialize_shadingY(){
    this->build_normal_vertices_sphere();
       this->setshaders(":/shaders/vshader11.glsl",":/shaders/fshader11.glsl");

       if(m_vboVertices){
           delete m_vboVertices;
           m_vboVertices =  NULL;
       }
       m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
       m_vboVertices->create();
       m_vboVertices->bind();
       m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
       m_vboVertices->allocate(this->verticesphere, this->n_points_sphere*sizeof(QVector4D));

       if(m_vboNormals) {
           delete m_vboNormals;
           m_vboNormals = NULL;
       }
       m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
       m_vboNormals->create();
       m_vboNormals->bind();
       m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
       m_vboNormals->allocate(this->normalsphere, this->n_points_sphere*sizeof(QVector3D));
       //delete []normals;
      // normals=NULL;

       if(m_vboIndices) {
           delete m_vboIndices;
           m_vboIndices= NULL;
       }
       m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
       m_vboIndices->create();
       m_vboIndices->bind();
       m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
       m_vboIndices->allocate(indicessphere, this->n_faces*3*sizeof(GL_UNSIGNED_INT));

       QVector4D ambient_product = light.ambient*material.ambient;
       //QVector4D diffuse_product = light.diffuse * material.diffuse;

      // QVector4D ambient_product = QVector4D(0.0,1.0,0.0,1.0);
       QVector4D diffuse_product = QVector4D(0.0,1.0,0.0,1.0);

       m_shaderProgram->setUniformValue("LightPosition",light.position);
       m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
       m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
       m_shaderProgram->setUniformValue("Shininess",material.shininess);
       m_shaderProgram->setUniformValue("alturaMin",min_y);
       m_shaderProgram->setUniformValue("alturaMax",max_y);
}

void GLWidget::execute_shadingY(){
    //Desenha o objeto com a iluminacao
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        m_vboVertices->bind();
        m_shaderProgram->enableAttributeArray("vPosition");
        m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
        m_vboNormals->bind();
        m_shaderProgram->enableAttributeArray("vNormal");
        m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
        m_shaderProgram->setUniformValue("Shininess",material.shininess);
        m_vboIndices->bind();
        glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
        m_vboVertices->release();
        m_vboIndices->release();
        m_vboNormals->release();
}


void GLWidget::initialize_tex1()
{
  //  this->reset_vbos();
    this->reloadMatriz();
    this->build_normal_vertices_sphere();
    this->set_texture();
    this->set_coordinate_textures();
    this->setshaders(":/shaders/vshader6.glsl",":/shaders/fshader6.glsl");
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere , this->n_points_sphere *sizeof(QVector4D));
    //delete []vertices;
    //vertices =NULL;
    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(this->normalsphere, this->n_points_sphere *sizeof(QVector3D));
    //delete []normals;
    //normals =NULL;
    m_vbo_texcoords = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vbo_texcoords->create();
    m_vbo_texcoords->bind();
    m_vbo_texcoords->setUsagePattern(QGLBuffer::StaticDraw);
    m_vbo_texcoords->allocate(this->texcoords , this->n_points_sphere *sizeof(QVector2D));
    //delete []texcoords;
    //texcoords =NULL;
    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere , this->n_faces*3*sizeof(GL_UNSIGNED_INT));
    //delete []this->indices;
    //indices = NULL;

    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    //m_shaderProgram->setUniformValue("AmbientProduct",light.ambient * material.ambient);
    m_shaderProgram->setUniformValue("AmbientProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    //m_shaderProgram->setUniformValue("DiffuseProduct",light.diffuse * material.diffuse);
    m_shaderProgram->setUniformValue("DiffuseProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    //m_shaderProgram->setUniformValue("SpecularProduct",light.specular*material.specular);
    m_shaderProgram->setUniformValue("SpecularProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    //m_shaderProgram->setUniformValue("Shininess",light.specular * material.specular);
    m_shaderProgram->setUniformValue("Shininess",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    m_shaderProgram->setUniformValue("texMap",0);
    glActiveTexture(GL_TEXTURE0);
    for(int i = 0; i < 7; i++)
        if(tx_id[i] != -1) QGLWidget::deleteTexture(tx_id[i]);
    tx_id[0] = QGLWidget::bindTexture(texColor);
}
void GLWidget::execute_tex1()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vbo_texcoords->bind();
    m_shaderProgram->enableAttributeArray("vTexCoords");
    m_shaderProgram->setAttributeBuffer("vTexCoords",GL_FLOAT,0,2,0);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    //vbo_vertices->release();
    //vbo_indices->release();
    //vbo_normals->release();
    //vbo_texcoords->release();
}


void GLWidget::initialize_tex2()
{
   // this->reset_vbos();
    this->setshaders(":/shaders/vshader7.glsl",":/shaders/fshader7.glsl");
    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere , this->n_points_sphere *sizeof(QVector4D));
    //delete []vertices;
    //vertices =NULL;

    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(this->normalsphere , this->n_points_sphere *sizeof(QVector3D));
    //delete []normals;
    //normals =NULL;

    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere , this->n_faces*3*sizeof(GL_UNSIGNED_INT));
    //delete []this->indices;
    //indices =NULL;
    QVector4D ambient_product = QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0);
    QVector4D diffuse_product = QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0);
    QVector4D specular_product = QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0);

    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("AmbientProduct",ambient_product);
    m_shaderProgram->setUniformValue("DiffuseProduct",diffuse_product);
    m_shaderProgram->setUniformValue("SpecularProduct",specular_product);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_shaderProgram->setUniformValue("texMap",0);

    glActiveTexture(GL_TEXTURE0);

    for(int i = 0; i < 7; i++)
        if(tx_id[i] != -1) QGLWidget::deleteTexture(tx_id[i]);

    tx_id[6] = QGLWidget::bindTexture(cube_img[5],GL_TEXTURE_CUBE_MAP);

    tx_id[0] = QGLWidget::bindTexture(cube_img[0],GL_TEXTURE_CUBE_MAP_NEGATIVE_X,GL_RGB);
    tx_id[1] = QGLWidget::bindTexture(cube_img[4],GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,GL_RGB);
    tx_id[2] = QGLWidget::bindTexture(cube_img[2],GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,GL_RGB);
    tx_id[3] = QGLWidget::bindTexture(cube_img[3],GL_TEXTURE_CUBE_MAP_POSITIVE_X,GL_RGB);
    tx_id[4] = QGLWidget::bindTexture(cube_img[1],GL_TEXTURE_CUBE_MAP_POSITIVE_Y,GL_RGB);
    tx_id[5] = QGLWidget::bindTexture(cube_img[5],GL_TEXTURE_CUBE_MAP_POSITIVE_Z,GL_RGB);

}

void GLWidget::execute_tex2()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    //vbo_vertices->release();
    //vbo_normals->release();
    //vbo_indices->release();
}


void GLWidget::initialize_tex3()
{

    //this->reset_vbos();
    this->reloadMatriz();
    this->set_coordinate_textures();

    texColor = QImage(":/normalmap/fieldstone-c.jpg","JPG");
    texNormal = QImage(":/normalmap/fieldstone-n.jpg","JPG");

    this->genTangentFrames();
    this->setshaders(":/shaders/vshader8.glsl",":/shaders/fshader8.glsl");

    m_vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboVertices->create();
    m_vboVertices->bind();
    m_vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboVertices->allocate(this->verticesphere , this->n_points_sphere *sizeof(QVector4D));
    //delete []vertices;
  //  vertices =NULL;
//
    m_vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vboNormals->create();
    m_vboNormals->bind();
    m_vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboNormals->allocate(this->normalsphere , this->n_points_sphere *sizeof(QVector3D));
    //delete []normals;
    //normals =NULL;

    m_vbo_tangents = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vbo_tangents->create();
    m_vbo_tangents->bind();
    m_vbo_tangents->setUsagePattern(QGLBuffer::StaticDraw);
    m_vbo_tangents->allocate(this->tangents , this->n_points_sphere *sizeof(QVector4D));
    //delete []tangents;
    //tangents =NULL;

    m_vbo_texcoords = new QGLBuffer(QGLBuffer::VertexBuffer);
    m_vbo_texcoords->create();
    m_vbo_texcoords->bind();
    m_vbo_texcoords->setUsagePattern(QGLBuffer::StaticDraw);
    m_vbo_texcoords->allocate(this->texcoords , this->n_points_sphere *sizeof(QVector2D));
    //delete []texcoords;
    //texcoords =NULL;


    m_vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
    m_vboIndices->create();
    m_vboIndices->bind();
    m_vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
    m_vboIndices->allocate(indicessphere , this->n_faces*3*sizeof(GL_UNSIGNED_INT));
    //delete []this->indices;
    //indices =NULL;

    m_shaderProgram->setUniformValue("LightPosition",QVector4D(lx,ly,lz,lw));
    m_shaderProgram->setUniformValue("AmbientProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    m_shaderProgram->setUniformValue("DiffuseProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    m_shaderProgram->setUniformValue("SpecularProduct",QVector4D(.8,.8,.8,1.0)*QVector4D(.8,.8,.8,1.0));
    m_shaderProgram->setUniformValue("Shininess",material.shininess);

    m_shaderProgram->setUniformValue("texColorMap",0);
    m_shaderProgram->setUniformValue("texNormalMap",1);

    for(int i = 0; i < 7; i++)
        if(tx_id[i] != -1) QGLWidget::deleteTexture(tx_id[i]);

    glActiveTexture(GL_TEXTURE0);
    tx_id[0] = QGLWidget::bindTexture(this->texColor);
    glActiveTexture(GL_TEXTURE1);
    tx_id[1] = QGLWidget::bindTexture(this->texNormal);

}

void GLWidget::execute_tex3()
{
    m_vboVertices->bind();
    m_shaderProgram->enableAttributeArray("vPosition");
    m_shaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4,0);
    m_vboNormals->bind();
    m_shaderProgram->enableAttributeArray("vNormal");
    m_shaderProgram->setAttributeBuffer("vNormal",GL_FLOAT,0,3,0);
    m_vbo_tangents->bind();
    m_shaderProgram->enableAttributeArray("vTangent");
    m_shaderProgram->setAttributeBuffer("vTangent",GL_FLOAT,0,4,0);
    m_shaderProgram->setUniformValue("Shininess",material.shininess);
    m_vbo_texcoords->bind();
    m_shaderProgram->enableAttributeArray("vTexCoords");
    m_shaderProgram->setAttributeBuffer("vTexCoords",GL_FLOAT,0,2,0);
    m_vboIndices->bind();
    glDrawElements(GL_TRIANGLES, 3*this->n_faces, GL_UNSIGNED_INT, 0);
    //vbo_vertices->release();
    //vbo_normals->release();
    //vbo_indices->release();
    //vbo_texcoords->release();
    //vbo_tangents->release();
}







void GLWidget::reloadMatriz(){

    //if (verticesphere) delete verticesphere;
    //if (indicessphere) delete indicessphere;

    //indicessphere = new unsigned int[3*n_faces];

    indicessphere = indicessphere_aux;

   // verticesphere = new QVector4D[n_points_sphere];

    verticesphere = verticesphere_aux;

}










void GLWidget::sphere(){
}


//Metodo para ler o arquivo OFF e carregar os valores do arquivo OFF para o array  verticesphere indicessphere
void GLWidget::loadsphere()
{
    QByteArray  fileFormat = "OFF";
    QString  fileName  =  QFileDialog::getOpenFileName(NULL, tr("OpenFile"), QDir::currentPath(),tr("%1 Files  (*.%2);;All Files(*)")
                    .arg(QString(fileFormat.toUpper()))
                    .arg(QString(fileFormat)));
    QFile file(fileName);
     if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",file.errorString());
      }
    if (verticesphere) delete verticesphere;
    if (indicessphere) delete indicessphere;
    if (verticesphere_aux) delete verticesphere_aux;
    if (indicessphere_aux) delete indicessphere_aux;
    unsigned int i,j;
    unsigned int a,b,c,d;


    min_y = 1000000;
    max_y = -1000000;
    float x,y,z;
    char *ftype = NULL;                    //variable to check file type
    QString linha1 = file.readLine();
    QByteArray ba = linha1.toLatin1();
    const char *c_str1 = ba.data();
    sscanf(c_str1,"%s",ftype);

    if(strcmp(c_str1,"OFF")){                      //Verificando se e um arquivo OFF ( Object File Format )
       isfile = true;
        QString linha2 = file.readLine();
        QByteArray barray = linha2.toLatin1();
        const char *c_str2 = barray.data();
        sscanf(c_str2," %d %d", &n_points_sphere, &n_faces);

        verticesphere = new QVector4D[n_points_sphere];
        verticesphere_aux = new QVector4D[n_points_sphere];
        indicessphere = new unsigned int[3*n_faces];
        indicessphere_aux = new unsigned int[3*n_faces];

      for(i=0; i< n_points_sphere; i++){
        QString linhaAux = file.readLine();
        QByteArray baAux = linhaAux.toLatin1();
        const char *c_strAux = baAux.data();
        sscanf(c_strAux,"%f %f %f",&x,&y,&z);


        verticesphere[i] = QVector4D(x, y, z, 1);  //atribuindo os valores dos vertices para o array de vertices
        verticesphere_aux[i] = QVector4D(x, y, z, 1);
        //  std::cout << verticesphere[i].x() << std::endl;

        if(verticesphere[i].y() > max_y) max_y = this->verticesphere[i].y();
        if(verticesphere[i].y() < min_y) min_y = this->verticesphere[i].y();

        if(verticesphere_aux[i].y() > max_y) max_y = this->verticesphere_aux[i].y();
        if(verticesphere_aux[i].y() < min_y) min_y = this->verticesphere_aux[i].y();

      }

     for(j=0; j < n_faces; j++){
        QString linhaAux2 = file.readLine();
        QByteArray baAux2 = linhaAux2.toLatin1();
        const char *c_strAux2 = baAux2.data();
        sscanf(c_strAux2,"%d %d %d %d",&a,&b,&c,&d);
        indicessphere[3*j] = b;                           //  atribuindo
        indicessphere[3*j+1] = c;                        //   atribuindo
        indicessphere[3*j+2] = d;                         // atribuindo
        indicessphere_aux[3*j] = b;
        indicessphere_aux[3*j+1] = c;
        indicessphere_aux[3*j+2] = d;
     }
    }else{
              std::cout << "NOT .OFF FILE" << std::endl;
              }
           file.close();

        initialize_example1();
}



void GLWidget::build_normal_vertices_sphere()
{
    //para uma esfera centrada na origem e com raio 1.
  //  if (normalsphere) delete []normalsphere;
   // normalsphere = new QVector3D[this->n_points_sphere];
    //for(unsigned int i = 0; i < n_points_sphere; i++)
     //   normalsphere[i] = this->verticesphere[i].toVector3D();

   //Iluminacao
    if (normalsphere) delete []normalsphere;
    normalsphere = new QVector3D[this->n_points_sphere];
    for(unsigned int i = 0; i < n_faces; i++){
        normalsphere[this->indicessphere[3*i]] = QVector3D(0,0,0);
        normalsphere[this->indicessphere[3*i+1]] = QVector3D(0,0,0);
        normalsphere[this->indicessphere[3*i+2]] = QVector3D(0,0,0);
    }
    for(unsigned int i = 0; i < n_faces; i++)
    {
        int i0 = this->indicessphere[3*i];
        int i1 = this->indicessphere[3*i+1];
        int i2 = this->indicessphere[3*i+2];
        QVector3D v1 = (this->verticesphere[i1] - this->verticesphere[i0]).toVector3D();
        QVector3D v2 = (this->verticesphere[i2] - this->verticesphere[i0]).toVector3D();
        normalsphere[this->indicessphere[3*i]]   += QVector3D::crossProduct(v1,v2).normalized();
        normalsphere[this->indicessphere[3*i+1]] += QVector3D::crossProduct(v1,v2).normalized();
        normalsphere[this->indicessphere[3*i+2]] += QVector3D::crossProduct(v1,v2).normalized();
    }
    for(unsigned int i = 0; i < n_points_sphere; i++){
        normalsphere[i]=normalsphere[i].normalized();
    }
}

void GLWidget::build_normal_faces_sphere()
{
    if (normalsphere) delete []normalsphere;
    normalsphere = new QVector3D[this->n_faces];
    for(unsigned int i = 0; i < n_faces; i++)
    {
        int i0 = this->indicessphere[3*i];
        int i1 = this->indicessphere[3*i+1];
        int i2 = this->indicessphere[3*i+2];
        QVector3D v1 = (this->verticesphere[i1] - this->verticesphere[i0]).toVector3D();
        QVector3D v2 = (this->verticesphere[i2] - this->verticesphere[i0]).toVector3D();
        normalsphere[i] = QVector3D::crossProduct(v1,v2).normalized();
    }
}




void GLWidget::initialize_all(void)
{
    //it can be more efficient -> You do not need to load the model everytime!
  // this->load_model();
    reloadMatriz();
    this->initialize_example();
}


void GLWidget::set_example(int option)
{
    this->exemplo = option;
    this->initialize_all();
}

void GLWidget::initialize_example(void){
//    exemplo = ex;
switch (exemplo){
    case 0:
        iscullface = true;
        initialize_example1();
        break;
    case 1:
        iscullface = false;
        initialize_example1();
        break;
    case 2:  
        this->initialize_flat();
        break;
    case 3:
        this->initialize_phong();
        break;
    case 4:
        this->initialize_phong_modificado();
        break;
    case 5:
        this->initialize_Gouraud();
        break;
    case 6:
        this->initialize_toon();
        break;
    case 7:
        this->initialize_toon2();
        break;
    case 8:
        this->initialize_shadingY();
        break;
    case 9:
        this->initialize_tex1();
        break;
    case 10:
        this->initialize_tex2();
        break;
    case 11:
        this->initialize_tex3();
        break;



     }
    updateGL();
}


void GLWidget::set_shine(double i)
{
    material.shininess = i;
    updateGL();
}


void GLWidget::setshaders(std::string const &s1, std::string const &s2)
{
    m_shaderProgram->release();
    if (m_vertexShader)   delete m_vertexShader;
    if (m_fragmentShader) delete m_fragmentShader;
    m_vertexShader = new QGLShader(QGLShader::Vertex);
    m_fragmentShader = new QGLShader(QGLShader::Fragment);
    if(!m_vertexShader->compileSourceFile(s1.c_str()))
        qWarning() << m_vertexShader->log();
    if(!m_fragmentShader->compileSourceFile(s2.c_str()))
        qWarning() << m_fragmentShader->log();
    if(m_shaderProgram) delete m_shaderProgram;
    m_shaderProgram = new QGLShaderProgram;
    m_shaderProgram->addShader(m_vertexShader);
    m_shaderProgram->addShader(m_fragmentShader);
    if(!m_shaderProgram->link())
        qWarning() << m_shaderProgram->log() << endl;
    else
        m_shaderProgram->bind();
}


void GLWidget::animate()
{
    rotatey = (rotatey<360 ? rotatey+0.2 : 360-rotatey);
    updateGL();
}



//Metodos da Cor de Fundo *************************************************
void GLWidget::mudaCorFundoR(double i){
    r=i;
    updateGL();
}
void GLWidget::mudaCorFundoG(double i){
    g=i;
    updateGL();
}
void GLWidget::mudaCorFundoB(double i){
    b=i;
    updateGL();
}


//Metodos da Camera ************************************************
void GLWidget::setEyeX(double x){
    eye.setX(x);
    updateGL();
}
void GLWidget::setEyeY(double y){
    eye.setY(y);
    updateGL();
}
void GLWidget::setEyeZ(double z){
    eye.setZ(z);
    updateGL();
}
void GLWidget::setLookAtX(double x){
    at.setX(x);
    updateGL();
}
void GLWidget::setLookAtY(double y){
    at.setY(y);
    updateGL();
}
void GLWidget::setLookAtZ(double z){
    at.setZ(z);
    updateGL();
}
void GLWidget::setUpX(double x){
    up.setX(x);
    updateGL();
}
void GLWidget::setUpY(double y){
    up.setY(y);
    updateGL();
}
void GLWidget::setUpZ(double z){
    up.setZ(z);
    updateGL();
}


// Metodos da Projecao Ortogonal **************************
void GLWidget::setLeft(double l)
{
    left = l;
    updateGL();
}
void GLWidget::setRight(double r)
{
    right = r;
    updateGL();
}
void GLWidget::setBottom(double b)
{
    bottom = b;
    updateGL();
}
void GLWidget::setTop(double t)
{
    top = t;
    updateGL();
}
void GLWidget::setNearOrtho(double n)
{
    zNearOrtho = n;
    updateGL();
}
void GLWidget::setFarOrtho(double f)
{
    zFarOrtho = f;
    updateGL();
}


// Metodos da Projecao Perspectiva ****************************************
void GLWidget::setNearPerspec(double f)
{
    zNearPerspec = f;
    updateGL();
}
void GLWidget::setFarPerspec(double f)
{
    zFarPerspec = f;
    updateGL();
}
void GLWidget::setFovy(double f)
{
    fovy = f;
    updateGL();
}



//* EVENTOS DO MOUSE *************************************
void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        std::cout << "Botao esquerdo clicado" <<std::endl;
    }
    if (event->button() == Qt::RightButton) {
        std::cout << "Botao direito clicado" <<std::endl;
    }
}
void GLWidget::wheelEvent(QWheelEvent * event)
{
        event->accept();
    if (event->delta()<0){
        dz+=0.09;
        if(dz>=5)
         dz=5;
        std::cout << dz <<std::endl;
         updateGL();
      }
    if (event->delta()>0){
        dz-=0.09;
        if(dz<=0.02)
            dz=0.02;
        std::cout << dz <<std::endl;
        updateGL();
       }

}
void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
   event->accept();
    if (event->buttons() && Qt::LeftButton) {           
        dx = event->x();
        dy = event->y();
    }
}
void GLWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->isAccepted())
        return;

    if (event->buttons() & Qt::LeftButton) {

        event->accept();
    }

    if (event->buttons() & Qt::RightButton) {

        event->accept();
    }

    if (event->buttons() & Qt::MidButton) {    
        event->accept();
    }
}
void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept();
    if (event->button() == Qt::LeftButton) {
        std::cout << "Botao esquerdo solto" <<std::endl;
    }

    if (event->button() == Qt::RightButton) {
        std::cout << "Botao direito solto" <<std::endl;
    }

    if (event->button() == Qt::MidButton) {
      }
}


//*************************************************
void GLWidget::set_projection(int  p)
{
    projectiontype = p;
    updateGL();
}

void GLWidget::getR(double i){
    r1=i;
}
void GLWidget::getG(double i){
    g1=i;
}
void GLWidget::getB(double i){
    b1=i;
}




// Metodos para posicao da Luz **************************************************
void GLWidget::grabLightXPosition(double x){
      lx = x;
      updateGL();
}
void GLWidget::grabLightYPosition(double y){
      ly = y;
      updateGL();
}
void GLWidget::grabLightZPosition(double z){
     lz = z;
      updateGL();
}
void GLWidget::grabLightWPosition(double w){
      lw = w;
      updateGL();
}

// Metodos para posicao da Luz *******
void GLWidget::setAmbientR(double r){
    ambR = r;
    updateGL();
}
void GLWidget::setAmbientG(double g){
    ambG = g;
    updateGL();
}
void GLWidget::setAmbientB(double b){
    ambB = b;
    updateGL();
}
void GLWidget::setDiffuseR(double r){
    difR = r;
    updateGL();
}
void GLWidget::setDiffuseG(double g){
    difG = g;
    updateGL();
}
void GLWidget::setDiffuseB(double b){
    difB = b;
    updateGL();
}
void GLWidget::setSpecularR(double r){
    specR = r;
    updateGL();
}
void GLWidget::setSpecularG(double g){
    specG = g;
    updateGL();
}
void GLWidget::setSpecularB(double b){
    specB = b;
    updateGL();
}
//
//void GLWidget::reset_vbos()
//{
//    if(m_vboVertices) {vbo_vertices->release(); delete vbo_vertices; vbo_vertices = NULL;}
//    if(vbo_normals)  {vbo_normals->release(); delete vbo_normals; vbo_normals = NULL;}
 //   if (vbo_indices) {vbo_indices->release(); delete vbo_indices; vbo_indices = NULL;}
//    if (vbo_texcoords) {vbo_texcoords->release(); delete vbo_texcoords; vbo_texcoords = NULL;}
//    if (vbo_tangents) {vbo_tangents->release(); delete vbo_tangents; vbo_tangents = NULL;}
//}


//Metodo para selecionar as texturas  [ pedra,laranja,limao,agua etc ]
void GLWidget::set_texture(int option)
{
    this->texture_index = option;
     reloadMatriz();
     initialize_all();
}

//Metodo para selecionar as texturas  [ pedra,laranja,limao,agua etc ]
void GLWidget::set_texture(void){
    switch(texture_index)    {
    case 0:  //pedregulho
        texColor = QImage(":/imagens/pedregulho.jpg","JPG");
        break;
    case 1: //pedra
        texColor = QImage(":/imagens/pedra.jpg","JPG");
        break;
    case 2:  //pedra2
        texColor = QImage(":/imagens/pedra2.bmp","BMP");
        break;
    case 3:  //laranja
        texColor = QImage(":/imagens/laranja.jpg","JPG");
        break;
    case 4: //limao
        texColor = QImage(":/imagens/limao.jpg","JPG");
        break;
    case 5: //agua
        texColor = QImage(":/imagens/agua.jpg","JPG");
        break;
    case 6: //fogo
        texColor = QImage(":/imagens/fogo.jpg","JPG");
        break;
    case 7: //UFABC
        texColor = QImage(":/imagens/ufabc.jpg","JPG");
        break;
    case 8: //xadrez
        texColor = QImage(":/imagens/xadrez.png","PNG");
        break;
       }
}


void GLWidget::set_coordinate_textures(void){
     switch(coordinate_texture_index){
    case 0:
        this->genTexCoordsCylinder();
        break;
    case 1:
        this->genTexCoordsSphere();
        break;
    case 2:
        this->genTexCoordsSpectral();
        break;
    case 3:
        this->genTexCoordsTriangles();
        break;
    }
    //initialize_all();
}

void GLWidget::set_coordinate_textures(int option)
{
    this->coordinate_texture_index = option;
    reloadMatriz();
    this->initialize_all();
    //set_example();
}


void GLWidget::set_texture_mode(int i){

    this->texture_mode = i;
}

void GLWidget::set_texture_mode(void){
    switch(texture_mode)
    {
    case 0:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        break;
    case 1:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,   GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,   GL_LINEAR);
    }
    //updateGL();
    this->initialize_all();
}



void GLWidget::genTexCoordsCylinder(void)
{
    if(texcoords) delete [] texcoords;
    texcoords = new QVector2D [this->n_points_sphere];

    double max_x = -1e10, min_x = 1e10;
    double max_y = -1e10, min_y = 1e10;

    for(unsigned int i = 0; i < this->n_points_sphere; i++)
    {
        if(this->verticesphere[i].x() > max_x) max_x = this->verticesphere[i].x();
        if(this->verticesphere[i].x() < min_x) min_x = this->verticesphere[i].x();
        if(this->verticesphere[i].y() > max_y) max_y = this->verticesphere[i].y();
        if(this->verticesphere[i].y() < min_y) min_y = this->verticesphere[i].y();
    }

    double u, v;
    for(unsigned int i = 0; i < this->n_points_sphere;i++)
    {
        double x = 2*(this->verticesphere[i].x() - min_x)/(max_x-min_x) - 1;
        u = ::acos(x)/(3.14);
        v = (this->verticesphere[i].y() - min_y)/(max_y-min_y);
        texcoords[i] = QVector2D(u,v);
    }
}



void GLWidget::genTexCoordsSpectral()
{
    //std::cerr << "Compile e adapte o codigo em: \n";
    //std::cerr << "http://www.riken.jp/brict/Yoshizawa/Research/Param.html" ;
   // reloadMatriz();
    if(texcoords){   delete [] texcoords;    texcoords = NULL;      }
    Polyhedron *mymesh = new Polyhedron();
    mymesh->readmesh(verticesphere,n_points_sphere,indicessphere,n_faces);
    mymesh->param();
    texcoords = new QVector2D [this->n_points_sphere];
    for(unsigned int i = 0; i < this->n_points_sphere;i++)    {

        texcoords[i] = QVector2D(mymesh->pU[i],mymesh->pV[i]);
    }

}

void GLWidget::genTexCoordsTriangles()
{

    if(texcoords) delete [] texcoords;
    texcoords = new QVector2D [this->n_points_sphere];

    for(unsigned int i = 0; i < this->n_points_sphere;i++)
    {
        texcoords[i] = QVector2D((i+1.0)/(n_points_sphere),(i+1.0)/(n_points_sphere));
    }
}

void GLWidget::genTexCoordsSphere(void)
{
    if(texcoords) delete [] texcoords;
    texcoords = new QVector2D [this->n_points_sphere];

    double u, v;
    for(unsigned int i = 0; i < this->n_points_sphere;i++)
    {
        //from - http://www.mvps.org/directx/articles/spheremap.htm
        u = ::asin(this->normalsphere[i].x())/3.14 + 0.5;
        v = ::asin(this->normalsphere[i].y())/3.14 + 0.5;

        texcoords[i] = QVector2D(u,v);
    }
}

//http://www.terathon.com/code/tangent.html

void GLWidget::genTangentFrames()
{
    if(tangents) delete [] tangents;

    tangents = new QVector4D[this->n_points_sphere];
    QVector3D *bitangents = new QVector3D[this->n_points_sphere];


    for (unsigned int i = 0; i < this->n_faces; i++)
    {
        unsigned int i1 = this->indicessphere[3*i];
        unsigned int i2 = this->indicessphere[3*i+1];
        unsigned int i3 = this->indicessphere[3*i+2];

        QVector4D v1 = this->verticesphere[i1];
        QVector4D v2 = this->verticesphere[i2];
        QVector4D v3 = this->verticesphere[i3];

        QVector2D w1 = this->texcoords[i1];
        QVector2D w2 = this->texcoords[i2];
        QVector2D w3 = this->texcoords[i3];

        double x1 = v2.x() - v1.x();
        double x2 = v3.x() - v1.x();
        double y1 = v2.y() - v1.y();
        double y2 = v3.y() - v1.y();
        double z1 = v2.z() - v1.z();
        double z2 = v3.z() - v1.z();

        double s1 = w2.x() - w1.x();
        double s2 = w3.x() - w1.x();
        double t1 = w2.y() - w1.y();
        double t2 = w3.y() - w1.y();

        double r = 1.0F / (s1 * t2 - s2 * t1);
        QVector3D sdir((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r,
                       (t2 * z1 - t1 * z2) * r);
        QVector3D tdir((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r,
                       (s1 * z2 - s2 * z1) * r);

        tangents[i1] += sdir;
        tangents[i2] += sdir;
        tangents[i3] += sdir;

        bitangents[i1] += tdir;
        bitangents[i2] += tdir;
        bitangents[i3] += tdir;
    }

    for (unsigned int a = 0; a < this->n_points_sphere; a++)
    {
        const QVector3D& n = normalsphere[a];
        const QVector4D& t = tangents[a];

        // Gram-Schmidt orthogonalize
        tangents[a] = (t - n * QVector3D::dotProduct(n, t.toVector3D())).normalized();

        // Calculate handedness
        double hand  = (QVector3D::dotProduct(QVector3D::crossProduct(n, t.toVector3D()), bitangents[a]) < 0.0F) ? -1.0F : 1.0F;
        tangents[a].setW(hand);
    }
    delete bitangents;
}




