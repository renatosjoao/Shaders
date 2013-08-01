attribute  vec4 vPosition;
attribute  vec3 vNormal;
varying vec4 color;

uniform vec4 AmbientProduct, DiffuseProduct, SpecularProduct;
uniform mat4 ModelView;
uniform mat3 NormalMatrix;
uniform mat4 Projection;
uniform vec4 LightPosition;
uniform float Shininess;

void main()
{

    vec3 pos = (ModelView * vPosition).xyz;

//L - posicao da luz; E - observador; H - refletor da luz
    vec3 L = normalize( (LightPosition).xyz - pos );
    vec3 E = normalize( -pos );
    vec3 H = normalize( L + E );

//N - vetor normal
    vec3 N = normalize(NormalMatrix*vNormal);


// Calculando os termos da equacao de iluminacao
    vec4 ambient = AmbientProduct;

    float Kd = max( dot(L, N), 0.0 );
    vec4  diffuse = Kd*DiffuseProduct;

    float Ks = pow( max(dot(N, H), 0.0), Shininess );
    vec4  specular = Ks * SpecularProduct;
    if( dot(L, N) < 0.0 ) {
        specular = vec4(0.0, 0.0, 0.0, 1.0);
    }

    gl_Position = Projection * ModelView * vPosition;

//a cor final é a combinacao da iluminacao ambiente, difusa e especular (quanto a luz absorve, quanto é refletida
    color = ambient + diffuse + specular;
    color.a = 1.0;
}
