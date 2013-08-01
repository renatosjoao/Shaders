attribute   vec4 vPosition;
attribute   vec3 vNormal;
attribute   vec4 vTangent;
attribute   vec2 vTexCoords;

varying  vec2 st;
varying  vec3 fE;
varying  vec3 fL;

uniform mat4 ModelView;
uniform mat3 NormalMatrix;
uniform vec4 LightPosition;
uniform mat4 Projection;


void main()
{
    vec3 bitangent = vTangent.w*cross(vNormal,vTangent.xyz);

    gl_Position = Projection*ModelView * vPosition;

    vec4 eyePosition = ModelView * vPosition;
    vec4 eyeLightPos =  LightPosition;

    vec3 T = NormalMatrix * vTangent.xyz;

    vec3 B = NormalMatrix * bitangent;
    vec3 N = NormalMatrix * vNormal;

    mat3 TBN = mat3(T.x,B.x,N.x,
                   T.y,B.y,N.y,
                   T.z,B.z,N.z);

     fL = TBN*(eyeLightPos.xyz - eyePosition.xyz);

     fE = TBN*(-eyePosition.xyz);

     st = vTexCoords;

}
