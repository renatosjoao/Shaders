attribute   vec4 vPosition;
attribute   vec3 vNormal;

varying  vec3 fN;
varying  vec3 fE;
varying  vec3 fL;

uniform mat4 ModelView;
uniform mat3 NormalMatrix;
uniform vec4 LightPosition;
uniform mat4 Projection;


void main()
{
 gl_Position = Projection*ModelView * vPosition;

 vec4 eyePosition = ModelView * vPosition;
 vec4 eyeLightPos = LightPosition;
 fN = NormalMatrix * vNormal;
 fL = eyeLightPos.xyz - eyePosition.xyz;
 fE = -eyePosition.xyz;
}
