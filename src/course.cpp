#include <bits/stdc++.h>
using namespace std;

struct student
{  // 学生结构
    string   name;
    string   id;
    string   sex;
    string   course[6];
    int      kyl = 0;
    string   password = "123456";
    student *next;
};
struct course
{  //课程
    string  name;
    string  num;
    string  cteacher;
    int     sum = 0;
    course *next;
};
student *head;
course  *head1;
student *stu;
void     help();
void     studentMeau();
void     teacherMeau();
void     meau();
int      tpassword();
int      spassword();
void     glstudent();
void     glcourse();
void     addCourse();
void     addStudent();
void     endStudent();
void     deleteStudent();
void     changeStudent();
void     glstudent();
void     findStudent();
void     chanStundentPassword();
void     chooseCourse();
void     creatChosenCourse();
void     findCourse();
void     changeCourse();
void     creatCourse();

int main()
{
    cout << "\t\t****************************************\n"
         << "\t\t*            贵州大学大学选课系统    *\n"
         << "\t\t*            输入“Y”开始使用         *\n"
         << "\t\t*            输入“N”退出系统         *\n"
         << "\t\t****************************************\n";
    cout << "\t\t              请输入：     ";
    char A;
    cin >> A;
    if ( A == 'Y' )
    {
        creatCourse();
        meau();
    }
    else if ( A == 'N' )
    {
        system( "clear" );
        cout << "\t\t             感谢使用，再见！";
        exit( 0 );
    }
    getchar();
}
void meau()
{
T:
    // system("clear");
    cout << "\t\t***************************************\n"
         << "\t\t*           欢迎使用选课系统          *\n"
         << "\t\t*             1.教师系统              *\n"
         << "\t\t*             2.学生系统              *\n"
         << "\t\t*               3.帮助                *\n"
         << "\t\t*               4.退出                *\n"
         << "\t\t***************************************\n";
    cout << "\t\t\t   请选择：";
    string A;
    cin >> A;
    if ( A == "1" )
    {
        teacherMeau();
    }
    else if ( A == "2" )
    {
        studentMeau();
    }
    else if ( A == "3" )
    {
        help();
    }
    else if ( A == "4" )
    {
        cout << "\t\t       谢谢使用，再见！";
        exit( 0 );
    }
    else
    {
        cout << "\t\t           输入有误，任意输入后重新选择";
        string a;
        cin >> a;
        goto T;
    }
}
void help()
{
    system( "clear" );
    cout << "\t系统由键盘输入控制，密码可修改但是只限于六位密码\n"
         << "\t教师密码统一为111111，学生初始密码都为123456\n"
         << "\t学生账号不可自己修改需要由教师修改" << endl
         << "\t教师无账号只需要登陆密码\n";
    cout << "\t输入任意键返回主菜单";
    string A;
    cin >> A;
    meau();
}
void creatCourse()
{
    course *p, *s;
    head1 = new course;
    p = new course;
    s = new course;
    p = head1;
    p->num = "01";
    p->name = "高数";
    p->cteacher = "燕赵魏";
    p->sum = 121;
    p->next = NULL;
}

void studentMeau()
{
    int mi;
    mi = spassword();
    if ( mi == 1 )
    {
    s1:
        system( "clear" );
        cout << "\t\t**********************************\n"
             << "\t\t*            学生系统            *\n"
             << "\t\t*           1.学生选课           *\n"
             << "\t\t*           2.查询结果           *\n"
             << "\t\t*           3.修改密码           *\n"
             << "\t\t*           4.返回上级           *\n"
             << "\t\t**********************************\n";
        string a;
        cin >> a;
        if ( a == "1" )
        {
            chooseCourse();
        }
        else if ( a == "2" )
        {
            creatChosenCourse();
        }
        else if ( a == "3" )
        {
            chanStundentPassword();
        }
        else if ( a == "4" )
        {
            meau();
        }
        else
        {
            goto s1;
        }
    }
}
void chooseCourse()
{
A:
    int      f = 0, f1 = 0, f3 = 0;
    student *p, *s, *q;
    course  *p1, *q1, *s1;
    p = new student;
    s = new student;
    q = new student;
    p1 = new course;
    s1 = new course;
    q1 = new course;
    system( "clear" );
    if ( stu->kyl == 6 )
    {
        cout << "\t\t\t      你选择课程数已达上限！";
        cout << "\n\t\t\t        键入回车返回学生菜单";
        getchar();
        getchar();
        studentMeau();
    }
    system( "clear" );
    int    sum = stu->kyl;
    string k;
    cout << "\n\t\t\t                        课程单";
    for ( p1 = head1; p1; p1 = p1->next )
    {
        cout << "\n\t\t          课程名:" << p1->name << " 课程号:" << p1->num << " 开课教师:" << p1->cteacher << " 课余量:" << p1->sum;
    }
    int ji = 0;
    cout << "\n\t\t\t      你还可以选择" << 6 - stu->kyl << "节课程.";
    cout << "\n\t\t\t       请输入要选择的课程号：";
    cin >> k;
    for ( p1 = head1; p1; p1 = p1->next )
    {
        if ( p1->num == k )
        {
            f = 1;
            s1 = p1;
        }
        if ( s1->sum > 0 )
        {
            f1 = 1;
        }
        for ( int i = 0; i < 6; i++ )
        {
            if ( k == stu->course[i] )
            {
                f3 = 1;
            }
        }
    }
    if ( f == 1 && f1 == 1 && f3 == 0 )
    {
        stu->course[sum] = k;
        stu->kyl++;
        s1->sum--;
        sum++;
        cout << "\n\t\t\t        成功选到" << s1->name << "这门课程！";
        cout << "\n\t\t\t        继续选课输入Y,返回学生菜单输入N:";
        char a;
        cin >> a;
        if ( a == 'Y' )
        {
            goto A;
        }
        else if ( a == 'N' )
        {
            studentMeau();
        }
    }
    else if ( f == 1 && f1 == 0 && f3 == 0 )
    {
        cout << "\n\t\t\t         课程课余量不足！请重新选择或者联系教师增加！"
             << "\n\t\t\t                 重新选择输入Y,返回学生菜单输入N";
        char b;
        cin >> b;
        if ( b == 'Y' )
        {
            goto A;
        }
        else if ( b == 'N' )
        {
            studentMeau();
        }
    }
    else if ( f == 0 )
    {
        cout << "\n\t\t\t            课程不存在！请重新选择或者联系教师！"
             << "\n\t\t\t                 重新选择输入Y,返回学生菜单输入N";
        char c;
        cin >> c;
        if ( c == 'Y' )
        {
            goto A;
        }
        else if ( c == 'N' )
        {
            studentMeau();
        }
    }
    else if ( f3 == 1 )
    {
        cout << "\n\t\t\t          已选该课程,请重新选择\n\t\t\t            回车继续";
        getchar();
        getchar();
        goto A;
    }
}
void creatChosenCourse()
{
    course *p;
    p = new course;
    cout << "\t\t     选课结果：";
    for ( int i = 0; i < stu->kyl; i++ )
    {
        for ( p = head1; p; p = p->next )
        {
            if ( stu->course[i] == p->num )
                cout << "课程名:" << p->name << " 课序号:" << p->num << " 开课教师:" << p->cteacher << " 课容量:" << p->sum << endl;
        }
    }
n:
    cout << "\t\t     返回上级输入Y";
    cout << "\t\t         请输入:";
    char a;
    cin >> a;
    if ( a == 'Y' )
    {
        studentMeau();
    }
    else
        goto n;
}
void chanStundentPassword()
{
    system( "clear" );
    int    k = 3, m = 2, p = 3, l = 2;
    string n, B;
    while ( 1 )
    {
        cout << "\n\t\t\t      请输入当前账号,三次错误后将退出登录";
        cin >> n;
        if ( stu->id == n )
        {
            system( "clear" );
            while ( 1 )
            {
                cout << "\t\t\t              请输入密码：\n";
                cout << "\t\t\t        输入连续错误三次将退出登录！\n";
                cin >> B;
                if ( stu->password == B )
                {
                    cout << "\n\t\t\t          身份确认！请输入新密码:";
                    string A;
                    cin >> A;
                    stu->password = A;
                    cout << "\n\t\t\t       修改完成！回车返回学生菜单";
                    getchar();
                    getchar();
                    studentMeau();
                }
                else
                {
                    k--;
                    m--;
                    cerr << "\n\t\t\t密码输入错误！请重新输入！你还有" << m + 1 << "次机会\n" << endl;
                }
                if ( k == 0 )
                {
                    help();
                }
            }
        }
        else
        {
            p--;
            l--;
            cerr << "\n\t\t\t      账号错误！请重新输入！你还有" << l + 1 << "次机会\n" << endl;
        }
        if ( p == 0 )
        {
            help();
        }
    }
}

void teacherMeau()
{
    int mi;
    mi = tpassword();
    if ( mi == 1 )
    {
    t:
        system( "clear" );
        cout << "\t\t\t*********************************************\n";
        cout << "\t\t\t*                   教师端                  *\n";
        cout << "\t\t\t*                 1.学生管理                *\n";
        cout << "\t\t\t*                 2.课程管理                *\n";
        cout << "\t\t\t*                 3.返回上级                *\n";
        cout << "\t\t\t*********************************************\n";
        cout << "\t\t\t请选择：";
        char a;
        cin >> a;
        if ( a == '1' )
        {
            glstudent();
        }
        else if ( a == '2' )
        {
            glcourse();
        }
        else if ( a == '3' )
        {
            meau();
        }
        else
        {
            goto t;
        }
    }
}  // 教师系统
void glcourse()
{
s1:
    system( "clear" );
    cout << "\t\t*******************************\n"
         << "\t\t*          课程管理系统        *\n"
         << "\t\t*          1.查询课程          *\n"
         << "\t\t*          2.修改课程          *\n"
         << "\t\t*          3.添加课程          *\n"
         << "\t\t*         4.返回教师菜单       *\n"
         << "\t\t********************************\n";
    cout << "\t\t            请选择:";
    char x;
    cin >> x;
    if ( x == '1' )
    {
        findCourse();
    }
    else if ( x == '2' )
    {
        changeCourse();
    }
    else if ( x == '4' )
    {
        teacherMeau();
    }
    else if ( x == '3' )
    {
        addCourse();
    }
    else
        goto s1;
}  // 课程管理菜单
void changeCourse()
{
A:
    system( "clear" );
    int f = 0;
    cout << "\t\t          请输入要修改的课程序号:";
    string x;
    cin >> x;
    for ( course *i = head1; i->next; i = i->next )
    {
        if ( x == i->num )
        {
            f = 1;
            cout << "\t\t       请按课程名、课程号、开课教师、课容量的顺序输入新的课程信息\n";
            string a;
            cin >> a;
            i->name = a;
            cin >> i->num;
            cin >> i->cteacher;
            cin >> i->sum;
            cout << "\t\t" << x << "课程已修改\n\t\t修改结果:";
            cout << "课程名:" << i->name << " 课程号:" << i->num << " 开课教师:" << i->cteacher << " 课容量:" << i->sum << endl;
            cout << "\n\t\t继续修改输入Y，返回课程管理菜单输入N";
        n:
            cout << "\t\t         请输入:";
            char b;
            cin >> b;
            if ( b == 'Y' )
            {
                goto A;
            }
            else if ( b == 'N' )
            {
                glcourse();
            }
            else
                goto n;
        }
    }
    if ( f == 0 )
    {
        cout << "\t\t      课程不存在，输入任意键后返回课程管理:";
        getchar();
    }
}  // 修改课程信息
void findCourse()
{
A:
    course *i;
    i = new course;

    system( "clear" );
    string s;
    int    f = 0;
    cout << "\t\t         1.通过课序号查询\n"
         << "\t\t        2.返回课程管理菜单\n"
         << "\t\t               请选择:";
    char x;
    cin >> x;
    if ( x == '1' )
    {
        cout << "\n\t\t         输入课序号:";
        cin >> s;
        for ( i = head1; i != NULL; i = i->next )
        {
            if ( s == i->num )
            {
                f = 1;
                cout << "\n\t\t\t      找到该课程！\n";
                f = 1;
                cout << "课程名:" << i->name << " 课程号:" << i->num << " 开课教师:" << i->cteacher << " 课容量:" << i->sum;
            n:
                cout << "\n\t\t      继续查询输入Y，返回课程管理输入N";
                cout << "\t\t              请输入:";
                char a;
                cin >> a;
                if ( a == 'Y' )
                {
                    goto A;
                }
                else if ( a == 'N' )
                {
                    glcourse();
                }
                else
                    goto n;
            }
        }
        if ( f == 0 )
            cout << "\t\t         课程不存在！输入任意键返回：";
        getchar();
        goto A;
    }
    else if ( x == '2' )
    {
        glcourse();
    }
    else
        goto A;
}
void addCourse()
{
A:
    system( "clear" );
    course *p, *s;
    p = head1;
    s = new course;
    while ( p->next )
    {
        p = p->next;
    }
    cout << "\n\t\t 添加课程\n";
    string n;
    cout << "课程号:";
    cin >> n;
    s->num = n;
    cout << " 课程名:";
    cin >> n;
    s->name = n;
    cout << " 开课教师:";
    cin >> n;
    s->cteacher = n;
    cout << " 课容量:";
    int x;
    cin >> x;
    s->sum = x;
    p->next = s;
    s->next = NULL;
n:
    cout << "\n\t\t  继续添加输入Y,返回输入N:";
    char f;
    cin >> f;
    if ( f == 'Y' )
    {
        goto A;
    }
    else if ( f == 'N' )
    {
        glcourse();
    }
    else
        goto n;
}

void glstudent()
{
s1:
    system( "clear" );
    cout << "\t\t\t********************************************\n";
    cout << "\t\t\t*              学生管理系统                *\n";
    cout << "\t\t\t*               1.增加学生                 *\n";
    cout << "\t\t\t*               2.删除学生                 *\n";
    cout << "\t\t\t*               3.修改学生                 *\n";
    cout << "\t\t\t*               4.查询学生                 *\n";
    cout << "\t\t\t*               5.返回上级                 *\n";
    cout << "\t\t\t********************************************\n";
    cout << "\t\t\t                请选择操作：";
    char a;
    cin >> a;
    if ( a == '1' )
    {
        addStudent();
    }
    else if ( a == '2' )
    {
        deleteStudent();
    }
    else if ( a == '3' )
    {
        changeStudent();
    }
    else if ( a == '4' )
    {
        findStudent();
    }
    else if ( a == '5' )
    {
        teacherMeau();
    }
    else
    {
        goto s1;
    }
}
void addStudent()
{
A:
    system( "clear" );
    int n;
    cout << "\t\t       请输入添加学生数:";
    cin >> n;
    cout << endl;

    head = new student;
    head->next = NULL;
    for ( int i = 0; i < n; i++ )
    {
        endStudent();
    }
B:
    cout << "\n\t\t        继续添加输入“Y”，返回学生管理菜单输入“N”\n"
         << "\t\t               请选择：";
    char q;
    cin >> q;
    if ( q == 'Y' )
    {
        goto A;
    }
    else if ( q == 'N' )
    {
        glstudent();
    }
    else
    {
        goto B;
    }
}
void endStudent()
{
    student *p, *s;
    p = head;
    s = new student;
    while ( p->next )
    {
        p = p->next;
    }
    string n;
    cout << "学号:";
    cin >> n;
    s->id = n;
    cout << " 姓名:";
    cin >> n;
    s->name = n;
    cout << " 性别:";
    cin >> n;
    s->sex = n;
    p->next = s;
    s->next = NULL;
}
void deleteStudent()
{
A:
    system( "clear" );
    string   x;
    int      f = 0;
    student *p, *s, *q;
    p = head;
    if ( head == NULL )
    {
        cout << "\t\t   无学生信息，输入任意字符返回：";
        char b;
        cin >> b;
        glstudent();
    }
    else
    {
        cout << "\t\t*******************************\n"
             << "\t\t*           删除学生          *\n"
             << "\t\t*        1.通过学号查找       *\n"
             << "\t\t*       2.返回学生管理菜单    *\n"
             << "\t\t*******************************\n";
        cout << "\t\t            请选择：";
        char a;
        cin >> a;
        if ( a == '1' )
        {
            system( "clear" );
            cout << "\n\t\t         输入需删除学生学号:";
            cin >> x;
            while ( p != NULL )
            {
                q = p;
                s = p->next;
                if ( s->id == x )
                {
                    q->next = s->next;
                    free( s );
                n:
                    cout << "\n\t\t  已删除，继续删除输入Y,返回输入N";
                    char c;
                    cin >> c;
                    if ( c == 'Y' )
                        goto A;
                    else if ( c == 'N' )
                    {
                        glstudent();
                    }
                    else
                        goto n;
                }
                p = p->next;
            }
            cout << "\n\t\t 学生不存在！输入任意键返回：";
            getchar();
        }
        else if ( a == '2' )
        {
            glstudent();
        }
        else
            goto A;
    }
}
void changeStudent()
{
A:
    student *p;
    p = head->next;
    system( "clear" );
    string name;
    int    f = 0;
    cout << "\t\t****************************\n"
         << "\t\t*         修改学生         *\n"
         << "\t\t*      1.通过学号查询      *\n"
         << "\t\t*     2.返回学生管理菜单   *\n"
         << "\t\t****************************\n"
         << "\t\t          请选择: ";
    char x;
    cin >> x;
    if ( x == '1' )
    {
        system( "clear" );
        cout << "\n\t\t       请输入学号:";
        cin >> name;
        while ( p && p->id != name )
        {
            p = p->next;
        }
        if ( p == NULL )
        {
            cout << "\n\t\t   学生不存在!输入任意字符返回:";
            getchar();
            goto A;
        }
        else
        {
            cout << "\n\t\t  请输入学生信息:";
            cout << "\n姓名:";
            cin >> p->name;
            cout << " 学号:";
            cin >> p->id;
            cout << " 性别:";
            cin >> p->sex;
            cout << endl;
        }
    n:
        cout << "\n\t\t  继续修改输入Y,返回输入N:";
        char a;
        cin >> a;
        if ( a == 'Y' )
            goto A;
        else if ( a == 'N' )
        {
            glstudent();
        }
        else
            goto n;
    }
    else if ( x == '2' )
    {
        glstudent();
    }
    else
        goto A;
}
void findStudent()
{
A:
    system( "clear" );
    string   name;
    student *p;
    p = new student;
    course *q;
    q = new course;
    p = head;
    if ( !p )
    {
        cout << "\t\t    无学生信息,请先添加学生,输入任意字符返回:";
        getchar();
        return;
    }

    cout << "\t\t*****************************\n"
         << "\t\t*        查询学生           *\n"
         << "\t\t*      1.通过学号查询       *\n"
         << "\t\t*     2.返回学生管理菜单    *\n"
         << "\t\t*****************************\n";
    cout << "\t\t          请选择:";
    char a;
    cin >> a;
    if ( a == '1' )
    {
        system( "clear" );
        cout << "\n\t\t       请输入学号:";
        cin >> name;
        while ( p && p->id != name )
        {
            p = p->next;
        }
        if ( !p )
        {
            cout << "\n\t\t   学生不存在!输入任意字符返回:";
            getchar();
            goto A;
        }

        cout << "\n姓名:" << p->name << " 学号:" << p->id << " 性别:" << p->sex << endl;
        cout << "\n\t\t   该学生选课结果\n";
        for ( int i = 0; i < p->kyl; i++ )
        {
            for ( q = head1; q != NULL; q = q->next )
            {
                if ( p->course[i] == q->num )
                {
                    cout << "课程名:" << q->name << " 课程号:" << q->num << " 开课教师:" << q->cteacher << " 课容量:" << q->sum << endl;
                }
            }
        }

    n:
        cout << "\n\t\t  继续查询输入Y,返回输入N:";
        char b;
        cin >> b;
        if ( b == 'Y' )
        {
            goto A;
        }
        else if ( b == 'N' )
        {
            glstudent();
        }
        else
            goto n;
    }
    else if ( a == '2' )
    {
        glstudent();
    }
    else
        goto A;
}

int spassword()
{
    system( "clear" );
    student *q, *p;
    q = new student;
    p = new student;
    p = head;
    if ( p == NULL )
    {
        cout << "\t\t\t    没有任何学生信息，请先联系老师添加！";
        cout << "\n\t\t\t         输入任意字符返回上级菜单:";
        char a;
        cin >> a;
        if ( a )
        {
            meau();
        }
    }
    int    k = 3, m = 2;
    char   a;
    string n, A;
    cout << "\n\t\t\t           请输入学号：";
    cin >> n;
    int j = 0;
    for ( q = head; q; q = q->next )
    {
        if ( n == q->id )
        {
            stu = q;
            cout << "登录者：" << stu->name;
            goto m;
        }
    }
m:
    while ( 1 )
    {
        cout << "\t\t\t        请输入密码：\n";
        cout << "\t\t\t    输入连续错误三次将自动退出\n";
        cin >> A;
        if ( A == stu->password )
            return 1;
        else
        {
            k--;
            m--;
            cerr << "\n\t\t\t密码输入错误！请重新输入！你还有" << m + 1 << "次机会\n" << endl;
        }
        if ( k == 0 )
        {
            return 0;
        };
    }
}

int tpassword()
{
    system( "clear" );
    int    k = 3, m = 2, s = 7;
    string A = "111111", B;
    while ( 1 )
    {
        cout << "\t\t\t        请输入教师管理密码：\n";
        cout << "\t\t\t    输入连续错误三次将自动退出\n";
        int i = 0;
        cin >> B;
        if ( A == B )
            return 1;
        else
        {
            k--;
            m--;
            cerr << "\n\t\t\t密码输入错误！请重新输入！你还有" << m + 1 << "次机会\n" << endl;
        }
        if ( k == 0 )
        {
            return 0;
        };
    }
}
