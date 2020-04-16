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
    arr = malloc(sizeof(int*) * row);//���� �����Ҵ����� ����
    for (int i = 0; i < row; i++) {
        arr[i] = malloc(sizeof(int) * col);//���� �����Ҵ����� ����
    }
    return arr;//arr�� �ּ� ��ȯ
}

int free_matrix(int** matrix, int row, int col){
   for(int i=0; i<row; i++){
      free(matrix[i]); // �� -> �� �޸�����
   }
   free(matrix); //matrix->��  �޸�����

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

            matrix[i][j] = rand() % 19 + 1; // 0~19���� ���� ���������� �迭�ȿ� �Է�
        }
    }
    return matrix;
}
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            matrix_t[j][i] = matrix[i][j]; // ��ġ


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
	                   sum+=matrix_a[i][k]*matrix_t[k][j]; //sum�� matrix_a[i][k]�� matrix_t[k][j]�� ������ ���� �Է�
	               }
	               matrix_axt[i][j]=sum;
	           }
	       }
	    return matrix_axt;
	   }

int main() {
printf("    ������                  2017038042 \n");
	int row, col;

    scanf("%d %d", &row, &col);
    if (row <= 0 || col <= 0) {
        printf("��� ���� �԰��� �߸��Ǿ����ϴ�.\n");
        return -1;
    }

    /*��ġ��� ���*/
    int** i_mtr = create_matrix(row, col);      //�� ��Ļ���
    int** t_mtr = create_matrix(col, row);    //��ġ����� ���� �� ��� ����
    i_mtr = fill_data(i_mtr, row, col);      //ù��° ����� ���� ����
    print_matrix(i_mtr, row, col);
    printf("---��ġ���---\n");
    t_mtr = transpose_matrix(i_mtr, t_mtr, row, col);   //ù��° ����� ��ġ���
    print_matrix(t_mtr, col, row);

    printf("=======================================\n");

    int** a_mtr = create_matrix(row, col);  // ���� �� ���
    int** b_mtr = create_matrix(row, col);
    int** sum_mtr = create_matrix(row, col);
    a_mtr = fill_data(a_mtr, row, col);
    b_mtr = fill_data(b_mtr, row, col); // ����� ���� ����
    print_matrix(a_mtr, row, col);
    printf("---------------\n");
    print_matrix(b_mtr, row, col);
    printf("---������� ��---\n");
    sum_mtr = addition_matrix(a_mtr, b_mtr, sum_mtr, row, col);// ������� ��
    print_matrix(sum_mtr, row, col);
    printf("=======================================\n");

    int** c_mtr = create_matrix(row, col);  // ���� ���� �� ���
    int** d_mtr = create_matrix(row, col);
    int** sub_mtr = create_matrix(row, col);
    c_mtr = fill_data(c_mtr, row, col);
    d_mtr = fill_data(d_mtr, row, col); // ����� ���� ����
    print_matrix(c_mtr, row, col);
    printf("---------------\n");
    print_matrix(d_mtr, row, col);
    printf("---������� ��---\n");
    sub_mtr = subtraction_matrix(c_mtr, d_mtr, sub_mtr, row, col);// ������� ��
    print_matrix(sub_mtr, row, col);

    printf("=======================================\n");
    int** mul_mtr = create_matrix(row,row); // ������� �������� ����� ����
    print_matrix(i_mtr, row, col);
    printf("----------\n");
    print_matrix(t_mtr, col, row);
    printf("ù��° ���� ��İ� ��ġ����� ��\n");
    mul_mtr=multiply_matrix(i_mtr, t_mtr, mul_mtr, row, col); // i_mtr�� ���� ��ġ����� ��
    print_matrix(mul_mtr, row, row);

    free_matrix(i_mtr, row, col);
    free_matrix(t_mtr, row, col);
    free_matrix(a_mtr, row, col);
    free_matrix(b_mtr, row, col);
    free_matrix(c_mtr, row, col);
    free_matrix(d_mtr, row, col);
    free_matrix(sub_mtr, row, col);
    free_matrix(mul_mtr, row, col); //�޸� �����Ϸ�!

    return 0;
}
