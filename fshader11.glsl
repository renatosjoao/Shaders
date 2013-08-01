// Altura

varying  float y;

uniform vec4 AmbientProduct, DiffuseProduct;
uniform float alturaMax, alturaMin;


void main()
{
    float dif = (alturaMax - alturaMin);
    float kd =(y-alturaMin)/dif;

    float levels = 4.0;
    float scaleFactor = 1.0/levels;

    vec4 ambient  = AmbientProduct;

    float f = floor(levels*kd);
    vec4 diffuse  = f*DiffuseProduct*scaleFactor;

    gl_FragColor = ambient + diffuse;
    gl_FragColor.a = 1.0;

}
