
/** Quickswap */
a = a + b - (b = a);

/** init array with \0 all around */
int a[] = {'\0'};


/** (int[n]) is a compound literal, compound literals are temporary objects that hold some value. IN this case, this creates a variable-lenght array of size n*/
int main(void) {
    int n = 5;
    int *p = (int[n]) { 1, 2, 3, 4, 5 };
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}

/** Compile-time tree struct */
struct bin_tree {
    int value;
    struct bin_tree *left;
    struct bin_tree *right;
};

#define NODE(V, L, R) &(struct bin_tree){V, L, R}

const struct bin_tree *tree = \
    NODE(4,
         NODE(2, NULL, NULL),
         NODE(7,
              NODE(5, NULL, NULL),
              NULL));

/** Objects can be used in the designators */
struct {
    int a[3], b;
} 
w[] = { [0].a = { [1] = 2 }, [0].a[0] = 1 };

int main() {
    printf("%d\n", w[0].a[0]);
    printf("%d\n", w[0].a[1]);
}

/** The inline keyword asks the compile to replace the function call forthe actual function. This can incease code size and compiling time but it makes execution faster.*/
inline int max(int x, int y) {
    return (x > y) ? x : y;
}

/** a[b] is equal to: */
*(a + b)

/** 1 is a pointer to an array of 5 ints
 2 is an array of 5 pointers to int*/
int (*b);
int (*b)(int);
int (*b)[5];   // 1
int *b[5];     // 2

/** null pointer to access the member of struct to get its size at compile time. */
#define member_size(type, member) sizeof(((type *)0)->member)