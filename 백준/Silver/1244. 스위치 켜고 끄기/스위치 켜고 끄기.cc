#include <vector>
#include <iostream>

using namespace std;

void man(int target, int n, vector<int>& switches) {

    for (int i=target; i<=n; i+=target) {
        switches[i] = (switches[i]==1) ? 0 : 1;
    }

}

void woman(int target, int n, vector<int>& switches) {
    int l = target-1;
    int r = target+1;
    switches[target] = (switches[target]==1) ? 0 : 1;
    while (l > 0 && r <= n) {
        if (switches[l] != switches[r]) break;

        switches[l] = (switches[l]==1) ? 0 : 1;
        switches[r] = (switches[r]==1) ? 0 : 1;

        l--;
        r++;
    }
}

vector<int> solution(int n, vector<int> switches, vector<vector<int>> students) {
    vector<int> answer(switches);

    for (int i=0;i<students.size();i++) {
        if (students[i][0] == 1) { // 남학생이면
            man(students[i][1], n, answer);
        }
        else {
            woman(students[i][1], n, answer);
        }
    }

    return answer;
}

int main() 
{
    int n,m;
    cin >> n;
    vector<int> switches(n+1);
    for (int i=1;i<=n;i++) {
        cin >> switches[i];
    }

    cin >> m;
    vector<vector<int>> students(m, vector<int>(2));
    for (int i=0;i<m;i++) {
        int a, b;
        cin >> students[i][0] >> students[i][1];
    }

    vector<int> res = solution(n, switches, students);

    for (int i=1;i<=n;i++) {
        cout << res[i] << " ";
        if (i % 20 == 0)cout << "\n";
    }
    return 0;
}
