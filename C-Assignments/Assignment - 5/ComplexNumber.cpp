#include <cstdio>
#include <cstdlib>

struct complex {
    int real;
    int img;
};

enum operation {
    addition = 1,
    subtraction,
    product,
    division
};
void display(struct complex c) {
    if (c.img >= 0)
        printf("%d + %di\n", c.real, c.img);
    else
        printf("%d %di\n", c.real, c.img);
}
void add(struct complex c1, struct complex c2) {
    struct complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    display(c);
}

void diff(struct complex c1, struct complex c2) {
    struct complex c;
    c.real = c1.real - c2.real;
    c.img = c1.img - c2.img;
    display(c);
}

void multiply(struct complex c1, struct complex c2) {
    struct complex c;
    c.real = c1.real * c2.real;
    c.img = c1.img * c2.img;
    display(c);
}

void divide(struct complex c1, struct complex c2) {
    struct complex c;
    //printf("Divided!");
	int x,y,z;
	if (b.real == 0 && b.img == 0)
        printf("Division by 0 + 0i isn't allowed.");
      else {
        x = a.real*b.real + a.img*b.img;
        y = a.img*b.real - a.real*b.img;
        z = b.real*b.real + b.img*b.img;
 
        if (x%z == 0 && y%z == 0) {
          if (y/z >= 0)
            printf("%d + %di", x/z, y/z);
          else
            printf("%d %di", x/z, y/z);
        } else if (x%z == 0 && y%z != 0) {
          if (y/z >= 0)
            printf("%d + %d/%di", x/z, y, z);
          else
            printf("%d %d/%di", x/z, y, z);
        } else if (x%z != 0 && y%z == 0) {
          if (y/z >= 0)
            printf("%d/%d + %di", x, z, y/z);
          else
            printf("%d %d/%di", x, z, y/z);
        } else {
          if (y/z >= 0)
            printf("%d/%d + %d/%di",x, z, y, z);
          else
            printf("%d/%d %d/%di", x, z, y, z);
        }
      }
}

int main() {
    struct complex c1, c2;
    printf("Enter Complex Number (a and b): ");
    scanf("%d %d", &c1.real, &c1.img);
    printf("Enter Complex Number (c and d): ");
    scanf("%d %d", &c2.real, &c2.img);
    printf("1. Addition \n2. Subtraction \n3. Product \n4. Division\n");
    enum operation op;
    scanf("%d", &op);
    switch(op) {
        case addition:
           add(c1, c2); break;
        case subtraction:
            diff(c1, c2); break;
        case product:
            multiply(c1, c2); break;
        case division:
            divide(c1, c2); break;
    }
	return 0;
}