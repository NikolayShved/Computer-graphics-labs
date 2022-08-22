#include "ogl_figure.h"
#include<QOpenGLFunctions>

/*
* Конструктор для инициализации переменных для поворота и передачи указателя на виджет предка конструктору наследуемого класса QOpenGLWidget.
*/
OGLFigure::OGLFigure(QWidget* pwgt) : QOpenGLWidget(pwgt), m_xRotate(0), m_yRotate(0){}

/*
* Метод для проведения инициализаций, связанных с OpenGL.
* Метод вызывается, если объекту, унаследованному от класса QOpenGLWidget, присваивается контекст OpenGL.
*/
void OGLFigure::initializeGL()
{
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions(); // доступ к текущему контексту OpenGL и к его функциям.
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // установка черного цвета для очистки буфера изображения.
    pFunc->glEnable(GL_DEPTH_TEST); // устанавливает режим разрешения проверки глубины фрагментов.
    glShadeModel(GL_FLAT); // отключение режима сглаживания цветов (иначе грани будут иметь радужную окраску).
    m_nFigure = createFigure(1.2f); // создание дисплейного списка для фигуры и возврат её номера, который присваивается переменной m_nFigure. Параметр, передаваемый в этот метод, задает размеры самой фигуры.
}

/*
* Метод вызывается при изменении размеров объекта, созданного от класса, наследующего QOpenGLWidget.
* В параметрах метода передаются актуальные размеры виджета.
*/
void OGLFigure::resizeGL(int nWidth, int nHeight)
{
    glViewport (0, 0, (GLint) nWidth, (GLint) nHeight); // устанавка размеров видового окна равных размерам окна виджета.
    glMatrixMode(GL_PROJECTION); // установка матрицы проектирования текущей матрицей.
    glLoadIdentity(); // текущая матрица устанавливается в единичную.
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0); //функция, которая задаёт видимость фигуры. Её параметры задают положения левой, правой, верхней, нижней, передней и задней отсекающих плоскостей.
}

/*
* Метод вызывается в случаях, когда требуется заново перерисовать содержимое виджета.
* В параметрах метода передаются актуальные размеры виджета.
*/
void OGLFigure::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка буферов изображения и глубины (последний служит для удаления невидимых поверхностей).
    glMatrixMode(GL_MODELVIEW); // устанавливается матрица моделирования, служащая для задания положения объекта и его ориентации.
    glLoadIdentity(); // присваивоение матрице моделирования единичной матрицы.
    glTranslatef(0.0, 0.0, -3.0); // сдвигает начало системы координат по оси Z на 3 единицы.
    glRotatef(m_xRotate, 1.0, 0.0, 0.0); // поворачивает систему координат вокруг оси Х на угол, задаваемый переменными m_xRotate.
    glRotatef(m_yRotate, 0.0, 1.0, 0.0); // поворачивает систему координат вокруг оси Y на угол, задаваемый переменными m_yRotate.
    glCallList(m_nFigure); // передача номера дисплейного списка фигуры для её отображения.
}

/*
* Метод обработки события мыши.
*/
void OGLFigure::mousePressEvent(QMouseEvent *e)
{
    m_ptPosition = e->pos(); // При нажатии пользователем кнопки мыши переменной m_ptPosition присваиваются координаты указателя мыши.
}

/*
* Метод  для осуществления поворота фигуры.
*/
void OGLFigure::mouseMoveEvent(QMouseEvent *e)
{
    m_xRotate += 180 * (GLfloat) (e->y() - m_ptPosition.y()) / height(); // вычисляются углы поворота для оси Х.
    m_yRotate += 180 * (GLfloat) (e->x() - m_ptPosition.x()) / width(); // вычисляются углы поворота для оси y.
    update(); // обновление изображения на экране, используя новые углы поворота.
    m_ptPosition = e->pos(); // Переменной m_ptPosition присваивается актуальная координата указателя мыши.
}

/*
* Метод  для графического построения первой части фигуры.
*/
void OGLFigure::createPartOne(GLfloat size)
{
    //Построение первой части
    glBegin(GL_QUAD_STRIP); //тип фигуры (каждая следующая пара вершин образует четырехугольник вместе с парой предыдущих)
    glColor3f(0.0, 0.0, 1.0); //цвет фигуры (синий)

    // нижняя грань
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0,  size / 2, 0.0);
    glVertex3f(size / 2,  0.0,  0.0);
    glVertex3f( size / 2, size / 2, 0.0);

    // задняя грань
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(size / 2, 0.0, 0.0);
    glVertex3f(0.0,  0.0,  size / 4);
    glVertex3f(size / 2, 0.0, size / 4);

    // правая грань
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, size / 2, 0.0);
    glVertex3f(0.0, 0.0, size / 4);
    glVertex3f(0.0, size / 2, size / 4);

    // левая грань
    glVertex3f(size / 2, 0.0, 0.0);
    glVertex3f(size / 2, size / 2, 0.0);
    glVertex3f( size / 2, 0.0, size / 4);
    glVertex3f( size / 2, size / 2, size / 4);

    // передняя грань
    glVertex3f(size / 2, size / 2, 0.0);
    glVertex3f(0.0, size / 2, 0.0);
    glVertex3f(size / 2, size / 2, size / 4);
    glVertex3f(0.0, size / 2, size / 4);

    // верхняя грань
    glVertex3f(0.0, 0.0, size / 4);
    glVertex3f(size / 2, 0.0, size / 4);
    glVertex3f(0.0,  size / 2,  size / 4);
    glVertex3f(size / 2, size / 2, size / 4);

    glEnd();
}

/*
* Метод  для графического построения второй части фигуры.
*/
void OGLFigure::createPartTwo(GLfloat size)
{
    //Построение второй части
    glBegin(GL_QUAD_STRIP); //тип фигуры (каждая следующая пара вершин образует четырехугольник вместе с парой предыдущих)
    glColor3f(1.0, 0.0, 0.0); //цвет фигуры (красный)

    // нижняя грань
    glVertex3f(size / 2, -0.3, 0.0);
    glVertex3f(0.35,  -0.3,  0.0);
    glVertex3f(size / 2, 0.0, 0.0);
    glVertex3f(0.35,  0.0,  0.0);

    // задняя грань
    glVertex3f(size / 2, -0.3, size / 2);
    glVertex3f(0.35,  -0.3,  size / 2);
    glVertex3f(size / 2, -0.3, 0.0);
    glVertex3f(0.35,  -0.3,  0.0);

    // правая грань
    glVertex3f(0.35,  -0.3,  size / 2);
    glVertex3f(size / 2, 0.0, size / 2);
    glVertex3f(0.35,  -0.3,  0.0);
    glVertex3f(size / 2, 0.0, 0.0);

    // передняя грань
    glVertex3f(size / 2, 0.0, size / 2);
    glVertex3f(0.35, 0.0, size / 2);
    glVertex3f(size / 2, 0.0, 0.0);
    glVertex3f(0.35, 0.0, 0.0);

    // верхняя грань
    glVertex3f(size / 2,  -0.3,  size / 2);
    glVertex3f(0.35,  -0.3,  size / 2);
    glVertex3f(size / 2, 0.0, size / 2);
    glVertex3f(0.35,  0.0,  size / 2);

    // левая грань (ближняя)
    glVertex3f(size / 2, -0.3, size / 2);
    glVertex3f(size / 2, 0.0, size / 2);
    glVertex3f(size / 2, -0.3, 0.0);
    glVertex3f(size / 2, 0.0, 0.0);

    glEnd();
}

/*
* Метод  для графического построения третей части фигуры.
*/
void OGLFigure::createPartThree(GLfloat size)
{
    //Построение третей части
    glBegin(GL_QUAD_STRIP); //тип фигуры (каждая следующая пара вершин образует четырехугольник вместе с парой предыдущих)
    glColor3f(1.0, 0.0, 0.0); //цвет фигуры (красный)

    // нижняя грань
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0,  -0.3,  0.0);
    glVertex3f(0.15, -0.3, 0.0);
    glVertex3f(0.15, 0.0, 0.0);

    // задняя грань
    glVertex3f(0.0,  -0.3,  size / 2);
    glVertex3f(0.15, -0.3, size / 2);
    glVertex3f(0.0,  -0.3,  0.0);
    glVertex3f(0.15, -0.3, 0.0);

    // левая грань
    glVertex3f(0.0,  -0.3,  size / 2);
    glVertex3f(0.15, -0.3, size / 2);
    glVertex3f(0.0,  -0.3,  0.0);
    glVertex3f(0.15, -0.3, 0.0);

    // передняя грань
    glVertex3f(0.0,  0.0,  size / 2);
    glVertex3f(0.15, 0.0, size / 2);
    glVertex3f(0.0,  0.0,  0.0);
    glVertex3f(0.15, 0.0, 0.0);

    // верхняя грань
    glVertex3f(0.0,  -0.3,  size / 2);
    glVertex3f(0.15, -0.3, size / 2);
    glVertex3f(0.0,  0.0,  size / 2);
    glVertex3f(0.15, 0.0, size / 2);

    // правая грань
    glVertex3f(0.0, 0.0, size / 2);
    glVertex3f(0.0,  -0.3,  size / 2);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0,  -0.3,  0.0);

    glEnd();
}

/*
* Метод  для графического построения четвёртой части фигуры.
*/
void OGLFigure::createPartFour()
{
    //Построение четвёртой части
    glBegin(GL_QUAD_STRIP); //тип фигуры (каждая следующая пара вершин образует четырехугольник вместе с парой предыдущих)
    glColor3f(1.0, 1.0, 0.0); //цвет фигуры (жёлтый)

    // нижняя грань
    glVertex3f(0.15, -0.3, 0.0);
    glVertex3f(0.15,  0.0,  0.0);
    glVertex3f(0.35, -0.3, 0.0);
    glVertex3f(0.35,  0.0,  0.0);

    // задняя грань
    glVertex3f(0.15, -0.3, 0.375);
    glVertex3f(0.35, -0.3, 0.375);
    glVertex3f(0.15, -0.3, 0.0);
    glVertex3f(0.35, -0.3, 0.0);

    // правая грань
    glVertex3f(0.15, -0.3, 0.375);
    glVertex3f(0.15,  0.0, 0.375);
    glVertex3f(0.15, -0.3, 0.0);
    glVertex3f(0.15,  0.0,  0.0);

    // левая грань (ближняя)
    glVertex3f(0.35, -0.3, 0.375);
    glVertex3f(0.35,  0.0, 0.375);
    glVertex3f(0.35, -0.3, 0.0);
    glVertex3f(0.35,  0.0,  0.0);

    // передняя грань
    glVertex3f(0.15,  0.0, 0.375);
    glVertex3f(0.35,  0.0, 0.375);
    glVertex3f(0.15,  0.0, 0.0);
    glVertex3f(0.35,  0.0, 0.0);

    // верхняя грань
    glVertex3f(0.15,  0.0, 0.375);
    glVertex3f(0.35,  0.0, 0.375);
    glVertex3f(0.15,  -0.3, 0.375);
    glVertex3f(0.35,  -0.3, 0.375);

    glEnd();
    glEndList();
}

/*
* Метод  для графического построения фигуры (возвращает номер для идентификации дисплейного списка).
*/
GLuint OGLFigure::createFigure(GLfloat size)
{
    GLuint n = glGenLists(1); // возвращает первый свободный номер для идентификации дисплейного списка.
    glNewList(n, GL_COMPILE); // Номер передается в функцию glNewList(). Второй параметр, GL_COMPILE, говорит о том, что команды нужно лишь запомнить.
    createPartOne(size = 1.0f); // построение первой составляющей
    createPartTwo(size = 1.0f); // построение второй составляющей
    createPartThree(size = 1.0f); // построение третей составляющей
    createPartFour(); // построение четвёртой составляющей
    return n;
}
