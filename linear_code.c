#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

// "Copyright[2014]<CopyrightBuratinkalol>"
int** initMatrix(int *rows, int *colmns) {
    int** Matrix= reinterpret_cast<int**>(malloc(*rows*sizeof(Matrix)));
    if (Matrix== NULL)
        return NULL;
    for (int i = 0; i < *rows; i++) {
        Matrix[i]=reinterpret_cast<int*>(malloc(*colmns*sizeof(Matrix[i])));
        if (Matrix== NULL)
            return NULL;
    }
    return Matrix;
}
int** initHMatrix(int *rowsH, int *colmnsH) {
    int** HMatrix= reinterpret_cast<int**>(malloc(*rowsH*sizeof(HMatrix)));
    if (HMatrix== NULL)
        return NULL;
    for (int i = 0; i < *rowsH; i++) {
        HMatrix[i]=reinterpret_cast<int*>(malloc(*colmnsH*sizeof(HMatrix[i])));
        if (HMatrix== NULL)
            return NULL;
    }
    return HMatrix;
}

//___________________________________________________________

int** initcheckmatrix(int *rows, int *colmns) {
    int** checkmatrix= reinterpret_cast<int**>(malloc(4*sizeof(checkmatrix)));
    if (checkmatrix== NULL)
        return NULL;
    for (int i = 0; i < 4; i++) {
        checkmatrix[i]=reinterpret_cast<int*>(malloc(12*sizeof(checkmatrix[i])));
        if (checkmatrix== NULL)
            return NULL;
    }
    return checkmatrix;
}

int** initcheckmatri() {
    int** checkmatri= reinterpret_cast<int**>(malloc(12*sizeof(checkmatri)));
    if (checkmatri== NULL)
        return NULL;
    for (int i = 0; i < 12; i++) {
        checkmatri[i]=reinterpret_cast<int*>(malloc(8*sizeof(checkmatri[i])));
        if (checkmatri== NULL)
            return NULL;
    }
    return checkmatri;
}

int** transCheckMatrix(int **checkmatri, int **HMatrix, int *rowsH, int *colmnsH) {
    for(int i=0;i<*rowsH; i++) {
        for(int j=0; j<*colmnsH; j++) {
            checkmatri[j][i]=HMatrix[i][j];
        }
    }
    return checkmatri;
}
int** transCodeWord(int **codeWordT, int **codeWord, int rowsCodeWord, int colmnsCodeWord) {
    for(int i=0;i<rowsCodeWord; i++) {
        for(int j=0; j<colmnsCodeWord; j++) {
            codeWordT[j][i]=codeWord[i][j];
        }
    }
    return codeWordT;
}

int** proverka(int **Matrix, int *rows, int *colmns,
                        int **HMatrix, int *rowsH, int *colmnsH, int **checkmatrix) {
    for(int i=0;i<*rows; i++) {
        for(int j=0; j<*colmns; j++) {
            for(int m=0; m<*rowsH; m++) {
                checkmatrix[i][j]=abs(fmod(checkmatrix[i][j]+Matrix[i][m]*HMatrix[m][j],2));
            }
        }
    }
    return checkmatrix;
}
int** printcheckmatri(int **checkmatri) {
    printf("Ваша транспонированная матрица: \n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", checkmatri[i][j]);
        }
        printf("\n");
    }
    return checkmatri;
}
int** printcheckmatrix(int **checkmatrix) {
    printf("Ваша проверочная матрица: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <12; j++) {
            printf("%d ", checkmatrix[i][j]);
        }
        printf("\n");
    }
    return checkmatrix;
}
//___________________________________________________________



int** insertData(int **Matrix, int *rows, int *colmns) {
    printf("Заполняем матрицу. После каждого введенного значения необходимо нажать пробел. \n");
    printf("После того, как строчка кончится, необходимо нажать Enter. \n");
    for (int i = 0; i < *rows; i++) {
        printf("Введите %d строку.\n", i+1);
        for (int j = 0; j < *colmns; j++) {
            std::cin >> Matrix[i][j];
        }
    }
    printf("\n");
    printf("Ваша порождающая матрица G: \n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *colmns; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
    return Matrix;
}


int** gaussFunc(int **Matrix, int *rows, int *colmns) {
    if (Matrix[0][0] == 1) {
        for (int i = 1; i < *rows; i++) {
            if (Matrix[i][0] != 0) {
                int a = Matrix[i][0];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[0][j]=abs(fmod((Matrix[0][j]*(Matrix[i][0]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[0][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[0][j]=abs(fmod(((Matrix[0][j])/(a*(-1))), 2));
                }
            }
        }
    } else {
        for (int i = 1; i < *rows; i++) {
            int z;
            if (Matrix[i][0] == 1) {
                    for (int j = 0; j < *colmns; j++) {
                        z = Matrix[0][j];
                        Matrix[0][j] = Matrix[i][j];
                        Matrix[i][j] = z;
                    }
            i=*rows;
            }
        }

        for (int i = 1; i < *rows; i++) {
            if (Matrix[i][0] != 0) {
                int a = Matrix[i][0];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[0][j]=abs(fmod((Matrix[0][j]*(Matrix[i][0]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[0][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[0][j]=abs(fmod(((Matrix[0][j])/(a*(-1))), 2));
                }
            }
        }
    }

    return Matrix;
}

int** gaussFunc1(int **Matrix, int *rows, int *colmns) {
    if (Matrix[1][1] == 1) {
        for (int i = 2; i < *rows; i++) {
            if (Matrix[i][1] != 0) {
                int a = Matrix[i][1];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[1][j]=abs(fmod((Matrix[1][j]*(Matrix[i][1]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[1][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[1][j]=abs(fmod(((Matrix[1][j])/(a*(-1))), 2));
                }
            }
        }
    } else {
        for (int i = 2; i < *rows; i++) {
            int z;
            if (Matrix[i][1] == 1) {
                    for (int j = 0; j < *colmns; j++) {
                        z = Matrix[1][j];
                        Matrix[1][j] = Matrix[i][j];
                        Matrix[i][j] = z;
                    }
            i = *rows;
            }
        }

        for (int i = 2; i < *rows; i++) {
            if (Matrix[i][1] != 0) {
                int a = Matrix[i][1];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[1][j]=abs(fmod((Matrix[1][j]*(Matrix[i][1]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[1][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[1][j]=abs(fmod(((Matrix[1][j])/(a*(-1))), 2));
                }
            }
        }
    }

    if (Matrix[0][1] != 0) {
        int a = Matrix[1][1];
            for (int j = 0; j < *colmns; j++) {
                Matrix[0][j]=abs(fmod((Matrix[0][j]*(Matrix[1][1]*(-1))), 2));
            }
            for (int j = 0; j < *colmns; j++) {
                Matrix[0][j]=abs(fmod((Matrix[0][j]+Matrix[1][j]), 2));
            }
            for (int j = 0; j < *colmns; j++) {
                Matrix[0][j]=abs(fmod(((Matrix[0][j])/(a*(-1))), 2));
            }
    }
    return Matrix;
}

int** gaussFunc2(int **Matrix, int *rows, int *colmns) {
    if (Matrix[2][2] == 1) {
        for (int i = 3; i < *rows; i++) {
            if (Matrix[i][2] != 0) {
                int a = Matrix[i][2];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[2][j]=abs(fmod((Matrix[2][j]*(Matrix[i][2]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[2][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[2][j]=abs(fmod(((Matrix[2][j])/(a*(-1))), 2));
                }
            }
        }
    } else {
        for (int i = 3; i < *rows; i++) {
            int z;
            if (Matrix[i][2] == 1) {
                    for (int j = 0; j < *colmns; j++) {
                        z = Matrix[2][j];
                        Matrix[2][j] = Matrix[i][j];
                        Matrix[i][j] = z;
                    }
            i = *rows;
            }
        }

        for (int i = 3; i < *rows; i++) {
            if (Matrix[i][2] != 0) {
                int a = Matrix[i][2];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[2][j]=abs(fmod((Matrix[2][j]*(Matrix[i][2]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[2][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[2][j]=abs(fmod(((Matrix[2][j])/(a*(-1))), 2));
                }
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        if (Matrix[i][2] != 0) {
            int a = Matrix[2][2];
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]*(Matrix[2][2]*(-1))), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[2][j]), 2));
                }
                for (int j = 0; j < *colmns; j++) {
                    Matrix[i][j]=abs(fmod(((Matrix[i][j])/(a*(-1))), 2));
                }
        }
    }

    return Matrix;
}
int** gaussFunc3(int **Matrix, int *rows, int *colmns) {
        for(int i = 0; i < 3; i++) {
                if (Matrix[i][3] != 0) {
                    int a = Matrix[3][3];
                        for (int j = 0; j < *colmns; j++) {
                            Matrix[i][j]=abs(fmod((Matrix[i][j]*(Matrix[3][3]*(-1))), 2));
                        }
                        for (int j = 0; j < *colmns; j++) {
                            Matrix[i][j]=abs(fmod((Matrix[i][j]+Matrix[3][j]), 2));
                        }
                        for (int j = 0; j < *colmns; j++) {
                            Matrix[i][j]=abs(fmod(((Matrix[i][j])/(a*(-1))), 2));
                        }
                }
            }
    return Matrix;
}

int** printMatrix(int **Matrix, int *rows, int *colmns) {
    printf("Ваша порождающая матрица G, приведённая к ступенчатому виду: \n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *colmns; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return Matrix;
}
void freeCodeWord(int **codeWord, int rowsCodeWord) {
    printf("Очистка памяти...");
    for (int i = 0; i < rowsCodeWord; i++) {
        free(codeWord[i]);
    }
    free(codeWord);
}
void freeMatrix(int **Matrix, int *rows) {
    for (int i = 0; i < *rows; i++) {
        free(Matrix[i]);
    }
    free(Matrix);
}
void freeHMatrix(int **HMatrix, int *rows) {
    for (int i = 0; i < *rows; i++) {
        free(HMatrix[i]);
    }
    free(HMatrix);
    printf("Память очищена.\n");
}

void freeMatrixForH(int **Matrix, int **HMatrix, int *rows, int *colmns, int *rowsH, int *colmnsH) {
    for (int ih = 0, j = 4; ih < *rowsH, j < *colmns; ih++, j++) {
        for (int jh = 0, i = 0; jh < 4, i < *rows; jh++, i++) {
                    HMatrix[ih][jh] = Matrix[i][j];
                }
            }

    for (int i = 0; i < *rowsH; i++) {
        for (int j = 4; j < *colmnsH; j++) {
            if ( (j-i) == 4)
            HMatrix[i][j] = 1;
        }
    }

}

int fact(int n) {   
    return (n==0)?1:n*fact(n-1);
}
int HammingFunc(int d, int *rowsH, int *colmnsH) {

    printf("Размерность:\n");
    printf("n: %d \n",*colmnsH);
    printf("k: %d \n",((*colmnsH)-(*rowsH)));
    int M = pow(2,((*colmnsH)-(*rowsH)));
    printf("Число кодовых слов (мощность кода): %d \n",M);

    int t = (d-1)/2;
    int s = d-1;
    int sCorrect = s-t;
    printf("Число обнаруживаемых ошибок s: \n");
    printf(" - в режиме обнаружения: %d \n", s);
    printf(" - в режиме исправления: %d \n", sCorrect);
    printf("Число исправляемых ошибок t: %d \n", t);

    int C=1,Bt;
    for(int i=1; i<=t; i++) {
        C=C+fact(*colmnsH)/(fact(*colmnsH-i)*fact(i));
    }

    //printf("Мощность шара %d \n",C );
    if( M == (pow(2,*colmnsH)) / (C) )
        printf("Совершенный код.\n");
    else {
        if (M < (pow(2,*colmnsH)) / (C))
        printf("Несовершенный код.\n");
    }


}
int** printHMatrix(int **HMatrix, int *rowsH, int *colmnsH) {
    printf("Ваша матрица H: \n");
    for (int i = 0; i < *rowsH; i++) {
        for (int j = 0; j < *colmnsH; j++) {
            printf("%d ", HMatrix[i][j]);
        }
        printf("\n");
    }
    return HMatrix;
}
int** printDecodeWord(int **decodeWord) {
    printf("Декодирование: \n");
    for (int i = 0; i < 8; i++){    
        for (int j = 0; j < 1; j++){
            printf("%d ", decodeWord[i][j]);
        }
        printf("\n");
    }
    printf("Завершение\n");
}


int** initCodeWord(int rowsCodeWord, int colmnsCodeWord) {
    int** codeWord= reinterpret_cast<int**>(malloc(rowsCodeWord*sizeof(codeWord)));
    if (codeWord== NULL)
        return NULL;
    for (int i = 0; i < rowsCodeWord; i++) {
        codeWord[i]=reinterpret_cast<int*>(malloc(colmnsCodeWord*sizeof(codeWord[i])));
        if (codeWord== NULL)
            return NULL;
    }
    return codeWord;
}

int** initDecodeWord() {
    int** decodeWord= reinterpret_cast<int**>(malloc(8*sizeof(decodeWord)));
    if (decodeWord== NULL)
        return NULL;
    for (int i = 0; i < 8; i++) {
        decodeWord[i]=reinterpret_cast<int*>(malloc(1*sizeof(decodeWord[i])));
        if (decodeWord== NULL)
            return NULL;
    }
    return decodeWord;
}
int** initCodeWordT(int rowsCodeWord, int colmnsCodeWord) {
    int** codeWordT= reinterpret_cast<int**>(malloc(colmnsCodeWord*sizeof(codeWordT)));
    if (codeWordT== NULL)
        return NULL;
    for (int i = 0; i < colmnsCodeWord; i++) {
        codeWordT[i]=reinterpret_cast<int*>(malloc(rowsCodeWord*sizeof(codeWordT[i])));
        if (codeWordT== NULL)
            return NULL;
    }
    return codeWordT;
}

int** insertCodeWord(int **codeWord, int rowsCodeWord, int colmnsCodeWord) {
    printf("Введите кодовое слово. После каждого введенного значения необходимо нажать пробел: \n");
    printf("После того, как длина слова закончится, необходимо нажать Enter.\n");
    for (int i = 0; i < rowsCodeWord; i++)
        for(int j=0; j < colmnsCodeWord; j++) {
            std::cin >> codeWord[i][j];
    }
    return codeWord;
}


int** decodeCodeWord(int **codeWord, int rowsCodeWord, int colmnsCodeWord,
                        int **HMatrix, int *rowsH, int *colmnsH, int **decodeWord) {
    
    for(int i=0;i<*rowsH; i++) {
        for(int j=0; j<colmnsCodeWord; j++) {
            for(int m=0; m<*colmnsH; m++) {
                decodeWord[i][j]=abs(fmod(decodeWord[i][j]+(HMatrix[i][m]*codeWord[m][j]),2));
            }
        }
    }
    return decodeWord;
}

int main(void) {
    int rows, colmns;
    printf("Здравствуйте! Задайте размер матрицы.\n");
    printf("Число строк в вашей порождающей матрице G: ");
    scanf("%d", &rows);
    printf("Число столбцов в вашей порождающей матрице G: ");
    scanf("%d", &colmns);
    printf("\n");

    int** p = initMatrix(&rows, &colmns);
    insertData(p, &rows, &colmns);
    
    gaussFunc(p, &rows, &colmns);
    gaussFunc1(p, &rows, &colmns);
    gaussFunc2(p, &rows, &colmns);
    gaussFunc3(p, &rows, &colmns);
    
    printMatrix(p, &rows, &colmns);

    int rowsH, colmnsH;
    printf("Вводим размерность проверочной матрицы H: \n");
    printf("Число строк проверочной матрицы H (ввести 8): ");
    scanf("%d", &rowsH);
    printf("\n");
    printf("Число столбцов проверочной матрицы H (ввести 12): ");
    scanf("%d", &colmnsH);

    int** z = initHMatrix(&rowsH, &colmnsH);
    freeMatrixForH(p, z, &rows, &colmns, &rowsH, &colmnsH);
    printHMatrix(z, &rowsH, &colmnsH);
    printf("\n");
    printf("Сейчас будет проверка...\n");

    int** u = initcheckmatri();
    transCheckMatrix(u, z, &rowsH, &colmnsH);
    printcheckmatri(u);
    
    int** w = initMatrix(&rows, &colmns);
    int** q = initcheckmatrix(&rows, &colmns);

    rowsH = 12;
    colmnsH = 8;

    proverka(w, &rows, &colmns, u, &rowsH, &colmnsH, q);
    printf("Умножаем порождающую матрицу на транспонированную проверочную для проверки.\n");
    printcheckmatrix(q);
    printf("Если матрица нулевая, значит проверочная матрица H найдена верно.\n");
    rowsH = 8;
    colmnsH = 12;
    int d;
    printf("\n");
    printf("Введите значение d (считаем ручками): \n");
    scanf("%d",&d);
    HammingFunc(d, &rowsH, &colmnsH);

    printf("\n");
    printf("Введите число строк кодового слова (ввести 1): ");
    int rowsCodeWord, colmnsCodeWord;
    scanf("%d", &rowsCodeWord);
    printf("Введите число столбцов кодового слова (ввести 12): ");
    scanf("%d", &colmnsCodeWord);

    int** x = initCodeWord(rowsCodeWord, colmnsCodeWord);
    int** y = initDecodeWord();
    rowsH = 8;
    colmnsH = 12;
    insertCodeWord(x, rowsCodeWord, colmnsCodeWord);
    
    int** b = initCodeWordT(rowsCodeWord, colmnsCodeWord);
    transCodeWord(b, x, rowsCodeWord, colmnsCodeWord);

    rowsCodeWord=12;
    colmnsCodeWord=1;
    decodeCodeWord(b, rowsCodeWord, colmnsCodeWord, z, &rowsH, &colmnsH, y);
    printDecodeWord(y);
    printf("Поздравляшки! Вы получили синдром s. Дальше нужно действовать по алгоритму решения задачи.\n");
    rowsCodeWord=1;
    colmnsCodeWord=12;
    freeCodeWord(x, rowsCodeWord);
    freeMatrix(p, &rows);
    freeHMatrix(z, &rows);
    return EXIT_SUCCESS;
}
