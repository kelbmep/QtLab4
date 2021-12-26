#include "cube.h"
#include <math.h>
#include <bitset>

Cube::Cube()
{
    reset();
    setEdges();
}

void Cube::reset()
{
    std::bitset<3> bs = 0;
    for(int i = 0; i < 8; i++, bs = i)
        for(int j = 0; j < 3; j++)
            m_verts[i][j] = ((double)bs[j] - 0.5) * 2;

    cabinet(ALPHA);
}

void Cube::setEdges()
{
    m_edges[0] = {0,1};
    m_edges[1] = {0,2};
    m_edges[2] = {0,4};
    m_edges[3] = {1,3};
    m_edges[4] = {1,5};
    m_edges[5] = {2,3};
    m_edges[6] = {2,6};
    m_edges[7] = {3,7};
    m_edges[8] = {4,5};
    m_edges[9] = {4,6};
    m_edges[10] = {5,7};
    m_edges[11] = {6,7};
}

void Cube::rotate(double x, double y)
{
    for(int i = 0; i < 8; i++)
    {
        double temp1 = cos(x / 100) * m_verts[i][1] - sin(x / 100) * m_verts[i][2];
        m_verts[i][2] = sin(x / 100) * m_verts[i][1] + cos(x / 100) * m_verts[i][2];
        m_verts[i][1] = temp1;
        double temp2 = cos(y / 100) * m_verts[i][0] + sin(y / 100) * m_verts[i][2];
        m_verts[i][2] = -sin(y / 100) * m_verts[i][0] + cos(y / 100) * m_verts[i][2];
        m_verts[i][0] = temp2;
    }
    cabinet(ALPHA);
}

void Cube::cabinet(double alpha)
{
    for(int i = 0; i < 8; i++)
    {
        m_projection[i][0] = m_verts[i][0] + 0.5 * m_verts[i][2] * cos(alpha);
        m_projection[i][1] = m_verts[i][1] + 0.5 * m_verts[i][2] * sin(alpha);
        m_projection[i][2] = 0;
    }
}
