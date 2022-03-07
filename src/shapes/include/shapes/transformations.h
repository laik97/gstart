
#define PI 3.14159265359

enum class Transformations
{
  radians,
  degrees,
  global,
  local,
};

class Transformation
{
  public:
  template<Transformations from, Transformations to, typename type>
  static void transform(type*);
};

template<>
void Transformation::transform<Transformations::radians, Transformations::degrees>(
    float* angle)
{
  *angle = (*angle / PI) * 180;
}

template<>
void Transformation::transform<Transformations::degrees, Transformations::radians>(
    float* angle)
{
  *angle = (*angle / 180.0) * PI;
}