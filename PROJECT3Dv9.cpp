#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <math.h>
#include <cmath>
/*
GLfloat qaBlack[]={0,0,0,1};
GLfloat qaGreen[]={0,1,0,1};
GLfloat qaWhite[]={1,1,1,1};
glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
glMaterialf(GL_FRONT, GL_SHININESS, 60);
*/
float a1 = 0, b1 =2, c1 = 0;
//float a = 0, b =2, c = 0;

float camTarX = -3.0f;
float camTarY = -2;
float camTarZ = -14.1;

float camDirectionX = 0;
float camDirectionY = 1;
float camDirectionZ = 0;

/*
float a1 = 0, b1 =2, c1 = 0;
//float a = 0, b =2, c = 0;

float camTarX = 0.0f;
float camTarY = -0.9;
float camTarZ = -14.1;

float camDirectionX = 0;
float camDirectionY = 1;
float camDirectionZ = 0;
*/
//GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
//GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */

// Requests to draw the next frame.
void timer(int v) {
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, v);
}

void special(int key, int, int) {
  switch (key) 
{
	  
    case GLUT_KEY_LEFT: if(a1 > -5)a1 -= 0.3; break;
    case GLUT_KEY_RIGHT: if(a1 < 5)a1 += 0.3; break;
    case GLUT_KEY_UP: if (b1 < 5)b1 += 0.3; break;
    case GLUT_KEY_DOWN: if (b1> 0) b1-= 0.3; break;
  }
  glutPostRedisplay();
}
/*
GLfloat WHITE[] = {1, 1, 1};
GLfloat RED[] = {1, 0, 0};
GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};
*/
float leavesx[100];
float leavesy[100];
float leavesz[100];

void randMake()
{
	for(int i = 0; i< 100; i++)
	{
		//glRotatef(90,(rand()%100)*.001,(rand()%100)*.001,(rand()%100)*.001);
		leavesx[i]=(rand()%100)*.001;
		leavesy[i]=(rand()%100)*.001;
		leavesz[i]=(rand()%100)*.001;
	}
}



void display();
void reshape(int, int);
void init()//initial settings
{
	/*
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat amLit[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat difLit[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat specLit[] = {1,1,1, 1.0};
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, amLit);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difLit);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specLit);

	GLfloat qaLightPosition[]={.5,.5,0,1};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
	*/
	/* Enable a single OpenGL light. *//*
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
	*/
  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
	/*
  glEnable(GL_DEPTH_TEST);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
  glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
	*/
	//glClearColor(0.0, 0.0, 0.0, 1.0);//set default "no color" color; red, green, blue, opacity; black is all zeros
	//glColor3f(1.0,1.0,1.0);//to use glColor4 aka red, green, blue, alpha, must also change initDisplayMode to GLUT_RGBA
	
	randMake();
}

int main(int argc, char**argv)//required arguments
{
	//**Initial Settings*****
	glutInit(&argc, argv);//required
	glutInitDisplayMode(GLUT_RGB);//display mode: red, green, blue
	glutInitWindowPosition(200, 200);//placement of window on desktop; no argument = random position
	glutInitWindowSize(500, 500);//window size: width, height
	glutCreateWindow("Project Scenery");//Create window, input name
	//***********************
	//Callback functions below:
	glutDisplayFunc(display);//input name of function to run when window starts
	glutReshapeFunc(reshape);//
	glutSpecialFunc(special);
	glutTimerFunc(100, timer, 0);
	init();
	//---------------------------
	glutMainLoop();//must have callback functions to start
}

void drawLine (GLint x, GLint y, GLint a, GLint b)
{
	glBegin (GL_LINES);  //draws one line
		glVertex3f (x, -1, y);    // between 2 vertices
		glVertex3f (a, -1, b);
	glEnd ();
 }
 
 void drawOrigin ()
{
	glPointSize(8);
	glColor3f(1,1,1); //Up/Down
	glBegin (GL_LINES);  //draws one line
		glVertex3f (0, 100, -5);    // between 2 vertices
		glVertex3f (0, -100, -5); //orthogonal to xz plane
	glEnd ();
	glColor3f(1,0.5,.5);//left/right
	glBegin (GL_LINES);  //draws one line
		glVertex3f (100, 1, -5);    // between 2 vertices
		glVertex3f (-100, 1, -5); //orthogonal to yz plane
	glEnd ();
	glColor3f(1,.1,.1);//back/forth
	glBegin (GL_LINES);  //draws one line
		glVertex3f (0,1, -100);    // between 2 vertices
		glVertex3f (0, 1, 100); //orthogonal to xy plane
	glEnd ();
	glColor3f(0,0,0);
	glPointSize(1);
 }
 
 void shade()
 {
	//glColor3f(0.698, 0.639, .423); //178 163 108 : vanilla
	glColor3f(0.568, 0.529, .494); //145 135 126
	glPushMatrix();
	glTranslatef(0,-.3,-5);
	glRotatef(-90, 1,0,0);
	glBegin(GL_QUADS);
		glVertex3f( 2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f, -0.7f, 0.0f);
		glVertex3f( 2.0f, -0.7f, 0.0f);
	glEnd();
	glPopMatrix();
	
	glColor3f(0.568, 0.529, .494); //145 135 126
	glPushMatrix();
	glTranslatef(0,0,-5);
	glRotatef(-60, 1,0,0);
	glBegin(GL_QUADS);
		glVertex3f( 2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f, -0.7f, 0.0f);
		glVertex3f( 2.0f, -0.7f, 0.0f);
	glEnd();
	glRotatef(-180, 1,0,0);
	glBegin(GL_QUADS);
		glVertex3f( 2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f,  0.7f, 0.0f);
		glVertex3f(-2.0f, -0.7f, 0.0f);
		glVertex3f( 2.0f, -0.7f, 0.0f);
	glEnd();
	glPopMatrix();
 }

 //Creates a grid on floor
void grid(GLint negX, GLint posX, GLint negY, GLint posY)
{
	glColor3f(0.0,0.0,0.0);
	for(int i = negX; i < posX; i++)
	{
		drawLine(i, negY, i, posY);
	}
	for(int j = negY; j < posY; j++)
	{
		drawLine(negX, j, posX, j);
	}
}

void grass()
{
	glPushMatrix();
	glRotatef(-10,0,1,0);
	glTranslatef(0,0,2);
	glScalef(2,1,1);
	glBegin(GL_QUADS);
	// Bottom face (y = -1.0f)
	//glColor3f(0.698, 0.639, .423); //178 163 108 : vanilla
	glColor3f(0.462, 0.541, .262); //118 138 67
	glVertex3f( -10.0f, -1.1f,  10.0f);
	glVertex3f( -10.0f, -0.9f,  -10.0f);
	glVertex3f( 10.0f, -1.1f,  -10.0f);
	glVertex3f( 10.0f, -1.1f,  10.0f);
 
	glEnd();
	glPopMatrix();
}

void road()
{
	glBegin(GL_QUADS);
	glColor3f(0.415, 0.345, .329); //106 88 84 : rocky road
	glVertex3f( -20.0f, -1.1f,  -30.0f);
	glVertex3f( -20.0f, -0.9f,  0.0f);
	glVertex3f( 20.0f, -1.1f,  0.0f);
	glVertex3f( 20.0f, -1.1f,  -30.0f);
 
	glEnd();
	//glFlush();
}

void sidewalk()
{
	//glColor3f(0.658,0.658,0.658);//168 168 168
	//glColor3f(0.423,0.392,0.321);//108 100 89
	glColor3f(0.76,0.662,0.541);//194 169 138
	glRotatef(40, 0.0f, 1.0f, 0.0f);// angle, x, y ,z
	glBegin(GL_QUADS);
	// Bottom face (y = -1.0f)
	//glColor3f(0.698, 0.639, .423); //178 163 108 : vanilla
	glVertex3f( -10.0f, -1.1f, 2.0f);
	glVertex3f( -10.0f, -0.9f,  -1.6f);
	glVertex3f( 10.0f, -1.1f,  2.0f);
	glVertex3f( 10.0f, -1.1f,  -1.6f);
 
	glEnd();
	//glFlush();
}

void sidewalk2()
{
	//glColor3f(0.423,0.392,0.321);//108 100 89
	glPushMatrix();
	glRotatef(-10, 0,1,0);
	glColor3f(0.76,0.662,0.541);//194 169 138
	glPushMatrix();
	glTranslatef(-3,-3.2,-3);
	glScalef(15,1,.5);
	glRotatef(-90, 1,0,0);
	//glRotatef(-45, 0,1,0);
	glBegin(GL_QUADS);
		glVertex3f( 1.0f,  1.0f, 0.0f);
		glVertex3f(-1.0f,  1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f( 1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPopMatrix();

}

void building()
{
	
	//shade();
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
	  glColor3f(0.247f, 0.270f, 0.129f);     // 63 69 33
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
	   //reverse
	  glPushMatrix();
	  glRotatef(-90,1,0,0);
	  glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
	  glPopMatrix();
 
      // Bottom face (y = -1.0f)
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
	   //reverse
	  glPushMatrix();
	  glRotatef(-90,0,1,0);
	   glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
	  glPopMatrix();
 
      // Front face  (z = 1.0f):BOTTOM
	  glColor3f(0.698, 0.639, .423);//vanilla
	  //glColor3f(0,0,0);
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
	  //reverse
	  glPushMatrix();
	  glRotatef(-90,1,0,0);
	  glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
	  glPopMatrix();
 
      // Back face (z = -1.0f): BOTTOM
	  glColor3f(0.835, 0.745, .623); //213 190 159
	  //glColor3f(0.698, 0.639, .423);//vanilla
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
	  glPushMatrix();
	  glRotatef(-90,1,0,0);
	  glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
	  glPopMatrix();
 
      // Right face (x = 1.0f): Back
	//glColor3f(0.325, 0.396, .160); 
	  glColor3f(0.698, 0.639, .423);//vanilla
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	  glPushMatrix();
	  glRotatef(-90,1,0,0);
	  glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	  glPopMatrix();
	  
	  // Left face (x = -1.0f): FRONT
	  glColor3f(0.698, 0.639, .423);//vanilla
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
	  glPushMatrix();
	  glRotatef(-90,1,0,0);
	   glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
	  glPopMatrix();
	  
   glEnd();  // End of drawing color-cube
   //glFlush();
}

void brickHouse()
{
	glPushMatrix();
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
	  glColor3f(0.6f, 0.368f, 0.298f);     // 153 94 76 brick
      glVertex3f( 1.0f, 5.0f, -1.0f);
      glVertex3f(-1.0f, 5.0f, -1.0f);
      glVertex3f(-1.0f, 5.0f,  1.0f);
      glVertex3f( 1.0f, 5.0f,  1.0f);
 
      // Bottom face (y = -1.0f)
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)
	  
      glVertex3f( 1.0f,  5.0f, 1.0f);
      glVertex3f(-1.0f,  5.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)
	  //glColor3f(0.835, 0.745, .623); //213 190 159
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  5.0f, -1.0f);
      glVertex3f( 1.0f,  5.0f, -1.0f);
 
      
 
      // Right face (x = 1.0f)
	//glColor3f(0.325, 0.396, .160); 
      glVertex3f(1.0f,  5.0f, -1.0f);
      glVertex3f(1.0f,  5.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	  
	  // Left face (x = -1.0f)
      glVertex3f(-1.0f,  5.0f,  1.0f);
      glVertex3f(-1.0f,  5.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
	  
   glEnd();  // End of drawing color-cube
   //glFlush();
   glPopMatrix();
}


void brickHouse2()
{//134 85 68
	glPushMatrix();
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
	  //glColor3f(0.6f, 0.368f, 0.298f);     // 153 94 76 brick
	  glColor3f(0.525f, 0.333f, 0.267f);
      // Front face  (z = 1.0f)
	  
      glVertex3f( 1.0f,  5.0f, 1.0f);
      glVertex3f(-1.0f,  5.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
   glEnd();  // End of drawing color-cube
   //glFlush();
   glPopMatrix();
}

void wall()
{
	glBegin(GL_QUADS);
		glVertex3f( 1.0f,  1.0f, 1.0f);
		glVertex3f(-1.0f,  1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
	glEnd();
	//glFlush();
}

void bwall()
{
	glPushMatrix();
	glTranslatef(0,-.7,-2);
	glScalef(10,.2,1);
	glRotatef(-75, 0,1,0);
	glColor3f(0.6f, 0.368f, 0.298f);     // 153 94 76 brick
	glBegin(GL_QUADS);
		glVertex3f( 3.0f,  1.0f, 1.0f);
		glVertex3f(-3.0f,  1.0f, 1.0f);
		glVertex3f(-3.0f, -1.0f, 1.0f);
		glVertex3f( 3.0f, -1.0f, 1.0f);
	glEnd();
	glPopMatrix();
}




void leafy()
{//39 61 14
	glColor3f(.152,.239,.054);
	/*
	GLfloat qaBlack[]={0,0,0,1};
	GLfloat qaGreen[]={0,1,0,1};
	GLfloat qaWhite[]={1,1,1,1};
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 60);
	*/
	glPushMatrix();
	//glRotatef(90,(rand()%100)*.001,(rand()%100)*.001,(rand()%100)*.001);
	glScalef(.01,.05,.01);
	//glTranslatef(3.0f,0.0f,0.0f);	// Move Right 3 Units
	glBegin(GL_POLYGON);	// Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);	// Top Left
	glVertex3f( 1.0f, 1.0f, 0.0f);	// Top Right
	glVertex3f( 1.0f,-1.0f, 0.0f);	// Bottom Right
	glVertex3f(-1.0f,-1.0f, 0.0f);	// Bottom Left
	glEnd();
	glPopMatrix();
}

void leafGreen()
{	//glRotatef(90,(rand()%100)*.001,(rand()%100)*.001,(rand()%100)*.001);
	//glTranslatef(x,y,z);
	int ia = 0;
	float limit = 1.5;
	for(float j = 0; j < limit; j = j + 0.02)
	{
		for(float i = 0; i < limit; i = i + 0.02)
		{
			if(ia > 99)
			{
				ia=0;
			}
			glPushMatrix();
			glTranslatef(i, j,0);
			//printf("x: %f, y: %f, z:%f\n", i, j, 0.0);
			//glRotatef(90,(rand()%100)*.001,(rand()%100)*.001,(rand()%100)*.001);
			glRotatef(90,leavesx[ia],leavesy[ia],leavesz[ia]);
			//glScalef(.2,0.2,0.2);
			leafy();	
			glPopMatrix();
			ia++;
			
		}
	}
}

void bush()
{
	leafGreen();
	glPushMatrix();
	glRotatef(90,0,1,0);
	leafGreen();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(0,0,1.5);
	leafGreen();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,1,0,0);
	glTranslatef(0,-1.5,-1.5);
	leafGreen();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,-1.5);
	leafGreen();
	glPopMatrix();
	
}

void cubert()//Hedge
{	
	//leafGreen();
	
	//(rand()%100)
	
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.325, 0.396, .160); 
	  //glColor3f(1-0.325, 1-0.396, 1-.160); 
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
	  
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glColor3f(0.325, 0.396, .160); 
	//glColor3f(1-0.325, 1-0.396, 1-.160); 
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f,  1.0f);
	glPopMatrix();
 
      // Bottom face (y = -1.0f)
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
	  
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	
	glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
	
	glPopMatrix();
 
      // Front face  (z = 1.0f)
	  
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
	  
	  glPushMatrix();
	glRotatef(180, 0, 1, 0);
	
	glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
	
	glPopMatrix();
 
      // Back face (z = -1.0f)
	  //glColor3f(1-0.325, 1-0.396, 1-.160); 
	  glColor3f(0.325, 0.396, .160); 
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
	  
	  glPushMatrix();
	glRotatef(180, 0, 1, 0);
	
	//glColor3f(1-0.325, 1-0.396, 1-.160); 
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
	
	glPopMatrix();
 
      // Right face (x = 1.0f)
	glColor3f(0.325, 0.396, .160); 
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	  
	  glPushMatrix();
	glRotatef(180, 0, 1, 0);
	
	glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	
	glPopMatrix();
	  
	  // Left face (x = -1.0f)
	  glColor3f(0.247f, 0.270f, 0.129f);     // 63 69 33
	  //glColor3f(1-0.247f, 1-0.270f, 1-0.129f);   
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
	  
	  glPushMatrix();
	glRotatef(180, 0, 1, 0);
	
	glColor3f(0.247f, 0.270f, 0.129f);     // 63 69 33
	//glColor3f(1-0.247f, 1-0.270f, 1-0.129f); 
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
	
	glPopMatrix();
	  
   glEnd();  // End of drawing color-cube
   
}

// Cone
GLdouble base=.6;
GLdouble height=.4;
GLint slices = 6;
GLint stacks =9;

void drawCircle(float cx, float cy, float r, int num_segments)
{
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < num_segments; i++)
  {
    float theta = i * (2.0f * M_PI / num_segments); // get the current angle
    float x = r * cos(theta); // calculate the x component
    float y = r * sin(theta); // calculate the y component
    glVertex2f(x + cx, y + cy); // output vertex
  }
  glEnd();
}

void cone(GLfloat xRotated, GLfloat yRotated, GLfloat zRotated)
{
	glPushMatrix();
	float radius = .45;
	glColor3f(.1,.1,.2);
	glTranslatef(0,-.35,0);
	glRotatef(90,1,0,0);
	
	for(float i = 0; i < radius; i=i+0.01)
	{
		drawCircle(0,0,i,20);//x, y , r, slices
	}
	glPopMatrix();
	
	glPushMatrix();
    //glTranslatef(0.0,0.0,-4.5);
    glColor3f(0.258f, 0.184f, 0.494f);     // Purple
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a Cone.
    glutSolidCone(base,height,slices,stacks);
	glPopMatrix();
	
	/*
	GLUquadricObj *quadratic5;
	quadratic5 = gluNewQuadric();
    gluCylinder(quadratic5, base, base,1,20,10);//base1, base2, height, slices1, slices2
	*/
	glPointSize(10);
	glBegin (GL_LINES);  //draws one line
		glVertex3f (0, 0, 0);    // between 2 vertices
		glVertex3f (0, -0.4, 0);
	glEnd ();
}

// Cone
GLdouble base1=.5;
GLdouble height1=.5;
GLint slices1 =15;
GLint stacks1 =15;

void can(GLfloat xRotated, GLfloat yRotated, GLfloat zRotated)
{
	glPushMatrix();
    //glTranslatef(0.0,0.0,-4.5);
    glColor3f(0.313f, 0.317f, 0.298);     // 80 81 76
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(0.5,0.5,1.0);
    // built-in (glut library) function , draw you a Cone.
 
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluCylinder(quadratic, base1, base1,height1,slices1,stacks1);
	glPopMatrix();
	//--------Top of Can------------------
	glTranslatef(0.0,0.25,0.0);
    //glColor3f(0.313f, 0.317f, 0.298);     // 80 81 76
   
    glRotatef(-90,1.0,0.0,0.0);
    // scaling transfomation 
    glScalef(0.35,0.35,0.8);
    // built-in (glut library) function , draw you a Cone.
 
	GLUquadricObj *quadratic2;
	quadratic2 = gluNewQuadric();
    gluCylinder(quadratic2, base1, base1,height1,slices1,stacks1);

}

//
void reshape(int width, int height)
{
	glViewport(0,0,(GLsizei)width, (GLsizei)height);//coordinates of view space in window, starting from bottom left corner. 0,0 means viewing space will be at edge, and having the same height and width will mean the viewing space will fill up the window entirely
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective, 3d alternate for gluOrtho2D
	gluPerspective(60.0, 1, 1, 100.0);//fov angle, aspect ratio(1, if square), near plane (prevents from seeing objects that are too close), far plane(how far way you can see)
	//gluOrtho2D(-100, -100, 100, 100);//coordinate system is defined by most negative x-axis number, most negative y-axis number, most positive x-axis number, most positive y-axis number
	glMatrixMode(GL_MODELVIEW);//
	glClearColor(0.415, 0.588f, 0.843f,0.0);//background color 
	
}

void disp()
{
	//***DRAW*********

	glPushMatrix();
	road();
	glPopMatrix();
	
	glPushMatrix();
	grass();
	glPopMatrix();
	
	glPushMatrix();
	sidewalk();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,-5);
	grid(-20, 20, -20, 20);
	glPopMatrix();
	
	//brick building
	glPushMatrix();
	glTranslatef(-11.0f, -1.0f, -24.0f);
	glScalef( 5.0f, 1.5, 1.0f );//x, y , z
	//glRotatef(45.0, 0.00f, 1.0f, 0.0f);//angle, x, y, z
	//glRotatef(45.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	glRotatef(-90.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	brickHouse();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.0f, 0.0f, -30.0f);
	glScalef( 5.0f, 2.0f, 1.0f );//x, y , z
	//glRotatef(90.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	//brickHouse();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-4.0f, -1.0f, -25.0f);
	glScalef(5,1.5,1);
	brickHouse();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-10.0f, -1.0f, -25.0f);
	glRotatef(20,0,1,0);
	glScalef(1,1.55,1);
	brickHouse2();
	glPopMatrix();
	
	//Beige Building
	glPushMatrix();
	glRotatef(-20.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	glTranslatef(-15.5f, -1.0f, -14.5f);
	glScalef(1,.8,0.5);
	building();
	glPopMatrix();
	glPushMatrix();
	glRotatef(-20.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	glTranslatef(-5.0f, 0.0f, 9.0f);
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, -25.0f);
	glScalef( 5.0f, 2.0f, 1.0f );//x, y , z
	glRotatef(45.0, 0.08f, 1.0f, 0.0f);//angle, x, y, z
	glRotatef(45.0, 0.0f, 1.0f, 0.0f);//angle, x, y, z
	building();
	//glTranslatef(1.0f, -1.8f, 10.0f);  //x, y, z
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-12.0f, 0.0f, -18.0f);
	shade();
	glPopMatrix();
	glPopMatrix();
	
	//------------test
	/*
	glPushMatrix();
	glTranslatef(-2.0f, -1.0f, -5.5f);
	//glScalef(4,1.5,1);
	leafGreen();
	glPopMatrix();
	*/
	//-----------------
	
	glPushMatrix();
	glTranslatef(-5, 0,4);
	glRotatef(-24,0,1,0);
	glPushMatrix();
	glTranslatef(-10.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-11.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-13.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(-14.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-16.0f, -1.0f, -18.0f);
	cone(-90, 0 , 0);
	glPopMatrix();
	
	//TRASH CANS
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(-11.0f, -2.0f, -18.0f);
	can(-90, 0 , 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-18.0f, -2.0f, -18.0f);
	can(-90, 0 ,0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-16.0f, -2.0f, -18.0f);
	can(-90, 0 , 0);
	glPopMatrix();
	glPopMatrix();
	//ORIGIN
	drawOrigin();
	
	glPushMatrix();
	glTranslatef(0,-1,-15);
	bwall();
	glPopMatrix();
	
	//sidewalk2
	glPushMatrix();
	glTranslatef(5.0f, 2.0f, -5.0f);
	sidewalk2();
	glPopMatrix();
	
	//HEDGE
	/*
	glPushMatrix();
	glTranslatef(0.0f, 1.5f, -15.0f);
	glScalef( 0.9f,0.7f, 0.9f );//x, y , z
	glTranslatef(1.0f, -2.4f, 12.2f);  //x, y, z
	glRotatef(45.0, -0.1f, 1.0f, 0.0f);//angle, x, y, z
	cubert();
	glPopMatrix();
	*/
	glPushMatrix();
	glTranslatef(0.0f, 1.5f, -15.0f);
	glTranslatef(1.0f, -2.4f, 12.2f);  //x, y, z
	glRotatef(45.0, -0.1f, 1.0f, 0.0f);//angle, x, y, z
	//glScalef(4,1.5,1);
	//leafGreen();
	bush();
	glPopMatrix();
	
	
	//RENDER
	glFlush();
}

//display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear frame buffer, so you can draw something on it; sets it to default clear color(unless default color was manually changed)
	glLoadIdentity();//resets coordinates system, if previous frame used a matrix transformation
	//glPointSize(10.0);//change size of point diameter in pixels, input float
	glShadeModel(GL_SMOOTH);//or use GL_FLAT for non-gradual color transition
	//x,y shift origin, which is useful when 3d object's vertices are tied to origin. dont change vertices, change origin for each object; dont call from inside "glBegin"
	gluLookAt(a1, b1, c1,
			//1.0f, -0.9, -14.1,
			camTarX, camTarY, camTarZ,
           // 0.0, 1.0, 0.0);
		   camDirectionX, camDirectionY, camDirectionZ);
	
	//GLfloat lightPosition[] = {0, 5, -2, 2};//x, y, z, ?
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	
	disp();
	glutSwapBuffers();
	
}

//frame buffer: specified memory for what will appear on screen

//translation: shifting of origin

//fov: field of view: angle of camera point and view space: usually 40-60 degrees
















