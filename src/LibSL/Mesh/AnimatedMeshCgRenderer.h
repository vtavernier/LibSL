/* --------------------------------------------------------------------
Author: Sylvain Lefebvre    sylvain.lefebvre@sophia.inria.fr

                  Simple Library for Graphics (LibSL)

This software is a computer program whose purpose is to offer a set of
tools to simplify programming real-time computer graphics applications
under OpenGL and DirectX.

This software is governed by the CeCILL-C license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL-C
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-C license and that you accept its terms.
-------------------------------------------------------------------- */
// ------------------------------------------------------
// LibSL::AnimatedMeshCgRenderer
// ------------------------------------------------------
//
// Cg renderer for animated meshes
//
// Fragment program can be customized by giving a code string
// to the constructor. The fp entry point must be named 'fp_animatedmesh'
// 
// ------------------------------------------------------
// Sylvain Lefebvre - 2006-08-09
// ------------------------------------------------------

#pragma once

#include <LibSL/LibSL.common.h>

#include <LibSL/Mesh/AnimatedMesh.h>
#include <LibSL/Mesh/AnimatedMeshController.h>

#include <LibSL/CgHelpers/CgHelpers.h>
#include <LibSL/GPUMesh/GPUMesh.h>

namespace LibSL {
  namespace Mesh {

    class LIBSL_DLL AnimatedMeshCgRenderer
    {
    private:

      typedef LibSL::Math::m4x4f m4x4f;
      typedef LibSL::Math::quatf quatf;
      typedef LibSL::Math::v2f   v2f;
      typedef LibSL::Math::v3f   v3f;

    public:

      typedef LibSL::Memory::Pointer::AutoPtr<AnimatedMeshCgRenderer> t_AutoPtr;
      typedef MVF5(
        mvf_position_3f,
        mvf_normal_3f,
        mvf_texcoord0_2f,
        mvf_texcoord1_3f,
        mvf_texcoord2_4f) mvf_SkinnedMesh;
      typedef GPUMesh::GPUMesh_Indexed_VertexBuffer<mvf_SkinnedMesh,ushort> SkinnedMesh;

    protected:

      LibSL::CgHelpers::CgShader    m_cgShader;
      LibSL::CgHelpers::CgParameter m_cgViewProj;
      LibSL::CgHelpers::CgParameter m_cgSkeletonMatrices[LIBSL_ANIMATEDMESH_MAX_MATRICES];
      //LibSL::CgHelpers::CgParameter m_cgSkeletonMatricesArray;

      LibSL::Memory::Pointer::AutoPtr<SkinnedMesh> m_SkinnedMesh;

      LibSL::Mesh::AnimatedMesh_Ptr m_AnimatedMesh;

    public:

      AnimatedMeshCgRenderer(LibSL::Mesh::AnimatedMesh_Ptr,const char *custom_code=NULL);
      ~AnimatedMeshCgRenderer();

      void render(const AnimatedMeshController& controller);

      LibSL::CgHelpers::CgShader& shader() {return (m_cgShader);}

    };

    /// autoptr for AnimatedMeshCgRenderer
    typedef AnimatedMeshCgRenderer::t_AutoPtr AnimatedMeshCgRenderer_Ptr;

  } //namespace LibSL::Mesh
} //namespace LibSL
