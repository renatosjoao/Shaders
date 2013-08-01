// per-fragment interpolated values from the vertex shader
varying  vec3 fN;
varying  vec3 fL;
varying  vec3 fE;
uniform vec4 AmbientProduct, DiffuseProduct, SpecularProduct;
uniform vec4 LightPosition;
uniform float Shininess;

void main(){
     vec3 N  = normalize(fN);
     vec3 L  = normalize(fL);
     vec3 E  = normalize(fE);
     vec3 H  = normalize(L+E);
    float Kd = max(dot(N,L),0.0);
    float dif;
    float levels = 3.0;
    float ScaleFactor = (1.0/levels);
    dif = floor(Kd*levels)*ScaleFactor;


    float Ks = pow(max(dot(H,N),0.0),Shininess);

    vec4 diffuse  = dif * DiffuseProduct;

    vec4 ambient  = AmbientProduct;

    vec4 specular = SpecularProduct;

    gl_FragColor = ambient + diffuse;
    gl_FragColor.a = 1.0;

}
