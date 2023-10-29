#include "GL_header.h"

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GL_MULTISAMPLE);
	glutInitWindowPosition(X_POS, Y_POS);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL");
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cerr << "Unable to initialize GLEW" << endl;  exit(EXIT_FAILURE);
	}
	else cout << "GLEW Initialized" << endl;
		
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	makeShaderProgram();
	for(int i = 0; i < MODEL_COUNTS; i ++)
		setBuffer(i, modeInit);
	
	glutDisplayFunc(displayOutput);
	glutReshapeFunc(displayReshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(10, timerOperation, 1);
	glutMainLoop();
}
