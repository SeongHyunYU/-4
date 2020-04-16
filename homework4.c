#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_matrix(int row, int col);
int free_matrix(int** matrix, int row, int col);
void print_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col);

int** create_matrix(int row, int col) {

	int**arr;
    arr = malloc(sizeof(int*) * row);//열을 동적할당으로 생성
    for (int i = 0; i < row; i++) {
        arr[i] = malloc(sizeof(int) * col);//행을 동적할당으로 생성
    }
    return arr;//arr의 주소 반환
}

int free_matrix(int** matrix, int row, int col){
   for(int i=0; i<row; i++){
      free(matrix[i]); // 열 -> 행 메모리해제
   }
   free(matrix); //matrix->열  메모리해제

   return 0;
}

void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}


int fill_data(int** matrix, int row, int col) {
   void srand (unsigned int seed);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            matrix[i][j] = rand() % 19 + 1; // 0~19까지 원소 랜덤값으로 배열안에 입력
        }
    }
    return matrix;
}
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            matrix_t[j][i] = matrix[i][j]; // 전치


        }
    }
    return matrix_t;
};
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return matrix_sum;
};
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }
    return matrix_sub;
};

int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col) {

	  int sum;
	   for(int i=0; i<row; i++){
	           for(int j=0; j<row; j++){
	               sum=0;
	               for(int k=0; k<col; k++){
	                   sum+=matrix_a[i][k]*matrix_t[k][j]; //sum에 matrix_a[i][k]와 matrix_t[k][j]의 곱들의 합을 입력
	               }
	               matrix_axt[i][j]=sum;
	           }
	       }
	    return matrix_axt;
	   }

int main() {
printf("    유성현                  2017038042 \n");
	int row, col;

    scanf("%d %d", &row, &col);
    if (row <= 0 || col <= 0) {
        printf("행과 열의 입값이 잘못되었습니다.\n");
        return -1;
    }

    /*전치행렬 출력*/
    int** i_mtr = create_matrix(row, col);      //빈 행렬생성
    int** t_mtr = create_matrix(col, row);    //전치행렬을 받을 빈 행렬 생성
    i_mtr = fill_data(i_mtr, row, col);      //첫번째 행렬의 원소 생성
    print_matrix(i_mtr, row, col);
    printf("---전치행렬---\n");
    t_mtr = transpose_matrix(i_mtr, t_mtr, row, col);   //첫번째 행렬의 전치행렬
    print_matrix(t_mtr, col, row);

    printf("=======================================\n");

    int** a_mtr = create_matrix(row, col);  // 합할 두 행렬
    int** b_mtr = create_matrix(row, col);
    int** sum_mtr = create_matrix(row, col);
    a_mtr = fill_data(a_mtr, row, col);
    b_mtr = fill_data(b_mtr, row, col); // 두행렬 원소 생성
    print_matrix(a_mtr, row, col);
    printf("---------------\n");
    print_matrix(b_mtr, row, col);
    printf("---두행렬의 합---\n");
    sum_mtr = addition_matrix(a_mtr, b_mtr, sum_mtr, row, col);// 두행렬의 합
    print_matrix(sum_mtr, row, col);
    printf("=======================================\n");

    int** c_mtr = create_matrix(row, col);  // 차를 구할 두 행렬
    int** d_mtr = create_matrix(row, col);
    int** sub_mtr = create_matrix(row, col);
    c_mtr = fill_data(c_mtr, row, col);
    d_mtr = fill_data(d_mtr, row, col); // 두행렬 원소 생성
    print_matrix(c_mtr, row, col);
    printf("---------------\n");
    print_matrix(d_mtr, row, col);
    printf("---두행렬의 차---\n");
    sub_mtr = subtraction_matrix(c_mtr, d_mtr, sub_mtr, row, col);// 두행렬의 차
    print_matrix(sub_mtr, row, col);

    printf("=======================================\n");
    int** mul_mtr = create_matrix(row,row); // 두행렬의 곱을담을 빈행렬 생성
    print_matrix(i_mtr, row, col);
    printf("----------\n");
    print_matrix(t_mtr, col, row);
    printf("첫번째 만든 행렬과 전치행렬의 곱\n");
    mul_mtr=multiply_matrix(i_mtr, t_mtr, mul_mtr, row, col); // i_mtr과 그의 전치행렬의 곱
    print_matrix(mul_mtr, row, row);

    free_matrix(i_mtr, row, col);
    free_matrix(t_mtr, row, col);
    free_matrix(a_mtr, row, col);
    free_matrix(b_mtr, row, col);
    free_matrix(c_mtr, row, col);
    free_matrix(d_mtr, row, col);
    free_matrix(sub_mtr, row, col);
    free_matrix(mul_mtr, row, col); //메모리 해제완료!

    return 0;
}
