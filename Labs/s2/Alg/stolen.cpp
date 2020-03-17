//
//  main.cpp
//  FirstLabPIAA
//
//  Created by Михаил Дементьев on 15/02/2019.
//  Copyright © 2019 Михаил Дементьев. All rights reserved.
//

#include <iostream>
#include <vector>

struct coordinates    //Класс координат, который содержит в себе значения координаты x и координаты y.
{
    //Конструктор класса, который присваивает нули координатам x и y.
    coordinates(int x = 0, int y = 0) : x(x), y(y){}
    int x;
    int y;
};

struct quadrate  //Класс квадрата, который содержит в себе координаты его левого верхнего угла и длинну стороны
{
    //Конструктор класса, который берет координаты левого верхнего угла квадрата из класса координат point, а значению длины присваивает 0.
    quadrate(coordinates p = coordinates(), unsigned long length = 0) : coord(p), length(length) {}
    unsigned long length;    //Длина стороны квадрата
    coordinates coord;    //Координаты левого верхнего угла квадрата
};

//Вывод ответа
void printAnswer( std::vector<quadrate> AnswerForOutput )
{
    std::cout << AnswerForOutput.size() << '\n';
    for( int i = 0; i < AnswerForOutput.size(); i++ )  //Обход массива из элементов типа answer и вывод необходимых полей: координат x, y и длины стороны.
        std::cout << AnswerForOutput[i].coord.x + 1 << ' ' << AnswerForOutput[i].coord.y + 1 << ' ' << AnswerForOutput[i].length << '\n';
    std::cout << '\n';
}

//Рисование квадрата
unsigned long buildingASquare( std::vector< std::vector<int> >* initialSquare, unsigned long sideLengthLimit, coordinates point, int colour )
{
    //Если квадрат, который нужно нарисовать выходит за границы поля, то сторона квадрата уменьшается вплоть до границы поля (по x или y).
    sideLengthLimit = initialSquare->size() < sideLengthLimit + point.x ? initialSquare->size() - point.x : sideLengthLimit;
    sideLengthLimit = initialSquare->size() < sideLengthLimit + point.y ? initialSquare->size() - point.y : sideLengthLimit;
    
    int i = point.y; //координата x левого верхнего угла квадрата
    int j = point.x; //координата y левого верхнего угла квадрата
    
    for( i = point.y; i < point.y + sideLengthLimit; i++)
    {
        for(  j = point.x; j < point.x + sideLengthLimit; j++)
        {
            if( (*initialSquare)[i][j] )  //Если в этой клетке поля не "0", прекращаем разростание квадрата по x и фиксируем рисование на новом значении стороны
            {
                sideLengthLimit = j - point.x;
            }
            else //Иначе, заполняем данную ячейку цветом, соответствующим данному квадрату
            {
                (*initialSquare)[i][j] = colour;
            }
        }
    }
    return sideLengthLimit; //Возрващается длина стороны нарисованного квадрата
}

//Поиск свободной точки
bool freeSpaceSearch(std::vector< std::vector<int> > initialSquare, coordinates* point)
{
    for( int i = 0; i < initialSquare.size(); i++ )      //Перебор всех элементов и поиск нулевого, как только он найден, записвает кординаты в p и возвращаем true, иначе - false.
        for( int j = 0; j < initialSquare.size(); j++ )
            if (!initialSquare[i][j])
            {
                *point = coordinates(j, i);
                return true;
            }
    return false;
}

//Проверка на отсутсвие пробелов по периметру
bool checkForGaps( std::vector< std::vector<int> > initialSquare, coordinates point, unsigned long squareSideLength  )
{
    int numOfMissSpaces = 0;
    
    //Проверка нижней части
    if( point.y + squareSideLength == initialSquare.size() ) //Если снизу граница большого квадрата
        numOfMissSpaces += squareSideLength;
    else
        for( int mov = point.x; mov < point.x+squareSideLength; mov++ )  //Если снизу квадрата не пусто, то прибавляем 1, иначе 0.
            numOfMissSpaces += initialSquare[point.y + squareSideLength][mov] ? 1 : 0;
    
    //Проверка левой части
    if( !point.x ) //Если координаты левой части 0, значит - левая граница маленького квадрата совпадает с левой границей большого
        numOfMissSpaces += squareSideLength;
    else
        for( int mov = point.y; mov < point.y+squareSideLength; mov++ )  //Если слева от квадрата не пусто, прибавляем 1, иначе - 0.
            numOfMissSpaces += initialSquare[mov][point.x - 1] ? 1 : 0;
    
    //Проверка правой части
    if( point.x + squareSideLength == initialSquare.size() )  //Если справа от квадрата - стенка
        numOfMissSpaces += squareSideLength;
    else
        for( int mov = point.y; mov < point.y+squareSideLength; mov++ ) //Если справа от квадрата не пусто, прибавляем 1, иначе - 0.
            numOfMissSpaces += initialSquare[mov][point.x + squareSideLength] ? 1 : 0;
    numOfMissSpaces += squareSideLength;
    
    if( numOfMissSpaces >= squareSideLength*3 ) //Если пробелы по периметру (снизу, слева, справа) отсуствуют, возвращаем true, иначе false.
        return true;
    else
        return false;
}



//Основная рекурсивная функция
void backtracking( std::vector< std::vector<int> > &initialSquare , unsigned long sideLengthLimit, int colour, std::vector<quadrate>* answer, std::vector<quadrate> tempAnswer )
{
    unsigned long squareSideLength = 0;    //Задание переменной для обозначения длины квадрата
    coordinates p(0,0);        //Задание координатной переменной
    
    bool perimeterGaps = true;   //true - нет пробелов по периметру вокруг квадртата, false - нет
    bool freeSpace = true; //true - есть свободные клетки, false - нет
    
    std::vector< std::vector<int> > beforelast = initialSquare; //Временный вектор для хранения большого квадрата, до рисования на нем очередного меньшего квадрата
    
    if( freeSpaceSearch(initialSquare, &p) )   //Если найдено свободное место
    {
        squareSideLength = buildingASquare(&initialSquare, sideLengthLimit, p, colour);  //Длина только что нарисованного квадрата
        perimeterGaps = checkForGaps( initialSquare, p, squareSideLength );   //Если пробелов по периметру вокруг квадрата нет - true, иначе - false
    }
    
    if( !perimeterGaps && sideLengthLimit > 1 )      //Если есть пробелы вокруг квадрата и максимальная  длина возможного квадрата больше 1-цы
    {
        backtracking(beforelast, sideLengthLimit-1, colour, answer, tempAnswer);  //Рекурсивный вызов основной функции
    }
    
    tempAnswer.push_back(quadrate(p, squareSideLength));  //Добавление координат только что нарисованного квадрата и его длины в временный массив
    ++colour;  //Изменение цвета для создания нового квадрата
    freeSpaceSearch(initialSquare, &p);  //Поиск свободного места и запись координаты в p
    
    while( freeSpace )  //Пока есть свободное место
    {
        beforelast = initialSquare;        //Временная переменная для хранения большого квадртара до рисования нового маленького
        squareSideLength = buildingASquare(&initialSquare, initialSquare.size() - 1, p, colour);  //Рисование квадрата на вновь найденных координатах свободного места p и сохранение его длинны в squareSideLength
        
        perimeterGaps = checkForGaps( initialSquare, p, squareSideLength );  //Проверка на отсутствие пробелов вокруг вновь нарисованного квадртата
        if( !perimeterGaps && sideLengthLimit > 1 )     //Если есть пробелы вокруг квадрата и максимальная  длина возможного квадрата больше 1-цы
        {
            backtracking(beforelast, sideLengthLimit-1, colour, answer, tempAnswer);  //Рекурсивный вызов основной функции
        }
        
        tempAnswer.push_back(quadrate(p, squareSideLength));    //Добавление координат только что нарисованного квадрата и его длины в временный массив
        freeSpace = freeSpaceSearch( initialSquare, &p );     //Поиск свободного места и запись его наличия в freeSpace, которая == false, если свободное место будет отсутствовать.
        ++colour;    //Изменение цвета для создания нового квадрата
    }
    
    if( tempAnswer.size() < answer->size() )    //Если размер массива с временным ответом меньше, чем массива с конечным, сделаем временный - конечным.
        *answer = tempAnswer;
    
}

int main( void )
{
    unsigned long squareSideLength;   //Переменная, равная длине стороны главного большого квадрата
    std::cin >> squareSideLength;    //Ее считывание
    
    std::vector<quadrate> answer;    //Массив ответов, состоящий из квадратов
    std::vector< std::vector<int> > data(squareSideLength, std::vector<int>(squareSideLength, 0));    //Массив исходного поля данных, который будет закрашивать в будущем
    std::vector<quadrate> tempAnswer;    //Массив временных ответов
    
    answer.resize(50);
    backtracking(data, squareSideLength - 1, 1, &answer, tempAnswer);   //Вызов основной рекурсивной функции
    
    printAnswer(answer);   //Вывод ответа
    
}