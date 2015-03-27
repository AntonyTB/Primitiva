#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

//material base de la tetera
double mat_ambient1=0.329412,mat_ambient2=0.223529,mat_ambient3=0.027451,
mat_diffuse1=0.780392,mat_diffuse2=0.568627,mat_diffuse3=0.113725,
mat_specular1=0.992157,mat_specular2=0.941176,mat_specular3=0.807843,
shin=27.8974;

void init(void)
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();

}

void ponerMaterial()
{

// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
    
    GLfloat mat_ambient[] = { mat_ambient1,mat_ambient2, mat_ambient3};
    GLfloat mat_diffuse[] = { mat_diffuse1, mat_diffuse2, mat_diffuse3 };
    GLfloat mat_specular[] = { mat_specular1, mat_specular2, mat_specular3};
    GLfloat shine[] = {shin}; 
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);  
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);              
//setMaterial

    glutSolidTeapot(125.0);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
 switch (key) 
   {
   case '1': //Material jade
   mat_ambient1=0.135;
   mat_ambient2=0.2225;
   mat_ambient3=0.1575;
   mat_diffuse1=0.54;
   mat_diffuse2=0.89;
   mat_diffuse3=0.63;
   mat_specular1=0.316228;
   mat_specular2=0.316228;
   mat_specular3=0.316228;
   shin= shin; 
    break;
  case '2': // Material Obsidian
   mat_ambient1=0.05375;
   mat_ambient2=0.05;
   mat_ambient3=0.06625;
   mat_diffuse1=0.18275;
   mat_diffuse2=0.17;
   mat_diffuse3=0.22525;
   mat_specular1=0.332741;
   mat_specular2=0.328634;
   mat_specular3=0.346435;
   shin= shin; 
    break;  
    
 case '3': // Material Pearl
  mat_ambient1=0.25;
  mat_ambient2=0.20725;
  mat_ambient3=0.20725;
  mat_diffuse1=1;
  mat_diffuse2=0.829;
  mat_diffuse3=0.829;
  mat_specular1=0.296648;
  mat_specular2=0.296648;
  mat_specular3=0.296648;
  shin=shin;
  break;
  case '4': // Material Ruby
  mat_ambient1=0.1745;
  mat_ambient2=0.01175;
  mat_ambient3=0.01175;
  mat_diffuse1=0.61424;
  mat_diffuse2=0.04136;
  mat_diffuse3=0.04136;
  mat_specular1=0.727811;
  mat_specular2=0.626959;
  mat_specular3=0.626959;
  shin=shin;
  break;
  case '5': //Material Turquoise
  mat_ambient1=0.1;
  mat_ambient2=0.18725;
  mat_ambient3=0.1745;
  mat_diffuse1=0.396;
  mat_diffuse2=0.74151;
  mat_diffuse3=0.69102;
  mat_specular1=0.297254;
  mat_specular2=0.30829;
  mat_specular3=0.306678;
  shin=shin;
  break;
  case 'n': // Volver al inicial
  mat_ambient1=0.329412;
  mat_ambient1=0.223529;
  mat_ambient1=0.027451;
  mat_diffuse2=0.780392;
  mat_diffuse2=0.568627;
  mat_diffuse2=0.113725;
  mat_specular1=0.992157;
  mat_specular1=0.941176;
  mat_specular1=0.807843;
  shin=shin;
  break;
  case 27: // 27 es Esc
  exit(0); // Sale del programa
  }
  glutPostRedisplay(); // actualización de visualización
     }
  
  int main(int argc, char **argv)
  {
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera");

// Inicializamos el sistema
    init();
    glutDisplayFunc(ponerMaterial);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); //llama funcion teclado
    glutMainLoop();
    
  //  glutponerMaterialFunc(ponerMaterial);
    return 0;
}
