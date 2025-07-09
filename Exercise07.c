#include <stdio.h>
#include <string.h>
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

// Hàm thêm phân tử là ký tự vào trong Stack
void push(Stack *s, char character){
    // Trước khi push thì cần kiẻerm tra xem stack có đủ bọ nhớ không
    if(isFull(s)){
        printf("Stack đã bị đầy!");
        return;
    }

    // Nếu Stack còn bộ nhớ thì tiến hành thêm vào
    s->data[++s->top] = character;
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


// Hàm kiểm tra 2 dấu ngoặc xem có khớp với nhau không?
int isMatchingPair(char characterOpen, char characterClose){
    int flag = 1;

    if (characterOpen == '(' && characterClose == ')' || characterOpen == '{' && characterClose == '}' || characterOpen == '[' && characterClose == ']'){
        return flag;
    }

    return 0;
}

int isValidBrackets(Stack* s, char* stringInput){
    // Duyệt từng ky tự trong biều thức
    for (int i = 0; stringInput[i] != '\0' ; i++) {
        // Lấy ra từng ký tự
        char character = stringInput[i];

        // Nếu gặp dấu ngoặc mở thì đẩy vào trong Stack
        if (character == '(' || character == '{' || character == '['){
            push(s, character);

            // Nếu gặp dấu ngoặc đóng
        } else if (character == ')' || character == '}' || character == ']') {
            // Nếu không có dấu ngoặc mở tương ứng => trả về 0
            if (isEmpty(s)) {
                return 0;
            }

            // Nếu là ngoặc đóng thì tiến hành đi kiểm tra đỉnh (top) của Stack
            char open = pop(s);

            // Kiểm tra tính hợp lệ của ký tự đóng và mở
            if (!isMatchingPair(open, character)) {
                return 0; // Không khớp
            }
        }
    }

    return isEmpty(s); // Nếu như Stack còn dư => Sai

}

int main(void) {
    Stack s;
    initialStack(&s);

    char stringInput[MAX];

    printf("Nhap chuoi can kiem tra: ");
    fgets(stringInput, sizeof (stringInput), stdin);
    stringInput[strcspn(stringInput, "\n")] = '\0'; // Xóa dấu xuống dòng

    // Gọi hàm kiểm tra tính hợp lệ của biu thức
    if (isValidBrackets(&s, stringInput)){
        printf("Bieu thuc hop le");
    } else {
        printf("Bieu thuc khong hop le");
    }


    return 0;
}
