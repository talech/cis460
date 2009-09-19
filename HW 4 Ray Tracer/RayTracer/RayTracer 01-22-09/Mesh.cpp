/*****************************
Tamara Levy
CIS 460
October 23, 2008
SceneGraph - Room Editor
******************************/


#include "Mesh.h"
#include <iostream>


Mesh::Mesh(){}

void
Mesh::addVertex(vec3 v){
	vertices.push_back(v);
}

void
Mesh::addNormal(vec3 vn){
	normals.push_back(vn);
	/*std::cout<<"Mesh: \nNormal x = "<<normals[normals.size()-1][0]<<std::endl;
	std::cout<<"Normal y = "<<normals[normals.size()-1][1]<<std::endl;
	std::cout<<"Normal z = "<<normals[normals.size()-1][2]<<"\n"<<std::endl;*/
}

void
Mesh::addFace(vector<vec2> f){
	faces.push_back(f);
	/*for(int i=0; i<f.size(); i++){
		std::cout<<"Face : vert: "<<f[i][0]<<" norm: "<<f[i][1]<<std::endl;
	}*/
}

//iterates faces to draw the corresponding mesh
void
Mesh::drawMesh(){
	
	GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_NORMALIZE);
	
			
	// draw mesh
	
	//std::cout<<"Faces = "<<faces.size()<<std::endl;
	for(int i=0; i<faces.size();i++){
		//std::cout<<"******\nFace i = "<<i<<std::endl;
		
		int index = faces[i][0][1];
		vec3 c(0,0,0);
		

		
		glBegin(GL_POLYGON);
		/*std::cout<<"Normal x : "<<i<<"= "<<normals[index][0]<<std::endl;
		std::cout<<"Normal y : "<<i<<"= "<<normals[index][1]<<std::endl;
		std::cout<<"Normal z : "<<i<<"= "<<normals[index][2]<<"\n"<<std::endl;*/
		glNormal3f(normals[index][0],normals[index][1],normals[index][2]);
		//std::cout<<"Faces intern = "<<faces[1].size()<<std::endl;
		for(int j = 0; j<faces[i].size();j++){
			/*std::cout<<"Face j = "<<j<<std::endl;
			std::cout<<"Vector x : "<<i<<"= "<<vertices[faces[i][j][0]][0]<<std::endl;
			std::cout<<"Vector y : "<<i<<"= "<<vertices[faces[i][j][0]][1]<<std::endl;
			std::cout<<"Vector z : "<<i<<"= "<<vertices[faces[i][j][0]][2]<<"\n"<<std::endl;*/
			
			glVertex3f(vertices[faces[i][j][0]][0],vertices[faces[i][j][0]][1],vertices[faces[i][j][0]][2]);
			c[0] = c[0] + vertices[faces[i][j][0]][0];
			c[1] = c[1] + vertices[faces[i][j][0]][1];
			c[2] = c[2] + vertices[faces[i][j][0]][2];
		}
		glEnd();

		c[0] = c[0]/faces[i].size();
		c[1] = c[1]/faces[i].size();
		c[2] = c[2]/faces[i].size();
		//draw normals to debug
		/*glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
		glBegin(GL_LINES);
			glVertex3f(c[0],c[1],c[2]);
			glVertex3f(c[0]+normals[index][0],c[1]+normals[index][1],c[2]+normals[index][2]);
		glEnd();*/
	}
	


}