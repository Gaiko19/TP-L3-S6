#include "Mesh.h"
#include "Skeleton.h"
#include "Vec3.h"
#include <GL/gl.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

Vec3 Mesh::scalarToRGB( float scalar_value ) const //Scalar_value ∈ [0, 1] 
{
    Vec3 rgb;
    float H = scalar_value*360., S = 1., V = 0.85,
            P, Q, T,
            fract;

    (H == 360.)?(H = 0.):(H /= 60.);
    fract = H - floor(H);

    P = V*(1. - S);
    Q = V*(1. - S*fract);
    T = V*(1. - S*(1. - fract));

    if      (0. <= H && H < 1.)
        rgb = Vec3( V,  T,  P);
    else if (1. <= H && H < 2.)
        rgb = Vec3( Q,  V,  P);
    else if (2. <= H && H < 3.)
        rgb = Vec3( P,  V,  T);
    else if (3. <= H && H < 4.)
        rgb = Vec3( P,  Q,  V);
    else if (4. <= H && H < 5.)
        rgb = Vec3( T,  P,  V);
    else if (5. <= H && H < 6.)
        rgb = Vec3( V,  P,  Q);
    else
        rgb = Vec3( 0.,  0.,  0.);

    return rgb;
}

void Mesh::computeSkinningWeights( Skeleton & skeleton ) {
    //---------------------------------------------------//
    //---------------------------------------------------//
    // code to change :

    // Indications:
    // you should compute weights for each vertex w.r.t. the skeleton bones
    // so each vertex will have B weights (B = number of bones)
    //Don't forget to normalize weights
    // these weights shoud be stored in vertex.weights:

    for( unsigned int i = 0 ; i < vertices.size() ; ++i ) {
        double scalAD, scalAC, scalCD;
        double poidsTot = 0;
        double poids = 0;
        Vec3 A, B, C, vectAB, vectAC, CD;
        MeshVertex & vertex = vertices[ i ];
        vertex.weights.resize(skeleton.bones.size());
        for (unsigned int j = 0; j < skeleton.bones.size(); j++) {
            A = skeleton.articulations[skeleton.bones[j].joints[0]].position;
            B = skeleton.articulations[skeleton.bones[j].joints[1]].position;
            C = vertex.position;
            //vectAB = B - A;
            //vectAC = C - A;
            Vec3 proj = A + std::min(1.0, std::max<double>(0.0, Vec3::dot(C - A, B - A))) * (B - A);
            //scalAC = sqrt(vectAC[0]*vectAC[0] + vectAC[1]*vectAC[1] + vectAC[2]*vectAC[2]);
            //scalAD = (vectAB[0] * vectAC[0] + vectAB[1] * vectAC[1] + vectAB[2] * vectAC[2]) / scalAC;
            //CD = sqrt(scalAC*scalAC - scalAD*scalAD);
            CD = proj - C;
            scalCD = std::sqrt(CD[0]*CD[0]+CD[1]*CD[1]+CD[2]*CD[2]);
            poids = (1/scalCD)*(1/scalCD);
            poidsTot += poids;
            vertex.weights[j] = poids;

        }
        for (unsigned int j = 0; j < skeleton.bones.size(); j++) {
            vertex.weights[j] /= poidsTot;
        }

    }
    

    //---------------------------------------------------//
    //---------------------------------------------------//
    //---------------------------------------------------//
}

void Mesh::draw( int displayed_bone ) const {

    glEnable(GL_LIGHTING);
    glBegin (GL_TRIANGLES);
    for (unsigned int i = 0; i < triangles.size (); i++)
        for (unsigned int j = 0; j < 3; j++) {
            const MeshVertex & v = vertices[triangles[i].v[j]];
            if( displayed_bone >= 0 && v.weights.size() > 0 ){
                // code to change :

                // Indications:
                //Call the function scalarToRGB so that you get the same coloring as slide 51
                //Update the color from the Vec3 resulting color
                Vec3 foo = scalarToRGB(1. - v.weights[displayed_bone]);
                glColor3f(foo[0], foo[1], foo[2]);
            }
            glNormal3f (v.normal[0], v.normal[1], v.normal[2]);
            glVertex3f (v.position[0], v.position[1], v.position[2]);
        }
    glEnd ();
}

void Mesh::drawTransformedMesh( SkeletonTransformation & transfo ) const {
    std::vector< Vec3 > new_positions( vertices.size() );

    //---------------------------------------------------//
    //---------------------------------------------------//
    // code to change :
    for( unsigned int i = 0 ; i < vertices.size() ; ++i ) {
        Vec3 p = vertices[i].position;

        // Indications:
        // you should use the skinning weights to blend the transformations of the vertex position by the bones.
        // to update the position use the weight and the bone transformation
        // for each bone p'=R*p+t
        
        Vec3 R = transfo.bone_transformations[i].world_space_rotation;
        Mat3 T = transfo.bone_transformations[i].world_space_translation;
        new_positions[i] = p;
        
    }
    //---------------------------------------------------//
    //---------------------------------------------------//
    //---------------------------------------------------//

    glEnable(GL_LIGHTING);
    glBegin (GL_TRIANGLES);
    for (unsigned int i = 0; i < triangles.size (); i++)
        for (unsigned int j = 0; j < 3; j++) {
            const MeshVertex & v = vertices[triangles[i].v[j]];
            Vec3 p = new_positions[ triangles[i].v[j] ];
            glNormal3f (v.normal[0], v.normal[1], v.normal[2]);
            glVertex3f (p[0], p[1], p[2]);
        }
    glEnd ();
}

void Mesh::loadOFF (const std::string & filename) {
    std::ifstream in (filename.c_str ());
    if (!in)
        exit (EXIT_FAILURE);
    std::string offString;
    unsigned int sizeV, sizeT, tmp;
    in >> offString >> sizeV >> sizeT >> tmp;
    vertices.resize (sizeV);
    triangles.resize (sizeT);
    for (unsigned int i = 0; i < sizeV; i++)
        in >> vertices[i].position;
    int s;
    for (unsigned int i = 0; i < sizeT; i++) {
        in >> s;
        for (unsigned int j = 0; j < 3; j++)
            in >> triangles[i].v[j];
    }
    in.close ();
    recomputeNormals ();
}

void Mesh::recomputeNormals () {
    for (unsigned int i = 0; i < vertices.size (); i++)
        vertices[i].normal = Vec3 (0.0, 0.0, 0.0);
    for (unsigned int i = 0; i < triangles.size (); i++) {
        Vec3 e01 = vertices[triangles[i].v[1]].position -  vertices[triangles[i].v[0]].position;
        Vec3 e02 = vertices[triangles[i].v[2]].position -  vertices[triangles[i].v[0]].position;
        Vec3 n = Vec3::cross (e01, e02);
        n.normalize ();
        for (unsigned int j = 0; j < 3; j++)
            vertices[triangles[i].v[j]].normal += n;
    }
    for (unsigned int i = 0; i < vertices.size (); i++)
        vertices[i].normal.normalize ();
}
