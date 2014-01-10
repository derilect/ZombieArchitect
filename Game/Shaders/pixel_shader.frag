uniform sampler2D texture;

void main()
{

    // lookup the pixel in the texture
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    // multiply it by the color

	gl_FragColor = vec4(0,0,1, 1);


//	gl_FragColor = vec4(pixel.r,pixel.g,pixel.b,pixel.a);

}