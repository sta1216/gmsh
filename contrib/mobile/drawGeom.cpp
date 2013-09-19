#if !defined(BUILD_ANDROID)
#define BUILD_IOS 1
#endif

#if defined(BUILD_IOS)
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>

#include <Gmsh/Gmsh.h>
#include <Gmsh/GModel.h>
#endif

#if defined(BUILD_ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>

#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/PView.h>
#include <gmsh/Context.h>
#endif

#include "drawContext.h"

void drawGeomVertex(GVertex *v)
{
	if(!v->getVisibility()) return;
	if(v->geomType() == GEntity::BoundaryLayerPoint) return;

	unsigned int col = CTX::instance()->color.geom.point;
	glColor4ub((GLubyte)CTX::instance()->unpackRed(col),
               (GLubyte)CTX::instance()->unpackGreen(col),
               (GLubyte)CTX::instance()->unpackBlue(col),
               (GLubyte)CTX::instance()->unpackAlpha(col));
	const GLfloat p[] = {(GLfloat)v->x(), (GLfloat)v->y(), (GLfloat)v->z()};
	glPointSize((GLfloat)CTX::instance()->geom.pointSize);
	glVertexPointer(3, GL_FLOAT, 0, p);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPointSize(1);
}
void drawGeomEdge(GEdge *e)
{
	if(!e->getVisibility()) return;
	if(e->geomType() == GEntity::DiscreteCurve) return;
	if(e->geomType() == GEntity::PartitionCurve) return;
	if(e->geomType() == GEntity::BoundaryLayerCurve) return;

	unsigned int col = CTX::instance()->color.geom.line;
	glColor4ub((GLubyte)CTX::instance()->unpackRed(col),
               (GLubyte)CTX::instance()->unpackGreen(col),
               (GLubyte)CTX::instance()->unpackBlue(col),
               (GLubyte)CTX::instance()->unpackAlpha(col));
	int N = e->minimumDrawSegments() + 1;
	Range<double> t_bounds = e->parBounds(0);
	double t_min = t_bounds.low();
	double t_max = t_bounds.high();

	// Create a VA for this edge
	GLfloat *edge = (GLfloat *) malloc(N*3*sizeof(GLfloat));
		
	for(unsigned int i=0; i < N; i++) {
		double t = t_min + (double)i / (double)(N-1) * (t_max - t_min);
		GPoint p = e->point(t);
		edge[i*3] = p.x(); edge[i*3+1] = p.y(); edge[i*3+2] = p.z();
	}
	// Then print the VA
	glLineWidth((GLfloat)CTX::instance()->geom.lineWidth);
	glVertexPointer(3, GL_FLOAT, 0, edge);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_LINE_SMOOTH);
	glDrawArrays(GL_LINE_STRIP, 0, N);
	glDisable(GL_LINE_SMOOTH);
	glDisableClientState(GL_VERTEX_ARRAY);
	free(edge);
}
void drawGeomFace(GFace *f)
{
	// TODO
}
void drawContext::drawGeom()
{
	for(unsigned int i=0; i<GModel::list.size(); i++) {
		GModel *m = GModel::list[i];
		if(!m->getVisibility()) continue;
		if(CTX::instance()->geom.points || CTX::instance()->geom.pointsNum)
			std::for_each(m->firstVertex(), m->lastVertex(), drawGeomVertex);
		if(CTX::instance()->geom.lines || CTX::instance()->geom.linesNum || CTX::instance()->geom.tangents)
			std::for_each(m->firstEdge(), m->lastEdge(), drawGeomEdge);
		if(CTX::instance()->geom.surfaces || CTX::instance()->geom.surfacesNum || CTX::instance()->geom.normals)
			std::for_each(m->firstFace(), m->lastFace(), drawGeomFace);

	}
}


