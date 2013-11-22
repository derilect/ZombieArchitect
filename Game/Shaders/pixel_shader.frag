uniform sampler2D texture;

void main()
{
    // lookup the pixel in the texture
    vec3 pixel = texture2D(texture, gl_TexCoord[0].xy).rgb;

    // multiply it by the color
	gl_FragColor = vec4(pixel.r,pixel.g,pixel.b,1.0);
    gl_FragColor = max(pixel.r, max(pixel.g, pixel.b));
}