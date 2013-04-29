varying vec3 lightDir;
varying vec3 viewDir;
uniform sampler3D volume;
uniform sampler2D lut;
uniform int width;
uniform int height;
uniform int depth;

vec3 computeGradient()
{
	//samples for forward differences
    vec3 sample1;
    vec3 sample2;
	vec4 offset = vec4(1.0/width, 1.0/height, 1.0/depth, 0.0);
    sample1.x = texture3D(volume, gl_TexCoord[0].xyz-offset.xww).x;
    sample2.x = texture3D(volume, gl_TexCoord[0].xyz+offset.xww).x;
    sample1.y = texture3D(volume, gl_TexCoord[0].xyz-offset.wyw).x;
    sample2.y = texture3D(volume, gl_TexCoord[0].xyz+offset.wyw).x;
    sample1.z = texture3D(volume, gl_TexCoord[0].xyz-offset.wwz).x;
    sample2.z = texture3D(volume, gl_TexCoord[0].xyz+offset.wwz).x;

    //central differences gradient
    return normalize(gl_NormalMatrix*(sample2 - sample1));	
}

vec4 shading(vec3 N, vec3 V, vec3 L, vec4 color)
{
    // ambient
    vec3 Ka = vec3(0.3, 0.3, 0.3);
    // diffuse
    vec3 Kd = vec3(0.6, 0.6, 0.6);
    // specular
    vec3 Ks = vec3(0.1, 0.1, 0.1);
    float n = 128.0;
        
    vec3 H = normalize(vec3(gl_LightSource[0].halfVector));
    
    vec3 ambient = Ka * color.rgb;
    
    float diffuseLight = max(dot(L, N), 0.0);
    vec3 diffuse = Kd * color.rgb * diffuseLight;
    
    float specularLight = pow(max(dot(H, N), 0.0), n);
    vec3 specular = Ks * color.a * specularLight;
    
    vec4 result;
    result.rgb = ambient + diffuse + specular;
    result.a = color.a;

    return result;
}

void main()
{
	float density = texture3D(volume, gl_TexCoord[0].xyz).x;
	
	float index = density * 65536.0;
	vec2 index2;
	index2.x = mod(index, 256.0);
	index2.y = floor(index/256.0);
	index2 /= vec2(256.0, 256.0);
	index2 = vec2(density, 0.5);
	vec4 color = texture2D(lut, index2);
	
	vec3 gradient = computeGradient();
	
	gl_FragColor = shading(gradient, viewDir, normalize(vec3(gl_LightSource[0].position)), color);
}