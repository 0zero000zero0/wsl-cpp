int test_variety = 0;
// const关键字可以使得变量只读,并且只在该文件内可以访问
// 由于只读的属性,const修饰的变量必须初始化
// 如果要跨文件使用const修饰的变量，那么在定义，声明时都必须加上extern
extern const int const_int = 666;

class test_class
{
  public:
    int ival;
};

// 选择排序
void selectionSort(int *arr, int length);
void selectionSort(double *arr, int length);

// 冒泡排序
void bubbleSort(int *a, int n);
void bubbleSort(int *a, int n);

// 链表
typedef struct Node
{ // 单向 链表数据结构
    int a;
    struct Node *next;
} node;
void linkedLstMain();                       // 显示函数
int insert_node(node **head, int i, int a); // 插入结点,i是插入位置，a是插入的数据

int delete_node_oder(node **head, int i); // 通过序号来删除结点

int delete_node_number(node **head, int a); // ͨ通过数值来删除链表的结点

int change_value(node *head, int i, int new_value); // 改变链表节点的值

int isPrime(int x); // 判断素数

void convert_string(char p[]); // 反转字符串
// 循环链表实现约瑟夫问题
typedef struct josepdus
{
    int data;
    struct josepdus *next;
} josepdus;
void tableOfMutiply();
void jps(int n /*人数*/, int k /*离开的报数*/); // 约瑟夫环(循环列表)
void numberOfWaterFlower(int min, int max);
int EuclideanAlgorithm(int x, int y);
void YangHuiSanJiao(int n);
// 删除小于平均数的结点
node *deleteNodeUnderAverage(node *head);