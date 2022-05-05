#include <iostream>
#include <stack>

using namespace std;

int F(int n)
{
    if (n <= 1) return 1;
    int a = n + F(n-1);
    int b = n * F(n/2);
    int c = n - 2 - ( a + b ) % 2;
    int d = F(c);
    return a + b + d;
}

int FIterative(int n)
{

    struct SnapshotStruct
    {
        int inputN;
        int a, b, d;
        int stage;
    };

    int result;

    stack<SnapshotStruct> s;

    SnapshotStruct currentSnapshot;
    currentSnapshot.inputN = n;
    currentSnapshot.stage = 0;

    s.push(currentSnapshot);

    while (!s.empty())
    {
        currentSnapshot = s.top();
        s.pop();

        switch(currentSnapshot.stage)
        {
            case 0:
                if (currentSnapshot.inputN <= 1)
                {
                    result = 1;
                    continue;
                }
                else
                {
                    currentSnapshot.stage = 1;
                    s.push(currentSnapshot);

                    SnapshotStruct newSnapshot;
                    newSnapshot.inputN = currentSnapshot.inputN - 1;
                    newSnapshot.stage = 0;
                    s.push(newSnapshot);
                    continue;
                }
            case 1:
                currentSnapshot.a = result + currentSnapshot.inputN;
                currentSnapshot.stage = 2;
                s.push(currentSnapshot);

                SnapshotStruct newSnapshot;
                newSnapshot.inputN = currentSnapshot.inputN / 2;
                newSnapshot.stage = 0;
                s.push(newSnapshot);
                continue;
            case 2:
                currentSnapshot.b = currentSnapshot.inputN * result;
                currentSnapshot.stage = 3;
                s.push(currentSnapshot);

                SnapshotStruct newSnapshot1;
                newSnapshot1.stage = 0;
                newSnapshot1.inputN = currentSnapshot.inputN - 2 - (currentSnapshot.a + currentSnapshot.b) % 2;
                s.push(newSnapshot1);
                continue;
            case 3:
                currentSnapshot.d = result;
                result = currentSnapshot.a + currentSnapshot.b + currentSnapshot.d;
                continue;
        }
    }
    return result;
}

int main()
{
    for (int i = 1; i <= 20; i++)
        cout << F(i) << "\t\t" << FIterative(i) << endl;
    return 0;
}