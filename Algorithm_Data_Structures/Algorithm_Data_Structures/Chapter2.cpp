#include "Chapter2.h"

/// <summary>
/// 짝수 나열 : 양의 정수  N 을 받아서 N이하의 양의 짝수를 모두 출력하는 알고리즘
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
/// 최근접 두 점의 거리 알고리즘의 복잡도는 O(N^2) 이다. 
/// 분할 정복법을 사용하면 O(NlogN)으로 개선할 수 있다.
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
