
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <string>
#include <iostream>
#include <QTimer>

#include <trackball.h>
#include <QGLShader>
#include <QGLShaderProgram>
#include <QGLBuffer>
#include <QMessageBox>
#include <qmath.h>
#include <QVector4D>
#include <QKeyEvent>
#include <iostream>
#include <QMatrix4x4>
#include <fstream>

#include <camera.h>
#include <light.h>
#include <material.h>

#include <QTextStream>
#include <QFile>
#include <QResource>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
    
    GLfloat left;
    GLfloat right;
    GLfloat bottom;
    GLfloat top;
    GLfloat zNearOrtho;
    GLfloat zFarOrtho;
    GLfloat fovy;  // Field-of-view in Y direction angle (in degrees)
    GLfloat aspect;       // Viewport aspect ratio
    GLfloat zNearPerspec;
    GLfloat zFarPerspec;

signals:
    
public slots:

    void getR(double);
    void getG(double);
    void getB(double);

    void set_projection(int p);
    void set_example(int);
    //void set_example();
    void set_shine(double);
    void animate();

    void mudaCorFundoR(double);
    void mudaCorFundoG(double);
    void mudaCorFundoB(double);

    void setEyeX(double);
    void setEyeY(double);
    void setEyeZ(double);
    void setLookAtX(double);
    void setLookAtY(double);
    void setLookAtZ(double);
    void setUpX(double);
    void setUpY(double);
    void setUpZ(double);

    void loadsphere();

    void setLeft(double);
    void setRight(double);
    void setBottom(double);
    void setTop(double);
    void setNearOrtho(double);
    void setFarOrtho(double);
    void setNearPerspec(double);
    void setFarPerspec(double);
    void setFovy(double);


    void grabLightXPosition(double);
    void grabLightYPosition(double);
    void grabLightZPosition(double);
    void grabLightWPosition(double);    

    void setAmbientR(double);
    void setAmbientG(double);
    void setAmbientB(double);

    void setDiffuseR(double);
    void setDiffuseG(double);
    void setDiffuseB(double);

    void setSpecularR(double);
    void setSpecularG(double);
    void setSpecularB(double);


    void set_texture(int);
    void set_texture();
    void set_coordinate_textures(int);
    void set_coordinate_textures();

    void set_texture_mode(int);
    void set_texture_mode();

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);
    void initshaders();
    void createScene();


    double m_distExp;
    virtual void wheelEvent(QWheelEvent * event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

    void reloadMatriz();

    void setshaders(std::string const &s1, std::string const & s2);

    void sphere();
    void build_normal_vertices_sphere();
    void build_normal_faces_sphere();

    void initialize_example1();
    void initialize_example2();
    void initialize_flat();
    void initialize_phong();
    void initialize_phong_modificado();
    void initialize_Gouraud();
    void initialize_toon();
    void initialize_toon2();
    void initialize_shadingY();
    void initialize_tex1();
    void initialize_tex2();
    void initialize_tex3();

    void execute_example_1(void);
    void execute_example_2(void);
    void execute_flat(void);
    void execute_phong(void);
    void execute_phong_modificado(void);
    void execute_shadingY(void);
    void execute_Gouraud(void);
    void execute_toon(void);
    void execute_toon2(void);
    void execute_tex1(void);
    void execute_tex2(void);
    void execute_tex3(void);

    void initialize_example();
    void initialize_all();


    void genTexCoordsCylinder();
    void genTexCoordsSphere();
    void genTexCoordsSpectral();
    void genTexCoordsTriangles();

    void genTangentFrames();


    QVector4D *verticesphere, *verticesphere_aux;
    QVector3D *normalsphere;
    unsigned int *indicessphere, *indicessphere_aux, n_points_sphere, n_faces;

    QVector3D eye;
    QVector3D at;
    QVector3D up;

    QMatrix4x4  Projection, ModelView;
    QMatrix3x3 NormalMatrix; // transpose_inverse_modelview

    QGLShader *m_vertexShader;
    QGLShader *m_fragmentShader;
    QGLShaderProgram *m_shaderProgram;

    QGLBuffer *m_vboVertices;
    QGLBuffer *m_vboNormals;
    QGLBuffer *m_vboColors;
    QGLBuffer *m_vboIndices;

    QGLBuffer *m_vbo_texcoords;
    //bi-tangents can be avoided, as it can be done on shader
    QGLBuffer *m_vbo_tangents;

    QImage texColor, texNormal;
    QImage cube_img[6];

    Camera camera;
    Light light;
    Material material;

    char exemplo;
    QString file;
    bool iscullface;
    float rotatey;
    float dx,dy,dz,r1,g1,b1;
    double r,g,b,lx,ly,lz,lw, ambR,ambG,ambB,difR,difG,difB,specR,specG,specB;
    float max_y,min_y;
    int projectiontype;
    bool isfile;
    int example_index, texture_index, coordinate_texture_index, texture_mode;
    int tx_id[7];

    QVector4D *tangents;
    QVector2D *texcoords;

     QVector4D lightposition;

};

#endif // GLWIDGET_H
