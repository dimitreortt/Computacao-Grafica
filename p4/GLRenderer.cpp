//[]---------------------------------------------------------------[]
//|                                                                 |
//| Copyright (C) 2018, 2019 Orthrus Group.                         |
//|                                                                 |
//| This software is provided 'as-is', without any express or       |
//| implied warranty. In no event will the authors be held liable   |
//| for any damages arising from the use of this software.          |
//|                                                                 |
//| Permission is granted to anyone to use this software for any    |
//| purpose, including commercial applications, and to alter it and |
//| redistribute it freely, subject to the following restrictions:  |
//|                                                                 |
//| 1. The origin of this software must not be misrepresented; you  |
//| must not claim that you wrote the original software. If you use |
//| this software in a product, an acknowledgment in the product    |
//| documentation would be appreciated but is not required.         |
//|                                                                 |
//| 2. Altered source versions must be plainly marked as such, and  |
//| must not be misrepresented as being the original software.      |
//|                                                                 |
//| 3. This notice may not be removed or altered from any source    |
//| distribution.                                                   |
//|                                                                 |
//[]---------------------------------------------------------------[]
//
// OVERVIEW: GLRenderer.cpp
// ========
// Source file for OpenGL renderer.
//
// Author(s): Paulo Pagliosa (and your name)
// Last revision: 09/09/2019

#include "GLRenderer.h"

namespace cg
{ // begin namespace cg


//////////////////////////////////////////////////////////
//
// GLRenderer implementation
// ==========
void
GLRenderer::update()
{
  Renderer::update();
  // TODO
}

void
GLRenderer::render()
{
  //const auto& bc = _scene->backgroundColor;
  auto program = GLSL::Program::current();
  const auto& bc = _scene->backgroundColor;

  glClearColor(bc.r, bc.g, bc.b, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  auto ec = this->camera();
  const auto& p = ec->transform()->position();
  auto vp = vpMatrix(ec);

  program->setUniformMat4("vpMatrix", vp);
  program->setUniformVec4("ambientLight", _scene->ambientLight);
  program->setUniformVec3("cameraPosition", ec->transform()->position());

  renderObjectTree(_scene->root());
 }

inline void
GLRenderer::drawMesh(GLMesh* mesh, GLuint mode)
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glDrawElements(GL_TRIANGLES, mesh->vertexCount(), GL_UNSIGNED_INT, 0);
}

inline void
GLRenderer::drawPrimitive(Primitive& primitive)
{
	auto program = GLSL::Program::current();

	auto m = glMesh(primitive.mesh());

	if (nullptr == m)
		return;

	auto t = primitive.transform();
	auto normalMatrix = mat3f{ t->worldToLocalMatrix() }.transposed();

	// sets material features to the shader
	auto pm = primitive.material;
	program->setUniformVec4("m.Oa", pm.ambient);
	program->setUniformVec4("m.Od", pm.diffuse);
	program->setUniformVec4("m.Os", pm.spot);
	program->setUniform("m.Ns", pm.shine);

	program->setUniformMat4("transform", t->localToWorldMatrix());
	program->setUniformMat3("normalMatrix", normalMatrix);

	m->bind();
	drawMesh(m, GL_FILL);
	drawMesh(m, GL_LINE);
}

void GLRenderer::renderObjectTree(SceneObject* obj)
{
	//std::cout <<"\nentrei0 ";
	for (const auto& o : obj->children())
	{
		if (!o->visible)
			continue;

		for (auto component : o->components())
			if (auto p = dynamic_cast<Primitive*>(component))
				drawPrimitive(*p);

		renderObjectTree(o);
	}
}

} // end namespace cg
