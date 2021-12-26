#ifndef CUBE_H
#define CUBE_H
#include<array>

typedef std::array<double, 3> point_t;
typedef std::array<point_t, 8> cube_t;

class Cube
{
    const double ALPHA = 1.5;

public:
    Cube();

    void reset();
    void setEdges();
    void rotate(double x, double y);
    void cabinet(double alpha);

    cube_t m_projection;
    std::array<std::pair<int, int>, 12> m_edges;
    cube_t m_verts;
};

#endif // CUBE_H
