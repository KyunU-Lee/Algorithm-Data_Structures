#include "Chapter2.h"

/// <summary>
/// ¦�� ���� : ���� ����  N �� �޾Ƽ� N������ ���� ¦���� ��� ����ϴ� �˰���
/// </summary>
void Chapter2::code2_3()
{
	int n;
	cout << "Please Input Number : ";
	cin >> n;

	for (int i = 2; i <= n; i += 2)
	{
          cout << i << endl;
	}
}
/// <summary>
/// �ֱ��� �� ���� �Ÿ� �˰����� ���⵵�� O(N^2) �̴�. 
/// ���� �������� ����ϸ� O(NlogN)���� ������ �� �ִ�.
/// </summary>
void Chapter2::code2_4() 
{
    cout << "Code2_4" << endl;
    int n;
    cout << "Input N" << endl;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "]";
        cin >> x[i];
        cout << "y[" << i << "]";
        cin >> y[i];
        cout << endl;
    }

    double minimum_dist = 10000000.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j){
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

            if (dist_i_j < minimum_dist) {
                minimum_dist = dist_i_j;
            }

        }

    }

    cout << minimum_dist << endl;

}

double Chapter2::calc_dist(double x1, double y1, double x2, double y2) 
{
    return sqrt((x1-x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
