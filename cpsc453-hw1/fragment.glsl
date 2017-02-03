#version 410

in vec4 colour;
in vec2 coords;

uniform vec2 center = vec2(0.0, 0.0);

out vec4 FragmentColour;

void main() {
  float dist = distance(coords, center);
  //vec2 delta =(coords - center);
  //float angle = atan(delta.x, delta.y);
  FragmentColour = vec4(pow(colour.r, dist),
                        pow(colour.g, dist),
                        pow(colour.b, dist), 1.0);
}
