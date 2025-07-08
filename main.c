#include <stdio.h>
#define MAX 100

// Khai báo cấu trúc Stack
typedef struct Stack {
    int data[MAX]; // Mảng chứa các phân tử của Stack
    int top; // Chỉ số phần tử đỉnh
} Stack;

// Khởi tạo Stack
void initialStack(Stack *s){
    s->top = -1; // Ban đầu stack rỗng
}

// Hàm kiểm tra xem Stack đã đầy hay chưa?
int isFull(Stack *s){
    return s->top == MAX - 1;
}

// Thêm phần tử vào Stack
void push(Stack *s, int value){
    // Trước khi push thì cần kiẻerm tra xem stack có đủ bọ nhớ không
    if(isFull(s)){
        printf("Stack đã bị đầy!");
        return;
    }

    // Nếu Stack còn bộ nhớ thì tiến hành thêm vào
    s->data[++s->top] = value;
}

// Kiểm tra Stack có bị rỗng?
int isEmpty(Stack *s){
    return s->top == -1;
}

// Lấy và loại bỏ phần tử trên cũng
int pop(Stack *s){
    // Kiểm tra xem Stack có bị rỗng không?
    if (isEmpty(s)){
        printf("Stack đang rỗng!");
        return -1;
    }

    return s->data[s->top--];
}

int peek(Stack *s){
    // Kiểm tra xem Stack có bị rỗng không?
    if (isEmpty(s)){
        printf("Stack đang rỗng!");
        return -1;
    }

    return s->data[s->top];
}

// Hàm in ra danh sách các phần tử có trong Stack => Hướng làm sai XXX
//void printElements(int elements[], int totalElement){
//    if (totalElement == 0){
//        printf("Stack đang rong!");
//        return;
//    }
//
//    // Duyệt các phần tử trong Stack
//    printf("Danh sach cac phan tu trong Stack");
//    for (int i = totalElement - 1; i >= 0 ; i--) {
//        printf("%d\n", elements[i]);
//    }
//}

// Hàm in ra danh sách các phân tử trong Stack theo thứ tự đảo ngược
void printElements(Stack *s){
    if (s->top == -1){
        printf("Stack dang rong!");
        return;
    }

    printf("Danh sach cac phan tu co trong Stack: \n");
//    for (int i = s->top; i >= 0 ; i--) {
//        printf("%d\n", s->data[i]);
//    }

    printf("[");
    for (int i = s->top; i >= 0 ; i--) {
        printf("%d", s->data[i]);

        if (i != 0) printf(", ");
    }
    printf("]");
}

int main(void) {
    Stack s;
    initialStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);

    printElements(&s);

    printf("\n");

    printf("Phan tu o dinh: %d\n", peek(&s)); // 60
    printf("Lay phan tu: %d\n", pop(&s)); // 60
    printf("Lay phan tu: %d\n", pop(&s)); // 50
    printf("Phan tu o dinh: %d\n", peek(&s)); // 40
    printf("Phan tu o dinh: %d\n", peek(&s)); // 40
    printf("Lay phan tu: %d\n", pop(&s)); // 40
    printf("Phan tu o dinh: %d\n", peek(&s)); // 30

    return 0;
}
