#include "headers.h"


#define random(x) (rand()%x)

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
inline int belonging(int x, int y) { return x / 3 * 3 + y / 3 + 1; }
inline int Position(int x, int y) { return 9 * x + y; }
using namespace std;
const int N = 11;
const int M = 83;

static int ans_all_cnt = 0, ans_all[1000010][M], ans_new[50010][M];

/*

�ڸ�����Ŀ�������޸ģ�ʵ��void generate(int number, int mode, int[][] result)�ӿڣ����������������Ϸ�������������Ѷȵȼ���ͨ��result�������ɵ�������Ϸ�ļ��ϡ�
����һgenerate�ӿڽ��в��ԣ��ѵ�Ԫ���Դ���Push��Github��(ע�����ѵ�Ԫ���ԵĽ��Push��Github��)��
ʵ��void generate(int number, int lower, int upper, bool unique, int[][] result)�ӿڣ�����number���հ����½�Ϊlower���Ͻ�Ϊupper��������Ϸ���������uniqueΪ�棬�����ɵ�������Ϸ�Ľ����Ψһ������Ľ���洢��result�С�
����һgenerate�ӿڽ��в��ԣ��ѵ�Ԫ���Դ���Push��Github��(ע�����ѵ�Ԫ���ԵĽ��Push��Github��)��
ʵ��bool solve(int[] puzzle, int[] solution)�ӿڣ����������������Ŀpuzzle������������չ��Ϊһά���飩������һ��boolֵ��ʾ�Ƿ��н⡣����н⣬��һ�����н�洢��solution�У�ͬ����ʾΪ���������һά����չ������
��solve�ӿڽ��в��ԣ��ѵ�Ԫ���Դ���Push��Github��(ע�����ѵ�Ԫ���ԵĽ��Push��Github��)��
����������ֵĽӿڣ�������ƺõĽӿ��ڸ�����Ŀ�����������޸ģ�ͬ���ѵ�Ԫ���Դ���Push��Github�ϡ�
�������һ�׶ε�����֮��ʹ��git tag step1��ǵ�һ�׶��Ѿ���ɣ�����Push��Github��ʱʹ��--tags������tagҲ���͵�Github������git push origin --tags��

*/


class Core { //__declspec(dllexport)
public:
	int sol = 0, tot, x[M], a[M][N], a_backup[M][M][N], aaa[M];
	bool debug;
	int hasAnswer = 0;
	FILE *out;

	int value, cnt, n, m, len = 0;  // value����Ҫ����ľ���ĸ���
	char ch;
	bool vis_col[N][N], vis_row[N][N], vis_magic[N][N];

	int num_0, id, game[M];
	bool isEmpty[M];
	double p_exist;
	bool hasException = false;

	bool find(int x, int y, int z); //�ж�����[x][y]��λ���ܷ���z
	void init_gen(int val, int type); //����-c
	void init_sol(); //����-s
	void trans(int a[81]); //�ѵ�ǰ������������ת����ת���ɵ�һ��Ϊ1..9������
	bool isEquivalent(int a[81], int b[81]); //�ж�����a������b�ǲ��ǵ�Ч
	bool deleteElement(int pos, int r); //��������еĲ���_����һ������Ԫ�ص�����
	bool modifyElement(int pos, int r); //��������еĲ���_���һ������Ԫ��
	void out_file(int *s); //�������s���ļ�(sudoku.txt)��
	void dfs1(int k, int type); //���������Ļ���1
	void dfs2(int k, int type); //��������Ļ���2
	int freedom(int a[M]); //�������a�����ɶ�
	double getRandData(int min, int max); //����һ��(min,max)�ĸ�����
	void dfs3(int k, int tot); //������Ԫ�ص��������ڿյĻ���3
	int work3(int num_0_t, int id_t, double p_t); //����ȷ��0������������ԭ���ǵ�id��������

	void generate(int number, int mode, int result[][M]); //���������������Ϸ�������������Ѷȵȼ���ͨ��result�������ɵ�������Ϸ�ļ���
	void generate(int number, int lower, int upper, bool unique, int result[][M]); //����number���հ����½�Ϊlower���Ͻ�Ϊupper��������Ϸ���������uniqueΪ�棬�����ɵ�������Ϸ�Ľ����Ψһ������Ľ���洢��result��
	bool check(int a[M]); //��麬0������a�ǲ��ǺϷ���
	bool solve(int puzzle[M], int solution[M]); //���������������Ŀpuzzle������������չ��Ϊһά���飩������һ��boolֵ��ʾ�Ƿ��н⡣����н⣬��һ�����н�洢��solution�У�ͬ����ʾΪ���������һά����չ����

	void generate_single(int number, int from, int ran, int dow, int upd, bool unique, int result[][M]); //����numer��������0�ĸ�����[ran, ran+from-1]�У����ɶ���[dow, upd]�У�unique����Ҫ��Ҫ����Ψһ��
	int solve_unique(int tmp[M]); //���һ����һ������tmp�������ĸ���, �������ans_first

	int ans_first[M];
};

