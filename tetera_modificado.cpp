#include <GL/gl.h>
#include <GL/glut.h>

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
void init(void)
{
/* selecciona el color de borrado */
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
/* borra la pantalla */
glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
/* seleccionamos la matriz modelo/vista */
glMatrixMode(GL_MODELVIEW);
/* color */
glColor3f(0.1, 0.3, 0.5);
glLoadIdentity();
glRotatef( rotate_x, 1.0, 0.0, 0.0 );
glRotatef( rotate_y, 0.0, 1.0, 0.0 );
glRotatef(rotate_z, 0.0, 0.0, 1.0 );
glTranslatef(X, Y, Z);
glScalef(scale, scale, scale);
glTranslatef(0.0, 0.0, 0.0);
//glRotatef(25.0, 0.0, 1.0, 0.0);
glScalef(0.6, 0.6, 0.6);
/* transformación modelo/vista */
gluLookAt(0.5,0.4,0.2, //punto de vista en el eje X,Y,Z
          0.2,0.2,0.2, //Centro del Objeto en el eje X,Y,Z
          0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
/* Dibujamos una tetera */
glutWireTeapot(0.5);
/* Vacia el buffer de dibujo */
glFlush ();
}

void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: disminuir rotación 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;

    else if (key == GLUT_KEY_UP)
        rotate_x += 7;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;

    else if (key == GLUT_KEY_F2)
        rotate_z += 7;

    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    // actualización de visualización
    glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    
    {
	case '-':
		scale=0.5;
		break;
	case '+':
		scale=1.5;
		break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;	
        
    case 27:
        exit(0);			// exit
    }

    glutPostRedisplay();		  // actualización de visualización
}


int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
glutInit(&argc, argv);
// Inicializa el modo de visualización
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
glutInitWindowSize(800, 600);
// Indica la posición inicial (xmin,ymin)
glutInitWindowPosition(100, 100);
// Abre la ventana con el título indicado
glutCreateWindow("Dibujando una tetera 3d");
glEnable(GL_DEPTH_TEST);
glutSpecialFunc(specialKeys);
glutKeyboardFunc(keyboard);
// Inicializar valores
init();
// Indica cual es la función de dibujo
glutDisplayFunc(display);
// Indica cual es la función para el cambio de tamaño de laventana

// Comienza el bucle de dibujo y proceso de eventos.
glutMainLoop();
}
